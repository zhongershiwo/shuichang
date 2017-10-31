/*
 * Servo.h
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef SERVO_H_
#define SERVO_H_
#include <../Generated_Code/PWMServo.h>
#define SERVO_MAX	65535
//4500	5050 //5600
#define Servo_left 	 4700//4800

extern int16_t Servo_center;

#define Servo_right  5500
//3800


void Servo_Init(void);
void Servo_SetVal(int32_t Val);
void Servo_Enable(void);
#endif /* SERVO_H_ */
