// Compile with     : gcc -g -Wall bug1.c -o prog
// Run and debugwith: gdb ./prog
// Check with       : valgrind ./prog
// 
// Fix the bugs so that the report of 5 students grades
// is correct. There should be no memory leaks.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct student{
    int grade;
    char* nameID;
}student_t;

void CreateStudent(student_t* s, int grade, char* nameID){
    s->grade = grade;
    s->nameID = strdup(nameID); 
}

//
float ComputeAverageGrade(student_t* class, int sizeOfClass){
    assert(sizeOfClass > 0 && "Must have at least 1 student");
    float total=0.0f;

    int i;
    for(i=0; i < 5; i++){

    for(int i=0; i < 5; i++){

        total+= class[i].grade;
    }
    return total / sizeOfClass;
}

int main(){

    // Create our classroom of 5 students
    student_t* class = (student_t*)malloc(sizeof(student_t)*5);
    int i;
    for(i=0; i <5 ; i++){
        // Assume all nameID's are "temporary"
        CreateStudent(&class[i],90,"temporary");
    }

    // Storage for students grades
    float averageGrade = ComputeAverageGrade(class,5);
    printf("Class Average = %f\n\n",averageGrade);
    // Manually check our work

    int j;
    for (j=0; j <5 ; j++){
        printf("Student %d\n",j);
        printf("\tGrade: %d\n",class[j].grade);
        printf("\tID   : %s\n",class[j].nameID);
    }
    


    for(int j=0; j <5 ; j++){
        printf("Student %d\n",j);
        printf("\tGrade: %d\n",class[j].grade);
        printf("\tID   : %s\n",class[j].nameID);
        free(class[j].nameID);
    }


    free(class);
    return 0;
}
