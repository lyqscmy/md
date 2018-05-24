tag:tensorflow

# session
[config](https://github.com/tensorflow/tensorflow/blob/r1.8/tensorflow/core/protobuf/config.proto)


# configure
Do you wish to build TensorFlow with jemalloc as malloc support? [Y/n]: y
Do you wish to build TensorFlow with XLA JIT support? [y/N]: y
Please specify optimization flags to use during compilation when bazel option "--config=opt" is specified [Default is -march=native]:

# compile
bazel build --config=opt //tensorflow/tools/pip_package:build_pip_package


# ConfigProto

message ConfigProto {
 // The execution of an individual op (for some op types) can be
  // parallelized on a pool of intra_op_parallelism_threads.
  // 0 means the system picks an appropriate number.
  int32 intra_op_parallelism_threads = 2;

  // Nodes that perform blocking operations are enqueued on a pool of
  // inter_op_parallelism_threads available in each process.
  //
  // 0 means the system picks an appropriate number.
  //
  // Note that the first Session created in the process sets the
  // number of threads for all future sessions unless use_per_session_threads is
  // true or session_inter_op_thread_pool is configured.
  int32 inter_op_parallelism_threads = 5;


  // If true, use a new set of threads for this session rather than the global
  // pool of threads. Only supported by direct sessions.
  //
  // If false, use the global threads created by the first session, or the
  // per-session thread pools configured by session_inter_op_thread_pool.
  //
  // This option is deprecated. The same effect can be achieved by setting
  // session_inter_op_thread_pool to have one element, whose num_threads equals
  // inter_op_parallelism_threads.
  bool use_per_session_threads = 9;
}

// Options passed to the graph optimizer
message OptimizerOptions {
  // If true, optimize the graph using common subexpression elimination.
  bool do_common_subexpression_elimination = 1;

  // If true, perform constant folding optimization on the graph.
  bool do_constant_folding = 2;

  // Constant folding optimization replaces tensors whose values can be
  // predetermined, with constant nodes. To avoid inserting too large constants,
  // the size of each constant created can be limited. If this value is zero, a
  // default limit of 10 MiB will be applied. If constant folding optimization
  // is disabled, this value is ignored.
  int64 max_folded_constant_in_bytes = 6;

  // If true, perform function inlining on the graph.
  bool do_function_inlining = 4;

  // Optimization level
  enum Level {
    // L1 is the default level.
    // Optimization performed at L1 :
    // 1. Common subexpression elimination
    // 2. Constant folding
    L1 = 0;

    // No optimizations
    L0 = -1;
  }

  // Overall optimization level. The actual optimizations applied will be the
  // logical OR of the flags that this level implies and any flags already set.
  Level opt_level = 3;

  // Control the use of the compiler/jit.  Experimental.
  enum GlobalJitLevel {
    DEFAULT = 0;  // Default setting ("off" now, but later expected to be "on")
    OFF = -1;
    // The following settings turn on compilation, with higher values being
    // more aggressive.  Higher values may reduce opportunities for parallelism
    // and may use more memory.  (At present, there is no distinction, but this
    // is expected to change.)
    ON_1 = 1;
    ON_2 = 2;
  }
  GlobalJitLevel global_jit_level = 5;
}

message RunOptions {
// The thread pool to use, if session_inter_op_thread_pool is configured.
  int32 inter_op_thread_pool = 3;
}