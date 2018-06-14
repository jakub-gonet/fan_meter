#include "measure.hpp"
#include <avr/io.h>
#include "pwm.hpp"

Measure::Measure(const uint16_t threshold) : threshold(threshold) {}

Measure::Measure(const uint16_t threshold, uint8_t hysteresis)
    : threshold(threshold), hysteresis(hysteresis) {}

void Measure::update_output(uint16_t measured_voltage, Pwm pwm) {
  if (measured_voltage < this->threshold - this->hysteresis) {
    pwm.set_duty_cycle_on_negative_output_pin(measured_voltage);
  } else if (measured_voltage > this->threshold + this->hysteresis) {
    pwm.set_duty_cycle_on_positive_output_pin(measured_voltage);
  }
}