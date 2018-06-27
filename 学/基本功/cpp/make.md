# debug build
cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ..
ninja -n -v


.PHONY: all clean
CC = gcc
CCFLAGS = -O3 -Wall -march=native -std=c11
CXX = g++
CXXFLAGS = -O3 -Wall -march=native -std=c++11
LDFLAGS =  -I /usr/lib64/openmpi-x86_64 -L/usr/lib64/openmpi/lib -lmpi

all: main

main: mpi
	$(CC) $(CCFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm main


.PHONY: train test vivo thu clean

model = run_cnn.py

train:
	python $(model) train

test:
	python $(model) test

vivo:
	ln -sf /data/yqli/text_classification/vivonews/ ./data/cnews

thu:
	ln -sf /data/yqli/text_classification/cnews/ ./data/cnews

clean:
	rm -r tensorboard/  checkpoints/