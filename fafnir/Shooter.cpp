int main() {
  Shooter target1(28.3928); // just a test
}

Shooter: Shooter() {
  setElevation(30.0); // constructor that will set the elevation as 30 (default)
}

Shooter: Shooter(elevationY) {
  setElevation(elevationY); // a constructor that will take an argument that will set the elevation of the shooter
}
Shooter: setElevation(float f) {
  //need code from WPILib to set the elevation of the shooter
} 
