#ifndef MEASURE_HPP
#define MEASURE_HPP

#include <avr/io.h>

class Measure {
 public:
  /**
   * @brief Used to mark value between positive and negative PWM
   *
   */
  uint16_t threshold;

  /**
   * @brief Used to prevent PWM from oscilating at exact threshold point
   *
   */
  uint8_t hysteresis = 50;

  /**
   * @brief Construct a new Measure object with provided threshold and default
   * histeresis
   *
   * @param threshold
   */
  Measure(const uint16_t threshold);

  /**
   * @brief Construct a new Measure object with provided threshold and
   * histeresis
   *
   * @param threshold
   * @param hysteresis
   */
  Measure(const uint16_t threshold, uint8_t hysteresis);

  void update_output();
};

#endif  // MEASURE_HPP