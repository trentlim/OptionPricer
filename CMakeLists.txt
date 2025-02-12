cmake_minimum_required(VERSION 3.31.0)
project(option_pricer VERSION 0.1.0 LANGUAGES C CXX)

include_directories(option_pricer/instruments)
include_directories(option_pricer/utils)

file(GLOB APP_SOURCES "option_pricer/*.cpp")

file(GLOB INSTRUMENTS_HEADERS "option_pricer/instruments/*.h")
file(GLOB UTILS_HEADERS "option_pricer/utils/*.h")
file(GLOB PRICING_HEADERS "option_pricer/pricing/*.h")

add_executable(OptionPricer 
    ${APP_SOURCES} 
    ${INSTRUMENTS_HEADERS}
    ${UTILS_HEADERS}
    ${PRICING_HEADERS}
)

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
