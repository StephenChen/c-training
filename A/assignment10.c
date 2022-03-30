#include <stdio.h>

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("The array1 has %d elements.\n", sizeof(array));
    printf("The array2 has %d elements.\n", sizeof(array[0]));
    printf("The array3 has %d elements.\n", sizeof(array) / sizeof(array[0]));

    return 0;
}
