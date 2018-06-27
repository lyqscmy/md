tag:redis


# src

- server
	- db
	- expire
- debug
- data structure
	- adlist
	- dict
	- geo
	- 
- network
	- anet
- IO
	- bio
	- aof
- ae
	ae.c  ae_epoll.c  ae_evport.c  ae.h  ae_kqueue.c  ae_select.c

- helper
	- bitops
	- crc*

[Separate chaining](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining)

# data type
- [string](https://redis.io/topics/internals-sds)
- [list]
- [hash](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining)
- set
- sorted set = hash + [skiplist](https://en.wikipedia.org/wiki/Skip_list)
- Bitmaps
- HyperLogLogs

transaction?

# [persistence](https://redis.io/topics/persistence)

# [replication](https://redis.io/topics/replication)

command table?

server.c
struct redisCommand redisCommandTable[]
