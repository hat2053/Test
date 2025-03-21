#ifndef __TIM2_H__
#define __TIM2_H__

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_tim.h"              // Keil::Device:StdPeriph Drivers:TIM
#include <stdint.h>


#ifdef __cplusplus
extern "C" {
#endif

/* ===================== KH?I T?O TIMER ===================== */
void Timer2_Init(void);

/* ===================== HÀM DELAY ===================== */
void Delay_us(uint16_t us);
void Delay_ms(uint32_t ms);

/* ===================== Ð?C TH?I GIAN ===================== */
uint32_t millis(void);

/* ===================== NG?T TIMER2 ===================== */
void TIM2_IRQHandler(void);


#ifdef __cplusplus
}
#endif

#endif
