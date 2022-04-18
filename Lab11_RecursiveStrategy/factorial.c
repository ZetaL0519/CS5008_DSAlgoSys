// gcc factorial.c -o factorial
// ./factorial

#include <stdio.h>

// TODO: Implement iterative solution here
long long int factorial(int n){
  long long int res = 1;
  while (n >= 1) {
    res = res * n;
    n = n - 1;
  }
  return res;
};

// TODO: Implement recursive solution here
long long int factorial_rec(int n){

  if (n <= 1) return 1;

  return factorial_rec(n - 1) * n;

}

int main(){

  int calc = 21; 
  // Both of these should print the same result!
  printf("factorial(%d) = %lld\n",calc, factorial(calc));
  printf("factorial_rec(%d) = %lld\n",calc, factorial_rec(calc));


  return 0;
}
