/***********************************************************************/
/* Author   : Ahmed Abdelsalam                                         */
/* Date     : 26 August 2024                                           */
/* Version  : V01                                                      */
/***********************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2


void RCC_voidEnableClock  (uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);
void RCC_voidDisableClock (uint8 Copy_uint8BusId, uint8 Copy_uint8PerId);
void RCC_voidInitSysClock (void);
#endif