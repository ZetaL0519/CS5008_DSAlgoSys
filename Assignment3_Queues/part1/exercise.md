Why is a ring buffer useful and/or when should it be used?

1. What is Circular Queue(ring buffer)?
Circular Queue(ring buffer) is a linear data structure in which the operations are performes based on FIFO(First In First Out) principle and the last position is connected back to the first position to make a circle.

2. Why is ring buffer useful?
(1) Ring buffers are useful as fixed-sized queues. The fixed size is beneficial for embedded systems, as developers often try to use static data storage methods rather than dynamic allocations.
(2) Ring buffers are useful for situations where data production and consumption happen at different rates: the most recent data is always available. 

3. When should it be used?
(1) The unused memory locations in the case of ordinary queues can be utilized in circular queues.
(2) Traffic system: In computer controlled traffic system, circular queues are used to switch on the traffic lights one by one repeatedly.
(3) CPU scheduling: Operating systems often maintain a queue of processes that are ready to execute or that waiting for a particular event to occur
