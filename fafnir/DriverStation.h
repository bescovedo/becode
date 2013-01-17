#ifndef DRIVER_STATION_H
#define DRIVER_STATION_H

#include "WPILib.h"

class DriverStation {
private:
   Joystick leftStick;
   Joystick rightStick; // how many joysticks do we have
	// buttons and things
public:
  void init(); // set up joysticks and the like
  void update();
  int getAutoType(); // we can set different autonomous starting places or procedures
  int getStickX(); // can we pass the joystick inside?
  int getStickY();
};

#endif /* DRIVER_STATION_H */
