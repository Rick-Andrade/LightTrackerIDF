#include "Servos.h"

ledc_channel_config_t ledc_channel1 = {
    .channel = LEDC_CHANNEL_1,
    .duty = 0,
    .gpio_num = SERVO_HORI,
    .speed_mode = LEDC_HIGH_SPEED_MODE,
    .hpoint = 0,
    .timer_sel = LEDC_TIMER_1,
    };

/**
 * @brief Make the channel configurations
 * 
 */
void servoConfig (void)
{
    ledc_timer_config_t ledc_timer = {
        .duty_resolution = LEDC_TIMER_11_BIT,
        .freq_hz = 50,
        .timer_num = LEDC_TIMER_1,
        .clk_cfg = LEDC_AUTO_CLK,
    };

    ledc_timer_config(&ledc_timer);
    ledc_channel_config(&ledc_channel1);
}

/**
 * @brief Set the Servo Zero Position object
 * 
 */
void setServoZeroPosition(void)
{
    printf("Setting servo on zero position\n");
    ServoSetDuty(153);
}

/**
 * @brief 
 * 
 * @param duty duty cycle (or pulse width) to put the servo motor in a desire position
 */
void ServoSetDuty(uint16_t duty)
{
    ledc_set_duty(ledc_channel1.speed_mode, ledc_channel1.channel, duty);
    ledc_update_duty(ledc_channel1.speed_mode, ledc_channel1.channel);
    printf("Incrementing servo...\n");
}