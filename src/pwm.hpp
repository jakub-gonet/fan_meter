#ifndef PWM_HPP
#define PWM_HPP

#include <avr/io.h>

class Pwm {
 public:
  /**
   * @brief Describes highest possible value of PWM comparision register
   *  for 10 bit resolution -> 1023 (2^10-1)
   *  for 8 bit resolution  -> 255  (2^8-1)
   */
  const uint16_t pwm_max_value = 1023;

  /**
   * @brief Constructs a new Pwm object and configures PWM settings
   *
   */
  Pwm();

  /**
   * @brief Sets duty cycle on positive PWM pin
   *
   * @param duty_cycle a new duty cycle value (10 bit width at most)
   */
  inline void set_duty_cycle_on_positive_output_pin(uint16_t duty_cycle) const {
    OCR1A = duty_cycle;
    OCR1B = 0;
  }

  /**
   * @brief Sets duty cycle on negative PWM pin
   *
   * @param duty_cycle a new duty cycle value (10 bit width at most)
   */
  inline void set_duty_cycle_on_negative_output_pin(uint16_t duty_cycle) const {
    OCR1A = 0;
    OCR1B = duty_cycle;
  }
};

#endif  // PWM_HPP