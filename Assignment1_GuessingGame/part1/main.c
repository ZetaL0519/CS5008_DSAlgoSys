#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count[5];

int randint(){
	time_t t;

   /* Intializes random number generator */
	srand((unsigned) time(&t));
    int target = rand() % 10 + 1;
    return target;
}

void resultshow(int testnum, int target){
    if (testnum == target){
        printf("You got it!\n");
    }
    else if (testnum > target){
        printf("No guess lower!\n");
    }else{
        printf("No guess higher!\n");
    }
}

int processguess(){
    int guess = 0;
    int testnum = 0;
    int target = randint();
    while (target != testnum){
        printf("Make a guess: ");
        scanf("%d", &testnum); 
        resultshow(testnum, target);
        guess ++;
    }
    return guess;
}

int main(){
    
    int i, j;
    for (i = 0; i < 5; i ++){
        printf("============================\n");
        printf("CPU Says: Pick a number 1-10\n"); 
        printf("============================\n");
        count[i] = processguess();
    }

    printf("============================================\n");
    printf("Here are the results of your guessing abilities\n"); 
    printf("=============================================\n");

    for (j = 0; j < 5; j ++){
        printf("Game %d took you %d guesses\n", j, count[j]);

    }
    
    return 0;
}
