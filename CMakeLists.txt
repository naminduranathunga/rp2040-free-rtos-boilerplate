cmake_minimum_required(VERSION 3.15)

# Pre project setup
include(rp-2040-config.cmake)

set(FREE_RTOS_CONFIG_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/include") # FreeRTOSConfig.h location


#############################################
# The PICO SDK
#############################################
include(${PICO_SDK_PATH}/pico_sdk_init.cmake) 
if (NOT DEFINED PICO_SDK_PATH)
    message(FATAL_ERROR "PICO_SDK_PATH not defined")
endif()
pico_sdk_init()




#############################################
# FreeRTOS
#############################################
add_subdirectory(FreeRTOS-Kernel)






#############################################
# Project setup
#############################################
project(blink_test)

include_directories(${FREE_RTOS_CONFIG_DIR})
file(GLOB SOURCES src/main.c)
add_executable(blink_test ${SOURCES})
target_link_libraries(blink_test pico_stdlib FreeRTOS)

### Enable USB for serial output
pico_enable_stdio_usb(blink_test 1)
pico_enable_stdio_uart(blink_test 0)

# add extra outputs
pico_add_extra_outputs(blink_test)