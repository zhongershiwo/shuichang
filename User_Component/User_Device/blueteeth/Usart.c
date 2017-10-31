/*
 * Usart.c
 *
 *  Created on: 2017Äê9ÔÂ25ÈÕ
 *      Author: »ÝÆÕ
 */
#include "Usart.h"

LDD_TDeviceDataPtr myusart;
uint8_t recbuff[5];
void Usart_Init(void)
{
	myusart = 	USART_Init(NULL);
}

void Usart_Enable(void)
{
	USART_Enable(myusart);
}

void Usart_Disable(void)
{
	USART_Disable(myusart);
}

void Usart_Send1Bit(uint8_t buff[])
{
	USART_SendBlock(myusart, &buff, 1);
}
void Usart_Rec5Bit(uint8_t buff[])
{
USART_ReceiveBlock(myusart,&buff, 5);
}
