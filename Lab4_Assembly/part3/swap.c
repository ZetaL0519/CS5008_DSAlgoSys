// Write a C program that swaps two integers in a function
void swap_int(int *a, int *b){
    int t0 = *a;
    int t1 = *b;
    *a = t1;
    *b = t0;
}