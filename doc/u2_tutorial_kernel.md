Tutorials {#tutorials}
=========

@tableofcontents

@section tutorial-objectives Objectives

----------------------------------------------------------------------------------------------------
Those tutorials will drive you through the general principles of **Boost.SIMD**:

  + using the pack abstraction
  + compiling **Boost.SIMD** code
  + using _SIMD_ specific idioms like reduction, branching or shuffling
  + vectorizing code using the Standard Template Library
  + handling _SIMD_ instructions set runtime detection

For all these tutorials, we will consider the use of a 128 bits wide _SIMD_ extensions (like SSE or Altivec). Depending on your actual architecture, the output of the various tutorial applications may varies.

@section tutorial-kernel A Simple SIMD Kernel

----------------------------------------------------------------------------------------------------
Here is a simple program computing a SIMD register full of 42.

@snippet helloworld.cpp hello

Not very exciting but it gives us a run on the main abstraction provided by **Boost.SIMD**: the boost::simd::pack template class.

## The boost::simd::pack abstraction

The main element of **Boost.SIMD** is the boost::simd::pack class, accessible through the boost/simd/pack.hpp header file. `pack<T,N>` is an abstraction over a block of `N` elements of type `T`, quite similar to `std::array`. The main semantic difference is that boost::simd::pack is implemented as the best hardware specific type able to store this amount of data which may be a simple scalar array, a single _SIMD_ register or a tuple of _SIMD_ registers depending on `N` and `T`.

## Constructing a boost::simd::pack

First way to construct a boost::simd::pack is to default-construct it. Such boost::simd::pack are not zero-initialized and
thus may contain arbitrary values.

@snippet helloworld.cpp hello-def-ctor

Another way to construct a boost::simd::pack is to fill it with a single value. This so-called splatting constructor takes one scalar value and replicates it in all elements of the pack.

@snippet helloworld.cpp hello-splat-ctor

Finally, you can also initializes every element of the boost::simd::pack itself by enumerating them.

@snippet helloworld.cpp hello-enum-ctor

Note that this constructor make the strong assumption that the size of your boost::simd::pack is correct. Unless required, it's always a good idea to try to not depend on a fixed size for boost::simd::pack unless
the algorithm requires it. If needed, the `splat` function can be used to generate size-independant pack filled with an arbitrary value.

## Operations on boost::simd::pack

Once initialized, operations on boost::simd::pack instances are similar to operations on scalar as all operators and standard library math functions are provided. A simple pattern make those functions and operators available: if you need to use an arbitrary function or operator like boost::simd::plus, you need to include the boost/simd/function/plus.hpp file. We do the same for boost::simd::splat and boost::simd::multiplies.

@snippet helloworld.cpp hello-ops

Note that type checking is stricter than one may expect when scalar and _SIMD_ values are mixed. **Boost.SIMD** only allows mixing types of the same scalar kind, i.e reals with reals or integers with integers. Here, we have to multiply by `2.f` and not simply `2`.

Finally, we display the boost::simd::pack content by using the `operator<<` overload provided by the boost/simd/io.hpp header file.

@snippet helloworld.cpp hello-io

## Compiling the code

The compilation of the code is rather straight-forward: just pass the path to **Boost.SIMD** and use your compiler options to activate the desired _SIMD_ extension support.

For example, on `gcc`:

`g++ my_code.cpp -O3 -o my_code -I/path/to/boost/ -msse2`

Some compilers, like Microsoft Visual Studio, don't propagate the fact a given architecture specific option is triggered. In this case, you need to also defines a architecture specific preprocessor symbol.

## The result

We can then have a look at the program's output which should look like:

`{42,42,42,42}`

Now, let's have a look at the generated assembly code (using `objdump` for example) :

@code{.objdump}
movaps 0x300(%rip),%xmm0
addps  0x2e6(%rip),%xmm0
mulps  0x2ff(%rip),%xmm0
movaps %xmm0,(%rsp)
@endcode

That's it, we correctly emitted `*ps` instructions. Note how the abstraction introduced by boost::simd::pack don't incur any penalty.


@section tutorial-reduction Reductions

----------------------------------------------------------------------------------------------------
Now that we know how to handle simple _SIMD_ kernel, let's have a look at more complex operations involving operations across the values stored in a boost::simd::pack.

## The result

@section tutorial-ifelse Branching and Selection

----------------------------------------------------------------------------------------------------
Scalar code is often using branching to specify how an application code path should be structured.
However, in _SIMD_, all the computations must follow a single code path. The solution is to use
selection operations to turn scalar `if-else` control blocks into _SIMD_ computation.

## The result

@section tutorial-process Data Processing

----------------------------------------------------------------------------------------------------
For now, we only cared about computing values in and out of a small amount of explicitly constructed
boost::simd::pack instances. WE will now build a simple _SIMD_ function processing large chunk of memory.
As an example, consider a simple sequential, scalar `DOT` function defined as:

@snippet dot.cpp scalar-dot

## The result

@section tutorial-shuffle Memory Access

----------------------------------------------------------------------------------------------------

## The result

@section tutorial-select Runtime Extensions Selection

----------------------------------------------------------------------------------------------------
Using **Boost.SIMD** requires compiling for a particular target machine with specific _SIMD_
instructions available. For many architectures (x86 in particular), _SIMD_ instructions may be conditionally supported depending on the exact hardware being used, with more recent hardware
typically supporting more _SIMD_ instructions than older ones.

In this tutorial, we will demonstrate how to switch between `SSE` and `AVX` for the same code
depending on the capabilities of the x86 hardware that the program is running on.

## The result
