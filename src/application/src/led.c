#include <stdbool.h>
#include <stddef.h>
#include "os_applAPI.h"

#include "main.h"
#include "log.h"

#define LOG_LEVEL LOG_DEBUG
#define LOG_MODULE_NAME "led"
#define CYCLE_PERIOD 500  // 500 ms

static uint8_t green_led_state = 1;


void led_task(void)
{
  task_open();

  while(true) {
    HAL_GPIO_WritePin(led_GPIO_Port , led_Pin, (green_led_state == 0) ? (green_led_state = GPIO_PIN_SET) : (green_led_state = GPIO_PIN_RESET));
    log_debug("test log");
    task_wait(CYCLE_PERIOD);
  }

  task_close();
}
