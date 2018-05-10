tag:rust|note

> An important part of the process of learning Rust is learning how to read the error messages that the compiler gives you

marco?
enum?

[Semantic Versioning](https://semver.org/)

[musl](http://www.musl-libc.org/)

> There are multiple trade-offs to consider, in addition to the prevention of bugs. For example, in cases where you’re using large data structures, mutating an instance in place may be faster than copying and returning newly allocated instances. With smaller data structures, creating new instances and writing in a more functional programming style may be easier to reason about, so the lower performance might be a worthwhile penalty for gaining that clarity.


> We split the types into two subsets: scalar and compound.

- A scalar type represents a single value.
- Compound types can group multiple values of other types into one type. Rust has two primitive compound types: tuples and arrays.

> Throughout this section, keep in mind that Rust is a statically typed language, which means that it must know the types of all variables at **compile time**.

> Arrays are useful when you want your data allocated on the stack rather than the heap 

> Statements are instructions that perform some action and do not return a value. Expressions evaluate to a resulting value. 


# Understanding Ownership

keywords: ownership borrowing slices

> All programs have to manage the way they use a computer’s memory while running. Some languages have garbage collection that constantly looks for no longer used memory as the program runs; in other languages, the programmer must explicitly allocate and free the memory. Rust uses a third approach: memory is managed through a system of ownership with a set of rules that the compiler checks at compile time. No run-time costs are incurred for any of the ownership features.

> The stack is fast because of the way it accesses the data: it never has to search for a place to put new data or a place to get data from because that place is always the top. Another property that makes the stack fast is that all data on the stack must take up a **known, fixed size**.

> Pushing values onto the stack is not considered allocating. Because the pointer is a known, fixed size, we can store the pointer on the stack, but when we want the actual data, we have to follow the pointer.


> When our code calls a function, the values passed into the function (including, potentially, pointers to data on the heap) and the function’s **local variables get pushed onto the stack**. When the function is over, those values get popped off the stack.

> Keeping track of what parts of code are using what data on the heap, minimizing the amount of duplicate data on the heap, and cleaning up unused data on the heap so we don’t run out of space are all problems that ownership addresses. 

> A String is made up of three parts, shown on the left: a pointer to the memory that holds the contents of the string, a length, and a capacity. 


> In addition, there’s a design choice that’s implied by this: Rust will never automatically create “deep” copies of your data. Therefore, any automatic copying can be assumed to be inexpensive in terms of runtime performance.

> Rust won’t let us annotate a type with the Copy trait if the type, or any of its parts, has implemented the Drop trait. If the type needs something special to happen when the value goes out of scope and we add the Copy annotation to that type, we’ll get a compile time error.

> You can check the documentation for the given type to be sure, but as a general rule, any group of simple scalar values can be Copy, and nothing that requires allocation or is some form of resource is Copy.

> The semantics for passing a value to a function are similar to assigning a value to a variable. 

> Note that the entire instance must be mutable; Rust doesn’t allow us to mark only certain fields as mutable.

> Unit-like structs can be useful in situations such as when you need to implement a trait on some type, but you don’t have any data that you want to store in the type itself.

> It’s possible for structs to store references to data owned by something else, but to do so requires the use of lifetimes


> A module is a namespace that contains definitions of functions or types, and you can choose whether those definitions are visible outside their module (public) or not (private)