#ifndef __FIFO_H
#define __FIFO_H

#include <stdbool.h>
#include <stdint.h>

#define FIFO_BUFFER_SIZE 256
#define EOF '\0'

// FIFO struct
typedef struct
{
  volatile uint8_t data[FIFO_BUFFER_SIZE];
  volatile uint16_t size;
  volatile uint16_t raddr;
  volatile uint16_t waddr;
} fifo;

// FIFO access routines
void fifo_init(fifo *_fifo);
uint8_t fifo_getc(fifo *_fifo);
bool fifo_putc(fifo *_fifo, int c);
uint16_t fifo_space(fifo *_fifo);

#endif
