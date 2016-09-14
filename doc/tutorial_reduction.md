SIMD Reductions {#tutorial-reduction}
=========

@tableofcontents
In this tutorial, we will explore how to reduce an array of data to a scalar
using **Boost.SIMD**. Such a reduction may involve calculating the sum or
product of the elements of the array, for example.

@section reduction-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Show how an array of data can be reduced to a scalar using **Boost.SIMD**](#tutorial-reduction-simd )

@section tutorial-reduction-simd Transforming a scalar reduction into a SIMD reduction

-------------------------------------

We will demonstrate how a scalar reduction loop may be transformed into a
SIMD loop. Take the following loop, for example:

@snippet reduction.cpp reduc-scalar

We see here that there is a dependence between loop iterations - the accumulated sum. However,
this dependency may be eliminated by forming our addition in the binary tree form shown here:

@snippet binary.txt binary

If we had an infinitely large __SIMD__ register, we could calculate the sum of _n_ elements in _log(n)_
steps. Unfortunately, we don't have infinitely large registers (even GPUs are limited in the number
of simultaneous calculations they can perform), however, the two approaches may be combined resulting
in a significant performance increase.

@subsection reduction-simultaneous Reducing into a pack

Let us assume we have defined:

@snippet reduction.cpp reduc-simd-types

Here we combine the approaches by summing into a boost::simd::pack, allowing us to perform as many
simultaneous additions as there are elements in a pack. It is only at the end that we accumulate
these sub-sums into the full scalar sum using the boost::simd::sum function provided by
`boost/simd/function/sum.hpp.`

@snippet reduction.cpp reduc-simd-o

@subsection reduction-compile Exploiting information available at compile time
If the size of our array is known at compile time and it's a power of 2, we can let boost::simd::pack
and boost::simd::sum do the heavy lifting and simply write:

@snippet reduction.cpp reduc-simd-l

In this case, the size of our input data is an exact multiple of a __SIMD__ vector. What about the
case where this is not true?

@subsection reduction-hanging-data What happens if the number of data is not a multiple of the cardinal?
@snippet reduction.cpp reduc-simd-r

This is exactly the same as in the previous tutorial!

@section reduction-full-code Full code

Here is a full code, should you wish to try it:

@snippet reduction.cpp reduc

