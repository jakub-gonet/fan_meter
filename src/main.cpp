#include <avr/io.h>
#include "adc.hpp"
#include "measure.hpp"
#include "pins.hpp"
#include "pwm.hpp"

#define F_CPU 1000000

int main() {
  // initialize modules
  Pins pins;
  Adc adc;
  Pwm pwm;

  Measure measure(500, 50);

  while (true) {
    uint16_t measured_voltage = adc.get_last_conversion();
    bool mode_enabled = pins.is_dynamic_range_mode_enabled();
    if (mode_enabled) {
      adc.update_measured_values(measured_voltage);
    }
    measure.update_output(measured_voltage, pwm);
  }
}