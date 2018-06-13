#include <avr/io.h>
#include "adc.hpp"
#include "pins.hpp"
#include "pwm.hpp"

int main() {
  // initialize modules
  Pins pins();
  Adc adc();
  Pwm pwm();

  while (true) {
  }

  return 0;
}
