/*
 * Servo.c
 *
 *  Created on: 2017��9��24��
 *      Author: ����
 */
#include "Servo.h"


LDD_TDeviceDataPtr myServo;
int16_t Servo_center=4370;
//4100	4750 //5400

void Servo_Init(void)
{
	myServo = PWMServo_Init(NULL);
}

void Servo_SetVal(int32_t Val)
{
	PWMServo_SetRatio16(myServo,SERVO_MAX - Val);
}

void Servo_Enable(void)
{
PWMServo_Enable(myServo);
}
