
# 高速缓存
cache-line
SMP cache consistent

# lock-free algorithm

> Ok, so what is the most important thing regarding synchronization algorithm's performance and scalability? I frequently hear the answer that it's a number of atomic RMW (read-modify-write) instructions (like Compare-And-Swap or Fetch-And-Add) per operation. 

> atomic loads and stores are better/cheaper/faster than atomic RMW operations.

> **The most stupid thing** one can do is try to implement everything in a non-blocking style. Generally it's perfectly Ok to use mutexes/condition variables/semaphores/etc on cold-paths. For example, during process or thread startup/shutdown mutexes and condition variables is the way to go.

> Memory access ordering is the most involved property of a memory model, and it requires the greatest amount of developer's attention. 

> So, a memory model determines what re-orderings are possible (relatively to program order).

> An important moment regarding memory fences is that it's always a game of two. It's about mutual ordering of memory accesses as how they are perceived by other threads, and thus there is always "this" thread and "that" thread.


Compiler vs. Hardware

> So, first we need to ensure that our high-level language memory access will be compiled to proper machine code memory accesses, and only then hardware guarantees will come into play.

> Creation of efficient scalable concurrent data structures is a kind of  **black magic**. There is no recipes for that. What we should do is carefully analyze usage patterns for a data structure, and then try to satisfy all user requirements and scalability prerequisites with all possible means. 

> The most important aggregate metric for a concurrent data structure is a mean number of cache line transfers between threads per operation. 

# scalable architecture


> Scalability starts with good high-level architecture. It's trivially easy to kill scalability on the lowest level with excessive amounts of write sharing, but it does not belittle value of good high-level architecture. In the end, all levels are equally important.

> The principles are all the same - excessive communications, dependencies, waits and centralization kill concurrency.

> Also keep in mind that a thread is not an application-level abstraction, it's an abstraction of a processor (thing that can execute code, any code). So don't create threads to do particular functions – any thread in your program can execute any function (however there can be exception from the rule – for example, frequently it's convenient to have a dedicated GUI thread). Don't create threads only to track timers. Don't create threads only to do IO. **Threads should generally be one level below application logic**

> You need some work distribution/balancing machinery, and it must be dynamic and feedback based. Why? Because you don't how many threads there will be, data set is generally unknown, application logic and details are in constant change, hardware is changing, plus there can other processes that contend for CPU and IO

什么情况thread专用？
> The idea behind the solution is that we have a set of **interchangeable** worker threads, and each thread decides what is the most optimal thing to do next.