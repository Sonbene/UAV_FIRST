#ifndef PID_H
#define PID_H

#include "MPU6050.h"

typedef struct
{
	double kp_x;
	double ki_x;
	double kd_x;
	double setpoint_x;
	double pre_error_x;
	double intergral_x;

	double kp_y;
	double ki_y;
	double kd_y;
	double setpoint_y;
	double pre_error_y;
	double intergral_y;

	double kp_z;
	double ki_z;
	double kd_z;
	double setpoint_z;
	double pre_error_z;
	double intergral_z;
}PID_t;

void PID_Init(MPU6050_t *mpu);
void PID_Calculated(MPU6050_t *mpu, double* PID_x_value, double* PID_y_value, double* PID_z_value);


#endif


