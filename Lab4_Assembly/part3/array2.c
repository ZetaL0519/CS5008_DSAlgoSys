#include <stdlib.h>
// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.
int main() {
    int* array = (int*) malloc(sizeof(int) * 400);
    array[10] = 121;
    array[20] = 484;
    array[30] = 878;
    array[380] = 8888;
    array[398] = 9999;
    array[399] = '\0';
    free(array);
    return 0;
}