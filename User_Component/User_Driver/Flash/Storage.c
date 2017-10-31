/*
 * Storage.c
 *
 *  Created on: 2017Äê9ÔÂ26ÈÕ
 *      Author: »ÝÆÕ
 */
#include "Storage.h"
LDD_TDeviceDataPtr myFLASH;

void Storage_Init(void)
{
	myFLASH = FLASH_Init(NULL);
}

bool Storage_Read(LDD_FLASH_TAddress FromAddress, LDD_TData* DataPtr, LDD_FLASH_TDataSize Size)
{
	LDD_TError Error;
	Error = FLASH_Read(myFLASH, FromAddress, DataPtr, Size);
	if (Error) {
		return FALSE;
	}
	do{
		FLASH_Main(myFLASH);
	}while(FLASH_GetOperationStatus(myFLASH) != LDD_FLASH_IDLE);
	return TRUE;
}

bool Storage_Write(LDD_FLASH_TAddress FromAddress,LDD_TData* DataPtr,LDD_FLASH_TDataSize Size)
{
	LDD_TError Error;
	Error = FLASH_Write(myFLASH, DataPtr, FromAddress, Size);
	if (Error) {
		return FALSE;
	}
	do{
		FLASH_Main(myFLASH);
	}while(FLASH_GetOperationStatus(myFLASH) != LDD_FLASH_IDLE);
	return TRUE;
}

bool Storage_Erase(LDD_FLASH_TAddress FromAddress, LDD_FLASH_TDataSize Size)
{
	LDD_TError Error;
	Error = FLASH_Erase(myFLASH, FromAddress, Size);
	if (Error) {
		return FALSE;
	}
	do{
		FLASH_Main(myFLASH);
	}while(FLASH_GetOperationStatus(myFLASH) != LDD_FLASH_IDLE);
	return TRUE;
}
