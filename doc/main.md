Introduction {#mainpage}
=========
@tableofcontents

Welcome to the world of portable, hassle free SIMD programming! **Boost.SIMD** was developed to simplify the difficult, tedious
and often error-prone process of developing SIMD programs. **Boost.SIMD** is designed to seamlessly integrate into existing projects
so that you can quickly and easily start developing high performance, portable and future proof software.

@section main-what What is SIMD?

-------------------------------------

Single instruction, multiple data (__SIMD__) instructions or **multimedia extensions** have been available
for many years. They are designed to significantly accelerate code execution, however they require expertise to be used correctly
and they depend on potentially fragile compiler support and the use of low-level intrinsics, or vendor-specific libraries.
The introduction of these instruction sets has allowed developers to exploit the latent data parallelism available in applications by
executing a given instruction simultaneously on multiple data stored in dedicated cpu registers. The SIMD unit is built as an independent
computation unit in the processor, it comes in addition to the regular computation unit complete with a special register file,
dispatching and pipelining unit.

@section main-why Why use Boost.SIMD?

-------------------------------------

Whether you are a first time SIMD programmer or an experienced team leader, **Boost.SIMD** can make your life and
that of your team easier as the use of SIMD instructions requires developers to program into a very verbose manner due to the low-level nature of SIMD instruction
sets. Furthermore, it is necessary to re-write code for each revision of each target architecture, accounting for each architecture's
vendor provided API as well as architecture dependent implementation details. This greatly complicates the design and maintenance of
SIMD code, significantly increasing the time required to develop, test and deploy software as well as increasing the scope for introducing
bugs.

For example, take this simple case where we calculate the sum of two vectors of `32-bit float` vectors:

@snippet addvector.cpp scalar-loop

Each element of the results vector is independent of every other element - therefore this function may easily be vectorized as there is latent data parallelism which may be exploited.
This simple loop may be vectorized for an x86 processor using Intel intrinsic functions. For example, the following code vectorizes this loop for an `SSE` enabled processor:

@snippet addvector.cpp sse2-simd-loop

Looks difficult? How abut we vectorize it for the following generation of Intel processor equipped with `AVX` instructions:

@snippet addvector.cpp avx-simd-loop

Both of these processor are manufactured by Intel yet two different versions of the code are required to get the best performance possible from the processors.
Imagine the complication of moving to another manufacturer's processor, for example IBM. Let's try re-write this same simple loop for a `VMX` equipped processor:

@snippet addvector.cpp vmx-simd-loop

This is quicky getting complicated and annoying. Wouldn't life be much easier if someone else took care of this mess? Imagine being able to write one version of your code,
which has optimal performance across all architectures, compilers and operating systems? Imagine not having to worry about re-writing your code for each new processor released?
Well, imagine no more and behold the beauty and simplicity of **Boost.SIMD**!

@snippet addvector.cpp bs-simd-loop

**Boost.SIMD** is designed to be user-friendly, easy to integrate into existing projects. To achieve this, **Boost.SIMD** harnesses the latest innovations in the
C++ language, but is still easy to use with an intuitive interface. To make life even easier for you, we have included lots of commonly used functions and constants
directly in **Boost.SIMD**, standardizing the use of common _SIMD_ programming idioms. And because we are nice people, we have thoroughly tested **Boost.SIMD**
across different architectures, compilers and operating systems, so we have even included work-arounds for all known compiler bugs!

**Boost.SIMD** allows you to focus on the important part of your work: the development of new features and functionality. We take care of all
of the architecture and compiler specific details and we provide updates when new architectures are released by manufacturers. All you have to
do is re-compile your code every time you target a new architecture!

**Boost.SIMD** provides the following:

  + a proper value semantic wrapper for _SIMD_ registers;
  + an automatic system to detect and exploit architecture specific optimization opportunities;
  + standard compliant iterators to iterate over contiguous range of data in a _SIMD_ compatible way;
  + standard compliant iterators encapsulating complex _SIMD_ idioms like sliding window or de-interleaving of data on the fly.

@section main-support Supported Compilers and Hardware

----------------------------------------------------------------------------------------------------
The open-source version of **Boost.SIMD** includes support for some x86 and VMX processors. Optional modules with support for
additional architectures are also available.
The following SIMD extensions are supported by **Boost.SIMD**:

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
g++                     | 4.8 and above
clang++                 | 3.5 and above
Microsoft Visual Studio | 15.0 and above
</center>

**Boost.SIMD** requires **Boost** version 1.60 or newer.

----------------------------------------------------------------------------------------------------

<!-- Links -->
<!-- [name]: url -->
