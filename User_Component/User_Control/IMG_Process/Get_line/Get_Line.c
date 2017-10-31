/*
 * Get_Line.c
 *
 *  Created on: 2017��10��30��
 *      Author: ����
 */

#include "Get_Line.h"

#define PIX_X 128
#define PIX_Y 64
#define LEFT  0
#define MIDDLE 1
#define RIGHT 2
extern uint8_t Image[64][128];//С�ָ��ҵ�����
uint8_t x_edge[PIX_Y][3]={0};//car_edge[PIX_Y][3]=0;
uint8_t Line_1[64];
#define IMG_BLACK       1
#define IMG_WHITE       0

float img_deflection()//
{
	uint8_t x,y;
	x_edge[0][LEFT]=PIX_X/2;
	x_edge[0][RIGHT]=PIX_X/2;

  	for(y=1;y<=PIX_Y;y++)
 	{
x=x_edge[y-1][LEFT]+1;
	while(x||x==PIX_X)
	{
	       if(Image[y][x])x++;else x--;
		if(Image[y][x]^Image[y][x+1]) break;
	};
x_edge[y][LEFT]=x;

x=x_edge[y-1][RIGHT]-1;
	while(x||x==PIX_X)
	{
		if(Image[y][x])x--;else x++;
		if(Image[y][x]^Image[y][x-1]) break;
	};
x_edge[y][RIGHT]=x;
	x_edge[y][MIDDLE]=(x_edge[y][RIGHT]+x_edge[y][LEFT])/2;
	Image[y][x_edge[y][MIDDLE]]=1;
//	img_trend+=(x_edge[y][LEFT]+x_edge[y][RIGHT]-PIX_X)/y;
	//how to compute img trend?
	//if((x_edge[y][LEFT]>car_edge[y][LEFT])||(car_edge[y][RIGHT]<x_edge[y][RIGHT]))//һ���������ڻ���
	return (x_edge[y][LEFT]+x_edge[y][RIGHT]-PIX_X)*1.0/y    /* +img_trend  */ ;
 	}
     return 0;
}








void zhongxing (void)
{
	uint8_t  x,y;

	for (y = 0 ;y < PIX_Y ; y++ )
	 {
		float pos=0;
		for (x = 0 ;x < PIX_X ; x++ )

		if(Image[y][x]==0)
			pos+=x;
		Line_1[y]=(int)(pos/PIX_X);
		Image[y][Line_1[y]]=1;

	 }
}


unsigned int m_sqrt(unsigned int x) {
	uint8_t ans=0,p=0x80;     while(p!=0)     {
        ans+=p;
        if(ans*ans>x)         {
            ans-=p;         }
        p=(uint8_t)(p/2);     }
    return(ans); }



