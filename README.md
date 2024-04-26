Atmega328p 16 MHz <br>
PCA9685 [datasheet](https://cdn-shop.adafruit.com/datasheets/PCA9685.pdf) <br>
PCA functions needed: <br> pwmInit(uint16_t desired_pwm_frequency), <br> pwmDutyCycle(uin8_t led_channel, uint16_t pulse_width_in_us) <br>
TWI frequency is set in twiInit() <br>
