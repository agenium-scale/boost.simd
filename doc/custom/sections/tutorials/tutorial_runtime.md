Runtime Extension Selection {#tutorial-runtime}
=========

@tableofcontents
In this tutorial we will demonstrate the use of SIMD extension
selection at runtime.

@section runtime-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Explain why runtime extension selection is very useful](#tutorial-runtime-intro)
- [Show you how to select the correct architecture at runtime](#tutorial-runtime-dispatch)

@section tutorial-runtime-intro Introduction

-------------------------------------

The selection of SIMD extensions at runtime enables you to release one executable which
will be of the highest performance possible on many different architectures. Without runtime
extension selecion, an executable released must be compiled for the earliest generation of processor
targeted, which is often SSE2. This means that you are artificially restricting the performance
of your software for your clients which have more modern processors. **@projectname**
provides everything you need to be able to target multiple architectures with one binary.

@section tutorial-runtime-dispatch How to select the correct extension at runtime

-------------------------------------

In this section, we will demonstrate how to compile your program for several different
generations of x86 processors and select automatically the correct version at runtime.
In order to do this, you must add an extra argument to the function you wish to call so
that the correct function will be found at runtime.

@snippet compute.cpp runtime-dec

The macro BOOST_SIMD_DEFAULT_SITE is set according to the architecture that the currect
file is being compiled for. You must also declare a prototype for each architecture
that you wish to target:

@snippet compute.hpp runtime-arch

In this case, we are compiling a version of our function for each iteration of x86 from sse2
to avx2. You must then call the correct version of your code, depending on the architecture
the binary is run on. The order of the conditions in the if-block is very important as each
generation of a processor in **@projectname@**, inherits from the previous generation. This
means that sse2 is supported on an sse4.2 equipped processor, for example.

@snippet runtime_extension.cpp runtime-main

Once you have compiled your file for each required architecture, you must link your executable
with each version of your code. On Linux, using cmake, this is done as follows:

@snippet CMakeLists.txt runtime-cmake

Using Microsoft Visual Studio, this can be done be setting the correct properties for your
project. See @ref win-compilation for more details.
