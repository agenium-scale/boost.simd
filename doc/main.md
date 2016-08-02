Introduction {#mainpage}
=========
@tableofcontents

Welcome to the world of portable, hassle free SIMD programming! **Boost.SIMD** was developed to simplify the difficult, tedious
and error-prone process of developing SIMD programs. **Boost.SIMD** is designed to seamlessly integrate into existing projects
so that you can quickly and easily start developing high performance, portable and future proof software.

@section main-what What is SIMD?

-------------------------------------

Single instruction, multiple data (__SIMD__) instructions or **multimedia extensions** have been available
for many years. They are designed to significantly accelerate code execution, however they require expertise to be correctly
used and they depend on potentially fragile compiler support and the use of low-level intrinsics, or vendor-specific libraries.
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

Many of the advancements in processor technology in recent years are SIMD related,
so in order to maximise the return on your hardware investment as well as extending its life, you must
exploit all of the silicon. This can also help reduce the energy consumption of your software, which is crucial
for mobile applications, allowing you to deliver more efficient and better software.

It is clear that the development of applications which exploit SIMD instructions is a complex and error-prone process and that
any tool which reduces this complexity can significantly reduce the time required to develop and maintain software whilst minimising
the potential for the introduction of bugs.

**Boost.SIMD** is a Boost candidate library which aims to abstract the use of _SIMD_ extensions in an architecture, compiler and vendor
neutral manner. This abstraction provides more than simple portable wrappers above hardware-specific registers, it also standardizes
the use of common _SIMD_ programming idioms.

**Boost.SIMD** allows you to focus on the important part of your work: the development of new features and functionality. We take care of all
of the architecture and compiler specific details and we provide updates when new architectures are released by manufacturers.
**Boost.SIMD** allows one to write _SIMD_ vectorized code that is portable across all (supported) compilers, architectures and operating systems.

**Boost.SIMD** achieves this by providing:

  + a proper value semantic wrapper for _SIMD_ registers;
  + an automatic system to detect and exploit architecture specific optimization opportunities;
  + standard compliant iterators to iterate over contiguous range of data in a _SIMD_ compatible way;
  + standard compliant iterators encapsulating complex _SIMD_ idioms like sliding window or de-interleaving of data on the fly.

The following function calculates the sum of two vectors of (`size=16`) `float` elements:

@snippet addvector.cpp scalar-loop

Each element of the results vector is independent of every other element - therefore this function may easily be vectorized.
To vectorize this for a processor which has sse instructions, one could write the following code:

@snippet addvector.cpp sse2-simd-loop

To vectorize this for a processor which has avx instructions, one could write the following code:

@snippet addvector.cpp avx-simd-loop

To vectorize this for an ARM processor which has neon instructions, one could write the following code:

@snippet addvector.cpp arm-simd-loop

In each of these examples, we have written code for two different generations of intel processors and an ARM processors. Each of these functions
are non-portable to other architectures, for example, the intel code will not run on intel processors which do not support these instruction sets or
ARM or IBM processors. This means that a different version of this function must be written for each target architecture. Note also the fact that writing
code using intrinsics functions requires hard coding variables such as the number of elements in a SIMD register. Clearly, coding in such a manner is
time-consuming, error-prone and difficult to maintain and debug. It also requires being intimately familiar with the details of each processor manufacturer's
API.

Another disadvantage of using raw intrinsics is the fact that compiler support varies greatly between vendor, operating system and architecture. For example,
an SSE code which performs as expected on Linux may suffer from performance degradation, bugs or compiler warnings when compiled on Windows and vice-versa.
The goal of **Boost.SIMD** is to abstract all of these disadvantages, leaving the user with one API, regardless of architecture, compiler or operating system.
All known compiler bugs are also managed by **Boost.SIMD** to ensure the quick and efficient development of high performance portable software.

For example, take the function to add two vectors. It may be written using **Boost.SIMD** as follows:

@snippet addvector.cpp bs-simd-loop

In order to obtain maximum performance on any architecture, the user must only re-compile the code specifying the correct architecture flag to the compiler.
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
Microsoft Visual Studio | 13.0 and above
</center>

## Standalone X86

**Boost.SIMD** requires **Boost** version 1.60 or newer.


## Adding Paid Architectures

To be completed...


@section main-howto How to use this documentation

----------------------------------------------------------------------------------------------------
The structure of this documention (available in the menu to the left) is as
follows:

  - @ref tutorials\n
    Tutorial for writing **Boost.SIMD** code.

  - @ref group-api\n
    Public functions and type API of **Boost.SIMD**

  - @ref group-concept\n
    Concepts defined and used throughout **Boost.SIMD**.

  - @ref group-config\n
    Macros which are defined to control the configuration of **Boost.SIMD** code.

  - @ref group-ext\n
    Documentation for extension points for library's components. This documentation is useful
    for people wanting to extend **Boost.SIMD** to work with their own types.

  - @ref group-hierarchy\n
    Documentation for the predefined type hierarchy used by the library.

  - @ref group-detail\n
    Documentation of library implementation details. This section is useful
    for those wishing to understand the library internals and those wishing
    to contribute to the development of **Boost.SIMD**.


----------------------------------------------------------------------------------------------------

<!-- Links -->
<!-- [name]: url -->
