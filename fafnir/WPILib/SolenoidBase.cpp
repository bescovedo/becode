/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "SolenoidBase.h"

#include "Synchronized.h"

SEM_ID SolenoidBase::m_semaphore = NULL;
Resource *SolenoidBase::m_allocated = NULL;

tSolenoid *SolenoidBase::m_fpgaSolenoidModule = NULL;
UINT32 SolenoidBase::m_refCount = 0;


/**
 * Constructor
 * 
 * @param moduleNumber The solenoid module (1 or 2).
 */
SolenoidBase::SolenoidBase(UINT8 moduleNumber)
	: m_moduleNumber (moduleNumber)
{
	m_refCount++;
	if (m_refCount == 1)
	{
		// Needs to be global since the protected resource spans all Solenoid objects.
		m_semaphore = semMCreate(SEM_Q_PRIORITY | SEM_DELETE_SAFE | SEM_INVERSION_SAFE);
		tRioStatusCode localStatus = NiFpga_Status_Success;
		m_fpgaSolenoidModule = tSolenoid::create(&localStatus);
		wpi_setError(localStatus);
	}
}

/**
 * Destructor.
 */
SolenoidBase::~SolenoidBase()
{
	if (CheckSolenoidModule(m_moduleNumber))
	{
		if (m_refCount == 1)
		{
			delete m_fpgaSolenoidModule;
			m_fpgaSolenoidModule = NULL;
			semDelete(m_semaphore);
			m_semaphore = NULL;
		}
		m_refCount--;
	}
}

/**
 * Set the value of a solenoid.
 * 
 * @param value The value you want to set on the module.
 * @param mask The channels you want to be affected.
 */
void SolenoidBase::Set(UINT8 value, UINT8 mask)
{
	tRioStatusCode localStatus = NiFpga_Status_Success;
	if (CheckSolenoidModule(m_moduleNumber))
	{
		Synchronized sync(m_semaphore);
		UINT8 currentValue = m_fpgaSolenoidModule->readDO7_0(m_moduleNumber - 1, &localStatus);
		// Zero out the values to change
		currentValue = currentValue & ~mask;
		currentValue = currentValue | (value & mask);
		m_fpgaSolenoidModule->writeDO7_0(m_moduleNumber - 1, currentValue, &localStatus);
	}
	wpi_setError(localStatus);
}

/**
 * Read all 8 solenoids as a single byte
 * 
 * @return The current value of all 8 solenoids on the module.
 */
UINT8 SolenoidBase::GetAll()
{
	if (CheckSolenoidModule(m_moduleNumber))
	{
		tRioStatusCode localStatus = NiFpga_Status_Success;
		UINT8 solenoids = m_fpgaSolenoidModule->readDO7_0(m_moduleNumber - 1, &localStatus);
		wpi_setError(localStatus);
		return solenoids;
	}
	return 0;
}
