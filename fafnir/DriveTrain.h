#ifndef DRIVE_TRAIN_H
#define DRIVE_TRAIN_H

#include "Constants.h"
#include "WPILabs.h"

class DriveTrain {
private:
  ShifterMode gear; //ShifterMode is enumerated in Constants.h
  Encoder leftFrontEnc;
  Encoder leftBackEnc;
  Encoder rightFrontEnc;
  Encoder rightBackEnc;
  bool periodicAuto();
  int speed;
  int rotateSpeed; 
  

public:
  bool driveSpd(double);
  bool driveDist(double);
  bool driveTo(double, double);

  bool rotateSpd(double);
  bool rotateDist(double);

  ShifterMode getGear();
  bool setGear(ShifterMode mode);

  bool update();
};

#endif /* DRIVE_TRAIN_H */
