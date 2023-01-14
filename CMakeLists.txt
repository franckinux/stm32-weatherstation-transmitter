cmake_minimum_required(VERSION 3.22)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/toolchain-gcc-cortex-m3.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(transmitter)
set(CMAKE_EXECUTABLE_SUFFIX_C .elf CACHE STRING "")
enable_language(C ASM)

set(MY_TARGET "${PROJECT_NAME}-firmware")
add_executable(${MY_TARGET})

add_compile_definitions(ATSAMD51N20A)

set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/src/stm32f103/STM32F103C8Tx_FLASH.ld)
set(EXTERNAL_LIBRARIES "m")

add_subdirectory(src)

add_custom_command(TARGET ${MY_TARGET} POST_BUILD
    COMMAND ${CROSS_OBJDUMP} "-CdSx" $<TARGET_FILE:${MY_TARGET}> > ${MY_TARGET}.lst
    COMMENT "Generating disassembler file")
add_custom_command(TARGET ${MY_TARGET} POST_BUILD
    COMMAND ${CROSS_OBJCOPY} "-Obinary" $<TARGET_FILE:${MY_TARGET}> ${MY_TARGET}.bin
    COMMENT "Generating bin file")
add_custom_command(TARGET ${MY_TARGET} POST_BUILD
    COMMAND ${CROSS_OBJCOPY} "-Oihex" $<TARGET_FILE:${MY_TARGET}> ${MY_TARGET}.hex
    COMMENT "Generating hex file")

add_custom_target(flash
        COMMAND openocd -f ${CMAKE_SOURCE_DIR}/wch/wch-riscv.cfg
            -c init
            -c halt
            -c "flash erase_sector wch_riscv 0 last"
            -c "program $<TARGET_FILE:${MY_TARGET}> verify"
            -c wlink_reset_resume
            -c exit
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${tgt}
        COMMENT "Running openocd ${tgt_name}"
        USES_TERMINAL)
