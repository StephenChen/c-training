project(B)

add_executable(B tcp.c)
add_executable(03-server 03-tcp-ip-client-server/server.c)
add_executable(03-client 03-tcp-ip-client-server/client.c)
add_executable(04-server 04-udp-echo-client-server/server.c)
add_executable(04-client 04-udp-echo-client-server/client.c)
