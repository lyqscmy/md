1. What is the expected throughput of the application?
2. What is the expected latency between a stimulus and a response to that
stimulus?
3. How many concurrent users or concurrent tasks shall the application support?
4. What is the accepted throughput and latency at the maximum number of concurrent
users or concurrent tasks?
5. What is the maximum worst case latency?
6. What is the frequency of garbage collection induced latencies that will be
tolerated?

[性能测试应该怎么做？](https://coolshell.cn/articles/17381.html)

# 第二章 操作系统性能监测
CPU Utilization

> For an application to reach its highest performance or scalability it needs to not only
take full advantage of the CPU cycles available to it but also to utilize them in a
manner that is not wasteful
这段话很有意义，单位时间内某个频率的CPU，其cycles数量是固定的。如何充分利用每个cycles做有意义的事情，而不是空等浪费。

高CPU利用率是指system call尽可能的少，CPU大部分时间在执行用户空间的代码。低利用率一般是IO读写引起的。

CPI（cycles per instruction）是指CPU执行指令在时钟周期内的密度，如果单位时钟周期内指令密度较低，那么意味着指令需要的数据不能从寄存器或者高速缓存中获取到，需要从主存中加载进来。这是会造成时钟周期内无指令可执行。

[性能之巅](https://book.douban.com/subject/26586598/)
第四章 obervability tools
选择自己想要观测的指标，然后再选择合适的观测手段。

[top各项指标的含义](https://www.booleanworld.com/guide-linux-top-command/)

CPU run queue
[vmstat](https://linode.com/docs/uptime/monitoring/use-vmstat-to-monitor-system-performance/)