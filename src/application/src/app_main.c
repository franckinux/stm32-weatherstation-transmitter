#include <stddef.h>
#include <stdbool.h>
#include "os_applAPI.h"

extern void led_task(void);


bool app_init()
{
  bool ok = true;

  task_create(led_task, 0, 1, NULL, 0, 0);

  return ok;
}
