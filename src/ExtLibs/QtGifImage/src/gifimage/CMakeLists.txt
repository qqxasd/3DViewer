cmake_minimum_required(VERSION 3.14)

project(gifimage LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)
add_subdirectory(giflib)
add_library(gifimage STATIC
       # qgifglobal.h
        #qgifimage_p.h
	qgifimage.cpp 
        #qgifimage.h
      #  giflib/dgif_lib.c
      #  giflib/egif_lib.c
      #  giflib/gif_err.c
      #  giflib/gif_font.c
      #  giflib/gif_hash.c
       # gif_hash.h
       # gif_lib_private.h
     #   giflib/gifalloc.c
       # giflib/quantize.c
)

target_link_libraries(gifimage PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui gif_lib)
target_include_directories(gifimage INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

