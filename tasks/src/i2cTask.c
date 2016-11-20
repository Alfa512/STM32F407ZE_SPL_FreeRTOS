#include "i2cTask.h"

const TickType_t xDelay = 100 / portTICK_PERIOD_MS;

void i2cTaskBefore(void) {
  i2cTask_init();
}

void i2cTaskMain(void* dummy) {
  /* main program loop */
  for (;;) {

  }

  /* never reached */
  vTaskDelete(NULL);
}

void i2cTaskAfter(void) {
}

//Private functions

void i2cTask_init(void) {

}
