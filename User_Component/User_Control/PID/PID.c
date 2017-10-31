/*
 * PID.c
 *
 *  Created on: 2017Äê10ÔÂ31ÈÕ
 *      Author: »İÆÕ
 */

struct
{
 float Kp,Ki,Kd,integral,last_bias,output;
}PID_p;
struct
{
 float Kp,Ki,Kd,integral,last_bias,last_last_bias,output;
}PID_w;


float Servo(float curret, float target )
{
	float bias;
	PID_p.integral = 0;
	PID_p.last_bias = 0;
	bias = target - curret;
	PID_p.integral += PID_p.Ki * bias ;
	PID_p.output = PID_p.Kp * bias + PID_p.integral + PID_p.Kd * ( bias - PID_p.last_bias ) ;
return PID_p.output;
}


/*

float Servo(float curret, float target )
{
	float bias;
	PID_w.integral = 0;
	PID_w.last_bias = 0;
	bias = target - curret;
	PID_w.output += PID_w.Kp * (bias - PID_w.last_bias)+ PID_w.Ki * bias + PID_w.Kd * ( PID_w.last_last_bias + bias - 2 * PID_w.last_bias ) ;
	PID_w.last_last_bias = PID_w.last_bias ;
	PID_w.last_bias = bias ;
    return PID_w.output;
}
*/
