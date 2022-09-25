#include "ADC.h"

esp_err_t adc1Setup(adc_bits_width_t adcWidthBit, adc_channel_t adcChanel)
{
    esp_err_t err;
    err = adc1_config_width(adcWidthBit);
    if (err == ESP_OK)
    {
        err = adc1_config_channel_atten(adcChanel, ADC_ATTEN_0db);
    }
    return err;
}

int16_t adcRead(adc_channel_t adcChanel, uint8_t numOfSamples)
{
    if (numOfSamples == 0)
    {
        printf("Num of samples = 0");
        return ESP_FAIL;
    }

    int16_t adc_reading = 0;

    for (uint8_t i = 0; i < numOfSamples; i++)
    {
        adc_reading += adc1_get_raw(adcChanel);
    }

    adc_reading = adc_reading / numOfSamples;

    //printf("%u \n", adc_reading);
    return adc_reading;
}

void adcReadAsString (adc_channel_t adcChanel, uint8_t numOfSamples, char * str)
{
    int16_t aux = adcRead(adcChanel, numOfSamples);

    /*int8_t * buffer;
    buffer[0] = aux / 100;
    buffer[1] = aux % 100;*/

    sprintf(str, "%d", aux);
    /*printf("buffer [0]: %d\n", buffer[0]);
    printf("buffer [1]: %d\n", buffer[1]);*/

    //sprintf(buffer, "%u", adcRead(adcChanel, numOfSamples));
    
}