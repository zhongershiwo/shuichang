/*
 * UI.c
 *
 *  Created on: 2017年9月26日
 *      Author: 惠普
 */

#include "UI.h"

#define Page0_Item_Max 	(sizeof(Page0_Item)/sizeof(Page0_Item[0])-1)
#define Page1_Item_Max 	(sizeof(Page1_Item)/sizeof(Page1_Item[0])-1)

static float direction_P,direction_I,direction_D;
Item_Lib const Page0_Item[] =
{
	"Dir.P",&direction_P,Float,RW,
	"Dir.I",&direction_I,Float,RW,
	"Dir.D",&direction_D,Float,RW,
};
/*
Item_Lib const Page1_Item[] =
{
	"Dir.F",&offsetVal,Float,RW,
	"Dir.L",&pwm_left,Float,RW,
	"Dir.R",&pwm_right,Float,RW,
};

*/
Page_Lib const Page[] =
{
	{"Para", (Item_LibPtr)Page0_Item, Page0_Item_Max},
	//{"Speed", (Item_LibPtr)Page1_Item, Page1_Item_Max},
};

UI_CMD_e UI_CMD;

Key_Type_e Key_Detected;

Active_Type Active;

uint16_t const Page_MAX = (sizeof(Page) / sizeof(Page[0]) - 1);

void UI_Init(void) {
	//Key_Init();
	OLED_Init();

	Storage_Init();

	Active.ShowGraphic = FALSE;
	Active.Accuracy = 100;
	Active.PageNum = 0;
	Active.ItemNum = 0;
	Active.PagePtr = (Page_LibPtr) Page + Active.PageNum;
	Active.ItemPtr = (Active.PagePtr->ItemPtr + Active.ItemNum);
	Key_Detected = Key_None;
	UI_CMD = UI_None;
}

uint32_t Save_Addr;
int16_t Page_Num,Item_Num;

void Save_Data(void)
{
	Storage_Erase(FLASH_USER_AREA0_User_ADDRESS,FLASH_USER_AREA0_User_SIZE);
	Save_Addr = FLASH_USER_AREA0_User_ADDRESS;
	for(Page_Num = 0;Page_Num <= Page_MAX;Page_Num++)
	{
		for(Item_Num = 0;Item_Num <= Page[Page_Num].Item_Max;Item_Num++)
		{
			if(Save_Addr > FLASH_USER_AREA0_User_ADDRESS+FLASH_USER_AREA0_User_SIZE){return;}
			Storage_Write(Save_Addr,(Page[Page_Num].ItemPtr+Item_Num)->DataPtr,4);
			Save_Addr+=4;
		}
	}
}

uint32_t Read_Addr;

void Read_Data(void)
{
	int16_t Page_Num,Item_Num;
	Read_Addr = FLASH_USER_AREA0_User_ADDRESS;
	for(Page_Num = 0;Page_Num <= Page_MAX;Page_Num++)
	{
		for(Item_Num = 0;Item_Num <= Page[Page_Num].Item_Max;Item_Num++)
		{
			if(Read_Addr > FLASH_USER_AREA0_User_ADDRESS+FLASH_USER_AREA0_User_SIZE){return;}
			Storage_Read(Read_Addr,(Page[Page_Num].ItemPtr+Item_Num)->DataPtr,4);
			Read_Addr+=4;
		}
	}
}

void Page_Plus(void) {

	Active.ShowGraphic = FALSE;
	Active.PageNum++;
	if (Active.PageNum > Page_MAX)
		Active.PageNum = 0;
	Active.PagePtr = (Page_LibPtr) Page + Active.PageNum;
	Active.ItemNum = 0;
	Active.ItemPtr = Active.PagePtr->ItemPtr + Active.ItemNum;
}

void Page_Minus(void) {

	Active.ShowGraphic = FALSE;
	Active.PageNum--;
	if (Active.PageNum < 0)
		Active.PageNum = Page_MAX;
	Active.PagePtr = (Page_LibPtr) Page + Active.PageNum;
	Active.ItemNum = 0;
	Active.ItemPtr = Active.PagePtr->ItemPtr + Active.ItemNum;
}

void Item_Plus(void) {

	Active.ShowGraphic = FALSE;
	Active.ItemNum++;
	if (Active.ItemNum > Active.PagePtr->Item_Max)
		Active.ItemNum = 0;
	Active.ItemPtr = Active.PagePtr->ItemPtr + Active.ItemNum;
}

void Item_Minus(void) {

	Active.ShowGraphic = FALSE;
	Active.ItemNum--;
	if (Active.ItemNum < 0)
		Active.ItemNum = Active.PagePtr->Item_Max;
	Active.ItemPtr = Active.PagePtr->ItemPtr + Active.ItemNum;
}

void Accuracy_Plus(void) {

	Active.Accuracy *= 10;
	if (Active.Accuracy > 1000)
		Active.Accuracy = 1000;
}

void Accuracy_Minus(void) {

	Active.Accuracy /= 10;
	if (Active.Accuracy < 0.001)
		Active.Accuracy = 0.001;
}

void Data_Plus(void) {

	switch (Active.ItemPtr->Data_Attribute.Type) {
	case Double:
		*(double*) Active.ItemPtr->DataPtr += (double) Active.Accuracy;
		break;
	case Float:
		*(float*) Active.ItemPtr->DataPtr += (float) Active.Accuracy;
		break;
	case Int32_t:
		*(int32_t*) Active.ItemPtr->DataPtr += (int32_t) Active.Accuracy;
		break;
	case Uint32_t:
		*(uint32_t*) Active.ItemPtr->DataPtr += (uint32_t) Active.Accuracy;
		break;
	case Int16_t:
		*(int16_t*) Active.ItemPtr->DataPtr += (int16_t) Active.Accuracy;
		break;
	case Uint16_t:
		*(uint16_t*) Active.ItemPtr->DataPtr += (uint16_t) Active.Accuracy;
		break;
	case Int8_t:
		*(int8_t*) Active.ItemPtr->DataPtr += (int8_t) Active.Accuracy;
		break;
	case Uint8_t:
		*(uint8_t*) Active.ItemPtr->DataPtr += (uint8_t) Active.Accuracy;
		break;
	case Function:
		Active.ShowGraphic = TRUE;
		break;
	default:
		break;
	}
}

