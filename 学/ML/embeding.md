[Word Embeddings: Encoding Lexical Semantics](http://pytorch.org/tutorials/beginner/nlp/word_embeddings_tutorial.html)

* How do we get from a massive dimensional space to a smaller dimensional space?

* This is what we mean by a notion of similarity: we mean semantic similarity, not simply having similar orthographic representations. It is a technique to combat the sparsity of linguistic data, by connecting the dots between what we have seen and what we haven’t. This example of course relies on a fundamental linguistic assumption: that words appearing in similar contexts are related to each other semantically. This is called the distributional hypothesis.

* Typcially, CBOW is used to quickly train word embeddings, and these embeddings are used to initialize the embeddings of some more complicated model. Usually, this is referred to as pretraining embeddings. It almost always helps performance a couple of percent.