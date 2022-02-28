#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char* argv1[24];
    char* argv2[24];
    char* argv3[24];

    argv1[0] = "/bin/ls";
    argv1[1] = NULL;

    argv2[0] = "/bin/echo";
    argv2[1] = "'testing'";
    argv2[2] = NULL;

    argv3[0] = "/bin/nl";
    argv3[1] = "example5.c";
    argv3[2] = NULL;

    char** commands[] = {argv1, argv2, argv3};
    int i;
    for (i = 0; i < 3; i ++){
	if (fork()==0){
	    printf("Running program%d\n",i);
	    exit(1);
	}else{
	    wait(NULL);
	    printf("Child Pass\n");
	}
    }
    return 0;
} 
    
