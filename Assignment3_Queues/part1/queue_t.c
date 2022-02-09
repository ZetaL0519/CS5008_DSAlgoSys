#include "queue_t.h"
#include <stdlib.h> 

// Create a queue
queue_t* create_queue(unsigned int _capacity){
	// allocate space for queue and data array.
    queue_t* queue = (queue_t*) malloc(sizeof(queue_t));
	int* data_int = (int*) malloc(_capacity * sizeof(int));
	// initialize front and back to -1.
	queue ->front = -1;
	queue ->back = -1;
	queue ->capacity = _capacity;
	queue ->size = 0;
	queue ->data = data_int;
	return queue;
}

// Queue Empty
int queue_empty(queue_t* q){
	if (q ->size == 0) {
		return 1;
	}
	return 0;
}

// Queue Full
int queue_full(queue_t* q){
	if (q ->size == q ->capacity) {
		return 1;
	}
	return 0;
}

// Enqueue a new item
int queue_enqueue(queue_t* q, int item){
	if (queue_full(q) == 1) {
		return -1;
	}
	else {
		unsigned int tail;
		unsigned int capacity;
		tail = q -> back;
		capacity = q -> capacity;
		int* data_int;
		data_int = q ->data;
		// store item in the according position in data array.
		data_int[(tail + 1) % capacity] = item;
		// update tail and back
		tail = (tail + 1) % capacity;
		q -> back = tail;
		q ->size ++;
		return 0;
	}
}

// Dequeue an item
int queue_dequeue(queue_t *q){
	if (queue_empty(q) == 1) {
		exit(1);
	}
	else {
		unsigned int head;
		unsigned int capacity;
		head = q -> front;
		capacity = q -> capacity;
		int* data_int;
		data_int = q ->data;
		int item;
		// find the item in data array.
		item = data_int[head % capacity];
		// clear the array position.
		data_int[head % capacity] = -1;
		head = (head + 1) % capacity;
		q -> front = head;
		q ->size --;
		return item;
	}
}


// Queue Size
unsigned int queue_size(queue_t* q){
	unsigned int s;
	s = q ->size;
	return s;
}


// Free queue
void free_queue(queue_t* q){
	if (q) {
		int* data;
		data = q ->data;
		free(data);
		free(q);
	}
}
