#include <stdio.h>
#include <sys/types.h>	// Includes some new data types (e.g. pid_t)
#include <unistd.h>	// This is a new library that includes various unix system calls.

int main(){
	alarm(180); // Please leave in this line as the first statement in your program.
		    // This will terminate your program after 180 seconds,
		    // and is useful in the case that you accidently leave a bunch of running processe
       
	// Variable to store the process id
	pid_t pid;
	// Variable 'x' allocated on the stack
	int x = 1;

	// pid returns the child process id.
	// o if it is the child
	// > 0 is the process id of the child which the parent receices
	pid = fork();

	if(pid==0){
		// Note: pre-increment '++x' adds 1 to x before printing.
		printf("child: x=%d\n", ++x);
		return 0;
	}

	// Parent process executing
	// Node: The 'pre-decrement' '--x' subtracts 1 from x before printing
	printf("parent: x=%d\n", --x);

	return 0;
}         
