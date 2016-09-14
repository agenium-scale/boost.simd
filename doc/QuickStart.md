Quick Start {#quickstart}
===========
@tableofcontents

This is a quick start guide for **Boost.SIMD**. Its purpose is to get you ready to go by learning
how to install **Boost.SIMD** and its dependencies, and how to compile a simple **Boost.SIMD** program.

@section dependencies Dependencies

----------------------------------

The use of **Boost.SIMD** depends on the header only components of the
[Boost Library](http://www.boost.org) version 1.60 or later. To install Boost,
please refer to the Boost library installation guide :

  - [for Unix](http://www.boost.org/doc/libs/release/more/getting_started/unix-variants.html)
  - [for Windows](http://www.boost.org/doc/libs/release/more/getting_started/windows.html).

In the rest of this documentation, we will refer to the path where your Boost library is installed
as the `BOOST_ROOT` environment variable.

@section installing Installing Boost.SIMD

-----------------------------------------

The installation of **Boost.SIMD** is done in two steps:

  - retrieve the current status of the library by cloning the repository. THis is done via the
    following command:

    `git clone https://github.com/NumScale/boost.simd.git`

    By default, the `develop` branch is fetched. As this branch contains the latest code,
    you may change this branch to `master` to fetch the latest stable version:

    `git clone https://github.com/NumScale/boost.simd.git -b master`

    In case you need to use an old **Boost.SIMD** release, please see the
    [Release pages](https://github.com/NumScale/boost.simd/releases) to select the one
    you're interested in.

  - Setup the repository to grab a local copy of the documentation:

    `git submodule init && git submodule update`

The **Boost.SIMD** library is now accessible by including files from the `include` directory
in this repository. In the rest of this documentation, we will refer to the path where your
**Boost.SIMD** library is installed as the `BOOST_SIMD_ROOT` environment variable.

@section compiling Compiling and Running a Program using Boost.SIMD

-------------------------------------

**Boost.SIMD** requires a C++11 compliant compiler and is thoroughly tested with the
following compilers:

<center>
Compiler                | Version
------------------------|-------------------
g++                     | 4.8 or above
clang++                 | 3.5 or above
Microsoft Visual Studio | 2015 update 1 or above
Intel C++ Compiler      | 16.0 or above
</center>

We recommend using a 64-bits compiler as this results in significantly better performance.
Also, **Boost.SIMD** performances are only provided when compiled in an optimized code with
assertions disabled.

@subsection linux-compilation Compiling for Linux

========================

**Boost.SIMD** can be compiled on Linux using `g++`, `clang` or `icpc`.
To compile a program using **Boost.SIMD**, use your compiler as usual and
adds the `BOOST_ROOT` and `BOOST_SIMD_ROOT` path along with the SIMD extensions
flags of your choices.

For example:

`g++ my_code.cpp -O3 -DNDEBUG -o my_code -I$BOOST_ROOT -I$BOOST_SIMD_ROOT-mavx`

Refer to your compiler user's manual to find the proper flag to use to trigger a given
SIMD extension support.

@subsection win-compilation Compiling for Windows

========================

The recommended compiler on Windows is Visual Studio. To compile a program using **Boost.SIMD**, add
the `BOOST_ROOT` and `BOOST_SIMD_ROOT`path to your project settings.

Contrary to other compilers, Visual Studio only recognize SSE, AVX and AVX2 are specific SIMD
targets. To enable **Boost.SIMD** supports for other architecture, you need to set a specific
preprocessor symbol.

<center>
SIMD Extension          | Symbol
------------------------|-------------------
SSE2                    | BOOST_SIMD_ASSUME_SSE2
SSE3                    | BOOST_SIMD_ASSUME_SSE3
SSSE3                   | BOOST_SIMD_ASSUME_SSSE3
SSE4.1                  | BOOST_SIMD_ASSUME_SSE4_1
SSE4.2                  | BOOST_SIMD_ASSUME_SSE4_2
XOP                     | BOOST_SIMD_ASSUME_XOP
FMA3                    | BOOST_SIMD_ASSUME_FMA3
FMA4                    | BOOST_SIMD_ASSUME_FMA4
</center>

When using AVX or AVX2, you may want to enable support for SSE4.2 to ensure maximal performance
from AVX code using SSE intrinsics.

\notebox{Visual Studio provides a `\Gv` settings that enables a special calling convention called
`__vectorcall` that try to use SIMD registers when passing SIMD values as function parameters. Its
effect in conjunction with Boost.SIMD depends on the code. Feel free to try it and use it if it
improves your performances.}

@section next What's Next ?

-------------------------------------

You can now :

  - [Have a look at some of our tutorials](@ref tutorials)
  - [Browse the Reference Documentation](modules.html)

If you encounter any problems or think you found bug, you can:
  - [Consult the FAQ](@ref faq)
  - [consult our Issues Tracker on GitHub](https://github.com/NumScale/boost.simd/issues)
  - [ask a question on our Q&A Forum](https://groups.google.com/forum/#!forum/boost-simd).
