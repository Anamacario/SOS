# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico CACHE STRING "Board type")

# Nome do projeto
cmake_minimum_required(VERSION 3.13)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(sos)

# Inicializa o SDK do Pico
pico_sdk_init()

# Adiciona o arquivo main.c ao projeto
add_executable(sos sos.c)

# Linka bibliotecas necessárias
target_link_libraries(sos pico_stdlib)

# Habilita a saída USB (para debug, opcional)
pico_enable_stdio_usb(sos 1)
pico_enable_stdio_uart(sos 0)

# Cria o arquivo .uf2 para carregar na Pico
pico_add_extra_outputs(sos)
