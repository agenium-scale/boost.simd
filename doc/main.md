Overview {#mainpage}
=========

@tableofcontents

@section main-preface Introduction

----------------------------------------------------------------------------------------------------
Single instruction, multiple data (_SIMD_) instructions or **multimedia extensions** have been developed by processor manufacturers for several decades. They are designed to significantly accelerate code execution, however they require expertise to be correctly used and they depend on potentially fragile compiler support, or vendor-specific libraries to be correctly and successfully exploited. The introduction of these instruction sets has allowed developers to exploit the latent data parallelism available in applications by executing a given instruction simultaneously on multiple data stored in dedicated cpu registers. The SIMD unit is built as an independent computation unit in the processor, it comes in addition to the regular computation unit complete with a special register file, dispatching and pipelining unit.

In order to exploit these powerful instruction sets, developers must use low-level intrinsics (for example, low-level C functions) in their code. This approach forces developers to program into a very verbose manner due to the low-level nature of _SIMD_ instruction sets. Furthermore, one is required to re-write code for each revision of each target architecture, accounting for each architecture's vendor provided API as well as architecture dependent implementation details. This greatly complicates the design and maintenance of code using _SIMD_ instructions, significantly increasing the development, testing and deployment time and well as the scope for introducing errors. Therefore, it is clear that developing applications that exploit  _SIMD_ extensions is a complex and error-prone task.

**Boost.SIMD** is a Boost candidate library which aims to abstract the use of _SIMD_ extensions in an architecture, compiler and vendor neutral manner. This abstraction provides more than simple portable wrappers above hardware-specific registers, it also standardizes the use of common _SIMD_ programming idioms.

**Boost.SIMD** allows one to write _SIMD_ vectorized code that is portable across all (supported) compilers, architectures and operating systems.

**Boost.SIMD** achieves this by providing:

  + a proper value semantic wrapper for _SIMD_ registers;
  + an automatic system to detect and exploit architecture specific optimization opportunities;
  + standard compliant iterators to iterate over contiguous range of data in a _SIMD_ compatible way;
  + standard compliant iterators encapsulating complex _SIMD_ idioms like sliding window or de-interleaving of data on the fly.

@section main-support Supported Compilers and Hardware

----------------------------------------------------------------------------------------------------
The open-source version of **Boost.SIMD** includes support for x86 processors. Optional modules with support for
The current set of SIMD extensions supported by **Boost.SIMD** includes:

#TODO: I do not understand the last sentence J.T.
#TODO: Make sure the free/paid columns are correct, maybe instead of column bold the free extensions?


<center>
Architecture | Extensions                                          | Accessibility
-------------|-----------------------------------------------------|-----------------
x86          | SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, FMA3, AVX2  | **Free**
x86          | Xeon Phi                                            | Premium
AMD          | SSE4a, XOP, FMA4                                    | Premium
PowerPC      | VMX                                                 | **Free**
PowerPC      | VMX, VSX, QPX                                       | Premium
ARM          | Neon                                                | Premium
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
    Tutorial for writing Boost.SIMD code.

  - @ref group-api\n
    Public functions and type API of Boost.SIMD

  - @ref group-concept\n
    Concepts defined and used throughout Boost.SIMD.

  - @ref group-config\n
    Macros which are defined to control the configuration of Boost.SIMD code.

  - @ref group-ext\n
    Documentation for extension points for library's components. This documentation is useful
    for people wanting to extend Boost.SIMD to work with their own types.

  - @ref group-hierarchy\n
    Documentation for the predefined type hierarchy used by the library.

  - @ref group-detail\n
    Documentation of library implementation details. This section is useful
    for those wishing to understand the library internals and those wishing
    to contribute to the development of Boost.SIMD.


----------------------------------------------------------------------------------------------------

<!-- Links -->
<!-- [name]: url -->
