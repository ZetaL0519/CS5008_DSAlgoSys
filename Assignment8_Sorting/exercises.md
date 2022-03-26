# Exercises

Discuss and answer the following questions (Please make sure to elaborate and justify your responses):

1. Explain what do you think the Big-O (worst-case) complexity of this algorithm is? Why?
2. What do you think the best-case (i.e. best case analysis, do a litlte research) complexity of this algorithm is?
   - Provide an example of an array of elements that fit the best-case in your answer below.
3. Does insertion sort require any additional storage beyond the original array? Explain why or why not.
4. What is a 'stable sorting' algorithm? Is insertion sort a 'stable' algorithm, why or why not?

## Answers:

1. I think it is O(n^2). There are two for-loops and two pointers iterating through the array in the algorithm.
2. I think the best case complexity is O(n) for an already sorted array. For example: [-8, 7, 56, 432, 578]
In this case, only the first for-loop is iterating. Since the array is already sorted, element insertion is no longer needed. 
3. No it does not require any additional storage. 
The entire sorting process is done on the change of original array. It does not allocate more memory for any new array. 
Its space complexity is O(1).
4. A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.
Insertion sort is a stable algorithm. Because the sorting process makes sure that element A only comes before element B when A < B
