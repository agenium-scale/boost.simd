Main Page {#mainpage}
=========

@tableofcontents

@section main-preface Preface

----------------------------------------------------------------------------------------------------
Single instruction, multiple data (_SIMD_) or **multimedia extensions** have been a feature of choice for processor manufacturers for a couple of decades. Designed to provide significant accelerations, they require expertise, the use of potentially fragile compiler support, or vendor-specific libraries to be correctly and successfully exploited. The introduction of those features has allowed processors to exploit the latent data parallelism available in applications by executing a given instruction simultaneously on multiple data stored in a single special register. Built as an independent computation unit in the processor, it comes in addition to the regular computation unit complete with a special register file, dispatching and pipelining unit.

To access the power of such extensions, programmers use low-level intrinsics (for example, low-level C functions) in their code. This approach forces programmers to deal with a verbose programming style because _SIMD_ instruction sets cover a few common functionalities. The initial algorithm, for example, ends in such a way that is buried in architecture-specific implementation details. Furthermore, these efforts must be repeated for every different extension that someone might want to support, due to the use of a new API when the architecture changes. Such concerns make the design and maintenance of these applications time consuming and error-prone. However, programming applications that take advantage of the _SIMD_ extension available on the current target remains a complex task.

**Boost.SIMD** is a Boost candidate library which aim to provide proper abstractions over the usage of _SIMD_ extensions. This abstraction provide more than a simple portable wrappers above hardware-specific registers, but also standardize the use of common _SIMD_ programming idioms.

**Boost.SIMD** solves these issues by providing :

  + a proper value semantic wrapper for _SIMD_ registers;
  + an automatic system to detect and exploit extension specific optimization opportunities;
  + standard compliant iterators to iterate over contiguous range of data in a _SIMD_ compatible way;
  + standard compliant iterators encapsulating complex _SIMD_ idioms like sliding window or de-interleaving of data on the fly.


@section main-support Supported Compilers and Hardware

----------------------------------------------------------------------------------------------------
The current set of SIMD extensions supported by **Boost.SIMD** includes:

Architecture | Extensions
-------------|------------------------------------------------------------
X86          | SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, FMA3, AVX2, MIC
AMD          | SSE4a, XOP, FMA4
PowerPC      | VMX, VSX, QPX
ARM          | Neon

In term of compiler, **Boost.SIMD** requires a C++11 compliant compiler and is thoroughly tested on the following set of compilers :

Compiler     | Version
-------------|----------------
g++          | 4.8 and above
clang++      | 3.5 and above
Visual VC++  | 13.0 and above

@section main-howto How to use this documentation

----------------------------------------------------------------------------------------------------
The structure of the reference (available in the menu to the left) goes as
follow:

  - @ref group-api\n
    Public function and type API of Boost.SIMD

  - @ref group-concept\n
    Concepts defined and used throughout Boost.SIMD.

  - @ref group-config\n
    Those macros are defined to control the configuration of Boost.SIMD code.

  - @ref group-ext\n
    Documentation for extension points for library's components. This documentation is useful
    for people wanting to extended Boost.SIMD to work with their own types.

  - @ref group-hierarchy\n
    Documentation for the predefined type hierarchy used by the library.

  - @ref group-detail\n
    Documentation for implementation details of the library. This documentation is useful
    for people wanting to work on the library internals and provide patches.


----------------------------------------------------------------------------------------------------

<!-- Links -->
<!-- [name]: url -->
