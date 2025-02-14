cmake_minimum_required(VERSION 3.31.0)
project(OptionPricer VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(OptionPricer/instruments)
include_directories(OptionPricer/pricing)
include_directories(OptionPricer/utils)

file(GLOB APP_SOURCES "OptionPricer/*.cpp")
file(GLOB INSTRUMENTS_SOURCES "OptionPricer/instruments/*.cpp")

file(GLOB INSTRUMENTS_HEADERS "OptionPricer/instruments/*.h")
file(GLOB UTILS_HEADERS "OptionPricer/utils/*.h")
file(GLOB PRICING_HEADERS "OptionPricer/pricing/*.h")

add_executable(OptionPricer 
    ${APP_SOURCES} 
    ${INSTRUMENTS_SOURCES} 
    ${INSTRUMENTS_HEADERS}
    ${UTILS_HEADERS}
    ${PRICING_HEADERS}
)


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
