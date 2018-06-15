#include "measure.hpp"
#include <avr/io.h>
#include "pwm.hpp"

Measure::Measure(uint16_t threshold, uint8_t hysteresis, const Pwm& pwm)
    : threshold(threshold),
      hysteresis(hysteresis),
      pwm(pwm),
      is_dynamic_mode_enabled(false),
      lowest_measured_value(0xFFFF),
      highest_measured_value(0) {}

void Measure::update_measured_values(uint16_t current_value) {
  if (is_dynamic_mode_enabled) {
    if (current_value < lowest_measured_value) {
      lowest_measured_value = current_value;
    } else if (current_value > highest_measured_value) {
      highest_measured_value = current_value;
    }

    top = highest_measured_value;
    bottom = lowest_measured_value;
  } else {
    top = pwm.pwm_max_value;
    bottom = 0;
  }

  middle_of_range = (top - bottom) / 2;
}

void Measure::use_dynamic_range(bool enabled) {
  is_dynamic_mode_enabled = enabled;
}
           
void Measure::update_output(uint16_t measured_voltage) {
  uint16_t lower_delta = middle_of_range - hysteresis;
  uint16_t higher_delta = middle_of_range + hysteresis;


  /*
  * Explanation:
  *    top ┬ h1            Let `x` be position on this drawing, `x in <bottom, top)`
  *        │               Also, let f be function mapping `x` to PWM output.
  *        │               When `x` is above `hight` level, PWM should be in range `<h0, h1>`, growing towards `h1`. 
  *  hight ┼ h0            When `x` is below `low` level PWM should be in range `<l0, l1>`, growing towards `l0`. 
  *    low ┼ l1            
  *        │               Therefore:     
  *        │                f(x) →  (x - hight) / (top - hight) * (h1 - h0),     when x in <0, top)
  * bottom ┴ l0             f(x) → (1 - ((x - bot) / (low - bot))) * (l1 - l0),  when x in <bottom, l1)
  */    
  if (measured_voltage <= lower_delta) {
    pwm.set_duty_cycle_on_negative_output_pin(
        (1 - ((measured_voltage - bottom) / (float)(lower_delta - bottom))) *
        pwm.pwm_max_value);

  } else if (measured_voltage >= higher_delta) {
    pwm.set_duty_cycle_on_positive_output_pin(
        ((measured_voltage - higher_delta) / (float)(top - higher_delta)) *
        pwm.pwm_max_value);
  }
}