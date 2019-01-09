cmake_minimum_required(VERSION 3.10)
Project(Server)

find_package(Threads)

add_executable(server src/server.cpp)
target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})