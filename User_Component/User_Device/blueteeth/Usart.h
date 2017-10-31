/*
 * Usart.h
 *
 *  Created on: 2017Äê9ÔÂ25ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef USART_H_
#define USART_H_
#include "../Generated_Code/USART.h"
extern uint8_t recbuff[5];
void Usart_Init(void) ;
void Usart_Enable(void);
void Usart_Disable(void);
void Usart_Send1Bit(uint8_t buff[]);
void Usart_Rec5Bit(uint8_t buff[]);
#endif /* USART_H_ */
