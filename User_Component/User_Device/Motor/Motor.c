/*
 * Motor.c
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »ÝÆÕ
 */
#include "Motor.h"

LDD_TDeviceDataPtr myPwm1;
LDD_TDeviceDataPtr myPwm2;
LDD_TDeviceDataPtr myPwm3;
LDD_TDeviceDataPtr myPwm4;

void Motor_Init(void)
{
	myPwm1 = PWM1_Init(NULL);
	myPwm2 = PWM2_Init(NULL);
	myPwm3 = PWM3_Init(NULL);
	myPwm4 = PWM4_Init(NULL);
}

void Motor_Enable(void)
{
	PWM1_Enable(myPwm1);
	PWM2_Enable(myPwm2);
	PWM3_Enable(myPwm3);
	PWM4_Enable(myPwm4);
}

void Motor_SetVal(int32_t Pwm_Left,int32_t Pwm_Right)     //-3000  3000
{
	if(Pwm_Left >= 0){
		if(Pwm_Left>=MOTOR_MAX) Pwm_Left=MOTOR_MAX;
		PWM1_SetRatio16(myPwm1,MOTOR_MAX - Pwm_Left);
		PWM2_SetRatio16(myPwm2,MOTOR_MAX - 0);
	}
	else
	{
		Pwm_Left = -Pwm_Left;
		if(Pwm_Left>=MOTOR_MAX) Pwm_Left=MOTOR_MAX;
		PWM1_SetRatio16(myPwm1,MOTOR_MAX - 0);
		PWM2_SetRatio16(myPwm2,MOTOR_MAX - Pwm_Left);
	}

	if(Pwm_Right >= 0){
		if(Pwm_Right>=MOTOR_MAX) Pwm_Right=MOTOR_MAX;
		PWM3_SetRatio16(myPwm3,MOTOR_MAX - 0);
		PWM4_SetRatio16(myPwm4,MOTOR_MAX - Pwm_Right);
	}
	else
	{
		Pwm_Right = -Pwm_Right;
		if(Pwm_Right>=MOTOR_MAX) Pwm_Right=MOTOR_MAX;
		PWM3_SetRatio16(myPwm3,MOTOR_MAX - Pwm_Right);
		PWM4_SetRatio16(myPwm4,MOTOR_MAX - 0);
	}
}
