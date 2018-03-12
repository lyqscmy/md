[Beautiful Native Libraries](http://lucumr.pocoo.org/2013/8/18/beautiful-native-libraries/)

# 对象指针传递
long handle
Booster *bst = static_cast<Booster*>(handle);

# [array access](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/functions.html#GetPrimitiveArrayCritical_ReleasePrimitiveArrayCritical)


# [data types](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/types.html)
# sites and books
[Java Native Interface Specification Contents](https://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/jniTOC.html)

https://en.wikipedia.org/wiki/Java_Native_Interface

https://www.ibm.com/developerworks/java/tutorials/j-jni/j-jni.html

https://www.ibm.com/developerworks/java/library/j-jni/

http://planet.jboss.org/post/pointers_in_jni_c



- R大讲传指针

  https://www.zhihu.com/question/28250278/answer/40071228
```java
private static native long createCFoo(Args args);
private static native long freeCFoo(long ptr);
```

```c
// in C:
jlong Java_JFoo_createCFoo(JNIEnv* env, jclass unused, jobject args) {
  CArgs cargs = extract_args(args); // 示意：把Java传入的参数转换为C库需要的形式
  CFoo* foo = create_cfoo(cargs); // 示意：调用C库里的函数，里面可能包括malloc(sizeof(CFoo))调用
  return (jlong) foo;
}

void Java_JFoo_freeCFoo(JNIEnv* env, jclass unused, jlong ptr) {
  free((CFoo*) ptr); // 释放CFoo
}
```

