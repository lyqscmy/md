tag:TVM|DL

operator library决定graph构造
operator fuse pattern
> Operator Fusion Fusing multiple operators together is an optimization that can greatly reduce execution time, particularly in GPUs and specialized accelerators. The idea is to combine multiple operators together into a single kernel **without saving the intermediate results back into global memory**

重要的是技术，作为工程师有必要过问每一块/种砖。
[TVM](https://github.com/dmlc/tvm)
[阿里巴巴](http://tvmlang.org/2018/03/23/nmt-transformer-optimize.html)
异构计算

计算/存储调度：有限时间内充分利用资源
资源有限，且各种资源工作方式存在巨大差异