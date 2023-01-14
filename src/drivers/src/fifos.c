#include "fifo.h"

fifo log_fifo;


void fifos_init()
{
  fifo_init(&log_fifo);
}
