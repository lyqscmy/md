# 原型
```C
#define M 32 //M maybe change

// matrix.shape = M x N; const between function calls
// indices in [0,N)
// sparse vector = (indices, values)
float foo(float *matrix, int len, int *indices, float *values)
{
    float y[M];
    for (int i = 0; i < len; i++)
    {
        axpy(M, values[i], matrix[indices[i]], y);
    }

    float z[M];
    for (int i = 0; i < len; i++)
    {
        // z = a*x(y-a*x) + z;
        mykernel(M, values[i], matrix[indices[i]], y, z);
    }

    return sum(z, 0, M) / 2;
}
```
# 参考
```c
void saxpy_kernel_16( int n, float *x, float *y, float *alpha)
{


	int register i = 0;

	__asm__  __volatile__
	(
	"vbroadcastss		(%4), %%ymm0		    \n\t"  // alpha	

	".align 16				            \n\t"
	"1:				            \n\t"

    "vmovups                  (%3,%0,4), %%ymm12         \n\t"  // 8 * y
    "vmovups                32(%3,%0,4), %%ymm13         \n\t"  // 8 * y
    "vmovups                64(%3,%0,4), %%ymm14         \n\t"  // 8 * y
    "vmovups                96(%3,%0,4), %%ymm15         \n\t"  // 8 * y
	"vfmadd231ps       (%2,%0,4), %%ymm0  , %%ymm12  	     \n\t"   // y += alpha * x
	"vfmadd231ps     32(%2,%0,4), %%ymm0  , %%ymm13  	     \n\t"   // y += alpha * x
	"vfmadd231ps     64(%2,%0,4), %%ymm0  , %%ymm14  	     \n\t"   // y += alpha * x
	"vfmadd231ps     96(%2,%0,4), %%ymm0  , %%ymm15  	     \n\t"   // y += alpha * x
	"vmovups	%%ymm12,   (%3,%0,4)		     \n\t"
	"vmovups	%%ymm13, 32(%3,%0,4)		     \n\t"
	"vmovups	%%ymm14, 64(%3,%0,4)		     \n\t"
	"vmovups	%%ymm15, 96(%3,%0,4)		     \n\t"

	"addq		$32, %0	  	 	             \n\t"
	"subq	        $32, %1			             \n\t"		
	"jnz		1b		             \n\t"
	"vzeroupper				     \n\t"

	:
        : 
          "r" (i),	// 0	
	  "r" (n),  	// 1
          "r" (x),      // 2
          "r" (y),      // 3
          "r" (alpha)   // 4
	: "cc", 
	  "%xmm0", 
	  "%xmm8", "%xmm9", "%xmm10", "%xmm11", 
	  "%xmm12", "%xmm13", "%xmm14", "%xmm15",
	  "memory"
	);

} 

```
# 尝试一
Intrinsics
失败
编译器没有做循环展开
指令对齐

```c
#include <immintrin.h>
#define ALIGNED_K 32

float fm_score(float *model, int n, int *indices,
               float *values) {
  __m256 YMMs0, YMMs1, YMMs2, YMMs3;
  for (int i = 0; i < n; ++i, ++indices, ++values) {
    float v = *values;
    __m256 YMMv = _mm256_set1_ps(v); // vbroadcastss
    float *w = model + (*indices) * ALIGNED_K;
    __m256 YMMw0 = _mm256_load_ps(w); // vmovups
    __m256 YMMw1 = _mm256_load_ps(w + 8);
    __m256 YMMw2 = _mm256_load_ps(w + 16);
    __m256 YMMw3 = _mm256_load_ps(w + 24);
    YMMs0 = _mm256_add_ps(YMMs0, _mm256_mul_ps(YMMw0, YMMv)); // vfmadd231ps
    YMMs1 = _mm256_add_ps(YMMs1, _mm256_mul_ps(YMMw1, YMMv));
    YMMs2 = _mm256_add_ps(YMMs2, _mm256_mul_ps(YMMw2, YMMv));
    YMMs3 = _mm256_add_ps(YMMs3, _mm256_mul_ps(YMMw3, YMMv));
  }

  /* __m256 YMMs0, YMMs1, YMMs2, YMMs3; */
  /* YMMt = _mm256_hadd_ps(YMMs0, YMMs1); */
  /* YMMt = _mm256_hadd_ps(YMMt, YMMt); */
  /* YMMt = _mm256_hadd_ps(YMMt, YMMt); */
  float t = 0.0f;
  _mm_store_ss(&t, _mm256_castps256_ps128(YMMs0));
  // vmovups
  return t;
}
```

```asm
fm_score:
  testl %esi, %esi
  jle .L2
  leal -1(%rsi), %eax
  xorl %esi, %esi
  leaq 4(,%rax,4), %r8
.L3:
  vbroadcastss (%rcx,%rsi), %ymm1
  movl $5, %eax
  shlx %eax, (%rdx,%rsi), %eax
  cltq
  addq $4, %rsi
  vfmadd231ps (%rdi,%rax,4), %ymm1, %ymm0
  cmpq %rsi, %r8
  jne .L3
.L2:
  vzeroupper
  ret
```

