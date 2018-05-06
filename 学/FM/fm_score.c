#include <immintrin.h>

#define HAVE_KERNEL_16 1

#ifdef HAVE_KERNEL_16

static void saxpy_kernel_16(int n, float *x, float *y, float *alpha) __attribute__((noinline));

static void saxpy_kernel_16(int n, float *x, float *y, float *alpha)
{

    int register i = 0;

    __asm__ __volatile__(
        "vbroadcastss		(%4), %%ymm0		    \n\t" // alpha

        ".align 16				            \n\t"
        "1:				            \n\t"

        "vmovups                  (%3,%0,4), %%ymm12         \n\t"     // 8 * y
        "vmovups                32(%3,%0,4), %%ymm13         \n\t"     // 8 * y
        "vmovups                64(%3,%0,4), %%ymm14         \n\t"     // 8 * y
        "vmovups                96(%3,%0,4), %%ymm15         \n\t"     // 8 * y
        "vfmadd231ps       (%2,%0,4), %%ymm0  , %%ymm12  	     \n\t" // y += alpha * x
        "vfmadd231ps     32(%2,%0,4), %%ymm0  , %%ymm13  	     \n\t" // y += alpha * x
        "vfmadd231ps     64(%2,%0,4), %%ymm0  , %%ymm14  	     \n\t" // y += alpha * x
        "vfmadd231ps     96(%2,%0,4), %%ymm0  , %%ymm15  	     \n\t" // y += alpha * x
        "vmovups	%%ymm12,   (%3,%0,4)		     \n\t"
        "vmovups	%%ymm13, 32(%3,%0,4)		     \n\t"
        "vmovups	%%ymm14, 64(%3,%0,4)		     \n\t"
        "vmovups	%%ymm15, 96(%3,%0,4)		     \n\t"

        "addq		$32, %0	  	 	             \n\t"
        "subq	        $32, %1			             \n\t"
        "jnz		1b		             \n\t"
        "vzeroupper				     \n\t"

        :
        : "r"(i),    // 0
          "r"(n),    // 1
          "r"(x),    // 2
          "r"(y),    // 3
          "r"(alpha) // 4
        : "cc",
          "%xmm0",
          "%xmm8", "%xmm9", "%xmm10", "%xmm11",
          "%xmm12", "%xmm13", "%xmm14", "%xmm15",
          "memory");
}

#else

static void saxpy_kernel_16(int n, float *x, float *y, float *alpha)
{
    int register i = 0;
    float a = *alpha;

    while (i < n)
    {
        y[i] += a * x[i];
        y[i + 1] += a * x[i + 1];
        y[i + 2] += a * x[i + 2];
        y[i + 3] += a * x[i + 3];
        y[i + 4] += a * x[i + 4];
        y[i + 5] += a * x[i + 5];
        y[i + 6] += a * x[i + 6];
        y[i + 7] += a * x[i + 7];
        i += 8;
    }
}

#endif

static void saxpy_intrinsics(int n, float a, float *x, float *y)
{
    int register i = 0;
    __m256 YMMs0, YMMs1, YMMs2, YMMs3;
    __m256 YMMa = _mm256_set1_ps(a); // vbroadcastss
    while (i < n)
    {
        __m256 YMMx0 = _mm256_load_ps(x); // vmovups
        __m256 YMMx1 = _mm256_load_ps(x + 8);
        __m256 YMMx2 = _mm256_load_ps(x + 16);
        __m256 YMMx3 = _mm256_load_ps(x + 24);
        YMMs0 = _mm256_add_ps(YMMs0, _mm256_mul_ps(YMMw0, YMMv)); // vfmadd231ps
        YMMs1 = _mm256_add_ps(YMMs1, _mm256_mul_ps(YMMw1, YMMv));
        YMMs2 = _mm256_add_ps(YMMs2, _mm256_mul_ps(YMMw2, YMMv));
        YMMs3 = _mm256_add_ps(YMMs3, _mm256_mul_ps(YMMw3, YMMv));

        i += 8;
    }
}
