[CMake VS Bazel](https://github.com/PaddlePaddle/Paddle/issues/932)

bazel query --nohost_deps --noimplicit_deps 'deps(:vivo)' --output graph

sudo apt install graphviz xdot

bazel query --nohost_deps --noimplicit_deps \
'deps(//tensorflow:libtensorflow_framework.so)' \
--output graph | xdot