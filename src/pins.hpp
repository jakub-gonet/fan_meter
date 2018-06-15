#ifndef PINS_HPP
#define PINS_HPP

#include <avr/io.h>
#include "pins_defines.hpp"

class Pins {
 public:
  /**
   * @brief Construct a new Pins and configures uC pins
   *
   */
  Pins();

  /**
   * @brief Check if dynamic mode pin is enabled (connected to ground)
   *
   * @return bool
   */
  inline bool is_dynamic_range_mode_enabled() const {
    return ~DYNAMIC_MODE_PIN_REG & (1 << DYNAMIC_MODE_PIN);
  }
};

#endif  // PINS_HPP