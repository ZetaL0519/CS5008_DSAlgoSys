// Now modify your program to swap two long's.
#include <stdio.h>
#include <stdlib.h>
int main() {
    long a = 1;
    long b = 2;
    long temp;
    temp = a;
    a = b;
    b = temp; 
    printf("%d", a);
    printf("%d", b);
    return 1;
}
