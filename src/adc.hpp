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
   * @brief Get the last conversion result
   *
   * @return uint16_t result from ADC conversion with 8 or 10 bit resolution
   */
  uint16_t get_last_conversion() const { return ADC; };
};
#endif
