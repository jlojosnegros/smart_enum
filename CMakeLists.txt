cmake_minimum_required(VERSION 3.9)
project(smart_enums)

set(CMAKE_CXX_STANDARD 17)


set(SMART_ENUMS_SOURCES main.cpp)
set(SMART_ENUMS_HEADERS
        catch.hpp
        EnglishSuits.hpp
        smart_enum.hpp
        pointee_comparator.hpp
        )
add_executable(smart_enums ${SMART_ENUMS_SOURCES} ${SMART_ENUMS_HEADERS})