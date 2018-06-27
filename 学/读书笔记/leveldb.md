tag:leveldb|rocksdb|存储引擎

# sites
[360宋昭](http://kernelmaker.github.io/)

# 三架马车
workload
- Point lookup
Get
- Range lookup
- Point modify
Put
Delete
- Bulk modify

background
- recovery
- compaction
- snapshot
- checkpoint

## memtable
解决的问题？
- 随机写->顺序写


write batch
- write_size < Capacity
- write_size >= Capacity
    - write_size - Capatcity < Capatcity
    - write_size - Capatcity > Capatcity

## skiplist
vs btree
性质？
insert

一写多读
## sstable
解决的问题？
带来的问题？
## WAL
解决的问题？
带来的问题？

# 存储引擎
写路径涉及哪些数据结构？如何应对crash？如何做并发控制？
LSM写放大？compaction对服务的影响？
key分布在多个segment如何做到transaction？
value大小不固定如何解决？B-tree vs LSM

# 写路径
首先写入memtable
memtable.size > nMB 写入segment

# workload
server
multicore
TB
SSD

point lookups
range scans
random-read

