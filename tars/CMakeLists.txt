project(tars)
set(CMAKE_CXX_STANDARD 17)


include(tc_epoller.h tc_epoll_server.h)


add_executable(main main.cpp)