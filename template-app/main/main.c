#include "Servos.h"
#include "WiFi.h"
#include "httpRequest.h"
#include "ADC.h"

#define RESOLUTION 0  // Defines the ADC resolution to 9 bits

/**
 * @brief define the left sensor in channel 4 and pin 32
 * 
 */
#define LEFTSENSORCHANNEL 4

/**
 * @brief define the righ sensor in channel 5 and pin 33
 * 
 */
#define RIGHTSENSORCHANNEL 5

/**
 * @brief define the photovoltaic in channel 6 and pin 34
 * 
 */
#define PHOTOVOLTAIC 6

void app_main(void)
{   
    printf("--- ESP 32 LORATION COURSE ---\n");

    checkNVS();
    wifi_init_sta();

    adc1Setup(RESOLUTION, LEFTSENSORCHANNEL);
    adc1Setup(RESOLUTION, RIGHTSENSORCHANNEL);
    adc1Setup(RESOLUTION, PHOTOVOLTAIC);

    servoConfig();

    char str [4];

    while(1)
    {
        printf("Left sensor measure: %u\n", adcRead(LEFTSENSORCHANNEL, NUMBER_OF_SAMPLES));
        printf("Right sensor measure: %u\n", adcRead(RIGHTSENSORCHANNEL, NUMBER_OF_SAMPLES));
        printf("Photovoltaic value: %u\n", adcRead(PHOTOVOLTAIC, NUMBER_OF_SAMPLES));

        rest_get(str);

        if (adcRead(LEFTSENSORCHANNEL, NUMBER_OF_SAMPLES) > adcRead(RIGHTSENSORCHANNEL, NUMBER_OF_SAMPLES))
        {
            ServoSetDuty(102);
            vTaskDelay(3000/ portTICK_RATE_MS);
            printf("Photovoltaic value: %u\n", adcRead(PHOTOVOLTAIC, NUMBER_OF_SAMPLES));

        }

        else if (adcRead(LEFTSENSORCHANNEL, NUMBER_OF_SAMPLES) < adcRead(RIGHTSENSORCHANNEL, NUMBER_OF_SAMPLES))
        {
            ServoSetDuty(204);
            vTaskDelay(3000/ portTICK_RATE_MS);
            printf("Photovoltaic value: %u\n", adcRead(PHOTOVOLTAIC, NUMBER_OF_SAMPLES));
        }
        else
        {
            ServoSetDuty(153);
            vTaskDelay(3000/ portTICK_RATE_MS); 
            printf("Photovoltaic value: %u\n", adcRead(PHOTOVOLTAIC, NUMBER_OF_SAMPLES));
        }

    }

}