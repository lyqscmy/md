# 开发环境

- CMake/make
- gcc
- vscode

# [C++ Core Guidelines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main)
# [A Tour of C++](https://isocpp.org/tour)

# [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)

- Style rules should pull their weight
  四两拨千斤
- Optimize for the reader, not the writer
  易于阅读意味易于推导

## [How to mix C and C++](https://isocpp.org/wiki/faq/mixing-c-and-cpp)

典型情况:

* 有c写的.so和.a
* 有c写的header

需求如何在cpp中使用(cpp做主导)


* You must use your C++ compiler when compiling main() (e.g., for static initialization)
* Your C++ compiler should direct the linking process (e.g., so it can get its special libraries)
* Your C and C++ compilers probably need to come from the same vendor and have compatible versions (e.g., so they have the same calling conventions)

第一条肯定满足
第二条第三条gcc

## 库

- [Fixed width integer types](http://en.cppreference.com/w/cpp/header/cstdint)

数组的长度必须在编译时确定     <C++ primer>p113

如何lint?

如何debug?

如何profile?



## 数据对齐

如何确保数据对齐?如何检测?

## Effective 

- List Initalization

  初始化和赋值是两码事，初始化尽量使用a= {}这种形式，包括内置类型，编译器可以检查出更多错误。

- 永远初始化

  在函数体内定义的局部变量可能会有uninitiated value

- 确认自己所想的type和编译器认为的语义是否一致

- scope

  - global scope
  - block scope

# c_api

- Header Guards
```cpp
#pragma once
#ifdef __cplusplus
extern "C" {
#endif

struct yl_task_s;
typedef struct yl_task_s yl_task_t;

YL_API yl_task_t *yl_task_new();
YL_API void yl_task_free(yl_task_t *task);
YL_API int yl_task_is_pending(const yl_task_t *task);
YL_API void yl_task_tick(yl_task_t *task);
YL_API const char *yl_task_get_result_string(const yl_task_t *task);
/* code goes here */

#ifdef __cplusplus
}
#endif
```

```cpp
#ifdef __cplusplus
extern "C" {
#endif

#define AS_TYPE(Type, Obj) reinterpret_cast<Type *>(Obj)
#define AS_CTYPE(Type, Obj) reinterpret_cast<const Type *>(Obj)

yl_task_t *yl_task_new()
{
    return AS_TYPE(yl_task_t, new yourlibrary::Task());
}

void yl_task_free(yl_task_t *task)
{
    if (!task)
        return;
    delete AS_TYPE(yourlibrary::Task, task);
}

int yl_task_is_pending(const yl_task_t *task)
{
    return AS_CTYPE(yourlibrary::Task, task)->is_pending() ? 1 : 0;
}

void yl_task_tick(yl_task_t *task)
{
    AS_TYPE(yourlibrary::Task, task)->tick();
}

const char *yl_task_get_result_string(const yl_task_t *task)
{
    return AS_CTYPE(yourlibrary::Task, task)->result_string();
}

#ifdef __cplusplus
}
#endif
```
