cmake_minimum_required(VERSION 3.15)
project(DataStructures C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructures main.c main.h global.c global.h Queue/Queue.c Queue/Queue.h Queue/OperationsQueue.c Stack/Stack.c Stack/Stack.h Stack/OperationsStack.c Hash/hash.c Hash/hash.h Hash/OperationsHash.c)