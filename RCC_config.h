/***********************************************************************/
/* Author   : Ahmed Abdelsalam                                         */
/* Date     : 26 August 2024                                           */
/* Version  : V01                                                      */
/***********************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* Options :              
                      1.RCC_HSE_CRYSTAL 
                      2.RCC_HSE_RC 
					  3.RCC_HSI
					  4.RCC_PLL                 */
#define RCC_CLOCK_TYPE  RCC_HSE_CRYSTAL


/* Options:
                      1.RCC_PLL_IN_HSI_DIV_2
                      2.RCC_PLL_IN_HSE_DIV_2
					  3.RCC_PLL_IN_HSE          */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif


/* Options: 2 to 16 */
/* Note: Select value only if you have PLL as input clock source */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL 4
#endif


/* Options:
                      1.RCC_HSE_CRYSTAL 
                      2.RCC_HSE_RC              */
/* Note: Select value only if you have PLL as input clock source and HSE as the input for the PLL */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT_HSE   RCC_HSE_CRYSTAL
#endif


#endif