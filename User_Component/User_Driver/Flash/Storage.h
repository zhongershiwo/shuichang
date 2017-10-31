/*
 * Storage.h
 *
 *  Created on: 2017Äê9ÔÂ26ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef STORAGE_H_
#define STORAGE_H_
#include "../Generated_Code/FLASH.h"


//#define DEV_STORAGE

void Storage_Init(void);
bool Storage_Read(LDD_FLASH_TAddress FromAddress, LDD_TData* DataPtr, LDD_FLASH_TDataSize Size);
bool Storage_Write(LDD_FLASH_TAddress FromAddress,LDD_TData* DataPtr,LDD_FLASH_TDataSize Size);
bool Storage_Erase(LDD_FLASH_TAddress FromAddress, LDD_FLASH_TDataSize Size);



#endif /* STORAGE_H_ */
