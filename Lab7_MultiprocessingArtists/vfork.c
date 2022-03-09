// Implement your part 1 solution here
// gcc vfork.c -o vfork
// this program spawns 8 child processes
// print out all of the pids.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Modify your paint function here
void paint(int workID){ 
	printf("Artist %d is painting\n",workID);
}

int main(int argc, char** argv){

    int numberOfArtists = 8; // How many child processes do we want?

	pid_t pid;
	// main loop where we fork new threads
        for(int i =0; i < numberOfArtists; i++){
                // (1) Perform a fork
                pid = vfork();
		                
                if (pid == -1){
                    printf("Fork failed");
                    exit(EXIT_FAILURE);
                }

                // (2) Make only the child do some work (i.e. paint) and then terminate.
                if(pid== 0){
			        //  make child paint
                    paint(i);
			        // Then terminate/exit child
                    exit(0);
		        }
        }

        printf("parent is exiting(last artist out!)\n");

return 0;
}