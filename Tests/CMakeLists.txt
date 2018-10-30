enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/Lib/googletest/googletest/include)
include_directories(${PROJECT_SOURCE_DIR}/Inc)

add_executable(Tests
    ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp)

target_link_libraries(Tests GoogleTest VNG_lib)