#ifndef ADC_H
#define ADC_H

#include "driver/gpio.h"
#include "driver/adc.h"
#include "esp_log.h"
#include "esp_err.h"
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#define NUMBER_OF_SAMPLES 10


/**
 * @brief Configure the ADC
 * 
 * @param adcWidthBit Channel resolution
 * @param adcChanel Channel to read
 * @return esp_err_t 
 */
esp_err_t adc1Setup(adc_bits_width_t adcWidthBit, adc_channel_t adcChanel);

/**
 * @brief Returns the ADC lectures
 * 
 * @param adcChanel Channel to read
 * @param numOfSamples How many samples are necessary?
 * @return uint16_t 
 */
int16_t adcRead(adc_channel_t adcChanel, uint8_t numOfSamples);

/**
 * @brief Converts the ADC lecture to a char array
 * 
 * @param adcChanel Target channel 
 * @param numOfSamples Channel Resolution
 * @param str char array that will be change
 */
void adcReadAsString (adc_channel_t adcChanel, uint8_t numOfSamples, char * str);


#endif