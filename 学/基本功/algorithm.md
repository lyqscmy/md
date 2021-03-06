tag:algorithm|data structure|数据结构

# 基本算法
## 排序
in-place
stable

### 冒泡排序

### 插入排序
- 常数空间
- 内循环紧凑
- 最坏二次时间复杂度

### 快速排序

## 搜索



# 算法新解
[《算法新解》作者刘新宇：我只是想打开那些黑盒子，告诉人们里面有什么（图灵访谈）](http://www.ituring.com.cn/article/274001)

[](elementary-algorithms.pdf)

- 如何顺应时代
> 第一个想法是关于变化的。面对剧烈变化的时代，飞速发展的技术，绝大多数个体都会感到压力。出于自我保护的本能，我们需要在变化的大潮中找到相对不变的东西。**什么是不变的呢?** 语言？框架？还是操作系统？在我上大学的时候，实验室中还在广泛使用Fortran语言用于科学计算。但是几年之间，C语言就替代了Fortran成为了主流语言。今天，各种新语言更是层出不穷；框架也是如此，我还记得上学的时候，大家怀着很高的热情学习微软的MFC框架。可是今天，除了在个别场合，很少有人还在用MFC了。各种框架也是如雨后春笋一般出现在各种领域；操作系统呢？我曾经在诺基亚的Symbian操作系统上开发了近10年。在Tanenbaum的经典教科书《现代操作系统》的附录中，Symbian被作为成功的嵌入式操作系统案例加以讲解。可是2011年，Symbian几乎在转瞬之间就轰然倒塌。2014年，当我完成这本书的英文草稿的时候，正逢诺基亚解散。这些经历使得我不断思考这一问题。

- 算法的重要性
> 出于业务上的挑战，我们把自己的技术架构在亚马逊的云计算平台AWS上，处理大数据下的高可靠性、并发性和一致性的问题。这里会用到很多的算法，包括最优化的算法和机器学习算法，等等。我们会根据库房的容量对货物在仓储网络中做优化的配置，我们会使用机器学习预测进出库的时间，等等。正因如此，亚马逊对于研发团队工程师的算法能力有很高的要求。在亚马逊的面试中，算法与数据结构是一个必考的环节，甚至是一票否决的。

- 如何掌握函数式编程
> 图灵奖获得者，迪杰斯特拉（Dijsktra） 说过：“程序=数据结构+算法”。使用函数式编程，如果不了解函数式算法就只能停留在表面，写出像“hello world”这样的简单程序。 这也是《算法新解》这本书希望能够帮助读者的一点。

- 合适的工具
> 这本书的章节安排和传统的大多数算法书不同，这也算是“新”的一个体现吧。按照函数式的思维，许多在命令式算法中比较复杂、困难的东西，一下子变得简单了，“红黑树”就是这样一个例子。使用函数式算法后，红黑树的实现只需要16行。这样按照难度来算，红黑树就排在了前面 。相反，有些看似容易的东西，想用函数式的方式实现却并不简单，例如队列和序列。我把这些比较难的内容安排在了后面。如果讲解完一个函数式的数据结构后，我们发现能立即用来实现某个算法，就穿插着讲一章算法。例如插入排序被安排在二叉树后，选择排序被安排在堆的后面就是这个原因。函数式算法的最底层、最基础的数据结构是链表，反复斟酌后，我把它作为附录列在书后。有一些函数式编程基础的读者可以随时参考，而零基础的读者可以先集中看一下。

> 命令式编程和函数式编程也是如此。我们并非说一种方法就一定比另一种方法好，而是说某些问题，一旦转换思路反而比较容易。有时是函数式算法容易一些（例如红黑树），有时是命令式算法直观容易一些（例如KMP匹配算法）。

- 并行化的重要性（单机，集群）
> 设计算法时，通常使用顺序模型，很少考虑算法的并行化扩展。但是在实际应用中，很多难以并行扩展的算法由于时间上不能满足要求而被放弃。您认为设计算法时是不是应该考虑并行扩展的因素？

- 推导是学习的过程
> 证明不在于确认或者推翻一个结论，而在于在证明过程中发展出来的方法和工具。

> 证明对于算法学习有促进作用，证明迫使我们更加深入思考，甚至从不同视角看待一个问题。

- 算法在实际中的应用
> 有很多程序员标榜自己是完美主义者，是代码洁癖。我觉得这很好，但是我们不能仅仅把洁癖停留在缩进、括号、和空格上；也不能仅仅停留在final和const这些关键字的使用上。当看到代码不美，不简洁，有重复时，通过抽象、改进，会慢慢发展算法思维。我以前曾经开发过这样一个程序，在社交app的列表中要显示用户的好友，产品上设计了很复杂的业务逻辑。比如，在线的好友在前面显示，离线的在后面显示，VIP在前面显示，最近聊过天的在前面显示，等等。代码中有很多if-else来实现这些复杂的逻辑。经过思考，最终把这些复杂的业务逻辑抽象成了当给定好友A和好友B时，如何决定A在B之前的比较。这样整个程序就化简成了一个排序算法。只要不断追求简洁优美的代码，就会自然而然产生算法的思想。对比前面的问题，我们谈的主要是如何求真，而这个问题，我们需要的是求美。

- 人工智能与人的关系
> 我想说，我们人类能解决的问题，仅仅占到了全部问题的一小部分。如果计算机、人工智能和算法的进步能帮助我们争取时间，解决更重要的问题，那就太好了。


递归定义类型：
- 二叉树