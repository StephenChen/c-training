#include <stdio.h>

void hello1(void) {
    char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33};

    printf("%s", array);
}

void hello2(void) {
    char array[] = {72, 101, 108, 108, 111, 44, 32, 87, 111, 114, 108, 100, 33, '\0'};

    printf("%s", array);
}

int main(void) {
    hello1();
    printf("\n");
    hello2();
}