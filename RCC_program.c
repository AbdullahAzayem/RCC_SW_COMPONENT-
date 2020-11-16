/***************************************************************************************/
/***************************************************************************************/
/*			AUTHOR		:		ABDULLAH AZAYEM										   */
/*			VERSION 	:		V01 												   */
/*			DATA        :       14 NOV 2020									    	   */
/*			COMPONENT	:		RESET AND CLOCK CONTROL	PROGRAM FILE   	               */
/***************************************************************************************/
/***************************************************************************************/


/*include Error States Library*/
#include "ERROR_STATES.h"

/*include Standards types library*/
#include "STD_TYPES.h"

/*include the bit math library*/
#include "BIT_MATH.h"

/*include the components header files*/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInit(void)
{		
	/* 1- if the system clock source is high speed external source (HSE)*/
	#if RCC_SYSTEM_CLOCK_SOURCE == RCC_HSE

			/*Set high speed external HSE status (Enable/Disable)*/
			RCC_CR &= RCC_HSEON_BIT_MASK;
			RCC_CR |= RCC_HSE_STATUS;

			/*High speed external entry source*/
			RCC_CR &= RCC_HSEBYP_BIT_MASK;
			RCC_CR |= RCC_HSE_ENTRY_SOURCE;

			/*System Security Mode*/
			RCC_CR &= RCC_HSE_CSSON_BIT_MASK;
			RCC_CR |= RCC_HSE_SECURITY_MODE;

			/*Polling on flag ready*/
			while(!(GET_BIT(RCC_CR,RCC_CR_HSERDY)));

	/* 2- if the system clock is high speed internal source*/
	#elif RCC_SYSTEM_CLOCK_SOURCE == RCC_HSI

			/*Set high speed internal status (Enable/Disable)*/
			RCC_CR &= RCC_HSION_BIT_MASK;
			RCC_CR |= RCC_HSI_STATUS;

			/*Polling on flag ready: if RCC_CR_HSIRDY == 1 :internal 8 MHz RC oscillator ready*/
			while((GET_BIT(RCC_CR,RCC_CR_HSIRDY)) == 0);

	/* 3- if the system clock is phase locked loop source*/
	#elif RCC_SYSTEM_CLOCK_SOURCE == RCC_PLL
		/*high speed external entry source */
		#if  RCC_PLL_ENTRY_SOURCE 	== 	RCC_PLL_HSE
			/*Set high speed external HSE status (Enable/Disable)*/
			RCC_CR &= RCC_HSEON_BIT_MASK;
			RCC_CR |= RCC_HSE_STATUS;

			/*High speed external entry source*/
			RCC_CR &= RCC_HSEBYP_BIT_MASK;
			RCC_CR |= RCC_HSE_ENTRY_SOURCE;

			/*System Security Mode*/
			RCC_CR &= RCC_HSE_CSSON_BIT_MASK;
			RCC_CR |= RCC_HSE_SECURITY_MODE;

			/*Polling on flag ready*/
			while(!(GET_BIT(RCC_CR,RCC_CR_HSERDY)));

			/*HSE oscillator clock selected as PLL input clock*/
			RCC_CFGR &= RCC_PLLSRC_BIT_MASK;
			RCC_CFGR |= RCC_PLLSRC_SET;

			/*HSE not divided by two*/
			RCC_CFGR &= RCC_PLLXTPRE_BIT_MASK;
			RCC_CFGR |= RCC_PLLXTPRE_CLR;


		#elif RCC_PLL_ENTRY_SOURCE 	== 	RCC_PLL_HSE_DIV_2 	//half high speed external entry source
			/*Set high speed external HSE status (Enable/Disable)*/
			RCC_CR &= RCC_HSEON_BIT_MASK;
			RCC_CR |= RCC_HSE_STATUS;

			/*High speed external entry source*/
			RCC_CR &= RCC_HSEBYP_BIT_MASK;
			RCC_CR |= RCC_HSE_ENTRY_SOURCE;

			/*System Security Mode*/
			RCC_CR &= RCC_HSE_CSSON_BIT_MASK;
			RCC_CR |= RCC_HSE_SECURITY_MODE;

			/*Polling on flag ready*/
			while(!(GET_BIT(RCC_CR,RCC_CR_HSERDY)));

			/*HSE oscillator clock selected as PLL input clock*/
			RCC_CFGR &= RCC_PLLSRC_BIT_MASK;
			RCC_CFGR |= RCC_PLLSRC_SET;

			/*HSE not divided by two*/
			RCC_CFGR &= RCC_PLLXTPRE_BIT_MASK;
			RCC_CFGR |= RCC_PLLXTPRE_SET;

		#elif RCC_PLL_ENTRY_SOURCE 	== 	RCC_PLL_HSI_DIV_2 	//half high speed internal entry source

			/*Set high speed internal status (Enable/Disable)*/
			RCC_CR &= RCC_HSION_BIT_MASK;
			RCC_CR |= RCC_HSI_STATUS;

			/*Polling on flag ready: if RCC_CR_HSIRDY == 1 :internal 8 MHz RC oscillator ready*/
			while((GET_BIT(RCC_CR,RCC_CR_HSIRDY)) == 0);

			/*HSI oscillator clock selected as PLL input clock*/
			RCC_CFGR &= RCC_PLLSRC_BIT_MASK;
			RCC_CFGR |= RCC_PLLSRC_CLR;
			
		#else
			#error ("Wrong Configuration on phase locked loop entry clock source")
		#endif
		
		/*define the multiplication factor*/
		RCC_CFGR &= PLL_PLLMUL_BIT_MASK;
		RCC_CFGR |= PLL_PLLMUL_VAL << 18 ;
		
		/*Set Phase Locked Loop status (Enable/Disable)*/
		RCC_CR &= RCC_PLLON_BIT_MASK;
		RCC_CR |= RCC_PLL_STATUS;

		/*Polling on flag ready*/
		while((GET_BIT(RCC_CR,RCC_CR_PLLRDY)) == 0);

	/*4- Error configuration*/
	#else 
		#error ("Wrong System Clock Source Configuration")
	#endif
}



