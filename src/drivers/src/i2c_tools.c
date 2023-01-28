#include "main.h"
#include "stm32f1xx_ll_i2c.h"

extern I2C_HandleTypeDef hi2c1;
extern I2C_HandleTypeDef hi2c2;

static uint16_t unlock_count_1 = 0;
static uint16_t unlock_count_2 = 0;


static void delayMicroseconds(uint32_t delay)
{
  volatile unsigned long i, j;

  for (i=0; i < delay; i++) {
    for (j=0; j < 7; j++) {
      __asm ("nop");
    }
  }
}


static void i2c_bus_recover(
    I2C_HandleTypeDef *hi2c,
    GPIO_TypeDef *GPIOx,
    uint32_t scl_pin,
    uint32_t sda_pin
) {
  /* https://www.analog.com/media/en/technical-documentation/application-notes/54305147357414an686_0.pdf */
  /* https://electronics.stackexchange.com/questions/267972/i2c-busy-flag-strange-behaviour */
  /* https://github.com/esp8266/Arduino/issues/1025 */
  HAL_I2C_DeInit(hi2c);

  HAL_GPIO_WritePin(GPIOx, sda_pin, GPIO_PIN_SET);

  // go to push-pull on sda and scl lines
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = scl_pin | sda_pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

  // generate clock pulses (at 100kHz = 5 us high, 5 us low)
  for (int i = 0; i < 9; i++) {  //9nth cycle acts as NACK
    HAL_GPIO_WritePin(GPIOx, scl_pin, GPIO_PIN_RESET);
    delayMicroseconds(5);  // half clock period
    HAL_GPIO_WritePin(GPIOx, scl_pin, GPIO_PIN_SET);
    delayMicroseconds(5);  // half clock period
  }

  // generate a stop condition (SDA from low to high while CLK is high)
  HAL_GPIO_WritePin(GPIOx, sda_pin, GPIO_PIN_RESET);
  delayMicroseconds(5);
  HAL_GPIO_WritePin(GPIOx, scl_pin, GPIO_PIN_SET);
  delayMicroseconds(2);
  HAL_GPIO_WritePin(GPIOx, sda_pin, GPIO_PIN_SET);
  delayMicroseconds(2);

  // go back to open-drain on sda and scl lines
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  HAL_GPIO_Init(GPIOx, &GPIO_InitStruct);

  HAL_I2C_Init(hi2c);
  SET_BIT(hi2c->Instance->CR1, I2C_CR1_ACK);
}


void i2c_bus_unlock(I2C_HandleTypeDef *hi2c)
{
  if (hi2c == &hi2c1) {
    i2c_bus_recover(hi2c, GPIOB, GPIO_PIN_6, GPIO_PIN_7);
    unlock_count_1++;
  } else if (hi2c == &hi2c2) {
    i2c_bus_recover(hi2c, GPIOB, GPIO_PIN_10, GPIO_PIN_11);
    unlock_count_2++;
  }
}


void check_i2c_status(I2C_HandleTypeDef *hi2c, HAL_StatusTypeDef status)
{
  UNUSED(hi2c);
  UNUSED(status);
  if (status != HAL_OK) {
    i2c_bus_unlock(hi2c);
  }
  /* if (status == HAL_BUSY) { */
  /*   i2c_bus_unlock(hi2c); */
  /* } else if (status != HAL_OK) { */
  /*   Error_Handler(); */
  /* } */
}
