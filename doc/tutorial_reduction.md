# Reductions {#tutorial-reduction}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

Now that we know how to use **Boost.SIMD** in simple cases, let's move onto more complex and useful
examples! This tutorial involves reducing an array of data to a scalar, for example computing the sum
or multiple of a vector.

We will now demonstrate how to calculate the sum of the contents of an array. The scalar way to calculate this is as follows:

@snippet reduction.cpp reduc-scalar

We see here that there is a dependence between loop iterations - the accumulated sum. However,
this dependency may be eliminated by forming our addition in the binary tree form shown here:

@snippet binary.txt binary

If we had an infinitely large __SIMD__ register, we could calculate the sum of _n_ elements in _log(n)_
steps. Unfortunately, we don't have infinitely large registers (even GPUs are limited in the number
of simultaneous calculations they can perform), however, the two approaches may be combined resulting
in a significant performance increase.

Here we combine the approaches by summing into a boost::simd::pack, allowing us to perform as many
simultaneous additions as there are elements in a pack. It is only at the end that we accumulate
these sub-sums into the full scalar sum using the boost::simd::sum function provided by 
`boost/simd/function/sum.hpp.`

@snippet reduction.cpp reduc-simd-o

If the size of our array is known at compile time and it's a power of 2, we can let boost::simd::pack
and boost::simd::sum do the heavy lifting and simply write:

@snippet reduction.cpp reduc-simd-l

In this case, the size of our input data is an exact multiple of a __SIMD__ vector. What about the
case where this is not true?

@snippet reduction.cpp reduc-simd-r

This is exactly the same as in the previous tutorial!

Here is a full code, should you wish to try it:

@snippet reduction.cpp reduc


