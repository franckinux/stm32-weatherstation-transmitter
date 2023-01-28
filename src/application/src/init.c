#include <stddef.h>
#include "os_applAPI.h"

extern void led_task(void);
extern void sensor_task(void);

uint8_t led_task_id;
uint8_t sensor_task_id;


void app_init(void)
{
  sensor_task_id = task_create(sensor_task, 0, 10, NULL, 0, 0);
  led_task_id = task_create(led_task, 0, 20, NULL, 0, 0);
}
