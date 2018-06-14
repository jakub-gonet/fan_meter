#include <avr/io.h>
#include <stdint.h>

#include "pins.hpp"
#include "pins_defines.hpp"

Pins::Pins() {
  PWM_OUT_DDR = (1 << PWM_OUT_POS) | (1 << PWM_OUT_NEG);
}