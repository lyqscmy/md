tag:benchmark|concurrency

[google benchmark](https://github.com/google/benchmark)
git checkout v1.4.0
makedir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=RELEASE -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON

[forceNoOptimizeDummy](http://en.cppreference.com/w/cpp/language/as_if)
# 基础组件
cpuid
创建线程
高精度系统时间

# 指标
Legend:
    'Avg':     Average time taken per operation, normalized to be per thread
    'Range':   The minimum and maximum times taken per operation (per thread)
    'Ops/s':   Overall operations per second
    'Ops/s/t': Operations per second per thread (inverse of 'Avg')
    Operations include those that fail (e.g. because the queue is empty).


python提取成csv可视化

# 机器学习推理性能测试
- 确定
	模型
	workload

cpuid
多线程并发调用
avg
range
ops/s
cpu负载

determineMaxOpsForBenchmark
{bench_id:nthreads:[(op_id, elapsedTime)]}}
bench_id|nthreads|op_id|elapsedTime
