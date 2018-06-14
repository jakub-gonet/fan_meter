#include <avr/io.h>

#include "adc.hpp"

Adc::Adc() {
  ADMUX = (1 << REFS0);    // AVcc voltage ref, MUX 000 -> ADC0 as input
  ADCSRA = (1 << ADEN) |   // ADC enabled
           (1 << ADPS0) |  // prescaler /8 -> 1MHz - 125kHz
           (1 << ADPS1) |  // (50-200kHz for max resolution)
           (1 << ADFR);    // free running mode
}

void Adc::update_measured_values(uint16_t current_value) {
  if (current_value < this->lowest_measured_value) {
    this->lowest_measured_value = current_value;
  } else if (current_value > this->highest_measured_value) {
    this->highest_measured_value = current_value;
  }
}