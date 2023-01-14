#! /usr/bin/env bash
# Prior to execute this script, open the project file (*.ioc) in ../stm32cubemx
# with the STM3CubeMX software, make the changes and generate the code
# and don't forget to save your changes in theses files !
set -e -x

cp -f ../../stm32cubemx/STM32F103C8Tx_FLASH.ld .
cp -f ../../stm32cubemx//startup_stm32f103xb.s startup/src
cp -f ../../stm32cubemx/Core/Src/stm32f1xx_it.c startup/src
cp -f ../../stm32cubemx/Core/Inc/stm32f1xx_it.h startup/inc
cp -f ../../stm32cubemx/Core/Inc/main.h startup/inc
cp -f ../../stm32cubemx/Core/Src/main.c startup/src/
cp -f ../../stm32cubemx/Core/Src/system_stm32f1xx.c startup/src/
cp -f ../../stm32cubemx/Core/Src/stm32f1xx_hal_msp.c startup/src/
cp -f ../../stm32cubemx/Core/Inc/stm32f1xx_hal_conf.h startup/inc
