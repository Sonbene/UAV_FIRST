#ifndef MOTORCONTROL_H
#define MOTORCONTROL_H

#include "main.h"
#include "PID.h"
#include "MPU6050.h"

#define MOTOR1_MIN_SPEED 1000
#define MOTOR1_MAX_SPEED 2000

#define MOTOR2_MIN_SPEED 1000
#define MOTOR2_MAX_SPEED 2000

#define MOTOR3_MIN_SPEED 1000
#define MOTOR3_MAX_SPEED 2000

#define MOTOR4_MIN_SPEED 1000
#define MOTOR4_MAX_SPEED 2000

typedef struct
{
	uint16_t motor1_speed;
	uint16_t motor2_speed;
	uint16_t motor3_speed;
	uint16_t motor4_speed;
}motor_speed_t;

void UAV_Motor_Init(TIM_HandleTypeDef *timer);
void UAV_Motor_Speed(uint8_t motor, uint16_t speed);
void UAV_Motor_calculate(MPU6050_t *mpu, motor_speed_t *speed, double PID_x, double PID_y, double PID_z);

#endif

