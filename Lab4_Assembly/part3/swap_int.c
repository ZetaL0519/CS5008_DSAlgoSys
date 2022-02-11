#include <stdio.h>
#include <stdlib.h>
int main() {
    int a = 1;
    int b = 2;
    int temp;
    temp = a;
    a = b;
    b = temp; 
    printf("%d", a);
    printf("%d", b);
    return 1;
}