/*
#define PIX_X 128
#define PIX_Y 64
#define LEFT  0
#define MIDDLE 1
#define RIGHT 2
extern uint8_t Image[PIX_Y][PIX_X];//С�ָ��ҵ�����
static uint8_t leftFindFlag;              // �������������Ƿ��ҵ�
static uint8_t rightFindFlag;             // ��������Һ����Ƿ��ҵ�
uint8_t findline;
uint8_t Cent_Line_[64];
uint8_t leftLine[PIX_Y] = {0};
uint8_t rightLine[PIX_Y] = {0};

#define LINGYU    5
#define CENTER_POINT    PIX_X/2
void Find_center_Line(void)
{
	uint8_t temp,tmp;
//����ǰ5������
	for(findline = PIX_Y - 1 ;findline > PIX_Y-6 ; findline-- )
	{
		leftFindFlag = 0;        rightFindFlag = 0;
		for(temp = 0; temp < CENTER_POINT; temp++)
		        {
		           // Ѱ�������
		            if(leftFindFlag == 0
		               && image[findLine][CENTER_POINT-temp-1] == IMG_BLACK
		            && image[findLine][CENTER_POINT-temp] == IMG_WHITE
		            && image[findLine][CENTER_POINT-temp+1] == IMG_WHITE
		            && image[findLine][CENTER_POINT-temp+2] == IMG_WHITE)
		            {
		                leftLine[findLine] = CENTER_POINT-temp-1;
		                leftFindFlag = 1;
		            }
		            // Ѱ���Һ���
		            if(rightFindFlag == 0
		            && image[findLine][CENTER_POINT+temp] == IMG_BLACK
		            && image[findLine][CENTER_POINT+temp-1] == IMG_WHITE
		            && image[findLine][CENTER_POINT+temp-2] == IMG_WHITE
		            && image[findLine][CENTER_POINT+temp-3] == IMG_WHITE)
		            {
		               rightLine[findLine] = CENTER_POINT+temp;
		               rightFindFlag = 1;
		            }
		            if(leftFindFlag == 1 && rightFindFlag == 1)
		                break;
		        }
		// ��δ�ҵ��ĺ��߽��в�ȫ
		       if(leftFindFlag == 0)
		            leftLine[findLine] = 0;
		        if(rightFindFlag == 0)
		            rightLine[findLine] = IMAGE_W-1;
		        // �����߽��и�ֵ
		        		centerLine[findLine] = (leftLine[findLine]+rightLine[findLine])/2;
		        	}

		        	// ʮ�к����ǰ����λ�ò��Һ���
		        	for(findLine = IMAGE_H-11; findLine >= 0; findLine--)
		        	{
		        		leftFindFlag = 0;
		        		rightFindFlag = 0;
		        		// Ԥ����һ�к���λ��
		        		leftCount = createPoint(FIND_LEFT, findLine);
		        		rightCount = createPoint(FIND_RIGHT, findLine);
		        		//leftCount = (2 * leftLine[findLine+1] - leftLine[findLine+2]);
		        		//rightCount = (2 * rightLine[findLine+1] - rightLine[findLine+2]);

		        		  //   /* ��Ԥ�������� FIND_COUNT ������Һ���λ�� */
		        		// Ѱ�������
/*
		        		for(temp = 0; temp < FIND_COUNT*2+1; temp++)
		        		{
		        			if(leftFindFlag != 0)
		        				break;
		        			else if((leftCount-temp+FIND_COUNT)+3 > IMAGE_W-1)
		        				continue;
		        			else if((leftCount-temp+FIND_COUNT) < 0)
		        				break;
		        			else if(image[findLine][leftCount-temp+FIND_COUNT] == IMG_BLACK
		        			&& image[findLine][leftCount-temp+FIND_COUNT+1] == IMG_WHITE
		        			&& image[findLine][leftCount-temp+FIND_COUNT+2] == IMG_WHITE
		        			&& image[findLine][leftCount-temp+FIND_COUNT+3] == IMG_WHITE)
		        			{
		        				leftLine[findLine] = leftCount-temp+FIND_COUNT;
		        				leftFindFlag = 1;
		        			}
		        		}
		        		// Ѱ���Һ���
		        		for(temp = 0; temp < FIND_COUNT*2+1; temp++)
		        		{
		        			if(rightFindFlag != 0)
		        				break;
		        			else if((rightCount+temp-FIND_COUNT)-3 < 0)
		        				continue;
		        			else if(rightCount+temp-FIND_COUNT > IMAGE_W-1)
		        				break;
		        			else if(image[findLine][rightCount+temp-FIND_COUNT] == IMG_BLACK
		        			&& image[findLine][rightCount+temp-FIND_COUNT-1] == IMG_WHITE
		        			&& image[findLine][rightCount+temp-FIND_COUNT-2] == IMG_WHITE
		        			&& image[findLine][rightCount+temp-FIND_COUNT-3] == IMG_WHITE)
		        			{
		        				rightLine[findLine] = rightCount+temp-FIND_COUNT;
		        				rightFindFlag = 1;
		        			}
		        		}



	}







}


*/






































