#ifndef ADC_HPP
#define ADC_HPP

class Adc {
 public:
  uint16_t lowest_measured_value;
  uint8_t highest_measured_value;

  /**
   * @brief Construct a new Adc:: Adc object and configures ADC registers
   *
   */
  Adc();

  /**
   * @brief Updates lowest and highest measured values
   *
   * @param current_value
   */
  void update_measured_values(uint16_t current_value);

  /**
   * @brief Get the last conversion result
   *
   * @return uint16_t result from ADC conversion with 8 or 10 bit resolution
   */
  inline uint16_t get_last_conversion() { return ADC; }
};
#endif
