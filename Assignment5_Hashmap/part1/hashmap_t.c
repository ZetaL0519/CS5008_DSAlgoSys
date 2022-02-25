#include "hashmap_t.h"
#include <stdio.h>

// Simple hash function that will put a key into a bucket
// You should not modify this
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
hashmap_t* hashmap_create(unsigned int _buckets){
    if (_buckets <= 0){
        return NULL;
    }

    // Allocate memory for our hashmap
    hashmap_t* map = (hashmap_t*)malloc(sizeof(hashmap_t));

    // Set the number of buckets
	map ->buckets = _buckets;
    // Initialize our array of lists for each bucket
	// Iterate through all of our buckets and set them to NULL
    map ->arrayOfLists = (node_t**)malloc(sizeof(node_t*)*_buckets);

	for(int i=0; i < _buckets; i++){
		map->arrayOfLists[i] = NULL;
	}
	// Set our function pointer to a hashing function 
	// that can hash strings into an integer which tells us
	// which 'bucket' to put in the hashmap arrayOfLists
	map->hashFunction = stringHash;
    // Return the new map that we have created
    return map;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
    if (_hashmap != NULL) {
        int _buckets;
        _buckets = _hashmap ->buckets;
        int i;
        for (i=0; i < _buckets; i ++) {
            node_t* iter = _hashmap ->arrayOfLists[i];
            node_t* tmp = iter;

            while(iter != NULL) {
                tmp = iter ->next;
                free(iter ->kv ->key);
                free(iter ->kv ->value);
                free(iter ->kv);
                free(iter);
                iter = tmp;
            }
            _hashmap ->arrayOfLists[i] = NULL;
        }
        free(_hashmap ->arrayOfLists);
        free(_hashmap);
    }
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Returns a '-9999' if the hashmap is NULL
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){
    if (_hashmap == NULL || key == NULL){
        return -9999;
    }

    unsigned int bucket = _hashmap->hashFunction(key,_hashmap->buckets);	
 	node_t* iter = _hashmap->arrayOfLists[bucket];
    while (iter != NULL){
        if (strcmp(iter ->kv ->key, key) == 0){
            return 1;
        }
        iter = iter ->next;
    }
    return 0;   
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//  - You should malloc the key/value in this function
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){
    if (key ==  NULL || value == NULL){
        return;
    }

    if(hashmap_hasKey(_hashmap, key) == 1){
        return;
    }

    pair_t* newpair = (pair_t*)malloc(sizeof(pair_t));
	newpair->key = (char*)malloc(strlen(key)*sizeof(char)+1);
	newpair->value = (char*)malloc(strlen(value)*sizeof(char)+1);
	// Copy the string 
	strcpy(newpair->key,key);
    strcpy(newpair->value,value);	
	// Create our new node
	node_t* newnode = (node_t*)malloc(sizeof(node_t));
	newnode->next = NULL;
	newnode->kv = newpair;
	// Now figure out where to put this key/value pair in
	// our hashmap
	unsigned int bucket = _hashmap->hashFunction(key,_hashmap->buckets);	

	// Create an iterator and set it to the bucket that we want
	// Then we'll iterate through this bucket to the end of the chain
	// (which remember, is just the end of the linked list)
	node_t* iter = _hashmap->arrayOfLists[bucket];
	if(iter==NULL){
		// If there is nothing in our bucket, then make this
		// the first node
		_hashmap->arrayOfLists[bucket] = newnode;
        return;
	}else{
        while(iter ->next != NULL){
            iter = iter ->next;
        }
        iter ->next = newnode;
	}
}

// Return a value from a key 
// Returns NULL if the _hashmap is NULL
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
	if (_hashmap == NULL) {
        return NULL;
    }
    unsigned int bucket = _hashmap->hashFunction(key,_hashmap->buckets);	
 	node_t* iter = _hashmap->arrayOfLists[bucket];
    while (iter != NULL){
        if (iter ->kv ->key == key){
            return iter ->kv ->value;
        }
        iter = iter ->next;
    }
    return NULL;   
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
    if (_hashmap == NULL || key == NULL) {
        return;
    }
    unsigned int bucket = _hashmap->hashFunction(key,_hashmap->buckets);
     node_t* iter = _hashmap->arrayOfLists[bucket];
    node_t* last = NULL;
    while (iter != NULL){
        if (strcmp(iter->kv->key, key) == 0){
            if (iter ->next != NULL) {
                if (!last) {
                    _hashmap->arrayOfLists[bucket] = iter->next;
                }
                else {
                    last ->next = iter ->next;
                }
            } else {
                if (!last) {
                    _hashmap->arrayOfLists[bucket] = NULL;
                }
                else {
                    last ->next = NULL;
                }
            }
            free(iter->kv->key);
            free(iter->kv->value);
            free(iter->kv);
            free(iter);
            return;
        }
        last = iter;
        iter = iter ->next;
    }
}


// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	if (_hashmap == NULL || key == NULL) {
        return;
    }
    unsigned int bucket = _hashmap->hashFunction(key,_hashmap->buckets);	
 	node_t* iter = _hashmap->arrayOfLists[bucket];
    while (iter != NULL){
        if (iter ->kv ->key == key){
            iter ->kv ->value = newValue;
            return;
        }
        iter = iter ->next;
    }
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){
	for(int i=0; i < _hashmap->buckets; i++){
		printf("Bucket# %d\n",i);
		// Iterate through all of the lists
		// starting at each bucket
		node_t* iter = _hashmap->arrayOfLists[i];
		while(iter !=NULL){
			// Remember a node consists of a key/value
			printf("\tKey=%s\tValues=%s\n",iter->kv->key,iter->kv->value);
			// Move our iterator in that particular bucket
			// forward one node until we reach the end
			// of our chain.
			iter = iter->next;			
		}
	}
}
