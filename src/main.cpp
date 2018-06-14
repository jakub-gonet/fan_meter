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

  Measure measure(500, 50);

  while (true) {
    if (!adc.is_conversion_in_progress()) {
      adc.start_one_async_conversion();
    }

    uint16_t measured_voltage = adc.get_last_conversion();
    if (measured_voltage != -1) {
      measure.update_output(measured_voltage, pwm);
    }
  }

  return 0;
}
