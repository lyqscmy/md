tag:memory|memory model|concurrency

# Memory model
命令式的语言，一条一条执行。
编译器/CPU优化会重排，但保证结果一致。
Memory model就是程序员明确共享变量的边界，限制编译器/CPU重排

> memory models in the context of multi-threading/concurrency. There are 3 fundamental properties: **Atomicity, Ordering and Visibility**; and 2 levels: **Compiler and Hardware**.

## atomic
> There are 2 classes of operations in the context of atomicity: (1) read-modify-write (RMW) operations and (2) loads and stores. Some people associate atomicity only with RMW operations like compare-and-swap and fetch-and-add; however, atomic loads and stores are no less important.

## visibility

> Visibility determines when other threads will see changes made by the current thread, and whether they will see them at all. A lot of people endeavour to do something special in order to ensure visibility (like placing memory fences).


## ordering

> For required ordering ensuring hardware usually provides special instructions called memory fences/barriers, which prevent some re-ordering types around them

> There are 2 types of memory fences - bi-directional (store-store, load-load) and tied to memory accesses (acquire and release). 

> Bi-directional fences prevent one type of memory accesses (load or store) from "sinking below" them, while other type of memory accesses (can be the same, though) from "hoisting above" them.


> Fences tied to memory accesses prevent all memory accesses from moving above (acquire fence) or below (release fence); for example, load-acquire is a load which simultaneously prevents any other memory accesses from hoisting above it (while any memory accesses can sink below it).
[](ebook/cpumemory.pdf)
[Memory model](https://en.wikipedia.org/wiki/Memory_model_(programming))

访问模式对多路内存的性能影响重大

CPU与DRAM的通信机制

高速缓存程序不能直接操控,但是运行细节暴露给程序,因此程序有必要帮助CPU更好的工作.