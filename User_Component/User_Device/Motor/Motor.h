/*
 * Motor.h
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "../Generated_Code/PWM1.h"
#include "../Generated_Code/PWM2.h"
#include "../Generated_Code/PWM3.h"
#include "../Generated_Code/PWM4.h"

#define MOTOR_MAX	65535

void Motor_Init(void);
void Motor_Enable(void);
void Motor_SetVal(int32_t Pwm_Left,int32_t Pwm_Right);


#endif /* MOTOR_H_ */
