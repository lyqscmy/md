tag:container|k8s
资源**远程**查看和控制
[cgroups](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/resource_management_guide/chap-introduction_to_control_groups)

slice
    scope
        service
resource controller

machinectl(1) — This manual page lists all command-line options of the machinectl utility. 
systemd-cgtop(1) — The manual page contains the list of all command-line options of the systemd-cgtop utility. 

> Delegate allows containerd and its runtimes to manage the cgroups of the containers that it creates. Without setting this option, systemd will try to move the processes into its own cgroups, causing problems for containerd and its runtimes to properly account for resource usage with the containers.


[What is Kubernetes?](https://kubernetes.io/docs/concepts/overview/what-is-kubernetes/)
>  Kubernetes is comprised of a set of independent, composable control processes that continuously drive the current state towards the provided desired state. It shouldn’t matter how you get from A to C. 

[Monitoring compute resource usage](https://kubernetes.io/docs/concepts/configuration/manage-compute-resources-container/#monitoring-compute-resource-usage)

[Tools for Monitoring Compute, Storage, and Network Resources](https://kubernetes.io/docs/tasks/debug-application-cluster/resource-usage-monitoring/)

kubectl patch pod default-cpu-demo-2 -p '{"spec":{"containers":[{"name":"default-cpu-demo-2-ctr","image":"nginx","resources":{"limits":{"cpu":"0.5"}}}]}}'