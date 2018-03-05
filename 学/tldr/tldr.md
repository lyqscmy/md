



```
FROM debian:jessie
RUN buildDeps='gcc libc6-dev make' \
&& apt-get update \
&& apt-get install -y $buildDeps \
&& wget -O redis.tar.gz "http://download.redis.io/releases/redis-3.2.5.tar.gz" \
&& mkdir -p /usr/src/redis \
&& tar -xzf redis.tar.gz -C /usr/src/redis --strip-components=1 \
&& make -C /usr/src/redis \
&& make -C /usr/src/redis install \
&& rm -rf /var/lib/apt/lists/* \
&& rm redis.tar.gz \
&& rm -r /usr/src/redis \
&& apt-get purge -y --auto-remove $buildDeps
```


- rpm

  ```
   rpm -ivh kernel-smp-2.4.21-15.0.3.EL.i686.rpm
  ```

# file

检测文本编码
file -i

# tree
控制最大展示层级
tree -L 1

# cut

== sort
sort -k 2
== ssh
scp {{path/to/local_file}} {{remote_host}}:{{path/to/remote_file}}
scp  10.21.25.10:/home/developer/

## user and group

useradd -m -G wheel liyongqiang
usermod -aG wheel developer
passwd liyongqiang
gpasswd --add username group
sudo chown -R xuxitao: /data/redis
chmod -R g+rw /data/redis

== package
yum clean all,yum makecache
scl enable rh-python35 bash
yum install -y epel-release && yum update -y

# Network

ping
>  It is a good practice to use the ping program to quickly check the latency between the client and server hosts is normal before launching the benchmark.
>  ifocnfig | grep inet

== parallel
 split file -b 100m data/

- install
   (wget -O - pi.dk/3 || curl pi.dk/3/ || fetch -o - http://pi.dk/3) | bash
- dry run
  parallel --dryrun echo {} ::: A B C
  ls data/ | parallel --dryrun python
- signle input source
  The input source can be a file:

  parallel -a abc-file echo

Output: Same as above.

STDIN (standard input) can be the input source:

  cat abc-file | parallel echo

# Linux

- checksum

```shell
$ cat hash.md5
595f44fec1e92a71d3e9e77456ba80d1  filetohashA.txt
71f920fa275127a7b60fa4d4d41432a3  filetohashB.txt
43c191bf6d6c3f263a8cd0efd4a058ab  filetohashC.txt
$ md5sum -c hash.md5
filetohashA.txt: OK
filetohashB.txt: OK
filetohashC.txt: OK
```

- list files sorted by time and show human-read size format
```shell
alias lt="ls -lht"
```


# Hive

- creat TEMPORARY table/创建临时表，会话结束后自动删除
```SQL
CREATE TEMPORARY TABLE  [db_name.]table_name
[(col_name data_type)...]
```
```SQL
-- 创建与已经存在的表，结构相似的临时表
CREATE TEMPORARY TABLE  [db_name.]table_name
LIKE existing_table_or_view_name
```

- insert select into/把select出来的数据加载到目标表中
```SQL
INSERT [OVERWRITE] TABLE tablename1  select_statement1 FROM from_statement;
```

- load data from local host file to Hive table/把本地机器上的文件加载到Hive里，需登录ssh
```SQL
-- 可以保存为load.hql,每次只需修改filepath和tablename
LOAD DATA [LOCAL] INPATH 'filepath' [OVERWRITE] INTO TABLE tablename
```
```shell
hive -f load.hql
```

- Writing data into the filesystem from queries/把Hive的查询数据写到本地csv文件
```SQL
-- 注意Hive表里有复合类型的列时，可能会有歧义。
hive -f select.hql | sed 's/[[:space:]]\+/,/g' > /home/syang/lyq/temp.csv
```

## beeline
!connect jdbc:hive2://10.20.7.33:10000 syang PoTCdg

beeline -u jdbc:hive2://10.20.7.33:10000/fleegood -n syang -p PoTCdg
