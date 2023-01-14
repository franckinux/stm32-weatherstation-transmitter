#include <stdbool.h>
#include <string.h>
#include "stm32f1xx.h"
#include "fifos.h"

static bool fifo_emptied = true;
extern UART_HandleTypeDef huart1;


void insert_in_log_fifo(char*module, char *msg)
{
  int module_len = strlen(module);
  int msg_len = strlen(msg);

  __disable_irq();
  if (module_len + msg_len + 5 <= fifo_space(&log_fifo)) { // "() \r\n" : 5 extra chars
    int i;
    fifo_putc(&log_fifo, '(');
    for (i = 0; i < module_len; i++) {
      fifo_putc(&log_fifo, module[i]);
    }
    fifo_putc(&log_fifo, ')');
    fifo_putc(&log_fifo, ' ');
    for (i = 0; i < msg_len; i++) {
      fifo_putc(&log_fifo, msg[i]);
    }
    fifo_putc(&log_fifo, '\r');
    fifo_putc(&log_fifo, '\n');

    if (fifo_emptied) {
      __HAL_UART_ENABLE_IT(&huart1, UART_IT_TXE);
      fifo_emptied = false;
    }
  }
  __enable_irq();
}


void USART1_IRQHandler(void)
{
  if ((huart1.Instance->SR & USART_SR_TXE) != RESET) {
    uint8_t c = fifo_getc(&log_fifo);
    if (c == EOF) {
      /* nothing more to send, the fifo has been emptied */
      __HAL_UART_DISABLE_IT(&huart1, UART_IT_TXE);
      fifo_emptied = true;
    } else {
      /* send next char */
      huart1.Instance->DR = c;
    }
  }
}

