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