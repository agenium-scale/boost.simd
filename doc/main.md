Introduction {#mainpage}
=========

Single instruction, multiple data (__SIMD__) instructions or **multimedia extensions** have been available
for many years. They are designed to significantly accelerate code execution, however they require expertise
to be used correctly, depends on non-uniform compiler support, the use of low-level intrinsics, or vendor-specific
libraries.

**Boost.SIMD** is Boost candidate library that aims at simplifying the error-prone process of developing
application exploiting the potential of SIMD instructions sets. **Boost.SIMD** is designed to seamlessly
integrate into existing projects so that you can quickly and easily start developing high performance,
portable and future proof software.

@section main-why Why use Boost.SIMD?

-------------------------------------

**Boost.SIMD** standardize and make the use of SIMD instructions across hardware simpler by not
relying on verbose, low-level nature SIMD instructions. Furthermore, the portability of **Boost.SIMD**
prevent the cumbersome re-write of code for each revision of each target architecture, accounting for
each architecture's vendor provided API as well as architecture dependent implementation details.
This greatly reduce the design complexity and maintenance of SIMD code, significantly decreasing
the time required to develop, test and deploy software as well as decreasing the scope for introducing bugs.

**Boost.SIMD** allows you to focus on the important part of your work: the development of new features
and functionality. We take care of all of the architecture and compiler specific details and we provide
updates when new architectures are released by manufacturers. All you have to do is re-compile your code
every time you target a new architecture through the following components:

  + a proper value semantic wrapper for _SIMD_ registers
  + more than 300 mathematical functions ready to use and already vectorized
  + an automatic system to detect and exploit architecture specific optimization opportunities
  + standard compliant iterators to iterate over contiguous range of data in a _SIMD_ compatible way

@subsection main-why-example A Short Example

-------------------------------------

Let's take this simple case where we calculate the sum of two vectors of 32-bits float:

@snippet addvector.cpp scalar-loop

Each element of the results vector is independent of every other element - therefore this function may easily be vectorized as there is latent data parallelism which may be exploited. This simple loop may be vectorized for an x86 processor using Intel intrinsic functions. For example, the following code vectorizes this loop for an `SSE` enabled processor:

@snippet addvector.cpp sse2-simd-loop

Looks difficult? How about we vectorize it for the following generation of Intel processor equipped with `AVX` instructions:

@snippet addvector.cpp avx-simd-loop

Both of these processor are manufactured by Intel yet two different versions of the code are required to get the best performance possible from the processors. Imagine the complication of moving to another manufacturer's processor, for example IBM. Let's try re-write this same simple loop for a `VMX` equipped processor:

@snippet addvector.cpp vmx-simd-loop

This is quicky getting complicated and annoying.

Now, look at how the code can become simpler with **Boost.SIMD** :

@snippet addvector.cpp bs-simd-loop

And of course, if your C++ sense is tingling, you have noticed this piece of code can actually be
a candidate to use standard algorithm like `std::transform`. The good news is that **Boost.SIMD**
also provide vectorizing version of such algorithms:

@snippet addvector.cpp bs-simd-transform

Happy user of C++14 ? **Boost.SIMD** is also compatible with the newest additions to the language like
lambda function:

@snippet addvector.cpp bs-simd-transform-14

@subsection main-support Supported Compilers and Hardware

-------------------------------------------------------------

**Boost.SIMD** includes support for some Intel and IBM processors:

<center>
Architecture | Extensions
-------------|-----------------------------------------------------
x86          | SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, FMA3, AVX2
PowerPC      | VMX
</center>

**Boost.SIMD** requires a C++11 compliant compiler and is thoroughly tested on the following compilers:

<center>
Compiler                | Version
------------------------|-------------------
g++                     | 4.8 or above
clang++                 | 3.5 or above
Microsoft Visual Studio | 2015 update 1 or above
Intel C++ Compiler      | 16.0 or above
</center>

**Boost.SIMD** requires **Boost** version 1.60 or newer.

----------------------------------------------------------------------------------------------------
