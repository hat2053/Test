#ifndef __SYS__
#define __SYS__


#include "stm32f10x.h"
#include "uart.h"
#include "rfid.h"
#include "tim2.h"
#include "gpio.h"
#include <stdint.h>

#ifdef __cplusplus  
extern "C" {
#endif

void Sys_Init(void);
void Sys_Run(void);

#ifdef __cplusplus  
#endif

#endif