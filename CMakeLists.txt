cmake_minimum_required(VERSION 3.29)
project(airport_booking_system)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 11)

add_executable(airport_booking_system src/main.cpp
        src/Ticket.cpp
        src/Airplane.cpp
        src/Registry.cpp
        src/FileReader.cpp
        src/CommandPerformer.cpp
        src/CLI.cpp)
