# FAQ
- 一次请求如何服务？多个servable分布在不同节点
- 并发请求？

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