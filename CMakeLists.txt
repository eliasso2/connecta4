cmake_minimum_required(VERSION 3.29)
project(connecta4 C)

set(CMAKE_C_STANDARD 11)

add_executable(connecta4 main.c
        Node.c
        Node.h
        Partida.c
        Partida.h
        testsPartida.c
        testsPartida.h)
