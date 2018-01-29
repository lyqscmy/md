## intrinsics

https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html

https://software.intel.com/sites/landingpage/IntrinsicsGuide/#

<https://gcc.gnu.org/onlinedocs/>

-Wall

-O3

-fopenmp <https://explainshell.com/explain?cmd=gcc+-fopenmp>

-std=c++0x <https://gcc.gnu.org/onlinedocs/gcc-7.2.0/gcc/C-Dialect-Options.html#C-Dialect-Options>

-march=native <https://gcc.gnu.org/onlinedocs/gcc-7.2.0/gcc/AArch64-Options.html#AArch64-Options> 

```shell
-fverbose-asm
    Put extra commentary information in the generated assembly code to make it more readable.  This
    option is generally only of use to those who actually need to read the generated assembly code
    (perhaps while debugging the compiler itself).
```

动态连接和静态连接对性能的影响?

Supports OpenMP and automatic parallelization. Supports vector intrinsics and automatic vectorization



如何确认编译器做了哪些优化?



`-ftree-loop-optimize`



## 内存管理

数据对齐malloc

https://www.gnu.org/software/libc/manual/html_node/Aligned-Memory-Blocks.html



https://gcc.gnu.org/onlinedocs/gcc-3.2/gcc/Variable-Attributes.html

```c++
int x __attribute__ ((aligned (16))) = 0;
```

## 静态链接

