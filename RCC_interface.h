/***************************************************************************************/
/***************************************************************************************/
/*			AUTHOR		:		ABDULLAH AZAYEM										   */
/*			VERSION 	:		V01 												   */
/*			DATA        :       14 NOV 2020									    	   */
/*			COMPONENT	:		RESET AND CLOCK CONTROL	INTERFACE HEADER FILE   	   */
/***************************************************************************************/
/***************************************************************************************/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/*Buses*/
#define RCC_AHB    1 
#define RCC_APB1   3
#define RCC_APB2   6


/*System Clock Source*/
#define RCC_HSE 	   1
#define RCC_HSI 	`  2
#define RCC_HALF_HSE   3
#define RCC_HALF_HSI   4

/*PLL clock entry*/
#define PLL_ENTRY_SOURCE 	HSE 

/*Enable or disable security system*/
#define SECURITY_ENABLE 	1
#define SECURITY_DISABLE 	2

/*HSE external sources*/
#define HSE_CRYSTAL 1
#define HSE_RC      2


/*Multiplication factor bit mask*/
#define PLL_MULTIPLICATION_FACTOR_PLLMUL_BIT_MASK 0b11111111110000111111111111111111
#define CLOCK_X_2 0b0000 	// PLL input clock x 2
#define CLOCK_X_3 0b0001 	// PLL input clock x 3
#define CLOCK_X_4 0b0010 	// PLL input clock x 4
#define CLOCK_X_5 0b0011 	// PLL input clock x 5
#define CLOCK_X_6 0b0100 	// PLL input clock x 6
#define CLOCK_X_7 0b0101 	// PLL input clock x 7
#define CLOCK_X_8 0b0110 	// PLL input clock x 8
#define CLOCK_X_9 0b0111 	// PLL input clock x 9
#define CLOCK_X_10 0b1000   // PLL input clock x 10
#define CLOCK_X_11 0b1001   // PLL input clock x 11
#define CLOCK_X_12 0b1010   // PLL input clock x 12
#define CLOCK_X_13 0b1011   // PLL input clock x 13
#define CLOCK_X_14 0b1100   // PLL input clock x 14
#define CLOCK_X_15 0b1101   // PLL input clock x 15
#define CLOCK_X_16 0b1110   // PLL input clock x 16
#define CLOCK_X_17 0b1111   // PLL input clock x 16

/*Calibration bit mask*/
#define HSICAL_BIT_MASK 0b00000000000000001111111100000000



/*initalization*/
void RCC_voidInit(void); 


/*Enable and disable */
u8 RCC_u8EnableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);
u8 RCC_u8DisableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);


#endif
