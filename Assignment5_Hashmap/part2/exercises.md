# Exercises

Discuss and answer the following questions (Make sure to elaborate and justify your responses):

1. How good is the provided hash function--are we really getting constant time operations with our hashmap? Explain.
2. What is one other way you could implement the hash function? Anything creative is acceptable in this answer, but justify how your hashing function works.
3. If I have to resize the hashmap to add more buckets, what is th Big-O complexity when you resize? (Explain why)
4. What is 'open addressing' in regards to hash maps and hash tables?

## Answers:

1. It is good to function but we are not getting constant time operations with hashmap.  We have to iterate through both bucket number of arraylists and the list to find the exact node.
So the time complexity is O(n) rather than O(1)
2. Instead of using chaining(linkedlist) to store elements in each bucket to avoid collisions, if the slot is taken, we can check the same position in the next bucket until an empty postion is found.
If the position in each bucket is taken, try the next empty position in the bucket list.
3. O(n) We have to go through each node to find them a new bucket.
4. open addressing is a method for handling collisions. All elements are stored in the hash table, at any point, the size of the table must be greater than or equal to the total number of keys.
It has at most one element per bucket.


