/*
Simple fifo struct access functions

First parameter of evry function is a pointer to the fifo struct (see fifo.h).

Example :

  fifo_getc(&thefifostruct);

Fifo design:

  read ptr  data array  write ptr
            |  max   |
            |  ...   |
            |   2    |
            |   1    |
  raddr  -> |   0    | <- waddr

Code under GPLv2.

Share, it's happiness !
*/

#include "fifo.h"

/**
 * Init FIFO struct.
 *
 */
void fifo_init(fifo *_fifo)
{
  _fifo->size  = 0;
  _fifo->raddr = 0;
  _fifo->waddr = 0;
}

/**
 * Read one character from FIFO.
 * Interrupts must be disabled
 *
 * @return	current character or EOF if FIFO empty
 */
uint8_t fifo_getc(fifo *_fifo)
{
  uint8_t c;

  // check fifo level
  if (_fifo->size == 0) {
    // empty fifo: return EOF
    return EOF;
  }

  // read current value
  c = _fifo->data[_fifo->raddr];
  _fifo->size--;

  // update read pointer
  if (_fifo->raddr < (FIFO_BUFFER_SIZE - 1)) {
    _fifo->raddr++;
  } else {
    _fifo->raddr = 0;
  }
  return c;
}

/**
 * Write one character to FIFO.
 * Interrupts must be disabled
 *
 * @return true if write ok or false if FIFO full
 */
bool fifo_putc(fifo *_fifo, int c)
{
  // check fifo level
  if (_fifo->size >= FIFO_BUFFER_SIZE) {
    return false;
  }

  // write current value
  _fifo->data[_fifo->waddr] = c;
  _fifo->size++;

  // update write pointer
  if (_fifo->waddr < (FIFO_BUFFER_SIZE - 1))
    _fifo->waddr++;
  else
    _fifo->waddr = 0;
  return true;
}

/**
 * Safe access to space of the FIFO.
 * Interrupts must be disabled
 *
 * @return	number of byte available in FIFO
 */
uint16_t fifo_space(fifo *_fifo)
{
  return FIFO_BUFFER_SIZE - _fifo->size;
}
