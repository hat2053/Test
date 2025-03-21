#ifndef __UART_H__
#define __UART_H__

#include "stm32f10x.h"        // Device header
#include "stm32f10x_usart.h"  
#include <stdint.h>           

#ifdef __cplusplus
extern "C" {
#endif

/* ===================== KH?I T?O UART ===================== */
void USART1_Init(uint32_t baud_rate);

/* ===================== G?I D? LI?U ===================== */
void USART1_Send_Char(char chr);
//void USART1_Send_String(const char* str);
void USART1_Send_String(char* str);
void USART1_Send_Data(uint8_t* data, uint8_t length);
//void USART1_Send_Data(const uint8_t* data, uint8_t length);

/* ===================== G?I D? LI?U Ð?C BI?T ===================== */
void USART1_Send_Number(int16_t num);
void USART1_Send_Float(float num);
void USART1_Send_Hex(uint8_t num);

#ifdef __cplusplus
}
#endif

#endif 
