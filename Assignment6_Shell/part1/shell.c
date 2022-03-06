#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_BUFFER_SIZE 80
#define MAX_HIST_CMD 100

// global variable to keep record of Commands.
char* builtInCmd[] = {"cd","help","exit","history"};
char* hisCmd[MAX_HIST_CMD];
int last_hist = 0;

// signal handler to interrupt the process
void sigint_handler(int sig){
	write(1, "\nmini-shell terminated!\n", 25);
	exit(0);
}

// cd command to change the directory.
int cd_Cmd(char** args) {
	// if cd has nothing after.
  	if (args[1] == NULL) {
		fprintf(stderr, "Nothing after cd command \n");
	}else{
		if (chdir(args[1]) != 0) {
	        	perror("Cannot find directory");
		}
	}
	return 1;
}

// help command to print all built-in commands.
void help_Cmd() {
	printf("Siyue's mini-shell\n");
	printf("Type a program name and arguments\n");
	printf("Built-in commands are:\n");
	int i = 0;
	for (;i < 4; i ++){
		printf("%s\n",builtInCmd[i]);
	}
}	

// add to history command array.
void add_hist(char* line){
	// won't add to the array if input logs over 100.
	if (last_hist > MAX_HIST_CMD){
		return;
	}
	hisCmd[last_hist] = strdup(line);
	last_hist ++;	
}

// history command to print out the history commands.
void hist_Cmd(){
	int i = 0;
	printf("Below are the history commands\n");
	for (;i < last_hist; i++) {
		printf("%s\n", hisCmd[i]);
	}
}

// find the index of seperation symbol.
int find_pipe(char** arg) {
        int i = 0;
        while(arg[i]) {
       		if (strcmp(arg[i], "|") == 0) {
	   			return i;
        	}
        	i ++;
    	}
   	return -1;
}

// put the tokens into the first command array.
char** PrePipeCmd(char** arg) {
  	int index = find_pipe(arg); 
	// store the array of strings for the first command
  	char** result = malloc(sizeof(char*) * MAX_BUFFER_SIZE); 
  	int i;

  	for (i = 0; i < index; i ++) {
		result[i] = arg[i];
  	}
  	return result;
}

// put the tokens into the second command array.
char** PostPipeCmd(char** arg) {
 	int index = find_pipe(arg); 
	// store the array of strings for the second command
  	char** result = malloc(sizeof(char*) * MAX_BUFFER_SIZE);
  	int i = index + 1;
  	int j = 0;

  	while(arg[i]) {
		result[j] = arg[i];
		i++;
		j++;
  	}
  	return result;
}

// Pipe command for writing the output and reading input.
void runPipedCmd(char** arg1, char** arg2){
	int fd[2];
	pid_t id;   
    id = fork();
    if (id == -1) {
        printf("Fork failed\n");
       	exit(EXIT_FAILURE);
    } 
	else if (id == 0) {
		// VERY IMPORTANT!!!
		// pipe has to be put here
		// So that pipe can be closed.
		pipe(fd);
		pid_t pre_id;
		pre_id = fork();
		if(pre_id == 0) {
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);	
			close(fd[1]);
			execvp(arg1[0], arg1);
			printf("Command not found\n");
			exit(0);
	} 
	 // Wait until the first command process is finished
    wait(NULL);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	// Execute the second command
	execvp(arg2[0], arg2);
	printf("Command not found\n");
	exit(0);
	}
	wait(NULL);
}

// Run BuiltIn commands.
int runCmd(char** arg){
	pid_t pid;
	pid = fork();

	if (pid == -1){
		printf("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0){
		execvp(arg[0], arg);
		printf("Command not found\n");
		exit(0);
	}else{
		wait(NULL);
	}
	return 1;
}

// get input and remove \n
char* getInput(){
	char* line = malloc(MAX_BUFFER_SIZE * (sizeof(char)) + 1);
	fgets(line, MAX_BUFFER_SIZE, stdin);
	// remove last enter \n
	line = strtok(line, "\n");
	return line;
}

// tokenize the input.
char** ProcessInput(char* line){
	int i = 0;
	char** array = malloc(MAX_BUFFER_SIZE * sizeof(char*));
	// remove the space
	char* arg = strtok(line, " \t");
	// remove space of the input and put it into array.
	while(arg){
		array[i] = arg;
		arg = strtok(NULL, " \t");
		i ++;
	}
	array[i] = NULL;
    return array;
}

// process different input
void readCmd() {
	char* line = getInput();
	// if User enters nothing.
	if (line == NULL) {
		free(line);
		return;
	}
	add_hist(line);
	// in case line would change.
	char* line_copy = strdup(line);
	char** array = ProcessInput(line_copy);
	char** arg1;
	char** arg2;

	if((strcmp(array[0], "exit") == 0) && (array[1] == NULL))  {
		free(array);
		exit(0);
	} else if((strcmp(array[0], "help") == 0)) {
	  	help_Cmd();
	} else if (strcmp(array[0], "cd") == 0) {
	  	cd_Cmd(array);
    } else if ((strcmp(array[0], "history") == 0)){
		hist_Cmd();
	} else {
    	int index = find_pipe(array);
		// if | is found
    	if (index != -1) {
      		arg1 = PrePipeCmd(array);
      		arg2 = PostPipeCmd(array);
      	 	runPipedCmd(arg1, arg2);
    	} else {
      		runCmd(array);   
	 	}   
	}
	free(line);
	free(array);
}

// mian function to run the mini shell
int main(){
  alarm(180); // Please leave in this line as the first statement in your program.
              // This will terminate your shell after 180 seconds,
              // and is useful in the case that you accidently create a 'fork bomb'

  signal(SIGINT, sigint_handler);
  printf("You can only terminate by pressing Ctrl + C\n");
  while(1){
	  printf("mini-shell >> ");
	  readCmd();
  }
  return 0;
}
