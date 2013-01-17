#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

class Accumulator {
private:
  Victor motor;
  bool start();
  bool kill();
public:
  bool collect();
  bool update();
  Accumulator();
};

#endif /* ACCUMULATOR_H */
