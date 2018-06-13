#include <avr/io.h>

#include "adc.hpp"

Adc::Adc() {
  ADMUX |= (1 << REFS0);      // AVcc voltage ref, MUX 000 -> ADC0 as input
  ADCSRA |= (1 << ADEN)       // ADC enabled
            | (1 << ADPS0) |  // prescaler /8 (50-200kHz for max resolution)
            (1 << ADPS1);
}
