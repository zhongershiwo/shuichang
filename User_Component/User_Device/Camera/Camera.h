/*
 * Camera.h
 *
 *  Created on: 2017Äê9ÔÂ25ÈÕ
 *      Author: »ÝÆÕ
 */

#ifndef CAMERA_H_
#define CAMERA_H_
#include "../Generated_Code/AD1.h"
#include "../Generated_Code/HREF.h"
#include "../Generated_Code/VSYN.h"
#include"stdint.h"



void Camera_Init(void);
extern void HREF_IRQ(void);
extern void VSYN_IRQ(void);

#endif /* CAMERA_H_ */
