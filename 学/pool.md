tag:object pool|concurrency

# array pool
<T> bigarray[CAPACITY]

# interface
```cpp
// critical region?
a_ptr = get(); //blocking
// critical region?

do_somework(a_ptr);
reset(a_ptr);

// critical region?
give_back(a_ptr); //blocking?
// critical region?
```

<T> require_block() {
    //链表为空,这里会有什么风险？
    while(free_list.isEmpty()){
        spin();
    }

    block = free_list.block();
    free_list.next();
    return block;
}

void give_back_block(block) {
    if(free_list.isEmpty()) {
        free_list.block = block;
    }
    else {
        free_list.insert(block);
    }
}

// critical region begin
auto block = pool.require_block();
// critical region end

// non-critical region
do_somework(block);
reset(block);
// non-critical region

// critical region begin
pool.give_back_block(block);
// critical region end


