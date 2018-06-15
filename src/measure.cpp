#include "measure.hpp"
#include <avr/io.h>
#include "pwm.hpp"

  uint16_t lower_delta = this->threshold - this->hysteresis;
  uint16_t higher_delta = this->threshold + this->hysteresis;

  /*
  * Explanation:
  * ┬ top, h1             Let x be position on this drawing, x in <bottom, top)
  * │   ⇑                 Also, let f be function mapping x to PWM output. When x is above h0 PWM should be in range <h0, h1), growing towards h1.
  * │   ⇑                 When x is below l1 PWM should be in range <l0, l1), growing towards l0.
  * ┼ h0                  Therefore:
  * ┼ l1
  * │   ⇓                 f(x) →  (l1 - x) / (l1 - l0) * l1,   when x in <h0, top)
  * │   ⇓                 f(x) → ((x - h0) / (h1 - h0)) * h1,  when x in <bottom, l1)
  * ┴ bottom, l0
  */
Measure::Measure(uint16_t threshold, uint8_t hysteresis, const Pwm& pwm)
    : threshold(threshold), hysteresis(hysteresis), pwm(pwm) {}

void Measure::update_output(uint16_t measured_voltage) {
  if (measured_voltage <= lower_delta) {
    pwm.set_duty_cycle_on_negative_output_pin(
        (lower_delta - measured_voltage) /
                      (float)lower_delta 
        
        * pwm.pwm_max_value);

  } else if (measured_voltage >= higher_delta) {
    pwm.set_duty_cycle_on_positive_output_pin(
        ((measured_voltage - higher_delta) /
         (float)(pwm.pwm_max_value - higher_delta))
         
          * pwm.pwm_max_value);
  }
}