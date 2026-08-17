cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/lib")

project(CLIAnimator)

set(SFML_DIR "D:/Programing/Libs/SFML/MinGW/SFML-3.0.2/lib/cmake/SFML")
find_package(SFML 3.0 REQUIRED COMPONENTS Graphics Window Audio)

set(SOURCES src/clianimator.cpp)

# .exe-s
# CliAnimator.EXE
add_executable(EXECliAnimator src/clianimator.cpp)
set_target_properties(EXECliAnimator PROPERTIES OUTPUT_NAME "clianimator")

target_link_libraries(EXECliAnimator PRIVATE 
    SFML::Graphics 
    SFML::Window 
    SFML::Audio
)

target_include_directories(EXECliAnimator PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")


