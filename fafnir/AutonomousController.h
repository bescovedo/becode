#ifndef AUTONOMOUS_CONTROLLER_H
#define AUTONOMOUS_CONTROLLER_H

#include "Robot.h"

class AutonomousController {
 private:
  Robot *fafnir;
  bool fire();
 public:
  AutonomousController(Robot *fafnir);
  virtual ~AutonomousController();
};

#endif /* AUTONOMOUS_CONTROLLER_H */