/*Implementation of clock enable*/
u8 RCC_u8EnableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*Define error state*/
	u8 Local_u8ErrorStatus = OK;	
	if(Copy_u8PeripheralID < REGISTER_LENGTH)
	{
		/*Switch on ID*/
		switch(Copy_u8BusID)
		{
			case RCC_AHB: /*Advanced High performance Bus*/
				SET_BIT(RCC_AHBENR,Copy_u8PeripheralID);
				break;
			case RCC_APB1: 
				SET_BIT(RCC_APB1ENR,Copy_u8PeripheralID);
				break;
			case RCC_APB2:
				SET_BIT(RCC_APB2ENR,Copy_u8PeripheralID);
			break;
			default:
				/*Set error status*/
				Local_u8ErrorStatus = NOK;
			break;
		}	
	}
	else
	{
		/*Set error status*/
		Local_u8ErrorStatus = NOK;
	}
	
	/*return error status*/
	return Local_u8ErrorStatus;
}

/*Implementation of disable function*/
u8 RCC_u8DisbleClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
{
	/*Define error state*/
	u8 Local_u8ErrorStatus = OK;
	
	if(Copy_u8PeripheralID <32)
	{
		/*Switch on ID*/
		switch(Copy_u8BusID)
		{
			case RCC_AHB:
				CLR_BIT(RCC_AHBENR,(u32)Copy_u8PeripheralID);
				break;
			case RCC_APB1:
				CLR_BIT(RCC_APB1ENR,(u32)Copy_u8PeripheralID);
				break;
			case RCC_APB2:
				CLR_BIT(RCC_APB2ENR,(u32)Copy_u8PeripheralID);
			break;
			default:
			break;
		}
	}
	else
	{
		/*Set error status*/
		Local_u8ErrorStatus = NOK;
	}
	/*return error status*/
	return Local_u8ErrorStatus;
}
