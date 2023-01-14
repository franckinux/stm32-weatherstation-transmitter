#ifndef __LOG_H
#define __LOG_H

#define ENABLE_LOGS 1

#include <stdbool.h>
#include "fifos.h"

#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARNING 2
#define LOG_ERROR 3
#define LOG_CRITICAL 4

bool insert_in_log_fifo(char* module, char *msg);

#define log(l, m) if (l >= LOG_LEVEL) do { insert_in_log_fifo(LOG_MODULE_NAME, m); } while (0)

#define log_debug(m) log(LOG_DEBUG, m)
#define log_info(m) log(LOG_INFO, m)
#define log_warning(m) log(LOG_WARNING, m)
#define log_error(m) log(LOG_ERROR, m)
#define log_critical(m) log(LOG_CRITICAL, m)

#endif
