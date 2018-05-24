tag:concurrency|多线程

# book and sites
http://www.1024cores.net/

> Many languages are strongly opinionated about the solutions they offer for dealing with concurrent problems. For example, Erlang has elegant functionality for message passing concurrency, but only obscure ways to share state between threads. Only supporting a subset of possible solutions is a reasonable strategy for higher-level languages to take, because a higher-level language **promises benefits from giving up some control** in order to gain abstractions. However, lower-level languages are expected to provide the solution with the best performance in any given situation, and have **fewer abstractions over the hardware**. Rust, therefore, gives us a variety of tools for modeling your problems in whatever way is appropriate for your situation and requirements.


> channels in any programming language are sort of like **single ownership**, **because once you transfer a value down a channel, you shouldn’t use that value any longer**. Shared memory concurrency is sort of like multiple ownership: **multiple threads can access the same memory location at the same time.** 

# 硬件层面并行
1. Instruction-Level
    - 流水线
    - 超标量
2. Data-Level
    - SIMD
    - GPU
3. Thread-Level
    - 多核
4. Request-Level
    - 集群

# 高级语言的并发模型
Erlang message passing
go goroutine
Scala actor

# 并发的基本组件
1. mutex
2. condition vaiable


# lock strategy 
- sleep
- spinlock

# deadlock

> The most common strategy is to standardize the lock acquisition sequences so that combinations of inter-dependent locks are always acquired in a specifically defined "cascade" order

# access mode
- exclusive access
- intend-to-exclude
- intend-to-upgrade
