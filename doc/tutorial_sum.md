# Sum of Arrays {#tutorial-sum}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

This tutorial presents the different ways to fill and use a boost::simd::pack in a more realistic use case than above.

The following methods will show different ways to vectorize the following scalar code computing the difference between an array and a constant.

@snippet arrayplus.cpp sum-scalar

In order to take advantage of **Boost.SIMD**, we will use the boost::simd::load and boost::simd::store functions to load data into the pack and store it back into memory.

@snippet arrayplus.cpp sum-include

The simplest approach, exclusive to arrays whose sizes are powers of 2, is to load the full array into a pack the size of the array.

@snippet arrayplus.cpp sum-packs

This section loads the full input array into a pack and fills another pack with our constant. This allows us to perform the substraction directly on the full array with one line of code.

For arrays whose sizes are not clean multiples of 2, we must use smaller sized packs (or pad the length to the next power of 2). It is generally simplest to use the default pack size, corresponding to the size of the available physical _SIMD_ registers. This size can be obtained using the boost::simd::cardinal\_of function.

Note that we increment our loop by the number of elements in our pack because we are treating more than one element per loop iteration.

The last two **Boost.SIMD** implementations must take advantage of this cardinal size in order to properly iterate over the array.
Both implementations must manually specify the memory address of the data to load into a pack, loading a few elements per loop iteration.
For each loop iteration, we must load the array data into a boost::simd::pack, perform the substraction between packs, then store the result into the output array.

There are two ways to load data into our packs:

1. By explicitly calling the boost::simd::load function
@snippet arrayplus.cpp sum-load

2. By constructing a boost::simd::pack with a pointer towards the correct address
@snippet arrayplus.cpp sum-pointer


Here is the full compilable code for reference.

@snippet arrayplus.cpp sum


