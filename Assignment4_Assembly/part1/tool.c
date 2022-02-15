// SIYUE LI
// CS5008 Spring 2022
// Homework 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	// Initialize count of commands.
	int count_add = 0;
	int count_mov = 0;
	int count_push = 0;
	int count_sub = 0;
	int count_mul = 0;
	int count_div = 0;
 	int count_lea = 0;
	int count_pop = 0;
	int count_ret = 0;
	
	char assembly[255];
	
	FILE* myFile = fopen(argv[1], "r");
	// Exit the program if file doesn't exist.
	if (NULL == myFile) {
        fprintf(stderr,"barebones.s not found\n");
        fprintf(stderr,"Program terminating now...\n");
		exit(1);
	}

	// Read the assembly file command.
	while(fscanf(myFile, "%s", assembly) != EOF) {

		if(strstr(assembly, "add")) {
			count_add ++;
		} else if (strstr(assembly, "mov")) {
			count_mov++;
		} else if (strstr(assembly, "push")) {
			count_push ++;
		} else if (strstr(assembly, "sub")) {
			count_sub ++;
		} else if (strstr(assembly, "mul")) {
			count_mul ++;
		} else if (strstr(assembly, "div")) {
			count_div ++;
		} else if (strstr(assembly, "lea")) {
			count_lea ++;
		} else if (strstr(assembly, "pop")) {
			count_pop ++;
		} else if (strstr(assembly, "ret")) {
			count_ret ++;
		}
	}
	fclose(myFile);
	
	// Print the count of commands.
	if(count_add > 0) {
		printf("ADD %d \n", count_add);
	}
	if(count_mov > 0) {
		printf("MOV %d \n", count_mov);
	}
	if(count_push > 0) {
		printf("PUSH %d \n", count_push);
	} 
	if(count_sub > 0) {
		printf("SUB %d \n", count_sub);
	}
	if(count_mul > 0) {
		printf("MUL %d \n", count_mul);
	}
	if(count_div > 0) {
		printf("DIV %d \n", count_div);
	}
	if(count_lea > 0) {
		printf("LEA %d \n", count_lea);
	}
	if(count_pop > 0) {
		printf("POP %d \n", count_pop);
	}
	if(count_ret > 0) {
		printf("RET %d \n", count_ret);
	}
	printf("\n");

	// Calculate and print the total instructions.
	printf("Total instructions = %d\n", count_add + count_mov + count_push + count_sub + count_mul + count_div + count_lea 
		+ count_pop + count_ret);	
	
	// Calculate and print the total cycles.
	printf("Total cycles = %d\n", (count_add * 1) + (count_mov * 1) + (count_push * 1) + (count_sub * 1) + (count_mul * 2) + 
	(count_div * 4) + (count_lea * 1) + (count_pop * 1) + (count_ret * 1));
	
	return 0;
} 
