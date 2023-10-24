cmake_minimum_required(VERSION 3.14)

project(gif_h LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(gif STATIC
    gif_lib.h
    dgif_lib.c
    egif_lib.c
    gif_err.c
    gif_font.c
    gif_hash.c
    gif_hash.h
    gif_lib_private.h
    gifalloc.c
    quantize.c
)

target_link_libraries(gif PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_include_directories(gif INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
#target_compile_definitions(gif PRIVATE GIF_LIBRARY)
