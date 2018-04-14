# 分享
1. 干什么的？
> TensorFlow Serving is a flexible, high-performance serving system for machine learning models, designed for production environments. TensorFlow Serving makes it easy to deploy new algorithms and experiments, while keeping the same server architecture and APIs. TensorFlow Serving provides out-of-the-box integration with TensorFlow models, but can be easily extended to serve other types of models and data.
重点是模型管理，不同模型，同个模型不同版本。
2. 一个query如何服务？
后面一堆servable，由manager相当于前台导流。

3. 未来工作
在线推理压测，打通链路，存在的坑gRPC通信模型。
[grpc评测](https://github.com/brpc/brpc/blob/master/docs/cn/benchmark.md)
是否需要替换grpc（仅推理部分）？
servable的计算优化？

![](https://www.tensorflow.org/serving/images/serving_architecture.svg)

结论

brpc：在吞吐，平均延时，长尾处理上都表现优秀。

UB：平均延时和长尾处理的表现都不错，吞吐的扩展性较差，提高线程数和client数几乎不能提升吞吐。

thrift：单机的平均延时和吞吐尚可，多机的平均延时明显高于brpc和UB。吞吐的扩展性较差，提高线程数和client数几乎不能提升吞吐。

sofa-pbrpc：处理小包的吞吐尚可，大包的吞吐显著低于其他RPC，延时受长尾影响很大。

hulu-pbrpc：单机表现和sofa-pbrpc类似，但多机的延时表现极差。

grpc：几乎在所有参与的测试中垫底，可能它的定位是给google cloud platform的用户提供一个多语言，对网络友好的实现，性能还不是要务。

首先保证模型加载卸载流程运作正常，其次RPC通信功能正常并且没有瓶颈，最后尝试提高计算性能。
工程端：
1. 持续集成稳定版本serving，掌握各个模块的关系。
2. 梳理请求处理的整个流程，多套算法如何选择，负载均衡。确定与Java的分工合作，输入接口的定义。
3. 搭建推理链路压测环境，分网络和计算两部分
    3.1 gRPC功能和性能
    3.2 典型模型的计算调优，包括kernel和并行/batching
4. 梳理模型版本管理的流程，根据业务需求实现模型管理策略。

算法端：
1. 给出模型/网络结构
2. 梳理模型版本迭代和实验策略。是否需要收集指标？

serving本身功能比较简单，需要定制的东西非常多。大概分三块：模型管理，请求路由，推理计算调优。其中请求路由和计算目测坑比较多。

# TODO
先规划单个模型跑通整体流程

# FAQ
[] 一次请求如何服务？多个servable分布在不同节点
[] 并发请求？
[] 输入数据的大小？
[] 是否有必要做batching增加吞吐量？


# 功能
机器学习在线服务框架需要哪些功能
- 同一个模型，不同版本
- 不同模型

# Version Policy
- Availability Preserving Policy
> avoid leaving zero versions loaded; typically **load a new version before unloading an old one**
- Resource Preserving Policy
> avoid having two versions loaded simultaneously, thus requiring double the resources; **unload an old version before loading a new one**


# etc

主要用于GPU环境
> Batching can be turned on by providing proper SessionBundleConfig when creating the SavedModelBundleSourceAdapter. In this case we set the BatchingParameters with pretty much default values. Batching can be fine-tuned by setting **custom timeout**, **batch_size**, etc.

> SavedModelBundle is a **key component** of TensorFlow Serving. It represents a TensorFlow model loaded from a given path and provides the same Session::Run interface as TensorFlow to run inference. SavedModelBundleSourceAdapter adapts storage path to Loader<SavedModelBundle> so that model lifetime can be managed by Manager.

https://www.tensorflow.org/serving/

> TensorFlow Serving makes it easy to **deploy new algorithms** and **experiments**, while keeping the **same server architecture and APIs**. TensorFlow Serving provides out-of-the-box integration with TensorFlow models, but can be easily **extended** to serve other types of models and data.

- roles
    - data
    - learner
    - model
    - serving

- Servable
> A single Servable might include anything from a single shard of a lookup table to a single model to a tuple of inference models.

- Servable Versions
> TensorFlow Serving can handle one or more versions of a servable over the lifetime of **a single server instance**. This enables fresh algorithm configurations, weights, and other data to be loaded over time. Versions enable more than one version of a servable to be **loaded concurrently**, supporting **gradual rollout and experimentation**. At serving time, **clients** may request either the latest version or a specific version id, for a particular model.

- Models
> TensorFlow Serving represents **a model as one or more servables**.
> A servable may also correspond to a fraction of a model. For example, **a large lookup table** could be **sharded** across many TensorFlow Serving instances.

- Loader
> Specifically, Loaders standardize the APIs for **loading** and **unloading** a servable.

- Soruces
> Sources can maintain state that is **shared across multiple servables or versions**. This is useful for servables that **use delta (diff) updates between versions**.