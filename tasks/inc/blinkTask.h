#ifndef _BLINK_TASK_H_
#define _BLINK_TASK_H_

#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx_conf.h"

#include "ccm.h"

// Defines

#define BLINK_TASK_STACK_SIZE 256

// Task control functions
void blinkTaskBefore(void);
void blinkTaskMain(void*);
void blinkTaskAfter(void);


void blinkTask_initGPIO(void);

// Public functions

// Public variables

extern StackType_t blinkTask_stack[BLINK_TASK_STACK_SIZE] CCM_RAM;  // Put task stack in CCM
extern StaticTask_t blinkTask_buffer CCM_RAM;  // Put TCB in CCM

#endif
