Hello World {#tutorial-hello}
=========

@tableofcontents
In this tutorial we will write and compile a very simple __SIMD__ kernel
to become familiar with the basics of **Boost.SIMD**.

@section hello-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Introduce the basic __SIMD__ register abstraction, boost::simd::pack](#hello-building-blocks)
- [Load data from memory into a boost::simd::pack](#hello-loading-data)
- [Perform a simple arithmetical calculation and print the result](#hello-building-blocks-operations)
- [Store the results back into memory](#hello-building-blocks-store)
- [Compile and run the code](#hello-compilation)
- [Observe the different outputs from compiling the same code on different processors](#hello-results-architectures)

@section hello-getting-started Getting Started

-------------------------------------
**Boost.SIMD** is a header only library which means that each of its components
is accessible through its corresponding include. The first step is to include the
file which give you the main boost::simd::pack.

@snippet helloworld.cpp hello-include-pack

In a similar way, all **Boost.SIMD** functions and constants may be accessed through
their respective headers. For example to access boost:simd::cos, you must include:

\code{.cpp}
#include <boost/simd/function/cos.hpp>
\endcode

Similarly, constant values may be accessed as follows:
\code{.cpp}
#include <boost/simd/constant/pi.hpp>
\endcode

All functions and constants are included in the same way.


@notebox{
All of **Boost.SIMD** functionality is wrapped in the `boost::simd` namespace.
The easiest way to do this is to assign an alias to it:
@snippet helloworld.cpp hello-namespace
This saves you from having to type the full namespace every time you call a
**Boost.SIMD** function.
}


@section hello-building-blocks Basic Building Block

-------------------------------------

@subsection hello-building-blocks-pack boost::simd::pack

boost::simd::pack can be considered analagous to an _SIMD_ register on your (or any other) machine.
Operations performed on packs - from elementary operations such as addition to
complicated functions such as sin(x) - will be performed using _SIMD_ registers
and operations if supported by your hardware. As shown in the following example,
data must be manually loaded into and stored from these registers.

A boost::simd::pack may contain many different primitive types, depending
on the target machine. A type alias for a pack of float is declared as follows:

@snippet helloworld.cpp hello-pack

@subsection hello-loading-data Loading Data into a Pack
One way to construct a boost::simd::pack is to simply declare (default-construct) it.
Such a pack may not zero-initialized and thus may contain arbitrary values.

@snippet helloworld.cpp hello-def-ctor

Another way to construct a boost::simd::pack is to fill it with a single value.
This so-called splatting constructor takes one scalar value and replicates it
in all elements of the pack.

@snippet helloworld.cpp hello-splat-ctor

You may also construct a pack by passing a pointer to a block of contiguous, aligned memory.

@snippet helloworld.cpp hello-ptr-iota

When constructing a pack in this manner, you must ensure that there is sufficient data in the block
of memory to fill the pack. For example, on an AVX enabled machine, a __SIMD__ vector of `float32`
contains `8` elements, or has a __cardinal__ of `8`. Therefore, there must be at least `8` elements
in the block of memory pointed to by this pointer. This same code compiled for the Intel KNL, would
require that the block of memory contain `16` elements, otherwise there would be undefined behaviour
at runtime. When writing vectorized code, care should be taken to write the code in as generic a manner
as possible to ensure portability across architectures.

@notebox{
Other functions exist to explicitly load data from unaligned memory, non-contiguous data
and other more complex scenarios. These functions are presented in later tutorials.
}

You may also construct a pack by passing a range of elements, however the length of this
range must be equal to the cardinal of the pack.

@snippet helloworld.cpp hello-iter-con

@notebox{
Please note that very few architectures provide an efficient way of loading
data in this manner as there is no guarantee that the data is contiguous.
Such a load should only be used in very specific circumstances and never inside
a critical loop.
}
Here, we have introduced `pack_t::static_size` which is the cardinal of the pack.

Finally, you can also initializes every element of the boost::simd::pack itself by enumerating them.

@snippet helloworld.cpp hello-enum-con

That this constructor makes the strong assumption that the number of elements
in the constructor matches the cardinal of boost::simd::pack on the target
machine. Unless required, it is generally good practice to avoid depending
on a fixed size for boost::simd::pack unless the algorithm specifically
requires it. The use of another constructor is strongly recommended
over this one.

@subsection hello-building-blocks-operations Operations on Pack

Once initialized, operations on boost::simd::pack instances are similar to scalar operations as all
operators and standard library math functions are provided. In order to access all of these functions
and operators, such as boost::simd::plus, you must include the relevant header:
\code{.cpp}
#include <boost/simd/function/plus.hpp>
\endcode

A simple arithmetical operation is performed as follows:

@snippet helloworld.cpp hello-ops

@subsection hello-building-blocks-store Storing the Result in memory
The result may be saved to memory as follows:

@snippet helloworld.cpp hello-store

Finally, we print the contents of a boost::simd::pack by using the `operator<<` overload provided.

@snippet helloworld.cpp hello-io

@section hello-compilation Compiling the Code

-------------------------------------

The compilation of using **Boost.SIMD** is rather straight-forward: you must pass the path of of the
**Boost.SIMD** include folder to your compiler as well as the path of your installation of **Boost**.
It is strongly recommended that you enable all of your compiler optimizations, for example, `-O3` for
g++, to exploit the full performance potential of **Boost.SIMD**. You should also pass the required compiler flag
for your target architecture to enable the __SIMD__ extensions, especially if you are cross-compiling.
The exhaustive list of all compiler flags for all supported compilers is provided in the the @ref QuickStart
guide.

For example, on `gcc`:

`g++ my_code.cpp -O3 -DNDEBUG -o my_code -I/path/to/boost.simd/ -mavx`

If use an IDE such as Visual Studio or XCode, set these flags and paths in
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
@section hello-results Results

-------------------------------------

When the above program is compiled, this output should be seen:

`{42,42,42,42}`

Let's take a look at the generated assembly code (using `objdump` for example) :

@snippet objdump.txt hello-objdump

This shows that *Boost.SIMD** performed as expected: the code has been vectorised!
This may be seen by the emitted `*ps` instructions. Note how the abstractions introduced
by boost::simd::pack are completely free, they do not incur any runtime penalty. The generated
assembly is identical to that generated by handwritten __SIMD__ instructions!

Now let's take a look at what happens when a **Boost.SIMD** code is compiled on different architecures:

@section hello-results-architectures Different Architectures

In this section we will examine what happens when the same code is compiled for different archiectures.
The following code loads a pack of various primitive data types from aligned memory (@ref tutorial-memory)
and prints it's contents.

@snippet iota_and_print.cpp iota-print

Let's compile this code for SSE2:

@snippet compile.txt hello-compile-iota-sse

And examine it's output:

@snippet compile.txt hello-output-iota-sse

Now compile it using AVX and the following output is printed:
@snippet compile.txt hello-compile-iota-avx

@snippet compile.txt hello-output-iota-avx
As you can see, the number of elements in each __SIMD__ vector has doubled, as an AVX vector has twice
the number of elements as an SSE2 vector.
