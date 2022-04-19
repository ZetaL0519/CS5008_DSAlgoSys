// Include our header file for our my_bst.c
#include "my_bst.h"

// Include any other libraries needed
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
bst_t* bst_create(){
    // Modify the body of this function as needed.
    bst_t* myBST= (bst_t*)malloc(sizeof(bst_t)); 
    myBST ->size = 0;
    myBST ->root = NULL;
    return myBST;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(bst_t* t){
    if (t -> root == NULL) {
        return 1;
    }

    return 0;
}

// Create a new bstnode_t
bstnode_t* new_node(int item) {
    bstnode_t* t = (bstnode_t*)malloc(sizeof(bstnode_t));
    t ->data = item;
    t ->leftChild = NULL;
    t ->rightChild = NULL;
    return t;
}

// Use recursion to add new node to existing binary tree.
bstnode_t* bst_addnode(bstnode_t* t, int item){
    if (t == NULL) {
        t = new_node(item);
        return t;
    } else {
        if (item <= t ->data) {
            t ->leftChild = bst_addnode(t ->leftChild, item);
        } else {
            t ->rightChild =bst_addnode(t ->rightChild, item);
        }
    }
}
// Adds a new node containng item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive imlementation is suggested.
int bst_add(bst_t* t, int item) {
    if (t->root == NULL) {
        bstnode_t* newT = (bstnode_t*)malloc(sizeof(bstnode_t));
        newT ->data = item;
        newT ->leftChild = NULL;
        newT ->rightChild = NULL;
        t ->root = newT;
        t ->size += 1;
        return 1;
    } else {
        bstnode_t* p = bst_addnode(t ->root, item);
        if (p == NULL) {
            return -1;
        }
        t ->size += 1;
        return 1;
    }
}

// Use Inorder traversal to print ascending order tree node value.
void bst_printnodeASC(bstnode_t *t) {
    if (t == NULL) {
        return;
    }

    bst_printnodeASC(t->leftChild);
    printf("%d", t->data);
    bst_printnodeASC(t->rightChild);

}

// Use post order traversal to print descending order tree node value.
void bst_printnodeDES(bstnode_t *t) {
    if (t == NULL) {
        return;
    }

    bst_printnodeDES(t->rightChild);
    bst_printnodeDES(t->leftChild);
    printf("%d", t->data);
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree -- print "(NULL)".
// It should run in O(n) time.
void bst_print(bst_t *t, int order){
    if(NULL == t){
        printf("(NULL)");
        return;
    }else{
        if (order == 0) {
            bst_printnodeASC(t->root);
        } else {
            bst_printnodeDES(t ->root);
        }
    }
}

// Use recursion to add up all the node value.
int bst_sumnode(bstnode_t *t) {
    if (t == NULL) {
        return 0;
    }
    int data = t -> data;
    int right = bst_sumnode(t ->rightChild);
    int left = bst_sumnode(t ->leftChild);
    int res = data + right + left;
    return res;
}

// Returns the sum of all the nodes in the bst. 
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(bst_t *t){
    if (t == NULL) {
        exit(0);
    } 
    return bst_sumnode(t ->root);
}

bstnode_t* bst_findnode(bstnode_t *t, int value) {
    if (t ->data == value || t == NULL) {
        return t;
    }

    else if (value > t ->data) {
        return bst_findnode(t->rightChild, value);
    } else {
        return bst_findnode(t->leftChild, value);
    }
}

// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(bst_t *t, int value){
    if (t == NULL){
        exit(0);
    }
    if (bst_findnode(t ->root, value) == NULL) {
        return 0;
    }
    return 1;
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(bst_t* t){
    if (t == NULL){
        exit(0);
    }
    return t->size;
}

// Free all the node with ascending order.
void bst_freenode(bstnode_t *t) {
    if (t != NULL) {
        bst_freenode(t ->rightChild);
        bst_freenode(t ->leftChild);
        free(t);
    }
}

// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the proram terminates.
void bst_free(bst_t* t){
    bst_freenode(t ->root);
    free(t);
}

