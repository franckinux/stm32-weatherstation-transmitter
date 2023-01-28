target_include_directories(${MY_TARGET}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/application/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/inc
)

target_sources(${MY_TARGET}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/application/src/led.c
        ${CMAKE_CURRENT_SOURCE_DIR}/application/src/sensor.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/bme280.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/fifo.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/fifos.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/nrf24.c
        ${CMAKE_CURRENT_SOURCE_DIR}/application/src/init.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/i2c_tools.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/log.c
        ${CMAKE_CURRENT_SOURCE_DIR}/drivers/src/printf.c
)

target_include_directories(${MY_TARGET}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/inc
        ${CMAKE_CURRENT_SOURCE_DIR}/os/inc
)

target_sources(${MY_TARGET}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_assert.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_cbk.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_event.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_kernel.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_msgqueue.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_sem.c
        ${CMAKE_CURRENT_SOURCE_DIR}/cocoos/src/os_task.c
)

# target_include_directories(${MY_TARGET}
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/storage
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode_stm32
#         ${CMAKE_SOURCE_DIR}/objdict
# )

# target_sources(${MY_TARGET}
#     PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/CANopen.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_ODinterface.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_NMT_Heartbeat.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_HBconsumer.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_Emergency.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_SDOserver.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_TIME.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_SYNC.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_PDO.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/303/CO_LEDs.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/305/CO_LSSslave.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/storage/CO_storage.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_fifo.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode/301/CO_SDOclient.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode_stm32/CO_app_STM32.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode_stm32/CO_driver_STM32.c
#         ${CMAKE_CURRENT_SOURCE_DIR}/canopennode_stm32/CO_storageBlank.c
#         ${CMAKE_SOURCE_DIR}/objdict/OD.c
# )

set(STM_HAL_DEVICE "STM32F103xB")
set(STM_USE_HAL_DRIVER true)
set(STM_USE_FULL_LL_DRIVER true)
set(STM_USE_FULL_ASSERT false)

target_compile_definitions(${MY_TARGET} PUBLIC ${STM_HAL_DEVICE})
target_compile_definitions(${MY_TARGET} PUBLIC ${STM_USE_HAL_DRIVER})
target_compile_definitions(${MY_TARGET} PUBLIC ${STM_USE_FULL_LL_DRIVER})
target_compile_definitions(${MY_TARGET} PUBLIC ${STM_USE_FULL_ASSERT})

add_subdirectory(stm32f103)

target_link_options(${MY_TARGET} PRIVATE -T${LINKER_SCRIPT})
target_link_options(${MY_TARGET} PRIVATE -Wl,-Map=${MY_TARGET}.map)
target_link_libraries(${MY_TARGET} stm32f103-hal ${EXTERNAL_LIBRARIES})
