/***********************************************************************/
/* Author   : Ahmed Abdelsalam                                         */
/* Date     : 26 August 2024                                           */
/* Version  : V01                                                      */
/***********************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	switch(RCC_CLOCK_TYPE)
	{
		#if    RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
			RCC_CR   = 0x00010000; /* Enable HSE with no Bybass */
			RCC_CFGR = 0x00000001; /* SysClock source is HSE    */
		
		#elif  RCC_CLOCK_TYPE == RCC_HSE_RC
			RCC_CR   = 0x00050000; /* Enable HSE with Bybass    */
			RCC_CFGR = 0x00000001; /* SysClock source is HSE    */
		
		#elif  RCC_CLOCK_TYPE == RCC_HSI
			RCC_CR   = 0x00000081; /* Enable HSI + Trimming = 0 */
			RCC_CFGR = 0x00000000; /* SysClock source is HSI    */
		
		#elif  RCC_CLOCK_TYPE == RCC_PLL
		
			#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2
				RCC_CFGR = 0x00000002; /* SysClock source is HSI divided by 2 */
				RCC_CR   = 0x01000081; /* Enable PLL and HSI + Trimming = 0   */
			
			#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
				RCC_CFGR = 0x00030002; /* SysClock source is HSE divided by 2 */
				switch(RCC_PLL_INPUT_HSE)
				{
					case RCC_HSE_CRYSTAL: RCC_CR = 0x01010000;  break; /* Enable PLL and HSE with no Bybass */
					case RCC_HSE_RC     : RCC_CR = 0x01050000;  break; /* Enable PLL and HSE with Bybass    */
				}
			
			#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
				RCC_CFGR = 0x00010002; /* SysClock source is HSE              */
				switch(RCC_PLL_INPUT_HSE)
				{
					case RCC_HSE_CRYSTAL: RCC_CR = 0x01010000;  break; /* Enable PLL and HSE with no Bybass */
					case RCC_HSE_RC     : RCC_CR = 0x01050000;  break; /* Enable PLL and HSE with Bybass    */
				}
			
			#else 
				#error("Invalid PLL input")
			
			#endif
		
		#else 
			#error("Invalid clock type")
		
		#endif
	}
}


void RCC_voidEnableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId)
{
	if(Copy_uint8PerId <= 31)
	{
		switch(Copy_uint8BusId)
		{
			case RCC_AHB : SET_BIT(RCC_AHBENR  ,Copy_uint8PerId);    break;
			case RCC_APB1: SET_BIT(RCC_APB1ENR ,Copy_uint8PerId);    break;
			case RCC_APB2: SET_BIT(RCC_APB2ENR ,Copy_uint8PerId);    break;
		}
	}
	else
	{
		/* return error */
	}
}

void RCC_voidDisableClock(uint8 Copy_uint8BusId, uint8 Copy_uint8PerId)
{
	if(Copy_uint8PerId <= 31)
	{
		switch(Copy_uint8BusId)
		{
			case RCC_AHB : CLR_BIT(RCC_AHBENR  ,Copy_uint8PerId);    break;
			case RCC_APB1: CLR_BIT(RCC_APB1ENR ,Copy_uint8PerId);    break;
			case RCC_APB2: CLR_BIT(RCC_APB2ENR ,Copy_uint8PerId);    break;
		}
	}
	else
	{
		/* return error */
	}
}