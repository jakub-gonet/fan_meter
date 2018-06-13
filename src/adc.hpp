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
   * @brief Starts single conversion from which result can be aquired later
   * @see get_last_conversion
   */
  void make_one_async_conversion();

  /**
   * @brief Get the last conversion result or -1 if none available
   *
   * @return uint16_t result from ADC conversion with 8 or 10 bit resolution
   */
  uint16_t get_last_conversion();
};
#endif
