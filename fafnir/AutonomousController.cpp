#include "AutonomousController.h"
#include "Robot.h"

AutonomousController::AutonomousController(Robot *fafnir) {
  this.fafnir = fafnir;
}

AutonomousController::~AutonomousController() {
  
}

bool AutonomousController::fire() {
  *fafnir.aim();
  *fafnir.shoot();
}
