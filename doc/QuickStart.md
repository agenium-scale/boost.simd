Quick Start {#quickstart}
=========

This is a quick start for **Boost.SIMD**. The purpose of this is to briefly introduce
**Boost.SIMD** so that you can start coding immediately.

@section dependencies Dependencies

-------------------------------------

Boost 1.60 or later

@section supported-compilers Supported Compilers

-------------------------------------

**Boost.SIMD** requires a C++11 compliant compiler and is thoroughly tested with the following compilers:

<center>
Compiler                | Version
------------------------|-------------------
g++                     | 4.8 and above
clang++                 | 3.5 and above
Microsoft Visual Studio | 15.0 and above
</center>

@section installing Installing

-------------------------------------

The easiest way to use **Boost.SIMD** is to download the latest release from the
<a href="https://github.com/NumScale/boost.simd/">github</a> page and extract it.
This is a header only library, therefore you do not need to compile it. The same
header files are used on all platforms.

@section compiling Compiling and Running a Program using Boost.SIMD

-------------------------------------

In order to use **Boost.SIMD** on Linux, you must pass the **Boost.SIMD** include
folder to the compiler and as well as the path of the boost directory. You must
also indicate what architecture

For example:

`g++ my_code.cpp -O3 -DNDEBUG -o my_code -I/path/to/boost.simd/ -I/path/to/boost/ -mavx`

If you use an IDE such as Visual Studio or XCode, set these flags and paths in
your project settings.
@warningbox{
Some compilers, such as Microsoft Visual Studio, do not propagate the fact a given architecture specific
option is triggered. In this case, you must also define an architecture specific preprocessor symbol.
For example, if you want to use SSE4.2 on Visual Studio, set the /ARCH:SSE2 flag and
define `BOOST_SIMD_ASSUME_SSE4_2` as a preprocessor definition.
}

@warningbox{
We recommend using a 64bit compiler as this results in significantly better
performance.
}
