/*
 * oled.h
 *
 *  Created on: 2017��9��24��
 *      Author: ����
 */

#ifndef OLED_H_
#define OLED_H_

#include <../Generated_Code/Oled_D0.h>
#include <../Generated_Code/Oled_D1.h>
#include <../Generated_Code/Oled_DC.h>
#include <../Generated_Code/Oled_Rst.h>


#include <stdint.h>

#define Correction        buxian_left// buxian_left // У��ͼ
#define Correction_Mid    buxian_center  // У������
#define Fill_Line         jiaozheng_left // ����ͼ
#define Line_Watch        jiaozheng_width//sum_left//jiaozheng_width   // ���ж�

#define Point_0           10
#define Point_1           20

#define Cross             64
#define Row               128
#define Display_Interval  2
#define Dot_Size 3

/******************************************************/
/*--------------------*OLEDд����*--------------------*/
void OLED_Write_Data(unsigned char Data);
/*--------------------*OLEDд����*--------------------*/
void OLED_Write_Command(unsigned char Cmd);
/******************************************************/


/*--------------------*��ʼ��*--------------------*/
extern void OLED_Init(void);

extern void OLED_Clear(void);


/*				��ʾ����				*/
extern void Dis_Int(unsigned char Position,signed int Number);
extern void Dis_Float(unsigned char Position,float Number);
extern void Dis_String(unsigned char Position,signed char String[]);
extern void Dis_Head(signed char String[]);

/*				��ʾ��ֵ				*/
extern void OLED_Write_Int(unsigned char x,unsigned char y,signed int Number);
extern void OLED_Write_Float(unsigned char x,unsigned char y,float Number);
extern void OLED_Write_String_7(unsigned char y,unsigned char x,signed char String[]);
extern void OLED_Write_String(unsigned char x,unsigned char y,signed char String[]);
extern void OLED_Write_Char(unsigned char x,unsigned char y,signed char Asc);
//������ǵ���OLED_Write_String()����//
extern void OLED_Write_Draw(unsigned char x,unsigned char y,signed char Asc) ;
//��ֵ��ȡ0~25������Draw[]����,AscӦ�����޷��ŵģ��з����ƺ�������

extern void Paint_Fresh(float New_Data,float Paint_Ave,float Paint_Margin);
/*Margin:��Ե*/   /*Ave*/
extern void List_Move(signed char New_Data);
extern void List_Paint(void);//Oled�ײ�����һ����
extern void Paint_List(float New_Data,float Paint_Ave,float Paint_Margin);

void Draw_BMP(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint8_t bmp[]);
//-----------------------ԭʼͼת��-----------------------//
void Image_Transform(void);
//------------------------�߽�ת��------------------------//
void Border_Transform(signed int *Border);
//------------------------�������------------------------//
void Add_Line_Transform(signed int *Add_Line);
//----------------------ֻ��һ��ֱ��----------------------//
void Line_Transform(signed int *Dis_Line);
//----------------------����ƽ������----------------------//
void Add_Cross(unsigned char Temp_Add_Cross);
//------------------------ͼ����ʾ------------------------//
void Image_Display(void);

extern void OLED_PrintImage(uint16_t *Image_data, uint8_t RowNum, uint8_t ColumnNum);
//------------------------��ʾģʽ------------------------//
//void Dis_Mode(signed char Choose_Mode);
//-----------------------��ʾ������-----------------------//
void Dis_Control(float New_Data,float Err_Ave,float Err_Margin);

#endif /* OLED_H_ */
