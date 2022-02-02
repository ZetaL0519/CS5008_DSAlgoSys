#include <stdlib.h>  // Include for malloc/free and NULL

#include "stack_t.h" // Include our function declarations and data types


// Creates a stack
stack_t* create_stack(unsigned int capacity){
	// Modify the body of this function as needed.
	stack_t* myStack = (stack_t*) malloc(sizeof(stack_t));	
	myStack ->capacity = capacity;
	myStack ->head = NULL;
	myStack -> count = 0;
	return myStack;
}

// Stack Empty
int stack_empty(stack_t* s){
	int size;
	size = s ->count;
	if (size > 0) {
		return 0;
	}
	return 1;
}

// Stack Full
int stack_full(stack_t* s){
	int max = s ->capacity;
	if (stack_size(s) < max) {
		return 0;
	}
	return 1;
}

// Enqueue a new item
int stack_enqueue(stack_t* s, int item){
	if (stack_full(s) == 1){
		return -1;
	} else {
		node_t* head = s -> head;
		node_t* node = (node_t*)malloc(sizeof(node_t));
		node ->data = item;
		node ->next = head;
		s->head = node;
		s ->count = stack_size(s) + 1;
		return 0;
	}

// Note: you should have two return statements in this function.
}

// Dequeue an item
int stack_dequeue(stack_t* s){
	if (stack_empty(s)){
		exit(1);
	}
	int headvalue;
	node_t* head = s -> head;
	headvalue = head ->data;
	node_t* node = head -> next;
	s -> head = node;
	s ->count = stack_size(s) - 1;
	return headvalue;
}

// Stack Size
unsigned int stack_size(stack_t* s){
	unsigned int size;
	size = s -> count;
	return size;
}

// Free stack
void free_stack(stack_t* s){
	node_t* head = s->head;
	if (head == NULL) {
		free(s);
		return;
	}

	while (head != NULL) {
		free(head);
		stack_dequeue(s);
		head = head -> next;
		s ->count = stack_size(s) - 1;
	}
	free(s);
}



