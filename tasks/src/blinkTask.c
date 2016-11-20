#include "blinkTask.h"

const TickType_t xDelay = 100 / portTICK_PERIOD_MS;

void blinkTaskBefore(void) {
  blinkTask_initGPIO();
}

void blinkTaskMain(void* dummy) {
  /* main program loop */
  for (;;) {
    /* set led on */
    GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_SET);
    /* delay */
    vTaskDelay(xDelay);
    /* clear led */
    GPIO_WriteBit(GPIOF, GPIO_Pin_10, Bit_RESET);
    /* delay */
    vTaskDelay(xDelay);
  }

  /* never reached */
  vTaskDelete(NULL);
}

void blinkTaskAfter(void) {
}

//Private functions

void blinkTask_initGPIO(void) {
  GPIO_InitTypeDef GPIO_InitStruct;
  /*USART_InitTypeDef USART_InitStruct;*/

  /*RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);*/
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

  GPIO_InitStruct.GPIO_Pin = /*GPIO_Pin_10 | GPIO_Pin_11 |*/ GPIO_Pin_10;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOF, &GPIO_InitStruct);
}
