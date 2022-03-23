#include <stdio.h>
#include <sys/socket.h>

int main() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    bind(fd, ...);
    listen(fd, 128);
    accept(fd, ...);
    return 0;
}
