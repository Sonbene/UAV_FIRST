#include "motorControl.h"

TIM_HandleTypeDef *tim1;

void UAV_Motor_Init(TIM_HandleTypeDef *timer)
{
	tim1 = timer;
}

void UAV_Motor_Speed(uint8_t motor, uint16_t speed)
{
	if(motor == 1)
	{
		if(speed < MOTOR1_MIN_SPEED)
		{
			speed = MOTOR1_MIN_SPEED;
		}
		else if(speed > MOTOR1_MAX_SPEED)
		{
			speed = MOTOR1_MAX_SPEED;
		}
		__HAL_TIM_SET_COMPARE(tim1, TIM_CHANNEL_1, speed);
	}
	else if(motor == 2)
	{
		if(speed < MOTOR2_MIN_SPEED)
		{
			speed = MOTOR2_MIN_SPEED;
		}
		else if(speed > MOTOR2_MAX_SPEED)
		{
			speed = MOTOR2_MAX_SPEED;
		}
		__HAL_TIM_SET_COMPARE(tim1, TIM_CHANNEL_2, speed);
	}
	else if(motor == 3)
	{
		if(speed < MOTOR3_MIN_SPEED)
		{
			speed = MOTOR3_MIN_SPEED;
		}
		else if(speed > MOTOR3_MAX_SPEED)
		{
			speed = MOTOR3_MAX_SPEED;
		}
		__HAL_TIM_SET_COMPARE(tim1, TIM_CHANNEL_3, speed);
	}
	else if(motor == 4)
	{
		if(speed < MOTOR4_MIN_SPEED)
		{
			speed = MOTOR4_MIN_SPEED;
		}
		else if(speed > MOTOR4_MAX_SPEED)
		{
			speed = MOTOR4_MAX_SPEED;
		}
		__HAL_TIM_SET_COMPARE(tim1, TIM_CHANNEL_4, speed);
	}
}

void UAV_Motor_calculate(MPU6050_t *mpu, motor_speed_t *speed, double PID_x, double PID_y, double PID_z)
{
	PID_Calculated(mpu, &PID_x, &PID_y, &PID_z);

	//speed.motor1_speed =
}


