### PICO SDK LOCATION ###
set(PICO_SDK_PATH "../pico-sdk" CACHE STRING "Path for the Pico SDK")


### COMPILER SETTINGS ###
set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "arm-none-eabi-g++")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)