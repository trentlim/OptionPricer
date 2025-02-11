cmake_minimum_required(VERSION 3.31.0)
project(option_pricer VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")

add_executable(MyApp ${SOURCES} ${HEADERS})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(
-Wshadow,
-Werror,
-Werror=vla,
-fdiagnostics-color=always,
-ggdb,
-pedantic-errors,
-Wall,
-Weffc++,
-WConversion,
-Wsign-conversion
)
