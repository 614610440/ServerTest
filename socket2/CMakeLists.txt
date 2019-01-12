#cmake_minimum_required(VERSION 3.10)
project(socket_test2)

find_package(Threads)

add_executable(server src/server.cpp)
add_executable(client src/client.cpp)

add_executable(my_server src/my_server.cpp)
add_executable(my_client src/my_client.cpp)

add_executable(server2 src/server2.cpp)
add_executable(client2 src/client2.cpp)

add_executable(server3 src/server3.cpp)
add_executable(client3 src/client3.cpp)

add_executable(server4 src/server4.cpp)
add_executable(client4 src/client4.cpp)

add_executable(server5 src/server5.cpp)
target_link_libraries(server5 ${CMAKE_THREAD_LIBS_INIT})