@anchor topofpage_sum
# Sum of Arrays {#tutorial-sum}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

In this tutorial we will demonstrate different ways to load and use a boost::simd::pack in a more realistic
uses cases than in the previous tutorial by vectorizing the following scalar code:

@snippet arrayplus.cpp sum-scalar

We will use boost::simd::load and boost::simd::store functions to load data into a pack and store
it back into memory. These functions are accessed by including the following headers:

@snippet arrayplus.cpp sum-include

We shall first assume that the size of our array is a multiple of the cardinal (number of elements
in a pack) for our target machine. Please note that this assumption is very unsafe as code written
using **Boost.SIMD** is designed to be portable across multiple architectures! The more realistic case
where this is no longer true is demonstrated afterwards. It is generally easiest and safest to use the
default pack size, corresponding to the size of the available physical _SIMD_ registers. This size may
be obtained using the boost::simd::cardinal\_of function.

@snippet arrayplus.cpp sum-cardinal

The first step in vectorizing this code is to load the data in a __SIMD__ vector. Several diferent ways
of doing this were demonstrated in the previous tutorial. We shall construct our pack with a pointer
to the data we wish to load. We then perform the subtraction using the operator `-` and then store
the data using `boost::simd::store`

@snippet arrayplus.cpp sum-pointer

Note that our loop is incremented by the number of elements in our pack as we are processing
`ipack_card` elements per loop iteration! Also note that `one28` is declared outside of the loop so
that it is not loaded at each iteration. Generally speaking, any compiler which supports **Boost.SIMD**
would automatically optimize this, although it is better to be safe!

If we wish to declare our pack outside of the loop, for example, if we wish to re-use it later,
we can load the data using `boost::simd::load`:

@snippet arrayplus.cpp sum-load

Easy, isn't it? Vectorization of code isn't using **Boost.SIMD** isn't so bad!

Now, let's extend the previous example to deal with the case where the size of our vector isn't
a multiple of our machine's phyiscal register size.

@snippet arrayplus.cpp sum-remainder

There are three main differences between this loop and the previous one. Firstly, the loop counter `i`
is declared outside of the first loop. This is so that its value is retained for use in the second loop.
The second difference is in seen in the first loops termination condition. The loop is now terminated when
`i + ipack_card <= size`. We do this to ensure that we never load data which is past the end of the array. 
The third and final difference is the second loop. This is almost identical to the scalar loop at the start
of this tutorial. The remaining elements in the input array, which are not sufficient to fill a __SIMD__
vector are processed individually. A more elegant way of achieving this is demonstrated in the tutorial
@ref tutorial-algorithm .

