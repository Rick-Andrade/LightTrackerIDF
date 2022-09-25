#ifndef SERVOS_H
#define SERVOS_H

#include "driver/ledc.h"


#define SERVO_HORI 26
/**
 * @brief Configure the server channel
 * 
 */
void servoConfig (void);

/**
 * @brief Set the Servo Zero Position object
 * 
 */
void setServoZeroPosition(void);

/**
 * @brief Set servo position
 * 
 * @param duty Position desire
 */
void ServoSetDuty(uint16_t duty);

#endif