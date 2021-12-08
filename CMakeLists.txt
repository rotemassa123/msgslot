cmake_minimum_required(VERSION 3.20)
project(msgslot C)

set(CMAKE_C_STANDARD 99)

add_executable(msgslot main.c message_slot.c message_slot.h message_reader.c message_sender.c)
include_directories(/usr/src/linux-headers-5.0.0-32/include)