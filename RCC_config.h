/***************************************************************************************/
/***************************************************************************************/
/*			AUTHOR		:		ABDULLAH AZAYEM										   */
/*			VERSION 	:		V01 												   */
/*			DATA        :       14 NOV 2020									    	   */
/*			COMPONENT	:		RESET AND CLOCK CONTROL	CONFIGURE HEADER FILE   	   */
/***************************************************************************************/
/***************************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* 1- System Clock Source
Options: 
	1-  RCC_HSI 
	2-  RCC_HSE
	3-  RCC_PLL
*/
#define RCC_SYSTEM_CLOCK_SOURCE 	RCC_PLL


/*Note: Select this value if clock type PLL*/
/*PLL clock entry value
Options: 
	1- RCC_PLL_HSE_DIV_2
	2- RCC_PLL_HSE
	3- RCC_PLL_HSI
*/

/*Note: Select this value if clock type PLL*/
#if 	RCC_SYSTEM_CLOCK_SOURCE == RCC_PLL
#define RCC_PLL_ENTRY_SOURCE 	RCC_PLL_HSE
/*PLL Status*/
#define RCC_PLL_STATUS 		RCC_PLL_ENABLE
/*Options: may be 2,3,4,5,6,7,8,9,.. 16*/
#define RCC_PLL_MUL_VAL 	4
#else
#error ("Wrong configuration in Choosing clock source")
#endif


/*HSE Status
 Options:
 	 1- RCC_HSE_ENABLE
 	 2- RCC_HSE_DISABLE
*/
#define RCC_HSE_STATUS 			RCC_HSE_ENABLE

/*HSE Security mode
 Options:
 	 1- RCC_HSE_CSSON
 	 2- RCC_HSE_CSSOFF
*/
#define RCC_HSE_SECURITY_MODE 	RCC_HSE_CSSON

/*HSE entry source
 Options:
 	 1- RCC_HSE_CRYSTAL
 	 2- RCC_HSE_RC
*/
#define RCC_HSE_ENTRY_SOURCE 	RCC_HSE_CRYSTAL




/*HSI Status
 Options:
 	 1- RCC_HSI_ENABLE
 	 2- RCC_HSI_DISABLE
*/
#define RCC_HSI_STATUS 			RCC_HSI_ENABLE


/*Multiplication factor
 Options:
 	 1- CLOCK_X_2
 	 2- CLOCK_X_3
 	 3- CLOCK_X_4
 	 4- CLOCK_X_5
 	 5- CLOCK_X_6
 	 6- CLOCK_X_7
 	 7- CLOCK_X_8
 	 8- CLOCK_X_9
 	 9- CLOCK_X_10
 	 10- CLOCK_X_11
 	 11- CLOCK_X_12
 	 12- CLOCK_X_13
 	 13- CLOCK_X_14
 	 14- CLOCK_X_15
 	 15- CLOCK_X_16
 	 16- CLOCK_X_16
*/
#define PLL_PLLMUL_VAL     		CLOCK_X_2

#endif
