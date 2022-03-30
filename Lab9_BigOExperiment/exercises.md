Please edit this document below with your responses. Each question is worth 1/8 of your lab.

# Exercise 1

1. Record here how long it took you to run bubblesort and csort (Note: If you want to run several trials, say '10' and take an average that is an even better result!).

BubbleSort: 
real    0m0.378s
user    0m0.373s
sys     0m0.003s

Csort:
real    0m0.008s
user    0m0.004s
sys     0m0.004s

# Exercise 2

What is the Big-O complexity of bubblesort?

O(n^2) There are two for-loops in the algorithm.

# Exercise 3

Do a little research and discover what algorithm qsort is in the C standard library. What is the algorithm? https://en.wikipedia.org/wiki/Qsort

1. *edit your answer here for question 3*

# Exercise 4

What is the Big-O complexity of 'qsort' that we use in the csort program?

O(nlogn)

# Exercise 5

Is qsort's Big-O complexity better or worse than bubblesort? (Answer: Yes it is better/ No it is worse/ It is equal)

Yes it is better.

# Exercise 6

List the following functions in terms of their Big-O complexity from **smallest** to **largest**.
<img src="./media/bigo.jpg"/>

LogN < N < N^2 < N^3 < 2^N < N!

# Exercise 7

- Given: f(n) = 3n^3 + n^2 + 27
- What is the O(n) of f(n)?

O(n^3)

# Exercise 8

- Given: f(n) = 3n^3 + n^2 + 27
- What are two constants c and k that prove your answer in exercise 7.
