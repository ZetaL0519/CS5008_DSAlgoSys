// gcc vfork.c -o vfork
// this program spawns 8 child processes
// print out all of the pids.
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int colors[64][64 * 3];

void paint(int workID){ 
	printf("Artist %d is painting\n",workID);
	// randomly choose a color
	int ColorID = rand() % 255;
	int i = 0;
	for (; i < 64 * 3; i ++){
		colors[workID][i] = ColorID;
	}
}

int save(){
	FILE *fp;
	fp = fopen("vfork.ppm", "w+");
	fputs("P3\n", fp);
	fputs("64 64\n", fp);
	fputs("255\n", fp);
	int i;
	int j;
	for(i = 0; i < 64; i ++){
		for (j = 0; j < 64 * 3; j ++){
			fprintf(fp, "%d", colors[i][j]);
			fputs(" ", fp);
		}
		fputs("\n", fp);
	}
	fclose(fp);
	return 1;
}


int main(int argc, char** argv){
   	int* integers = malloc(sizeof(int)*8000);
    int numberOfArtists = 64; // 64 child processes
	srand(time(NULL));
   	pid_t pid;
  
    // main loop where we fork new threads
   	int i = 0;
   	for(; i < numberOfArtists; i++){
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
	
	pid_t wpid;
	int status = 0;
	while((wpid = wait(&status)) > 0);

        printf("parent is exiting(last artist out!)\n");
	
	save();	
	free(integers);
	return 0;
}
