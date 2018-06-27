什么样的value能move？

pass/return by value, transfer ownership


immutable/mutable reference
```rust
//Just as variables are immutable by default, so are references. We’re not allowed to modify something we have a reference to.
//调用者和被调用者都要保证immutable
fn change(some_string: &String) {
    some_string.push_str(", world");
}

fn change(some_string: &mut String) {
    some_string.push_str(", world");
}
```

```cpp
//when invoke mutter method
void change(const String& str);
void change(String& str);
```