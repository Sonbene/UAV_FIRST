#include "PID.h"

PID_t PID_para;

void PID_Init(MPU6050_t *mpu)
{
	PID_para.setpoint_x = mpu->Ax;
	PID_para.setpoint_y = mpu->Ay;
	PID_para.setpoint_z = mpu->Az;

	PID_para.kp_x = 5.0;
	PID_para.ki_x = 0.0;
	PID_para.kd_x = 0.0;

	PID_para.kp_y = 5.0;
	PID_para.ki_y = 0.0;
	PID_para.kd_y = 0.0;

	PID_para.kp_z = 5.0;
	PID_para.ki_z = 0.0;
	PID_para.kd_z = 0.0;
}

void PID_Calculated(MPU6050_t *mpu, double* PID_x_value, double* PID_y_value, double* PID_z_value)
{
	 double error_x = PID_para.setpoint_x - mpu->Ax;
	 PID_para.intergral_x += error_x;
	 double derivative_x = error_x -PID_para.pre_error_x;
	 PID_para.pre_error_x = error_x;
	 *PID_x_value = PID_para.kp_x * error_x + PID_para.ki_x * PID_para.intergral_x + PID_para.kd_x * derivative_x;

	 double error_y = PID_para.setpoint_y - mpu->Ay;
	 PID_para.intergral_y += error_y;
	 double derivative_y = error_y -PID_para.pre_error_y;
	 PID_para.pre_error_y = error_y;
	 *PID_y_value = PID_para.kp_y * error_y + PID_para.ki_y * PID_para.intergral_y + PID_para.kd_y * derivative_y;

	 double error_z = PID_para.setpoint_z - mpu->Az;
	 PID_para.intergral_z += error_z;
	 double derivative_z = error_z -PID_para.pre_error_z;
	 PID_para.pre_error_z = error_z;
	 *PID_z_value = PID_para.kp_z * error_z + PID_para.ki_z * PID_para.intergral_z + PID_para.kd_z * derivative_z;
}



