#include "measure.hpp"
#include <avr/io.h>

Measure::Measure(const uint16_t threshold) : threshold(threshold) {}

Measure::Measure(const uint16_t threshold, uint8_t hysteresis)
    : threshold(threshold), hysteresis(hysteresis) {}

void Measure::measure_voltage() {}

void Measure::update_output() {}