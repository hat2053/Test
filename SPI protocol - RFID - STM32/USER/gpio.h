#ifndef __GPIO__
#define __GPIO__

#include "stm32f10x_rcc.h"
#include "stm32f10x.h" 
#include "stm32f10x_gpio.h"
#include "tim2.h"
#include <stdint.h>

#ifdef __cplusplus  
extern "C" {
#endif


 /* ========== GPIO ========= */
#define LED_PIN GPIO_Pin_13
#define LED_PORT GPIOC

/* ========== khai b�o du li�u :struct, enum, typedef ========= */
typedef enum {
    LED_OFF = 0,
    LED_ON
} LED_State_t;	

 /* ========== Khai b�o bien  ========= */
extern uint8_t led_status;

/* ========== H�m ========= */
void GPIO_Debug_Init(void);
void Debug(void);
void On (void);
void Off (void);


#ifdef __cplusplus  
}
#endif


#endif
