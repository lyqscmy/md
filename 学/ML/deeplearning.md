A typical training procedure for a neural network is as follows:

    Define the neural network that has some learnable parameters (or weights)
    Iterate over a dataset of inputs
    Process input through the network
    Compute the loss (how far is the output from being correct)
    Propagate gradients back into the network’s parameters
    Update the weights of the network, typically using a simple update rule

# 独立组件
## model(模型序列化,多语言反序列化?)
## data 存储,预处理
torch.utils.data.Dataset
    len(dataset)
    dataset[i]

transformed_sample = tsfm(sample)

torch.utils.data.DataLoader
    Batching the data
    Shuffling the data
    Load the data in parallel using multiprocessing workers.

dataloader = DataLoader(transformed_dataset, batch_size=4,
                        shuffle=True, num_workers=4)

for i_batch, sample_batched in enumerate(dataloader):
    print(i_batch, sample_batched['image'].size(),
          sample_batched['landmarks'].size())
## 训练框架
## 在线预测


# 训练数据
多分类 训练数据分布为何要均衡?
