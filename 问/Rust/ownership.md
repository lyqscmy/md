ownership
borrowing
reference
smart pointer
lifetime
move/copy

> All programs have to manage the way they use a computer’s memory while running. Some languages have garbage collection that constantly looks for no longer used memory as the program runs; in other languages, the programmer must explicitly allocate and free the memory. Rust uses a third approach: memory is managed through a system of ownership with a set of rules that the compiler checks at compile time. No run-time costs are incurred for any of the ownership features.


JVM的堆内存分配也总是从顶上获取,所以非常快.没有GC的语言如何高效的管理堆内存?参考nginx?
> The stack is fast because of the way it accesses the data: it never has to search for a place to put new data or a place to get data from because that place is always the top. Another property that makes the stack fast is that all data on the stack must take up a known, fixed size.

> Accessing data in the heap is slower than accessing data on the stack because we have to follow a pointer to get there. **Contemporary processors are faster if they jump around less in memory**.

1. Each **value** in Rust has a **variable** that’s called its owner.
包括栈和堆的上value
2. There can only be **one owner at a time**.
3. When the owner goes out of **scope**, the value will be **dropped**.

> When a variable goes out of scope, Rust calls a special function for us. This function is called drop, and it’s where the author of String can put the code to return the memory. Rust calls drop automatically at the closing }.


> If you’ve heard the terms “shallow copy” and “deep copy” while working with other languages, the concept of copying the pointer, length, and capacity without copying the data probably sounds like a shallow copy. But because Rust **also invalidates the first variable**, instead of calling this a shallow copy, it’s known as a move. 

rust有许多默认行为,而在C++中要注意与这些的区别,以及如何手动选择.
> In addition, there’s a design choice that’s implied by this: Rust will never automatically create “deep” copies of your data. Therefore, any automatic copying can be assumed to be inexpensive in terms of runtime performance.

copy与move不能共存
> Rust won’t let us annotate a type with the Copy trait if the type, or any of its parts, has implemented the Drop trait

重点在于move
> The semantics for passing a value to a function are similar to assigning a value to a variable. Passing a variable to a function will move or copy, just like assignment

> These ampersands are references, and they allow you to **refer to some value without taking ownership of it**
为什们引用的本质是指针但是是线程安全的?
因为在同一时刻只有一个value只有一个owner,而这个owner的lifetime由调用者保证,在被调用者返回之前,可以确保owner的有效性.不存在其他方法在被调用者使用时修改value(share_prt在多线程情况下?),而调用者也可以放心被调用者不会修改.

owner所有权能对value做哪些事?drop?


1. At any given time, you can have either but not both of:
    - One mutable reference.
    - Any number of immutable references.
2. References must always be valid.

slice如何扩展到其他方面?


> One lifetime annotation by itself doesn’t have much meaning: lifetime annotations tell Rust how the generic lifetime parameters of multiple references relate to each other

为什们函数需要lifetime标注?
>  This is because Rust is able to analyze the code within the function without any help, but when a function has references to or from code outside that function, the lifetimes of the arguments or return values will potentially be **different each time the function is called**. This would be incredibly costly and often impossible for Rust to figure out. In this case, we need to annotate the lifetimes ourselves.

> When returning a reference from a function, the lifetime parameter for the return type needs to match the lifetime parameter of one of the arguments. If the reference returned does not refer to one of the arguments, the only other possibility is that it refers to a value created within this function, which would be a dangling reference since the value will go out of scope at the end of the function