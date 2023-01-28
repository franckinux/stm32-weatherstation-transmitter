#ifndef _i2c_tools_H_
#define _i2c_tools_H_

#include "main.h"

void i2c_bus_unlock(I2C_HandleTypeDef *hi2c);
void check_i2c_status(I2C_HandleTypeDef *hi2c, HAL_StatusTypeDef status);

#endif
