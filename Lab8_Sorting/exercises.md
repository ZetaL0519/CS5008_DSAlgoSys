# Exercises

1. What do you think the Big-O (worst-case) complexity of this algorithm is? 
2. What do you think the best-case complexity of this algorithm is? 
	- Note-- assume you do not have any information about if the array is already sorted or not.
3. Does selection sort require any additional storage beyond the original array? 
	- i.e. Did you have to allocate any extra memory to perform the sort?
5. Would the Big-O complexity change if we used a linked list instead of an array?

## Answers:

1. O(n^2)
2. O(n^2)
3. Yes. It needs to store the minimum number for arrays from length 1 to size.
4. No it won't change. We still have to go through the list to find minimum and swap numbers.
