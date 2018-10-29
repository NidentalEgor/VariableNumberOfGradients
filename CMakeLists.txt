cmake_minimum_required (VERSION 3.5)
project (VariableNumberOfGradients)

# only for gcc
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++14 -pthread -rdynamic")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Lib)

add_executable(VNG Main.cpp Src/VNG.cpp Inc/VNG.h Inc/Logger.h)

target_link_libraries(VNG EasyBMP)