void Data_Minus(void) {

	switch (Active.ItemPtr->Data_Attribute.Type) {
	case Double:
		*(double*) Active.ItemPtr->DataPtr -= (double) Active.Accuracy;
		break;
	case Float:
		*(float*) Active.ItemPtr->DataPtr -= (float) Active.Accuracy;
		break;
	case Int32_t:
		*(int32_t*) Active.ItemPtr->DataPtr -= (int32_t) Active.Accuracy;
		break;
	case Uint32_t:
		*(uint32_t*) Active.ItemPtr->DataPtr -= (uint32_t) Active.Accuracy;
		break;
	case Int16_t:
		*(int16_t*) Active.ItemPtr->DataPtr -= (int16_t) Active.Accuracy;
		break;
	case Uint16_t:
		*(uint16_t*) Active.ItemPtr->DataPtr -= (uint16_t) Active.Accuracy;
		break;
	case Int8_t:
		*(int8_t*) Active.ItemPtr->DataPtr -= (int8_t) Active.Accuracy;
		break;
	case Uint8_t:
		*(uint8_t*) Active.ItemPtr->DataPtr -= (uint8_t) Active.Accuracy;
		break;
	case Function:
		Active.ShowGraphic = FALSE;
		break;
	default:
		break;
	}
}

void UI_Process(void) {

	switch (UI_CMD) {
	case UI_Value_Plus:
		Data_Plus();
//		Save_Data();
		break;
	case UI_Value_Minus:
		Data_Minus();
//		Save_Data();
		break;
	case UI_Page_Plus:
		Page_Plus();
		break;
	case UI_Page_Minus:
		Page_Minus();
		break;
	case UI_Item_Plus:
		Item_Plus();
		break;
	case UI_Item_Minus:
		Item_Minus();
		break;
	case UI_Accuracy_Plus:
		Accuracy_Plus();
		break;
	case UI_Accuracy_Minus:
		Accuracy_Minus();
		break;
	default:
		break;
	}
}

void UI_ShowData(uint8_t y, Item_LibPtr ItemPtr) {

	OLED_Write_String(y, 8, ItemPtr->Name);
	switch (ItemPtr->Data_Attribute.Type) {
	case Double:
		Dis_Float(y, (float) *(double*) ItemPtr->DataPtr);
		break;
	case Float:
		Dis_Float(y, (float) *(float*) ItemPtr->DataPtr);
		break;
	case Int32_t:
		Dis_Int(y, (int32_t) *(int32_t*) ItemPtr->DataPtr);
		break;
	case Uint32_t:
		Dis_Int(y, (int32_t) *(uint32_t*) ItemPtr->DataPtr);
		break;
	case Int16_t:
		Dis_Int(y, (int32_t) *(int16_t*) ItemPtr->DataPtr);
		break;
	case Uint16_t:
		Dis_Int(y, (int32_t) *(uint16_t*) ItemPtr->DataPtr);
		break;
	case Int8_t:
		Dis_Int(y, (int32_t) *(int8_t*) ItemPtr->DataPtr);
		break;
	case Uint8_t:
		Dis_Int(y, (int32_t) *(uint8_t*) ItemPtr->DataPtr);
		break;
	case Function:
		OLED_Write_String(y, 100, "Fun");
	}
}

void UI_GetCmd(void)
{
	static Key_Type_e Key_Pressed_New = Key_None;
	static Key_Type_e Key_Pressed_Old = Key_None;

	Key_Pressed_New = Keyscan();

	if (Key_Pressed_New == Key_Pressed_Old)
	{
		UI_CMD = UI_None;
	}
	else
	{
		UI_CMD = (UI_CMD_e) Key_Pressed_New;
		Key_Pressed_Old = Key_Pressed_New;
	}
}

void UI_PutMsg(void) {

	if(UI_CMD != UI_None) OLED_Clear();								//清屏

	OLED_Write_String(0, 0, Active.PagePtr->Name);
	OLED_Write_Float(0,80,Active.Accuracy);
	if (Active.ShowGraphic == FALSE) {
		if (Active.ItemNum < 3) {
			OLED_Write_String(2 * (Active.ItemNum + 1), 0, ">");
			UI_ShowData(2, Active.PagePtr->ItemPtr);
			if (Active.PagePtr->Item_Max<1) {return;}
			UI_ShowData(4, Active.PagePtr->ItemPtr + 1);
			if (Active.PagePtr->Item_Max<2) {return;}
			UI_ShowData(6, Active.PagePtr->ItemPtr + 2);
		} else {
			OLED_Write_String(6, 0, ">");
			UI_ShowData(2, Active.ItemPtr - 2);
			UI_ShowData(4, Active.ItemPtr - 1);
			UI_ShowData(6, Active.ItemPtr);
		}
	} else {
		(*(tIsrFunc) Active.ItemPtr->DataPtr)();
	}
}

void UI_SelectData(void) {

	if(UI_CMD == UI_Save)
	{
		Save_Data();
	}

	if(UI_CMD== UI_Read)
	{
		Read_Data();
	}
}

void UI_Main(void) {

	UI_GetCmd();
	UI_Process();
	UI_SelectData();
	UI_PutMsg();
}
