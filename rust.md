# book and sites
https://crates.io/

[doc](https://doc.rust-lang.org/)

[the book](https://doc.rust-lang.org/book/second-edition/)

[*Attribute* ](https://doc.rust-lang.org/reference/attributes.html)

# RFC

## simd
https://github.com/rust-lang/rfcs/blob/master/text/1199-simd-infrastructure.md

## crate

- data parallelism
    - https://github.com/rayon-rs/rayon

## 金句

> Programming language design is often thought of in terms of which features you include, but the features you exclude are important too. Rust doesn’t have the null feature that many other languages have. *Null* is a value that means there is no value there. In languages with null, variables can always be in one of two states: null or not-null.

> Everywhere that a value has a type that isn’t an `Option<T>`, you *can* safely assume that the value isn’t null. This was a deliberate design decision for Rust to limit null’s pervasiveness and increase the safety of Rust code.

> The power of `match` comes from the
> expressiveness of the patterns and the compiler checks that make sure all
> possible cases are handled.

> Overall, these are the rules for item visibility:
>
> 1. If an item is public, it can be accessed through any of its parent modules.
> 2. If an item is private, it can be accessed only by its immediate parent module and any of the parent’s child modules.

https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization

> Rust won’t let us annotate a type with the `Copy`trait if the type, or any of its parts, has implemented the `Drop` trait.

A *data race* is similar to a race condition and happens when these three behaviors occur:

1. Two or more pointers access the same data at the same time.

2. At least one of the pointers is being used to write to the data.

3. There’s no mechanism being used to synchronize access to the data.

   ​


1. At any given time, you can have *either* but not both of:

- One mutable reference.
- Any number of immutable references.

2. References must always be valid.

## 内存布局

> Vectors allow us to store more than one value in a single data structure that puts all the values next to each other in memory.

> When the vector gets dropped, all of its contents will also be dropped, meaning those integers it holds will be cleaned up. This may seem like a straightforward point but can get a bit more complicated when we start to introduce references to the elements of the vector.

```rust
#[repr(C, packed)]
struct Object {
    a: u8,
    b: u16,
    c: u32, // other members
}

fn main() {
    let obj = Object {
        a: 0xaa,
        b: 0xbbbb,
        c: 0xcccccccc,
    };
    let a_ptr: *const u8 = &obj.a;
    let b_ptr: *const u16 = &obj.b;
    let c_ptr: *const u32 = &obj.c;

    let base = a_ptr as usize;

    println!("a: {}", a_ptr as usize - base);
    println!("b: {}", b_ptr as usize - base);
    println!("c: {}", c_ptr as usize - base);
}
```