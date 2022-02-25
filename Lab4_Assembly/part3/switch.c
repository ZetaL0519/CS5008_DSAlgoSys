#include <stdio.h>
 
int main () {

   int grade = 70;

   switch(grade) {
      case 90 :
         printf("Excellent!\n" );
         break;
      case 80 :
         printf("Good job!\n" );
         break;
      case 70 :
         printf("Well done\n" );
         break;
      case 60 :
         printf("You passed\n" );
         break;
      case 50 :
         printf("Better try again\n" );
         break;
      default :
         printf("Invalid grade\n" );
   }
   
   printf("Your grade is  %d\n", grade );
 
   return 0;
}
