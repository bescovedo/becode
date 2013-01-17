#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter {
private:
   Encoder elevationEncoder;
   Victor motor1; //this is the first motor that spins the wheel to propel the frisbee
   Victor motor2; // this is the second motor that spins the swheel to propel the frisbee
   Victor motorElevation; //this is the third motor that will elevate the shooting mechanism of the robot. 
   
public:
   void setElevation(float angle); // set elevation 
   int elevationY;
};

#endif /* SHOOTER_H */
