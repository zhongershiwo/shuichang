/*
 * UI.h
 *
 *  Created on: 2017年9月26日
 *      Author: 惠普
 */

#ifndef UI_H_
#define UI_H_
#include "../User_Component/User_Device/Key/key.h"
#include "../User_Component/User_Device/oled/oled.h"
#include "../User_Component/User_Driver/Flash/Storage.h"


/******************************************
 ********UI命令与输入设备信号之间的对应关系**********
 ******************************************/
typedef enum{
	UI_None			= Key_None,
	UI_Value_Plus 		= Number3,
	UI_Value_Minus 		= Number1,
	UI_Item_Plus		= Number2,
	UI_Item_Minus		= Number8,
	UI_Page_Plus		= Number6,
	UI_Page_Minus		= Number4,
	UI_Accuracy_Plus	= Number9,
	UI_Accuracy_Minus	= Number7,
	UI_Save			= Signj,
	UI_Read		    = Signx,
	UI_Start        = Number5
}UI_CMD_e,*UI_CMD_Ptr_e;

/*************************
 **变量的参数，包括变量的类型和权限**
 *************************/
typedef struct {
	enum{
		Double,
		Float,
		Int32_t,
		Uint32_t,
		Int16_t,
		Uint16_t,
		Int8_t,
		Uint8_t,
		Function,	//表示显示图像的函数
	}Type;

	enum{
		RO,			//只读
		RW,			//读写
	}Authority;
}Variable_Attribute;

/********************************************
 ************一个Item所必备的元素*****************
 ********************************************/
typedef struct{
	signed char*		Name;				//Item名，字符串类型
	void*				DataPtr;			//这个Item指向的数据地址
	Variable_Attribute	Data_Attribute;		//这个Item对应数据的参数
}Item_Lib,*Item_LibPtr;

/********************************************
 ************一个Page所必备的元素*****************
 ********************************************/
typedef struct{
	signed char*		Name;				//Page名，字符串类型
	Item_LibPtr			ItemPtr;			//这个Page的第一个Item的首地址
	uint16_t			Item_Max;			//这个Page对应的最大的Item个数
}Page_Lib,*Page_LibPtr;

/********************************************
 ***************保存当前的活动状态*****************
 ********************************************/
typedef struct{
	float 				Accuracy;			//当前数据调整精度
	bool				ShowGraphic;		        //标记是否有图像显示
	int16_t				PageNum;			//当前的Page，类型：整形数
	Page_LibPtr			PagePtr;			//当前Page指向的Page信息首地址，类型：指针
	int16_t				ItemNum;			//当前的Item，类型：整形数
	Item_LibPtr			ItemPtr;			//当前Item指向的Item信息首地址，类型：指针
}Active_Type,*Active_TypePtr;

void UI_Init(void);
void UI_Main(void);
void UI_GetCmd(void);
void Read_Data(void);
void Save_Data(void);

extern UI_CMD_e UI_CMD;

#endif /* UI_H_ */
