[google benchmark](https://github.com/google/benchmark)
git checkout v1.4.0
makedir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=RELEASE -DBENCHMARK_DOWNLOAD_DEPENDENCIES=ON
