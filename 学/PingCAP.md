tag:container|k8s
# 容器资源使用**远程**查看和控制

实验环境：https://www.katacoda.com/courses/kubernetes/playground

1. 创建集群
```shell
launch.sh
kubectl cluster-info
```

2. 创建容器
```shell
kubectl create -f https://raw.githubusercontent.com/lyqscmy/md/master/%E5%AD%A6/pod.yaml
kubectl describe pod
```
```yaml
apiVersion: v1
kind: Pod
metadata:
  name: default-mem-demo-2
spec:
  containers:
  - name: defalt-mem-demo-2-ctr
    image: nginx
    resources:
      limits:
        memory: "1Gi"
```

3. 部署heapster
```shell
git clone https://github.com/kubernetes/heapster.git
cd heapster
kubectl create -f deploy/kube-config/influxdb/
kubectl cluster-info
```

4. 查看容器资源使用情况
```shell
kubectl top pod
```

6. 删除容器，修改配置后重新创建
```shell
kubectl delete -f https://raw.githubusercontent.com/lyqscmy/md/master/%E5%AD%A6/pod.yaml
vi pod.yaml
kubectl create -f https://raw.githubusercontent.com/lyqscmy/md/master/%E5%AD%A6/pod.yaml
```

```yaml
apiVersion: v1
kind: Pod
metadata:
  name: default-mem-demo-2
spec:
  containers:
  - name: defalt-mem-demo-2-ctr
    image: nginx
    resources:
      limits:
        memory: "2Gi"
```
# references
1. [为什么必须删除重建而不能直接patch](https://github.com/kubernetes/kubernetes/issues/39060#issuecomment-268449812)
2. [patch](https://kubernetes.io/docs/reference/generated/kubectl/kubectl-commands#patch)
3. [Officially-supported Kubernetes client libraries](https://kubernetes.io/docs/reference/client-libraries/)
4. [cgroups](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/resource_management_guide/chap-introduction_to_control_groups)