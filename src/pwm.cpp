#include "pwm.hpp"
#include <avr/io.h>

Pwm::Pwm() {
  // set output pins behavior
  TCCR1A = (1 << COM1A1) |  // Clear OC1A, OC1B on Compare Match, set OC1A, OC1B
           (1 << COM1B1) |  // at BOTTOM, (non-inverting mode)

           // set mode of operation Fast PWM, 10 bit
           (1 << WGM10) | (1 << WGM11);
  TCCR1B = (1 << WGM12) |

           // set clock source
           (1 << CS10);  // internal clock source, no prescaling

  // set comparision registers (16 bit)
  OCR1A = 0;  // one of them should be always 0
  OCR1B = 0;
}