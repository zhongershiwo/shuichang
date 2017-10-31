/*
 * Camera.c
 *
 *  Created on: 2017��9��25��
 *      Author: ����
 */
#include "Camera.h"

const uint8_t GetLine[64] = {	0,  3,  6,  9, 12, 15, 18, 21, 24, 27,
		   	   	   	   	   	   30, 33, 36, 39, 42, 45, 48, 51, 54, 57,
		   	   	   	   	   	   60, 63, 66, 69, 72, 75, 78, 81, 84, 87,
		   	   	   	   	   	   90, 93, 96, 99,102,105,109,111,114,117,
		   	   	   	   	   	   120,123,126,129,132,135,139,141,144,147,
		   	   	   	   	   	   150,153,156,159,162,165,169,171,174,177,
		   	   	   	   	   	   180,183,186,189
					  	  	};
 uint8_t Image[64][128];
uint8_t Line = 0;
int16_t Line_count = 0;
uint8_t linenum=30;
uint8_t List1;
uint8_t delaytick=85;
uint16_t Fit_Middleline[64]={0};
LDD_TDeviceDataPtr myHREF;
LDD_TDeviceDataPtr myVSYN;
LDD_TDeviceDataPtr myCamD;

void Camera_Init(void)
{
	myHREF	= HREF_Init(NULL);
	myVSYN	= VSYN_Init(NULL);
	myCamD	= AD1_Init(NULL);

}
/*���ж�*/
void HREF_IRQ(void)
{
	Line_count++;
	if(Line_count == GetLine[Line]+linenum)//ͼ��ƽ��
		                              //������������  70
	{

		for(int i=0;i<delaytick;i++)
							          {
											asm("NOP");

							          }
		for (List1 = 0; List1 < 128; List1++)
		        {
				   /*�˴��Ŀ�ָ�����ѹ���ұ�������*/
				asm("NOP");asm("NOP");



//				  Image[Line][List1] = !((GPIO_PDD_GetPortDataInput(CamD_MODULE_BASE_ADDRESS) & CamD_PORT_MASK));//IO������
//				  Image[Line][List1] =!((LDD_AnalogComp_TOutputValue)CMP_PDD_GetComparatorOutput(CMP0_BASE_PTR));
					if ((GPIO_PDD_GetPortDataInput(AD1_MODULE_BASE_ADDRESS) & AD1_PORT_MASK)) {
						Image[Line][List1] = 1;
					} else {
						Image[Line][List1] = 0;
					}
				}
				Line++;
	}

}
/*���ж�*/
void VSYN_IRQ(void)
{


	Line_count=-1;
	Line = 0;

}
