# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Set the pimoroni-pico path.
set(PIMORONI_PICO_PATH "${CMAKE_CURRENT_LIST_DIR}/externals/pimoroni-pico")

# Pull in Raspberry Pi Pico SDK & Pimoroni Pico SDK
include(pico_sdk_import.cmake)
include(pimoroni_pico_import.cmake)

project(mtg_damage_health_counter C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(mtg_damage_health_counter main.cpp)

# Add includes
include(common/pimoroni_i2c)
include(common/pimoroni_bus)
include(libraries/pico_display/pico_display)
include(libraries/pico_graphics/pico_graphics)
include(drivers/rgbled/rgbled)
include(drivers/st7789/st7789)
include(drivers/button/button)

pico_set_program_name(mtg_damage_health_counter "mtg_damage_health_counter")
pico_set_program_version(mtg_damage_health_counter "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(mtg_damage_health_counter 0)
pico_enable_stdio_usb(mtg_damage_health_counter 1)

# Add the standard library to the build
target_link_libraries(mtg_damage_health_counter
        pico_stdlib
        pimoroni_i2c
        pico_display
        pico_stdlib
        pico_graphics
        hardware_spi
        hardware_dma
        hardware_pwm
        hardware_pio
        st7789
        rgbled
        button
)

# Add the standard include files to the build
target_include_directories(mtg_damage_health_counter PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}
  ${CMAKE_CURRENT_LIST_DIR}/.. # for our common lwipopts or any other standard includes, if required
)

# Add any user requested libraries
target_link_libraries(mtg_damage_health_counter 
        
        )

pico_add_extra_outputs(mtg_damage_health_counter)

