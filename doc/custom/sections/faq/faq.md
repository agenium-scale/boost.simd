Frequently Asked Questions {#faq}
=========

@section faq-questions Frequently Asked Questions

-------------------------------------------------

- [Is it good practice to use a pack as an array?](#faq-pack-array)
- [Why is the speed-up of my code not as expected?](#faq-speed)
- [My code seg-faulted or crashed](#faq-memory-alignment)
- [I tried to use a comparison operator and my code failed to compile](#faq-comparison)
- [How do I measure the speed-up of my code](#faq-speed-up)
- [My AVX code is not twice as fast as SSE](#faq-sse-avx)
- [I disassembled my code, and the generated code is less than optimal.](#faq-code-gen)
- [How can I use a certain intrinsic?](#faq-intrisic)

@subsection faq-pack-array Is it good practice to use a pack as an array?

-------------------------------------------------

The main element of @projectname is the boost::simd::pack class. pack is an abstraction over a block
of `N` elements of type `T`, quite similar to `std::array`. The main semantic difference is that
boost::simd::pack is implemented as the best hardware specific type able to store this amount of
data which may be a simple scalar array, a single SIMD register or a tuple of SIMD registers
depending on `N` and `T`.

In general, the good practice is to store data in regular, dynamic allocated data block and apply
your algorithms over those data using pack and related functions.

@subsection faq-speed Why is the speed-up of my code not as expected?

-------------------------------------------------

  There are several factors which can reduce the speed-up obtained using **@projectname**.
  - Have you enabled compiler optimizations?
    You must enable all compiler optimizations as well as defining the `NDEBUG` flag

    <center>
    Compiler                | Flag
    ------------------------|-------------------
    g++                     | -O3
    clang++                 | -O3
    Intel C++ Compiler      | -O3
    Microsoft Visual Studio | Enable Release mode
    </center>


  - Have you compiled in 64bit mode?
    There is significant performance increase on architectures supporting
    64 bit binaries.

  - Is you algorithm memory bound?
    Computational problems can often be classed as either compute-bound or
    memory-bound. Memory bound problems reach the limits of the system
    bandwidth transfering data between the memory and the processor, while
    compute-bound problems are limited by the processor's calculation ability.

    Processors have often several hierarchies of caches. The time taken to
    transfer data from the cache to a register varies depending on the cache.
    When the required data is not in the cache, it is referred to as a cache
    miss. Cache-misses are very expensive. Data is transferred from memory
    to the cache in cache-lines sized chunks. On modern x86 machines, a cache-line is
    64 bytes or twice the size of an AVX register. It is therefore highly
    advantageous to use all data loaded into cache.

    The following loop is clearly memory bound as all of the time is spent
    loading and storing the data. The cost of the computation is negligible
    compared to that of the memory accesses.

    @snippet memorybound.cpp memory-memory

    The following loop is compute-bound. As most of the time is spent calculating
    exp, significant speed-up is observed when this code is vectorized.

    @snippet memorybound.cpp memory-compute

  - Is your code trivially vectorizable?
    Modern compilers can vectorize trivial code segments automatically. If you
    benchmark a trivial scalar code versus a vectorized code, the compiler may
    vectorize the scalar code, thereby giving similar performance to the vectorized
    version.

  - Is your algorithm vectorizable?
  - Have you used the fastest version of your function?
    Several **@projectname** functions, particularly more complex ones, come in several
    versions, where the user has a choice between accuracy and speed. This is achieved using
    decorators. Please refer to @ref group-decorator for more information.

@subsection faq-memory-alignment Why did my code seg-faulted or crashed?

-------------------------------------------------

The most common cause of seg-faults in SIMD codes is accessing non-aligned memory. For best
performance, all memory should be aligned on pack_t::alignment bytes. @projectname includes an
aligned memory allocator to help you with this. Please refer to @ref tutorial-memory for details
on how to ensure that you memory is correctly aligned.

@subsection faq-comparison I tried to use a comparison operator and my code failed to compile

-------------------------------------------------

The most common reason for this is that the two packs being compared are not of the same type.
Another common reason is that the return type is incorrect. Using auto is one way of preventing
this error, however, it is best to be aware of the types you are using. Comparison operators in
**@projectname** are of two types, either vectorized comparison, where the results is a vector
of logical with the same cardinal as the input vectors, or a reduction comparison, where the
result is a bool.

@subsection faq-speed-up How to measure the speed-up of SIMD code?

-------------------------------------------------

There are several ways to measure the speed-up of your code. You may use the **@projectname** bench
system to benchmark your code segment. This allows you to measure the execution time of your code
in cycles per element or in units of time.

Otherwise, you may use standard timing routines such as those available in `std::chrono`.
In order to accurately benchmark your code, there are several points to consider.

- Your input should be sufficiently large. This is to eliminate cache effects.
- Your code is compiled in release mode, with all optimizations enabled and debug information
  not included.
- You should measure several times and use the average (or better the median).

A typical case where a benchmark could give inaccurate results is where the input is not
large enough to fill the cache and a scalar and SIMD code segment are individually benchmarked, one
after the other. In this case, all of the data will be loaded into the cache during the first bench,
and will be available for the second bench, therefore decreasing the execution time of the second bench.
Also, if you measure the code segment multiple times, the data from the first execution will already be
in the cache.

@subsection faq-sse-avx My code compiled for AVX is not twice as fast as for SSE

-------------------------------------------------

Not all SSE instructions have an equivalent AVX instruction. Also, the cycles required for
certain instructions are not equal on both architectures, for example, sqrt on SSE requires
10-14 cycles whereas sqrt on AVX requires 21-28 cycles. Please refer
<a href="http://www.agner.org/optimize/instruction_tables.pdf">here</a> for more information.

Very few integer operations are supported on AVX, AVX2 is required for most integer operations. If
a **@projectname** function is called on an integer AVX register, this register will be split into
two SSE registers and the equivalent instruction called on both register. In the case, no speed-up
will be observed compared with SSE code. This is true also on Altivec, where double is not
supported.

@subsection faq-code-gen I disassembled my code, and the generated code is less than optimal.

-------------------------------------------------

- Have you compiled in release mode, with full optimizations with DNDEBUG defined?
- Have you used a 64 bit compiler?
- There are many SIMD related bugs across all compilers, and some compilers generate less than
  optimal code in some cases. Is it possible to update your compiler to a more modern compiler?
- We provide workarounds for all known compiler bugs, however, we may have missed some. You may
  also have found a bug in **@projectname**. Please report this through issues on our
  <a href="https://github.com/numscale/boost.simd/issues">github</a>
  with a minimal code example. We responds quickly to bug reports and do our best to patch them as
  quickly as possible.

@subsection faq-intrisic How can I use a certain intrinsic?

-------------------------------------------------

If you require a certain intrinsic, you may search inside of **@projectname** for it and then call
the relevant function.

In rare cases, the intrinsic may not be included in **@projectname** as we map the intrinsic wherever
it makes sense semantically. If a certain intrinsic does not fit inside of this model, if may be
excluded. In this case, you may call it yourself, however, this will not be portable.
