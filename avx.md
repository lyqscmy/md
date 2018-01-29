[**Intrinsics Guide**](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#)

[**SSE intrinsics optimizations in popular compilers** ](http://www.liranuna.com/sse-intrinsics-optimizations-in-popular-compilers/)

align array?

Assume no pointer aliasing. __declspec(noalias) or __restrict or #pragma optimize("a",on). Specifies that pointer aliasing does not occur. See page 79 for an explanation. Note that these directives do not always work.

Data alignment. __declspec(align(16)) or __attribute__((aligned(16))). Specifies alignment of arrays and structures. Useful for vector operations, see page 107.

