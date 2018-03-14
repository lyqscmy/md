TAGS:nginx openresty microservice

[Inside NGINX: How We Designed for Performance & Scale](https://www.nginx.com/blog/inside-nginx-how-we-designed-for-performance-scale/)

[What is Kubernetes?](https://kubernetes.io/docs/concepts/overview/what-is-kubernetes/)

[nginx](http://aosabook.org/en/nginx.html)

> Nowadays, concurrency is caused by a combination of mobile clients and newer application architectures which are typically based on maintaining a **persistent connection** that allows the client to be updated with news, tweets, friend feeds, and so on. Another important factor contributing to increased concurrency is the changed behavior of modern browsers, which open four to six **simultaneous connections** to a website to improve page load speed.

> more and more often an exercise in pushing the web server to the edge of the infrastructure and integrating the same or a revamped set of applications and database tools **around it** in a different way.

> nginx is very well suited for this, as it provides the key features necessary to conveniently **offload concurrency**, **latency processing**, **SSL (secure sockets layer)**, **static content**, **compression** and **caching**, connections and **requests throttling**, and even HTTP **media streaming** from the application layer to a much more efficient edge web server layer.

>  It was actually inspired by the ongoing development of advanced **event-based mechanisms** in a variety of operating systems. What resulted is a **modular**, **event-driven**, **asynchronous**, **single-threaded**, **non-blocking** architecture which became the foundation of nginx code.

> The nginx worker code includes the core and the functional modules. The core of nginx is responsible for maintaining a tight run-loop and executing appropriate sections of modules' code on each stage of request processing. Modules constitute most of the presentation and application layer functionality. 

> Modules read from and write to the network and storage, transform content, do outbound filtering, apply server-side include actions and pass the requests to the upstream servers when proxying is activated.

>  nginx modules come in slightly different incarnations, namely **core modules**, **event modules**, **phase handlers**, **protocols**, **variable handlers**, **filters**, **upstreams** and **load balancers**. 

[The NGINX Application Platform](https://www.nginx.com/products/)
[OpenResty 最佳实践](https://moonbingbing.gitbooks.io/openresty-best-practices/content/)
[自动为你编程的分布式流量管理软件](https://openresty.com/en/)


# [Streaming media](https://www.nginx.com/products/nginx/streaming-media/)
应用场景
- content(text/image/video) cache
- load balancer
- waf

>  The NGINX Application Platform includes **NGINX Plus** for load balancing and application delivery, the NGINX WAF for security, and **NGINX Unit** to run the application code, all monitored and managed by the **NGINX Controller**.