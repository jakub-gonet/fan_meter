#include <avr/io.h>

#include "adc.hpp"

Adc::Adc() {
  ADMUX = (1 << REFS0);      // AVcc voltage ref, MUX 000 -> ADC0 as input
  ADCSRA = (1 << ADEN)       // ADC enabled
            | (1 << ADPS0) |  // prescaler /8 (50-200kHz for max resolution)
            (1 << ADPS1);
}
bool Adc::is_conversion_in_progress() {
  return ADCSRA & (1 << ADSC);
}

void Adc::start_one_async_conversion() {
  ADCSRA |= (1 << ADSC);
}

uint16_t Adc::get_last_conversion() {
  return ADC;
}
