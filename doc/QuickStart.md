Quick Start {#QuickStart}
=========

This is a quick start for **bSIMD**. The purpose of this is to briefly introduce **bSIMD** so that you can start coding immediately.

@section dependencies Dependencies

-------------------------------------

Boost 1.60 or later


@section supported-compilers Supported Compilers

-------------------------------------

**bSIMD** requires a C++11 compliant compiler and is thoroughly tested with the following compilers:

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Compiler                <th>Version        
<tr><td>g++                     <td>4.8 and above
<tr><td>clang                   <td>3.5 and above
<tr><td>Microsoft Visual Studio <td>13.0 and above
</table>

@section installing Installing

-------------------------------------

The easiest way to use **bSIMD** is to download the latest release from the github page and extract it. This is a header only library, therefore you do not need to compile it. The same header files are used on all platforms.

@section compiling Compiling and Running a Program using bSIMD

-------------------------------------

In order to use **bSIMD** on Linux, you must pass the **bSIMD** include folder to the compiler and as well as the path of the boost directory. That's it!

For example:

'g++ -o helloworld helloworld.cpp -std=c++11 -I/path/to/boost/ -I/path/to/boost/simd/include -O3 -msse2'

On Windows, the process is similar. We recommend that you use the 64 bit version of Visual Studio as this results in significantly better performance.
'cl /Oxt /EHsc /MD /DNDEBUG /D_WINDOWS /fp:precise /LD /arch:SSE2 /I/path/to/boost /I/path/to/boost/simd/include helloworld.cpp'

@section hello-world Hello World

-------------------------------------

This small code sample presents the basic building blocks of **bSIMD**, which we explain below.
@snippet helloworld.cpp hello

@subsection explanation Explanation of HelloWorld
For a simple program such as this, you need only include pack.hpp and iostream. The first two lines of the code are a namespace alias for boost::simd and a type alias for bs::pack, which is the **bSIMD** abstraction for a SIMD register.

The next three lines are the declarations of our data for this small example. Firstly, we declare an empty register to hold the results of out calculation. We then fill two packs with 10s and 11s. The next line is the calculation and is a great example of the power of **bSIMD**. In this line, vectorised code for the current architecture is automatically generated, in the case the SIMD instructions for addition and multiplication. The final line of this program prints the result.

Please refer to the tutorial @ref tutorials section for more detailed examples.
