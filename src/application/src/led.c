#include <stdbool.h>
#include <stddef.h>
#include "os_applAPI.h"

#include "main.h"
#include "log.h"

#define LOG_LEVEL LOG_DEBUG
#define LOG_MODULE_NAME "led"
#define CYCLE_PERIOD 500  // 500 ms


void led_task(void)
{
  task_open();

  while(true) {
    HAL_GPIO_TogglePin(led_GPIO_Port , led_Pin);
#if ENABLE_LOGS
    log_debug("test log");
#endif
    task_wait(CYCLE_PERIOD);
  }

  task_close();
}
