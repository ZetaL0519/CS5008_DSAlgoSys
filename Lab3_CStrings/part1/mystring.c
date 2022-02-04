#include <stdlib.h> // malloc/free and NULL

// Include the declarations of our string functions
#include "mystring.h"

// return the length of string input
size_t my_strlen(const char* input){
    size_t length = 0;
    while(*input != '\0'){
        length ++;
        *input ++;
    }
    return length;   
}

// compare two strings
// if they are the same, return 0
// it src1 is larger, return > 0; src1 smaller, return <0
int my_strcmp(const char* src1, const char* src2){
    while (*src1 != '\0' && *src2 != '\0'){
        if (*src1 != *src2){
            break;
        }
        *src1 ++;
        *src2 ++;
    }
    return *(const unsigned char*)src1 - *(const unsigned char*)src2;   
}

// return the first character c that appears in src1
char* my_strchr(const char* src1, int c){
    while (*src1 != c && *src1 != '\0'){
        *src1 ++;
    }
    if (*src1 == c){
        return (char*)src1;
    }
    return NULL;   
}

// search: 'man strcat' to see what function should do
// Note: Our 'string append' is going to be slightly different
//       than 'strcat'. 
//       I would like you to return a 'heap allocated' string
//       that appends both of src1 and src2 into a new buffer
char* my_string_append(const char* src1, const char* src2){
    char* res = (char*) malloc(my_strlen(src1) + my_strlen(src2));
    int i = 0;
    while (*src1 != '\0'){
        res[i ++] = *src1++;
    }
    while (*src2 != '\0'){
        res[i ++] = *src2++;
    }
    res[i] = '\0';
    return res;   
}
