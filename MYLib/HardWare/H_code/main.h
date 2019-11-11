/**
  ******************************************************************************
  * @file    main.h 
  * @author  Debug406 Team
  * @date    
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "string.h"
#include "My_Usart.h"
#include "ds18b20.h"
#include "dht22.h"

/* Debug Lab's HeadLib */
#include "My_ADC.h"
#include "test.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* EXTERN CONT----------------------------------------------------------------*/
extern uint8_t temp[255];
extern uint8_t okflag;

/* Exported functions ------------------------------------------------------- */
/* Reference Only -> (F12) SysTick_Handler(); */
#endif /* __MAIN_H */

/**
  ******************************************************************************
  * @text    PROJECT Style Guide
  * @date    15-Fabrulary-2018
  ******************************************************************************
  * @style
  *                   Head & Source    ::   lowerCamelCase  .c or .h
  *                   Parameters       ::   lowerCamelCase
  *                   Local variables  ::  _lowerCamelCase
  *    # dont use! #  Global variables ::   lowerCamelCase_g              
  *                   Enums & Union    ::   lowerCamelCase__
  *                   Structs          ::   UpperCamelCase
  *                   Global functions ::   UpperCamelCase
  *                   Local functions  ::  _UpperCamelCase
  *                   Typedefs         ::   UowerCamelCase_t
  *                   macros           ::   ALL_UPPER
  *                   Private macros   ::  _ALL_UPPER
  *                   Private define   ::  _ALL_UPPER
  *
  * @CoreStyle        
  *                   funcitons        :: UpperCamelCase_UnderscoreTolerant
  *
  ******************************************************************************
  */

