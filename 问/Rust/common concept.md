Variables and Mutability
变量默认是否可变?

> In Rust the compiler guarantees that when we state that a value won’t change, it really won’t change. That means that when you’re reading and writing code, you don’t have to keep track of how and where a value might change, which can make code **easier to reason about**.

>  In some cases, you’ll want to make a variable mutable because it makes the code more convenient to write than an implementation that only uses immutable variables.

何时权衡?
> There are multiple trade-offs to consider, in addition to the prevention of bugs. For example, in cases where you’re using large data structures, **mutating an instance in place may be faster** than copying and returning newly allocated instances. With smaller data structures, creating new instances and writing in a more **functional programming style** may be easier to reason about, so the lower performance might be a worthwhile penalty for gaining that clarity.


> First, we aren’t allowed to use mut with constants: constants aren’t only immutable **by default**, they’re **always immutable**.

编译期和运行期
> The last difference is that constants may only be set to a constant expression, not the result of a function call or any other value that could only be computed at runtime.

> So how do you know which type of integer to use? If you’re unsure, Rust’s defaults are generally good choices, and integer types default to i32: it’s generally the fastest, even on 64-bit systems. The primary situation in which you’d use isize or usize is when indexing some sort of collection.

other types不限于scalar type
> Compound types can group multiple values of **other types** into **one type**. Rust has two primitive compound types: tuples and arrays.

哪些类型分配在栈上?
> Arrays are useful when you want your data allocated on the stack rather than the heap

>  If you’re unsure whether to use an array or a vector, you should probably use a vector

> An example of when you might want to use an array rather than a vector is in a program that needs to know the names of the months of the year. It’s very unlikely that such a program will need to add or remove months

> An array is a single chunk of memory allocated on the stack

> Statements are instructions that perform some action and do not return a value. Expressions evaluate to a resulting value.