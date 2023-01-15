#ifndef OS_PORT_H_
#define OS_PORT_H_

#include "stm32f1xx.h"

#define os_enable_interrupts()  __enable_irq()
#define os_disable_interrupts() __disable_irq()

#define N_TASKS 5
#define N_QUEUES 0
#define N_SEMAPHORES 0
#define N_EVENTS 0

#endif
