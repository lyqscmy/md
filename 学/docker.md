tag:docker|container
# docker
[Configure the default CFS scheduler](https://docs.docker.com/config/containers/resource_constraints/#configure-the-default-cfs-scheduler)
docker run -it --cpus=".5" ubuntu /bin/bash
--cpuset-cpus