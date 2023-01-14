target_sources(${MY_TARGET}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/startup_stm32f103xb.s
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/system_stm32f1xx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/main.c
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/system_stm32f1xx.c
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/stm32f1xx_it.c
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/src/stm32f1xx_hal_msp.c
)

add_library(stm32f103-hal)

set(STM32F1_HAL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/stm32cubef1/Drivers/STM32F1xx_HAL_Driver/Src")

target_include_directories(stm32f103-hal
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/startup/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32cubef1/Drivers/STM32F1xx_HAL_Driver/Inc
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32cubef1/Drivers/CMSIS/Device/ST/STM32F1xx/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/stm32cubef1/Drivers/CMSIS/Include
)

target_sources(stm32f103-hal
    PRIVATE
        # ${STM32F1_HAL_SOURCE_DIR}/Legacy/stm32f1xx_hal_can.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_adc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_adc_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_can.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_cec.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_cortex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_crc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_dac.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_dac_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_dma.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_eth.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_exti.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_flash.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_flash_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_gpio.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_gpio_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_hcd.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_i2c.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_i2s.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_irda.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_iwdg.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_mmc.c
        # ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_msp_template.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_nand.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_nor.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_pccard.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_pcd.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_pcd_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_pwr.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_rcc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_rcc_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_rtc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_rtc_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_sd.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_smartcard.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_spi.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_sram.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_tim.c
        # ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_timebase_rtc_alarm_template.c
        # ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_timebase_tim_template.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_tim_ex.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_uart.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_usart.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_hal_wwdg.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_adc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_crc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_dac.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_dma.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_exti.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_fsmc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_gpio.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_i2c.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_pwr.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_rcc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_rtc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_sdmmc.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_spi.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_tim.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_usart.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_usb.c
        ${STM32F1_HAL_SOURCE_DIR}/stm32f1xx_ll_utils.c
)

if (${STM_USE_HAL_DRIVER})
  target_compile_definitions(stm32f103-hal PUBLIC USE_HAL_DRIVER)
endif()
if (${STM_USE_FULL_LL_DRIVER})
  target_compile_definitions(stm32f103-hal PUBLIC USE_FULL_LL_DRIVER)
endif()
if (${STM_USE_FULL_ASSERT})
  target_compile_definitions(stm32f103-hal PUBLIC USE_FULL_ASSERT)
endif()
target_compile_definitions(stm32f103-hal PUBLIC ${STM_HAL_DEVICE})
