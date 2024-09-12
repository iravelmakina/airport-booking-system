cmake_minimum_required(VERSION 3.29)
project(airport_booking_system)

set(CMAKE_CXX_STANDARD 11)

add_executable(airport_booking_system main.cpp
        Airplane.cpp
        Airplane.cpp
        Ticket.h
        Ticket.cpp
        Registry.h
        Registry.cpp
        CommandPerformer.h
        CommandPerformer.cpp
        FileReader.h
        FileReader.cpp
        CLI.h
        CLI.cpp)
