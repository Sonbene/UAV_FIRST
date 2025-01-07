#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "main.h"

#define MOTOR1_MIN_SPEED 1000
#define MOTOR1_MAX_SPEED 2000

#define MOTOR2_MIN_SPEED 1000
#define MOTOR2_MAX_SPEED 2000

#define MOTOR3_MIN_SPEED 1000
#define MOTOR3_MAX_SPEED 2000

#define MOTOR4_MIN_SPEED 1000
#define MOTOR4_MAX_SPEED 2000

void motor_init(TIM_HandleTypeDef *timer);
void UAV_Motor_Speed(uint8_t motor, uint16_t speed);


#endif

