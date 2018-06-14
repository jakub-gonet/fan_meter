#ifndef ADC_HPP
#define ADC_HPP

class Adc {
 public:
  /**
   * @brief Construct a new Adc:: Adc object and configures ADC registers
   *
   */
  Adc();

  /**
   * @brief Checks if ADC conversion is in progress
   *
   * @return true
   * @return false
   */
  bool is_conversion_in_progress();

  /**
   * @brief Starts single conversion from which result can be aquired later
   * @see get_last_conversion
   */
  void start_one_async_conversion();

  /**
   * @brief Get the last conversion result
   *
   * @return uint16_t result from ADC conversion with 8 or 10 bit resolution
   */
  uint16_t get_last_conversion();
};
#endif
