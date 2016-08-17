@anchor topofpage_hello
# A Simple SIMD Kernel {#tutorial-hello}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

The following program is a basic demonstration of **Boost.SIMD**:

@snippet helloworld.cpp hello

This small code sample presents the basic building blocks of **Boost.SIMD**, which are explained below.

### The Boost.SIMD namespace ###

When using a **Boost.SIMD** type or function, it is necessary to use the boost::simd namespace. In order to simplify the code, you may assign an alias to it:

@snippet helloworld.cpp hello-namespace

This saves you from having to type the full namespace every time you call a **Boost.SIMD** function.

### The boost::simd::pack abstraction

The basis of any code using **Boost.SIMD** is the boost::simd::pack class which is defined in:

@snippet helloworld.cpp hello-include-pack

The pack may be considered analagous to an _SIMD_ register on your (or any other) machine. Operations performed on packs - from elementary operations such as addition to complicated functions such as sin(x) - will be performed using _SIMD_ registers and operations if supported by your hardware. As shown in the following example, data must be manually loaded into and stored from these registers.

### Constructing a boost::simd::pack

One way to construct a boost::simd::pack is to simply declare (default-construct) it. Such boost::simd::pack are not zero-initialized and thus may contain arbitrary values.

@snippet helloworld.cpp hello-def-ctor

Another way to construct a boost::simd::pack is to fill it with a single value. This so-called splatting constructor takes one scalar value and replicates it in all elements of the pack.

@snippet helloworld.cpp hello-splat-ctor

You may also perform the splat explicitly if you wish

@snippet helloworld.cpp hello-splat-explicit

You may also construct a pack by passing a pointer to a block of contiguous, aligned memory.

@snippet helloworld.cpp hello-ptr-iota

When constructing a pack in this manner, you must ensure that there is sufficient data in the block
of memory to fill the pack. For example, on an AVX enabled machine, a __SIMD__ vector of `float32`
contains `8` elements, or has a __cardinal__ of `8`. Therefore, there must be at least `8` elements
in the block of memory pointed to by this pointer. This same code compiled for the Intel KNL, would
require that the block of memory contain `16` elements, otherwise there would be undefined behaviour
at runtime. When writing vectorized code, care should be taken to write the code in as generic a manner
as possible to ensure portability across architectures.

You may also construct a pack by passing a range of elements, however the length of this
range must be equal to the cardinal of the pack.

@snippet helloworld.cpp hello-iter-con

Finally, you can also initializes every element of the boost::simd::pack itself by enumerating them.

@snippet helloworld.cpp hello-enum-con

Note that this constructor makes the strong assumption that the size of your boost::simd::pack is correct.
Unless required, it is generally good practive to avoid depending on a fixed size for boost::simd::pack
unless the algorithm specifically requires it. The use of another constructor is strongly recommended
over this one.

###Operations on boost::simd::pack

Once initialized, operations on boost::simd::pack instances are similar to scalar operations as all
operators and standard library math functions are provided. In order to access all of these functions
and operators, such as boost::simd::plus, you must include the boost/simd/function/plus.hpp header file.

@snippet helloworld.cpp hello-ops

Finally, we display the contents of a boost::simd::pack by using the `operator<<` overload provided.

@snippet helloworld.cpp hello-io


###Compiling the code

The compilation of using **Boost.SIMD** is rather straight-forward: you must pass the path of of the
**Boost.SIMD** include folder to your compiler as well as the path of your installation of **Boost**.
It is strongly recommended that you enable all of your compiler optimizations, for example, `-O3` for
g++, to enable the full performance of **Boost.SIMD**. You should also pass the required compiler flag
for your target architecture to enable the __SIMD__ extensions, especially if you are cross-compiling.
The exhaustive list of all compiler flags for all supported compilers is provided in the the @ref QuickStart
guide.

For example, on `gcc`:

`g++ my_code.cpp -O3 -o my_code -I/path/to/boost.simd/ -mavx`

Some compilers, such as Microsoft Visual Studio, do not propagate the fact a given architecture specific
option is triggered. In this case, you must also define an architecture specific preprocessor symbol.

The following command is used to compile a **Boost.SIMD** program with Visual Studio:

`g++ my_code.cpp -O3 -o my_code -I/path/to/boost.simd/ -mavx`

You may also define the above flags in the Visual Studio GUI.

###The result

When the above program is compiled, this output should be seen:

`{42,42,42,42}`

Let's take a look at the generated assembly code (using `objdump` for example) :

@code{.objdump}
addps  0x2e6(%rip),%xmm0
mulps  0x2ff(%rip),%xmm0
movaps %xmm0,(%rsp)
@endcode

This shows that *Boost.SIMD** performed as expected: the code has been vectorised!
This may be seen by the emitted `*ps` instructions. Note how the abstractions introduced
by boost::simd::pack are completely free, they do not incur ant runtime penalty. The generated
assembly is identical to that generated by handwritten __SIMD__ instructions!

Now let's take a look at what happens when a **Boost.SIMD** code is compiled on different architecures:

@snippet iota_and_print.cpp iota-print

This code loads a pack of various primitive data types from aligned memory (@ref tutorial-memory)
and prints it's contents. This code gives the following output when it is compiled for SSE2:

\code{.sh}
clang++ -Wall -Wextra -std=c++11 -I/tmp/boost.simd.install/include -msse2 /tmp/main.cpp
\endcode

```
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
(1, 2, 3, 4)
(1, 2)
(1, 2)
(1, 2, 3, 4)
(1, 2)
```

Now compile it using AVX and the following output is printed:
```
clang++ -Wall -Wextra -std=c++11 -I/tmp/boost.simd.install/include -mavx /tmp/main.cpp
```

```
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
(1, 2, 3, 4)
(1, 2, 3, 4, 5, 6, 7, 8)
(1, 2, 3, 4)
```
As you can see, the number of elements in each __SIMD__ vector has doubled, as an AVX vector has twice
the number of elements as an SSE2 vector.

@snippet iota_and_print.cpp iota-call

[Top of Page](#topofpage_hello)
