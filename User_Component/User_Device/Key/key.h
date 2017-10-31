/*
 * key.h
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »İÆÕ
 */

#ifndef KEY_H_
#define KEY_H_
#include "../Generated_Code/key1.h"
#include "../Generated_Code/key2.h"
#include "../Generated_Code/key3.h"
#include "../Generated_Code/key4.h"
#include "../Generated_Code/key5.h"
#include "../Generated_Code/key6.h"
#include "../Generated_Code/key7.h"
#include "../Generated_Code/key8.h"

typedef enum
{
	Signj=14,Number1=1,Number4,Number7,Number2,
	Number5,Number8,Number3,Number6,Number9,Signx=12,LetterB=17,
	LetterA=10,Number0=13,LetterC=17,LetterD=15,Key_None
}Key_Type_e;


Key_Type_e Keyscan(void);
void Key_Init(void);
uint8_t huidu(void);
#endif /* KEY_H_ */
