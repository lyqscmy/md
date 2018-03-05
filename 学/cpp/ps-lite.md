(doc)[http://ps-lite.readthedocs.io/en/latest/overview.html]

> Note that asynchronous SGD is semantically different the single machine version. Since there is no communication between workers, so it is possible that the weight is updated while one worker is calculating the gradients. In other words, each worker may used the delayed weights.

> Comparing to a single machine algorithm, the distributed algorithms have two additional costs, one is the data communication cost, namely sending data over the network; the other one is synchronization cost due to the imperfect load balance and performance variance cross machines. 