/* ###################################################################
**     Filename    : main.c
**     Project     : Demo
**     Processor   : MK10DN512VLL10
**     Version     : Driver 01.01
**     Compiler    : IAR ARM C Compiler
**     Date/Time   : 2017-09-24, 01:10, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Delay_us.h"
#include "TU1.h"
#include "PWM4.h"
#include "TU2.h"
#include "PWM3.h"
#include "PWM2.h"
#include "PWM1.h"
#include "PWMServo.h"
#include "TU3.h"
#include "key1.h"
#include "key2.h"
#include "key3.h"
#include "key4.h"
#include "key5.h"
#include "key6.h"
#include "key7.h"
#include "key8.h"
#include "Oled_D0.h"
#include "Oled_D1.h"
#include "Oled_Rst.h"
#include "Oled_DC.h"
#include "USART.h"
#include "HREF.h"
#include "VSYN.h"
#include "Delay_ms.h"
#include "TU4.h"
#include "AD1.h"
#include "FLASH.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "../User_Component/User_Driver/User_driver.h"
#include "../User_Component/User_Control/User_Control.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
int P= 0;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  //UI_Init();
  OLED_Init();
 Camera_Init();
//  Usart_Init();
 Servo_Init();
  //Motor_Init();
 // Motor_Enable();
//  Save_Data();
  //Read_Data();
 Servo_Enable();
//  Delay_Ms_Init();
//  Usart_Enable();

for(;;)
{

//	Usart_Send1Bit("A");
	//List_Paint();



	Servo_SetVal(5050+P*img_deflection());
	Image_Transform();
//	Delay_Ms(1000);
	//Servo_SetVal(4200);
}
  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.4 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
