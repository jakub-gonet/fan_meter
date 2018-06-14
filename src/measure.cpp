#include "measure.hpp"
#include <avr/io.h>
#include "pwm.hpp"

Measure::Measure(const uint16_t threshold, uint8_t hysteresis)
    : threshold(threshold), hysteresis(hysteresis) {}

void Measure::update_output(uint16_t measured_voltage, const Pwm& pwm) {
  uint16_t lower_delta = this->threshold - this->hysteresis;
  uint16_t higher_delta = this->threshold + this->hysteresis;

  if (measured_voltage <= lower_delta) {
    pwm.set_duty_cycle_on_negative_output_pin(
        lower_delta - (measured_voltage / lower_delta) * pwm.pwm_max_value);
  } else if (measured_voltage >= higher_delta) {
    pwm.set_duty_cycle_on_positive_output_pin(
        ((measured_voltage - higher_delta) /
         (pwm.pwm_max_value - higher_delta)) *
        pwm.pwm_max_value);
  }
}