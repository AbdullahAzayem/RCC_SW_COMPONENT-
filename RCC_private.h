/***************************************************************************************/
/***************************************************************************************/
/*			AUTHOR		:		ABDULLAH AZAYEM										   */
/*			VERSION 	:		V01 												   */
/*			DATA        :       14 NOV 2020									    	   */
/*			COMPONENT	:		RESET AND CLOCK CONTROL	PRIVATE HEADER FILE   	       */
/***************************************************************************************/
/***************************************************************************************/


/*Preprocessor Guard File												*/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

									/*System Clock Source*/
/*********************************************************************************************/

/******************************* [1] HSE (HIGH SPEED EXTERNAL) *******************************/
/* 1- HSE Status*/
#define RCC_HSE 	   			1
#define RCC_HSEON_BIT_MASK      0xFFFEFFFF	// High-speed external HSEON bit mask
#define RCC_HSE_ENABLE 			0x00010000  // High-speed external enable
#define RCC_HSE_DISABLE 		0x00000000  // High-speed external disable

/* 2- HSE Entry source*/
#define RCC_HSEBYP_BIT_MASK		0xFFFBFFFF 	// High-speed external by pass bit mask
#define RCC_HSE_CRYSTAL 		0x00040000 	// High-speed external crystal
#define RCC_HSE_RC		 		0x00000000 	// High-speed external RC

/* 3- HSE Security system*/
#define RCC_HSE_CSSON_BIT_MASK 	0xFFF7FFFF	// Clock security system bit mask
#define RCC_HSE_CSSON 			0x00080000	// Clock security system enable
#define RCC_HSE_CSSOFF 			0x00000000	// Clock security system disable

/* 4- HSE Ready flag*/
#define RCC_CR_HSERDY 			17 			// External high-speed clock ready flag

/******************************* [2] HSI (HIGH SPEED INTERNAL) ******************************/
/* 1- HSI Status*/
#define RCC_HSI 	  			2
#define RCC_HSION_BIT_MASK 		0xFFFFFFFE  // High-Speed Internal bit mask
#define RCC_HSI_ENABLE 			0x00000001  // High-Speed Internal clock enable
#define RCC_HSI_DISABLE 		0x00000000  // High-Speed Internal clock disable
/* 2- HSI Ready flag*/
#define RCC_CR_HSIRDY			1  			// Internal high-speed clock ready flag

/******************************* [3] PLL (PHASE LOCKED LOOP) ********************************/
/* 1- PLL Status*/
#define RCC_PLL					3
#define RCC_PLLON_BIT_MASK 		0xFEFFFFFF  // High-Speed Internal bit mask
#define RCC_PLL_ENABLE 			0x01000000  // High-Speed Internal clock enable
#define RCC_PLL_DISABLE 		0x00000000  // High-Speed Internal clock disable
/* 2- HSI Ready flag*/
#define RCC_CR_PLLRDY 			25		    // PLL clock ready flag

/* 3- HSE Divider by two*/
#define RCC_PLLXTPRE_BIT_MASK 	0xFFFDFFFF
#define RCC_PLLXTPRE_SET 		0x00020000
#define RCC_PLLXTPRE_CLR 		0x00000000

/* 4- PLL entry source*/
#define RCC_PLLSRC_BIT_MASK 	0xFFFEFFFF
#define RCC_PLLSRC_SET 			0x00010000
#define RCC_PLLSRC_CLR 			0x00000000

/* 5- PLL (Phase Locked Loop) Entry Source*/
#define RCC_PLL_HSE    			1
#define RCC_PLL_HSE_DIV_2  		2
#define RCC_PLL_HSI_DIV_2  		3

/* 6- PLL Multiplication factor mask*/
#define PLL_PLLMUL_BIT_MASK     0xFFC3FFFF
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
#define CLOCK_X_16_2 0b1111   // PLL input clock x 16

/********************************************************************************************/


/*Calibration bit mask*/
#define HSICAL_BIT_MASK 0b00000000000000001111111100000000



/***************************  REGISTER DEFINITION    *****************************************/
/*1- Reset and Clock Control "Control Register" 						*/
#define RCC_CR 			(*((volatile u32*) 0x40021000))

/*2- Reset and Clock Control "Clock Configuration Register" 			*/
#define RCC_CFGR 		(*((volatile u32*) 0x40021004))

/*3- Reset and Clock Control "Clock Interrupt Register" 				*/
#define RCC_CIR 		(*((volatile u32*) 0x40021008))

/*4- Reset and Clock Control "APB2 Peripheral Reset Register" 			*/
#define RCC_APB2RSTR 	(*((volatile u32*) 0x4002100C))

/*5- Reset and Clock Control "APB1 Peripheral Reset Register" 			*/
#define RCC_APB1RSTR 	(*((volatile u32*) 0x40021010))

/*6- Reset and Clock Control "AHB Peripheral Clock Enable Register" 	*/
#define RCC_AHBENR 		(*((volatile u32*) 0x40021014))

/*7- Reset and Clock Control "APB2 Peripheral Enable Register" 			*/
#define RCC_APB2ENR 	(*((volatile u32*) 0x40021018))

/*8- Reset and Clock Control "APB1 Peripheral Enable Register "			*/
#define RCC_APB1ENR 	(*((volatile u32*) 0x4002101C))

/*9- Reset and Clock Control "Backup Domain Control Register" 			*/
#define RCC_BDCR 		(*((volatile u32*) 0x40021020))

/*10- Reset and Clock Control "Control and Status Register" 			*/
#define RCC_CSR 		(*((volatile u32*) 0x40021024))

#endif
