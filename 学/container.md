tag:container

# FAQ
[x] what is image?
[x] what is container?
[x] what os/linux feature use for container?
    - namespace?
    - cgroups
容器是一种技术应用，操作系统并没有容器的概念，而是通过操作系统一系列的特性组合来实现容器。

[p] 容器的价值所在？以及容器所依赖技术的单独价值？

# 运行时容器资源控制
容器的创建,运行,销毁详细过程

资源的如何量化?
- CPU
- memory
- IO
- network

cgroups如何工作?

[Docker Internals](http://docker-saigon.github.io/post/Docker-Internals/)
[Linux namespaces](https://en.wikipedia.org/wiki/Linux_namespaces)
[Docker基础技术：Linux Namespace（上）](https://coolshell.cn/articles/17010.html)
[Docker基础技术：Linux CGroup](https://coolshell.cn/articles/17049.html)

- containerd: containerd is an industry-standard container **runtime** with an emphasis on simplicity, robustness and portability. It is available as a daemon for Linux and Windows, which can manage the complete container lifecycle of its host system: **image** transfer and storage, container execution and supervision, low-level storage and network attachments, etc.

- runC: CLI tool for spawning and running containers according to the OCI specification

- libcontainer

# PingCAP

目前我了解了runC,containerd和docker三者的角色和关系。

关于资源管理，本质是对容器所属的cgroups做控制，所以需要知道容器cgroups的组织方式，具体以何种方式调控待定。倾向于在containerd的基础上做扩展，因为已经包含了gRPC方便远程调用。但是它的文档不齐全，不清楚内部对这块的支持如何。而运行时的调控，只能确认向上调整是安全的，向下调整要具体分析（资源类型和当前使用情况）。docker对资源管理好像只限于CPU和memory，不太清楚其内部是否也是基于containerd。

关于网络调试，有点不明确的是要在何种场景下使用，网络编程这块经验比较少。是进入容器内部的shell交互式调试？如果是这样可以临时挂载宿主机的命令行工具，调试完再卸载。还是通过宿主机调试？

# tools
unshare
nsenter --target pid --mount --uts --pic --net --pid ps aux

# 资源管理
模仿docker的管理方式/术语，基于runC来做

hard limit vs soft limit
## CPU
## memory