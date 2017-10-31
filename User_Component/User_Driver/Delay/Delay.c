/*
 * Delay.c
 *
 *  Created on: 2017Äê9ÔÂ25ÈÕ
 *      Author: »ÝÆÕ
 */
#include "Delay.h"

LDD_TDeviceDataPtr myDelayus ;
LDD_TDeviceDataPtr myDelayms ;
uint16_t ms=0;
uint16_t us=0;


void  Delay_Ms_Init ()
{
	myDelayms = Delay_ms_Init(NULL);
}

void  Delay_Ms_Enable ()
{
	 Delay_ms_Enable(myDelayms);
}

void  Delay_Ms_Disable ()
{
	Delay_ms_Disable(myDelayms);
}

void  Delay_Ms(uint16_t Ms)
{
	ms=65535-Ms;
	Delay_Ms_Enable();
	while(ms>=(65535-Ms));
	ms=0;
	Delay_Ms_Disable ();
}

void  Delay_Us_Init ()
{
	myDelayus = Delay_us_Init(NULL);
}

void  Delay_Us_Enable ()
{
	 Delay_us_Enable(myDelayms);
}

void  Delay_Us_Disable ()
{
	Delay_us_Disable(myDelayus);
}

void  Delay_Us(uint16_t Us)
{
	us=Us;
	Delay_Us_Enable();
	while(us);

}
void EasyDelay(volatile uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}
