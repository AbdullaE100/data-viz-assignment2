cmake_minimum_required(VERSION 3.26)
project(EmailSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(EmailSystem main.cpp
        Email.cpp
        Email.h
        Stack.cpp
        EmailManager.cpp
        EmailManager.h
        Queue.cpp
        Queue.h
        User.cpp
        User.h
        Map.cpp

)
