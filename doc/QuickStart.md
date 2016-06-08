Quick Start {#QuickStart}
=========

@section getting-started Getting Started

----------------------------------------------------------------------------------------------------

This is a quick start for **Boost.SIMD**. The purpose of this is to briefly introduce **Boost.SIMD** so that you can start coding immediately.

@section how-to-install How to Install **Boost.SIMD**

@subsection dependencies Dependencies
Boost 1.60 or later

@subsection supported-compilers Supported Compilers
**Boost.SIMD** requires a C++11 compliant compiler and is thoroughly tested on the following compilers:

Compiler                | Version
------------------------|-------------------
g++                     | 4.8 and above
clang++                 | 3.5 and above
Microsoft Visual Studio | 13.0 and above

@subsection installing Installing
The easiest way to use **Boost.SIMD** is to download the latest release from the github page and extract it. This is a header only library, therefore you do not need to compile it. The same header files are used on all platforms.

@section hello-world Hello World

This small code sample presents the basic building blocks of **Boost.SIMD**, which we explain below.
@snippet helloworld.cpp hello

@section compiling Compiling and Running a Program using **Boost.SIMD**
In order to use **Boost.SIMD** on Linux, you must pass the **Boost.SIMD** include folder to the compiler and as well as the path of the boost directory. That's it!

For example:

'g++ -o helloworld helloworld.cpp -std=c++11 -I/path/to/boost/ -I/path/to/boost/simd/include -O3 -msse2'

On Windows, the process is similar. We recommend that you use the 64 bit version of Visual Studio as this results in significantly better performance.
'cl /Oxt /EHsc /MD /DNDEBUG /D_WINDOWS /fp:precise /LD /arch:SSE2 /I/path/to/boost /I/path/to/boost/simd/include helloworld.cpp'

@subsection explanation Explanation of HelloWorld
For a simple program such as this, you need only include pack.hpp and iostream. The first two lines of the code are a namespace alias for boost::simd and a type alias for bs::pack, which is the **Boost.SIMD** abstraction for a SIMD register.

The next three lines are the declarations of our data for this small example. Firstly, we declare an empty register to hold the results of out calculation. We then fill two packs with 10s and 11s. The next line is the calculation and is a great example of the power of **Boost.SIMD**. In this line, vectorised code for the current architecture is automatically generated, in the case the SIMD instructions for addition and multiplication. The final line of this program prints the result.

Please refer to the tutorial @ref tutorials section for more detailed examples.
