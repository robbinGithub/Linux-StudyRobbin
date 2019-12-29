cmake_minimum_required(VERSION 3.6)
project(untitled C)

set(CMAKE_C_STANDARD 99)

find_package(Threads)
if(THREADS_FOUND)
  message(STATUS "found threads")
endif()


#add_executable(untitled server.c client.c tcp6.c remove_zone.c)
add_executable(echo_mpserv echo_mpserv.c)
add_executable(echo_mpclient echo_mpclient.c)
add_executable(pipe1 pipe1.c)
add_executable(pipe2 pipe2.c)
add_executable(chat_serv chat_serv.c)
add_executable(chat_clnt chat_clnt.c)
add_executable(echo_EPLTserv echo_EPLTserv.c)
add_executable(echo_EPETserv echo_EPETserv.c)
target_link_libraries(chat_serv ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(chat_clnt ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(echo_EPLTserv ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(echo_EPETserv ${CMAKE_THREAD_LIBS_INIT})
