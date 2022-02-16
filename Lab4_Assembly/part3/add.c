// Write a C program that calls an add function(long add(long a, long b).
#include <stdio.h>

long add(long a, long b) {
    return a + b;
}

int main() {
    printf("%d", add(1, 2));
    return 0;
}