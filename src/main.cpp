#include <avr/io.h>
#include "adc.hpp"
#include "measure.hpp"
#include "pins.hpp"
#include "pwm.hpp"

int main() {
  // initialize modules
  Pins pins;
  Adc adc;
  Pwm pwm;

  Measure measure(50, pwm);

  while (true) {
    uint16_t measured_voltage = adc.get_last_conversion();
    if (pins.is_dynamic_range_mode_enabled()) {
      measure.use_dynamic_range(true);
    } else {
      measure.use_dynamic_range(false);
    }

    measure.update_measured_values(measured_voltage);
    measure.update_output(measured_voltage);
  }
}