# Boost.SIMD

**Boost.SIMD** is a portable SIMD programming library to be proposed as a Boost library.
It's a sensible subset of the features proposed by [bSIMD](https://www.numscale.com/en/solutions/bsimd/) - NumScale's closed-source library for SIMD programming - that we saw fit for open sourcing.

[![Build Status](https://travis-ci.org/NumScale/boost.simd.png?branch=develop)](https://travis-ci.org/NumScale/boost.simd)

**Boost.SIMD** was developed to simplify the difficult, tedious and often error-prone process of developing SIMD programs. **Boost.SIMD** is designed to seamlessly integrate into existing projects so that you can quickly and easily start developing high performance, portable and future-proof software.

## Important Links :
 - [The current Issues List](https://github.com/NumScale/boost.simd/issues)
 - [The documentation](https://developer.numscale.com/boost.simd/documentation/develop)
 - [the Q&A Google group](https://groups.google.com/forum/#!forum/boost-simd)

# What is SIMD?

Single instruction, multiple data (__SIMD__) instructions or **multimedia extensions** have been available
for many years. They are designed to significantly accelerate code execution, however they require expertise to be used correctly
and they depend on potentially fragile compiler support and the use of low-level intrinsics, or vendor-specific libraries.
The introduction of these instruction sets has allowed developers to exploit the latent data parallelism available in applications by
executing a given instruction simultaneously on multiple data stored in dedicated cpu registers. The SIMD unit is built as an independent
computation unit in the processor, it comes in addition to the regular computation unit complete with a special register file,
dispatching and pipelining unit.

# Why use Boost.SIMD?

The use of SIMD instructions requires developers to program into a very verbose manner due to the low-level nature of SIMD instruction
sets or to rely on fragile, black-box auto-vectorizating compilers. Furthermore, it can be necessary to re-write code for each revision
of each target architecture, accounting for each architecture's vendor provided API as well as architecture dependent implementation details.
This greatly complicates the design and maintenance of SIMD code, significantly increasing the time required to develop, test and deploy
software as well as increasing the scope for introducing bugs.

**Boost.SIMD** is designed to be user-friendly and easy to integrate into existing projects. To make life even easier, **Boost.SIMD** includes
a large number of commonly used functions and constants, standardizing the use of common _SIMD_ programming idioms. **Boost.SIMD** allows
you to focus on the important part of your work: the development of new features and functionality.

**Boost.SIMD** provides the following:

  + [a proper value semantic wrapper for _SIMD_ registers](https://developer.numscale.com/boost.simd/documentation/develop/classboost_1_1simd_1_1pack.html);
  + an automatic system to detect and exploit architecture specific optimization opportunities;
  + [standard compliant ranges and algorithms to process contiguous range of data in a _SIMD_ compatible way](https://developer.numscale.com/boost.simd/documentation/develop/group__group-std.html);
  + [over 350 operators and mathematical functions usable on scalar and SIMD values](https://developer.numscale.com/boost.simd/documentation/develop/group__group-functions.html)

# Supported Compilers and Hardware

Architecture | Extensions
-------------|-----------------------------------------------------
x86          | SSE2, SSE3, SSSE3, SSE4.1, SSE4.2, AVX, FMA3, AVX2

**Boost.SIMD** requires a C++11 compliant compiler and Boost 1.61 and is thoroughly tested on the following compilers:

Compiler                | Version
------------------------|-------------------
g++                     | 4.8 and above
clang++                 | 3.5 and above
Microsoft Visual Studio | 15.0 and above

# Getting Started

We start out on the premise you already have a proper installation of Boost 1.61 or superior setup on your machine.

You can retrieve the current status of the library by cloning the repository:

    git clone https://github.com/NumScale/boost.simd.git

By default, the develop branch is fetched. You can change that to `master` if you want to use the stable version instead of the development version.

Once cloned, the library headers are located in the `include/` folder and are ready to be used. A very simple example like:

```cpp
#include <boost/simd/pack.hpp>
#include <iostream>

namespace bs = boost::simd;

int main()
{
   bs::pack<float,4> p{1.f,2.f,3.f,4.f};
   std::cout << p + 10*p << "\n";

   return 0;
}
```

can then be compiled via:

    g++ main.cpp -std=c++11 -O3 -msse4.2 -I<path/to/boost/1.61/include> -I<path/to/boost/simd/include> -o main

and display:

    (11, 22, 33, 44)

Now, you can [have a look at our documentation](https://developer.numscale.com/boost.simd/documentation/develop/) to follow one of our tutorials on how to use **Boost.SIMD**.
