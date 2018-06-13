#ifndef PWM_HPP
#define PWM_HPP

#include <avr/io.h>

class Pwm {
 public:
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
  void set_duty_cycle_on_positive_output_pin(uint16_t duty_cycle);

  /**
   * @brief Sets duty cycle on negative PWM pin
   *
   * @param duty_cycle a new duty cycle value (10 bit width at most)
   */
  void set_duty_cycle_on_negative_output_pin(uint16_t duty_cycle);
};

#endif  // PWM_HPP