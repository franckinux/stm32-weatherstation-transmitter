#include <stddef.h>
#include <stdbool.h>
#include "os_applAPI.h"

extern bool sensor_init(void);

extern void led_loop(void);
extern void sensor_loop(void);


bool app_init()
{
  bool ok = true;

  ok = ok && sensor_init();

  task_create(led_loop, 0, 1, NULL, 0, 0);
  task_create(sensor_loop, 0, 2, NULL, 0, 0);

  return ok;
}
