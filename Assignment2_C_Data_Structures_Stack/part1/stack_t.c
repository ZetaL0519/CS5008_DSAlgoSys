#include <stdlib.h>  // Include for malloc/free and NULL>
#include "stack_t.h" // Include our function declarations and data types


// Creates a stack
stack_t* create_stack(unsigned int capacity){
	// malloc space for stack
	stack_t* myStack = (stack_t*) malloc(sizeof(stack_t));
	// initialize all attibutes
	myStack ->capacity = capacity;
	myStack ->head = NULL;
	myStack -> count = 0;
	return myStack;
}

// Stack Empty
// if size is not empty, return 0
// else, return 1
int stack_empty(stack_t* s){
	int size;
	size = s ->count;
	if (size > 0) {
		return 0;
	}
	return 1;
}

// Stack Full
// if size is not full, return 0
// else, return 1
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
		// create new node for new item
		node_t* node = (node_t*)malloc(sizeof(node_t));
		node ->data = item;
		node ->next = head;
		s->head = node;
		s ->count ++;
		return 0;
	}
}

// Dequeue an item
// if empty, exit
int stack_dequeue(stack_t* s){
	if (stack_empty(s)){
		exit(1);
	}
	int headvalue;
	node_t* head = s -> head;
	headvalue = head -> data;
	node_t* node = head -> next;
	free(head);
	s -> head = node;
	s ->count --;
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

	node_t* next = head ->next;
	while (head != NULL) {
		free(head);
		head = next;
		if (head != NULL) {
			next = head ->next;
		}
		s ->count --;
	}
	free(s);
}



