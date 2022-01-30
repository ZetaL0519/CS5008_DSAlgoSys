// Modify this file
// compile with: gcc main.c linkedlist.c -o prog

#include <stdio.h>

#include "linkedlist.h"

/* Linked list to exercise creating 5 elements */
void unitTest1(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedListOfFiveItems();
    // Print out our list so we can verify the contents
    PrintLinkedList(myList);
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

/* Linked list to exercise appending to an empty linked list */
void unitTest2(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedList();
    // Append one item to our list
    AppendToLinkedList(myList,42);
    // Print out our list to verify the contents
    PrintLinkedList(myList);
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

/* Linked list to exercise creating and deleting an empty list*/
void unitTest3(){
    // Create our linked list
    linkedlist_t* myList = CreateLinkedList();
    // Free our list when we are done
    // This frees the 'heap' memory
    FreeLinkedList(myList);
}

/* Create a linked list with more than 10 elements*/
void unitTest4(){
    // Create an empty list
    linkedlist_t* myList = CreateLinkedList();
    // Append more than 10 elements to the list
    AppendToLinkedList(myList, 3);
    AppendToLinkedList(myList, 4);
    AppendToLinkedList(myList, 5);
    AppendToLinkedList(myList, 6);
    AppendToLinkedList(myList, 7);
    AppendToLinkedList(myList, 8);
    AppendToLinkedList(myList, 9);
    AppendToLinkedList(myList, 10);
    AppendToLinkedList(myList, 11);
    AppendToLinkedList(myList, 12);
    AppendToLinkedList(myList, 13);
    AppendToLinkedList(myList, 14);
    // Print the list
    PrintLinkedList(myList);
    // Free the 'heap' memory
    FreeLinkedList(myList);
}

int main(){
  
    // Call our unit Test. A unit test is a test that
    // exercises some functionality in our program, often
    // a feature or short sequence of events.
    unitTest1();
    // Call another unit test
    unitTest2();
    // Call another unit test
    unitTest3();
    // Call another unit test
    unitTest4();
    return 0;
}
