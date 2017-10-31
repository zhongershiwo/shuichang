/*
 * key.c
 *
 *  Created on: 2017Äê9ÔÂ24ÈÕ
 *      Author: »ÝÆÕ
 */

#include "key.h"

LDD_TDeviceDataPtr mykeyrow1;
LDD_TDeviceDataPtr mykeyrow2;
LDD_TDeviceDataPtr mykeyrow3;
LDD_TDeviceDataPtr mykeyrow4;
LDD_TDeviceDataPtr mykeycross1;
LDD_TDeviceDataPtr mykeycross2;
LDD_TDeviceDataPtr mykeycross3;
LDD_TDeviceDataPtr mykeycross4;

#define Row1_High key8_SetVal(mykeyrow1)
#define Row2_High key7_SetVal(mykeyrow2)
#define Row3_High key6_SetVal(mykeyrow3)
#define Row4_High key5_SetVal(mykeyrow4)
#define Row1_Low  key8_ClrVal(mykeyrow1)
#define Row2_Low  key7_ClrVal(mykeyrow2)
#define Row3_Low  key6_ClrVal(mykeyrow3)
#define Row4_Low  key5_ClrVal(mykeyrow4)

#define Cross1    key4_GetVal(mykeycross1)
#define Cross2    key3_GetVal(mykeycross2)
#define Cross3    key2_GetVal(mykeycross3)
#define Cross4    key1_GetVal(mykeycross4)

#define Cross1_High key4_SetVal(mykeycross1)
#define Cross2_High key3_SetVal(mykeycross2)
#define Cross3_High key2_SetVal(mykeycross3)
#define Cross4_High key1_SetVal(mykeycross4)

#define Cross1_out key4_SetDir(mykeycross1,1)
#define Cross2_out key3_SetDir(mykeycross2,1)
#define Cross3_out key2_SetDir(mykeycross3,1)
#define Cross4_out key1_SetDir(mykeycross4,1)

#define Cross1_in key4_SetDir(mykeycross1,0)
#define Cross2_in key3_SetDir(mykeycross2,0)
#define Cross3_in key2_SetDir(mykeycross3,0)
#define Cross4_in key1_SetDir(mykeycross4,0)


Key_Type_e press_temp = Key_None;

void Key_Init(void)
{
	mykeyrow1 = key8_Init(NULL);
	mykeyrow2 = key7_Init(NULL);
	mykeyrow3 = key6_Init(NULL);
	mykeyrow4 = key5_Init(NULL);
	mykeycross1 = key4_Init(NULL);
	mykeycross2 = key3_Init(NULL);
	mykeycross3 = key2_Init(NULL);
	mykeycross4 = key1_Init(NULL);
}
uint8_t huidu(void)
{

	return (key7_GetVal(mykeyrow2)*8+key6_GetVal(mykeyrow3)*4 +  key5_GetVal(mykeyrow4) * 2 + key5_GetVal(mykeyrow4));

}



void Delaytime(void)
{
  int i,j;
  for(i=0;i<100;i++)
  {
    for(j=0;j<200;j++)
    {asm("nop");}
  }
}

void delay0(int n)
{
  int i;
  for(;n>=0;n--)
  {
    for(i=0;i<10;i++)
    {
      ;
    }
  }
}

/*
 * ¼üÅÌ
 * 1  2  3  12
 * 4  5  6  13
 * 7  8  9  14
 * 10 0  11 15
 */

Key_Type_e Keyscan(void)
{
	press_temp = Key_None;

	Cross1_in;
	Cross2_in;
	Cross3_in;
	Cross4_in;

	Row1_Low;
	Row2_High;
	Row3_High;
	Row4_High;

	if (Cross1 == 0) {press_temp = Number1;Cross1_out;Cross1_High;}
	if (Cross2 == 0) {press_temp = Number4;Cross2_out;Cross2_High;}
	if (Cross3 == 0) {press_temp = Number7;Cross3_out;Cross3_High;}
	if (Cross4 == 0) {press_temp = Signx;  Cross4_out;Cross4_High;}

	Row1_High;
	Row2_Low;
	Row3_High;
	Row4_High;

	if (Cross1 == 0) {press_temp = Number2;Cross1_out;Cross1_High;}
	if (Cross2 == 0) {press_temp = Number5;Cross2_out;Cross2_High;}
	if (Cross3 == 0) {press_temp = Number8;Cross3_out;Cross3_High;}
	if (Cross4 == 0) {press_temp = Number0;Cross4_out;Cross4_High;}

	Row1_High;
	Row2_High;
	Row3_Low;
	Row4_High;

	if (Cross1 == 0) {press_temp = Number3;Cross1_out;Cross1_High;}
	if (Cross2 == 0) {press_temp = Number6;Cross2_out;Cross2_High;}
	if (Cross3 == 0) {press_temp = Number9;Cross3_out;Cross3_High;}
	if (Cross4 == 0) {press_temp = Signj;  Cross4_out;Cross4_High;}

	Row1_High;
	Row2_High;
	Row3_High;
	Row4_Low;

	if (Cross1 == 0) {press_temp = LetterA;Cross1_out;Cross1_High;}
	if (Cross2 == 0) {press_temp = LetterB;Cross2_out;Cross2_High;}
	if (Cross3 == 0) {press_temp = LetterC;Cross3_out;Cross3_High;}
	if (Cross4 == 0) {press_temp = LetterD;Cross4_out;Cross4_High;}

	Row1_High;
	Row2_High;
	Row3_High;
	Row4_High;

    return(press_temp);
}
