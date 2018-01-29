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