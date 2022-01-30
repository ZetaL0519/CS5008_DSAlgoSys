// In this file you will implement the 
// 'Function definitions'
// Recall, function definitions are the implementations
// of all of the function 'declarations' in our linkedlist.h
#include <stdio.h>
#include <stdlib.h>     // Included for malloc/free
#include "linkedlist.h"


linkedlist_t* CreateLinkedListOfFiveItems() {
    // Create an empty linkedlist
    linkedlist_t* mylist_5 = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    // Create five nodes
    node_t* node_1 = (node_t*)malloc(sizeof(node_t));
    node_t* node_2 = (node_t*)malloc(sizeof(node_t));
    node_t* node_3 = (node_t*)malloc(sizeof(node_t));
    node_t* node_4 = (node_t*)malloc(sizeof(node_t));
    node_t* node_5 = (node_t*)malloc(sizeof(node_t));
    // Link head with node value and point to the next node
    mylist_5 -> head = node_1;
    node_1 -> data = 1;
    node_1 -> next = node_2;
    node_2 -> data = 2;
    node_2 -> next = node_3;
    node_3 -> data = 3;
    node_3 -> next = node_4;    
    node_4 -> data = 4;
    node_4 -> next = node_5;
    node_5 -> data = 5;
    // The last node leads to NULL
    node_5 -> next = NULL;
    return mylist_5; 
}

/* Create an empty linkedlist */
linkedlist_t* CreateLinkedList(){
    // Create an emtpy list
    linkedlist_t* mylist = (linkedlist_t*)malloc(sizeof(linkedlist_t));
    // The list leads to a NULL head    
    mylist -> head =NULL;
    return mylist; 
}

/* Print every node value in linkedlist */
void PrintLinkedList(linkedlist_t* list){
    // Create a head node
    node_t* node = list ->head;
    // Iterate through all nodes
    while(node != NULL) {
        printf("%d\n", node ->data);
        node = node ->next;
    }
}

/* Free node and linkedlist */
void FreeLinkedList(linkedlist_t* list){
    // Create a head node
    node_t* node = list ->head;
    // If head node is null, free and return
    if (node == NULL){
        free(list);
        return;
    }
    // Iterate through all nodes and free each
    while(node != NULL){
        free(node);
        node = node -> next;
    }
    // Free the list space
    free(list);
}

/* append new element to the end of linked list */
void AppendToLinkedList(linkedlist_t* list, int data){
    // if linked list is null, data is the head node value
    if (list -> head == NULL){
        node_t* newnode = (node_t*) malloc(sizeof(node_t));
        newnode ->data = data;
        newnode ->next = NULL;
        list ->head = newnode;
    }else{
        // if not, iterate through the list to find the last element
        node_t* iter = list ->head;
        while(iter ->next != NULL){
            iter = iter->next;
        }
        node_t* newnode = (node_t*)malloc(sizeof(node_t));
        newnode ->data = data;
        newnode ->next = NULL;
        iter ->next = newnode;
    }
    
}
