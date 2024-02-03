cmake_minimum_required(VERSION 3.15)

project(FreeRTOS)

file(GLOB FREE_RTOS_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.c) # Add all .c files in the current directory to the sources

add_library(FreeRTOS STATIC ${FREE_RTOS_SOURCES} 
                        # heap
                        ${CMAKE_CURRENT_SOURCE_DIR}/portable/MemMang/heap_4.c
                        ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/ARM_CM0/port.c
                        )

target_include_directories(FreeRTOS PUBLIC 
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include
                                    ${CMAKE_CURRENT_SOURCE_DIR}/portable/GCC/ARM_CM0
                                    ${FREE_RTOS_CONFIG_DIR}
                                    )