#ifndef MEASURE_HPP
#define MEASURE_HPP

#include <avr/io.h>
#include "pwm.hpp"

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
  uint8_t hysteresis;

  /**
   * @brief Construct a new Measure object with provided threshold and
   * histeresis
   *
   * @param threshold
   * @param hysteresis
   */
  Measure(uint16_t threshold, uint8_t hysteresis, const Pwm& pwm);

  /**
   * @brief Enables or disables dynamic changes of `top`, `bottom` and
   * `middle_of_range`
   *
   * If enabled, those values will be based on lowest and highest measured
   * values.
   * If disabled, those values will be set to maximum pwm duty cycle
   * value, 0 and middlepoint between them.
   *
   */
  void use_dynamic_range(bool enabled);

  /**
   * @brief Updates lowest and highest measured values
   *
   * @param current_value
   */
  void update_measured_values(uint16_t current_value);

  /**
   * @brief Updates `PWM_POS` and `PWM_NEG` duty cycles based on measured
   * voltage
   *
   * @param measured_voltage
   */
  void update_output(uint16_t measured_voltage);

 private:
  bool is_dynamic_mode_enabled;

  /**
   * @brief Used to get maximum PWM values
   *
   */
  const Pwm& pwm;

  /**
   * @brief Used to store maximum ratings of measured voltage
   *
   */
  uint16_t lowest_measured_value;
  uint16_t highest_measured_value;

  /**
   * @brief Used to calculate PWM value
   *
   */
  uint16_t middle_of_range, top, bottom;
};

#endif  // MEASURE_HPP