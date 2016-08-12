# Reductions {#tutorial-reduction}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

Now that we know how to handle simple _SIMD_ kernel, let's have a look at more complex operations involving operations across the values stored in a boost::simd::pack.

Here we will examine how to calculate the sum of the contents of an array. The scalar way to calculate this is as follows:

@snippet reduction.cpp reduc-scalar

We see here that there is a dependence between loop iterations - the accumulated sum. However, this dependency can be eliminated by forming our addition in the binary tree form shown here:

@snippet binary.txt binary

If we had an infinitely large _SIMD_ register, this would allow us to calculate the sum of _n_ elements in _log(n)_ steps. Unfortunately, we do not have infinitely large registers (even GPUs are limited in their number of simultaneous calculations), but we can combine the two approaches to nonetheless gain a certain amount of performance.

Here we combine the approaches by summing into a boost::simd::pack, allowing us to perform as many simultaneous additions as there are elements in a pack. It is only at the end that we accumulate these sub-sums into the full scalar sum using the boost::simd::sum function provided by boost/simd/function/sum.hpp.

@snippet reduction.cpp reduc-simd-o

If the size of our array is known at compile time and is a power of 2, we may let boost::simd::pack and boost::simd::sum handle the hard parts and simply write

@snippet reduction.cpp reduc-simd-l

Here is a full code, should you wish to compile it.

@snippet reduction.cpp reduc


