/*
 * oled.h
 *
 *  Created on: 2017年9月24日
 *      Author: 惠普
 */

#ifndef OLED_H_
#define OLED_H_

#include <../Generated_Code/Oled_D0.h>
#include <../Generated_Code/Oled_D1.h>
#include <../Generated_Code/Oled_DC.h>
#include <../Generated_Code/Oled_Rst.h>


#include <stdint.h>

#define Correction        buxian_left// buxian_left // 校正图
#define Correction_Mid    buxian_center  // 校正中线
#define Fill_Line         jiaozheng_left // 补线图
#define Line_Watch        jiaozheng_width//sum_left//jiaozheng_width   // 线判断

#define Point_0           10
#define Point_1           20

#define Cross             64
#define Row               128
#define Display_Interval  2
#define Dot_Size 3

/******************************************************/
/*--------------------*OLED写数据*--------------------*/
void OLED_Write_Data(unsigned char Data);
/*--------------------*OLED写命令*--------------------*/
void OLED_Write_Command(unsigned char Cmd);
/******************************************************/


/*--------------------*初始化*--------------------*/
extern void OLED_Init(void);

extern void OLED_Clear(void);


/*				显示变量				*/
extern void Dis_Int(unsigned char Position,signed int Number);
extern void Dis_Float(unsigned char Position,float Number);
extern void Dis_String(unsigned char Position,signed char String[]);
extern void Dis_Head(signed char String[]);

/*				显示数值				*/
extern void OLED_Write_Int(unsigned char x,unsigned char y,signed int Number);
extern void OLED_Write_Float(unsigned char x,unsigned char y,float Number);
extern void OLED_Write_String_7(unsigned char y,unsigned char x,signed char String[]);
extern void OLED_Write_String(unsigned char x,unsigned char y,signed char String[]);
extern void OLED_Write_Char(unsigned char x,unsigned char y,signed char Asc);
//这个还是调用OLED_Write_String()函数//
extern void OLED_Write_Draw(unsigned char x,unsigned char y,signed char Asc) ;
//数值可取0~25，根据Draw[]数组,Asc应该是无符号的，有符号似乎会乱码

extern void Paint_Fresh(float New_Data,float Paint_Ave,float Paint_Margin);
/*Margin:边缘*/   /*Ave*/
extern void List_Move(signed char New_Data);
extern void List_Paint(void);//Oled底部出现一条线
extern void Paint_List(float New_Data,float Paint_Ave,float Paint_Margin);

void Draw_BMP(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint8_t bmp[]);
//-----------------------原始图转换-----------------------//
void Image_Transform(void);
//------------------------边界转换------------------------//
void Border_Transform(signed int *Border);
//------------------------添加中线------------------------//
void Add_Line_Transform(signed int *Add_Line);
//----------------------只画一条直线----------------------//
void Line_Transform(signed int *Dis_Line);
//----------------------画出平行虚线----------------------//
void Add_Cross(unsigned char Temp_Add_Cross);
//------------------------图像显示------------------------//
void Image_Display(void);

extern void OLED_PrintImage(uint16_t *Image_data, uint8_t RowNum, uint8_t ColumnNum);
//------------------------显示模式------------------------//
//void Dis_Mode(signed char Choose_Mode);
//-----------------------显示控制量-----------------------//
void Dis_Control(float New_Data,float Err_Ave,float Err_Margin);

#endif /* OLED_H_ */
