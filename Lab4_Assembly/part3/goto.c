// Write a C program using the goto command and a label.
// With reference to tutorialspoint
#include <stdio.h>
 
int main () {

   /* local variable definition */
   int a = 0;

   /* do loop execution */
   LOOP: do{
      if( a == 3) {
         a = a + 1;
         goto LOOP;
      }
		
      printf("value of a: %d\n", a);
      a++;
   }while(a <= 5);
 
   return 0;
}
