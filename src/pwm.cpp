#include "pwm.hpp"
#include <avr/io.h>

Pwm::Pwm() {
  // set output pins behavior
  TCCR1A |= (1 << COM1A1) |
            (1 << COM1B1);  // Clear OC1A, OC1B on Compare Match, set OC1A, OC1B
                            // at BOTTOM, (non-inverting mode)

  // set mode of operation
  TCCR1A |= (1 << WGM12) | (1 << WGM11);  // Fast PWM, 10-bit
  TCCR1B |= (1 << WGM10);

  // set clock source

  TCCR1B |= (1 << CS10);  // internal clock source, no prescaling

  // set comparision registers (16 bit)
  OCR1A = 0;  // one of them should be always 0
  OCR1B = 0;
}

void Pwm::set_duty_cycle_on_positive_output_pin(uint16_t duty_cycle) const {
  OCR1A = duty_cycle;
  OCR1B = 0;
}

void Pwm::set_duty_cycle_on_negative_output_pin(uint16_t duty_cycle) const {
  OCR1A = 0;
  OCR1B = duty_cycle;
}