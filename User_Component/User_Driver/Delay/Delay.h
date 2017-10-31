/*
 * Delay.h
 *
 *  Created on: 2017Äê9ÔÂ25ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef DELAY_H_
#define DELAY_H_
#include "../Generated_Code/Delay_ms.h"
#include "../Generated_Code/Delay_us.h"
extern uint16_t ms;
extern uint16_t us;
void Delay_Ms_Init ();
void  Delay_Ms_Enable ();
void  Delay_Ms_Disable ();
void  Delay_Ms(uint16_t Ms);

void Delay_Us_Init ();
void  Delay_Us_Enable ();
void  Delay_Us_Disable ();
void  Delay_Us(uint16_t Us);

void EasyDelay(volatile uint32_t nCount);




#endif /* DELAY_H_ */
