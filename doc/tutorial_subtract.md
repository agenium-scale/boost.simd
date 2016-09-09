A SIMD Loop {#tutorial-simd-loop}
=========

@tableofcontents
In this tutorial we will demonstrate how to construct a SIMD loop by subtracting a constant
from a vector of input data.

@section sum-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Transform a scalar loop into a __SIMD__ loop](#sum-scalar-simd)
- [Loop over the input data and perform the calculation on several elements at once](#sum-construct-loop)
- [Show how handle cases where the number of input data is not an exact multiple of the size of a pack](#sum-hanging-data)

@section sum-scalar-simd Transforming a scalar loop into a SIMD loop
In this tutorial we will demonstrate how to transform the following scalar loop into a __SIMD__ loop:

@snippet arraysubtract.cpp sum-scalar

The first step is to determine the number of elements in a pack of the choosen primitive type, in this
case an `int`.  It is generally easiest and safest to use the default pack size, corresponding to the
size of the available physical _SIMD_ registers. This size may be obtained using the
boost::simd::cardinal\_of function.

@snippet arraysubtract.cpp sum-cardinal

This size may also be accessed through the member variable pack_t::static_size.

We shall first assume that the size of our array is a multiple of the cardinal of the pack.
Please note that this assumption is very unsafe as code written
using **Boost.SIMD** is designed to be portable across multiple architectures! The more realistic case
where this is no longer true is demonstrated afterwards.

@subsection sum-constant Filling the subtraction pack
We wish to subtract `128` from each element in the input data. We therefore fill a vector will this
value in the exact same way as in the previous tutorial.

@snippet arraysubtract.cpp sum-one28

@subsection sum-construct-loop Constructing the loop

We now construct our loop. Note how `i` is incremented by the cardinal of the pack as we process `cardinal`
elements of the input data for each iteration of the loop.

@snippet arraysubtract.cpp sum-loop-con

@subsection sum-load-simd Filling the loop
In order to process the input data, we must
load load the data from memory using boost::simd::load and then store it afterwards back in memory
using boost::simd::store These functions are accessed by including the following headers:

@snippet arraysubtract.cpp sum-include

We shall construct our pack with a pointer to the data we wish to load. We then perform the subtraction
using the operator `-` and then store the data using boost::simd::store

@snippet arraysubtract.cpp sum-pointer

Note that `one28`, the pack of constants to be subtracted from the input data, is declared outside
of the loop so that it is not loaded at each iteration.
Generally speaking, any compiler which supports **Boost.SIMD** would automatically optimize this,
although it is better to be safe!

If we wish to declare our pack outside of the loop, for example, if we wish to re-use it later,
we can load the data using boost::simd::load:

@snippet arraysubtract.cpp sum-load

@section sum-hanging-data What happens when the input data is not a multiple of the cardinal?

So, how do we handle the case where the input data is not a multiple of the cardinal? We simply
write a scalar loop to handle this extra data.

@snippet arraysubtract.cpp sum-remainder

There are three main differences between this loop and the previous one. Firstly, the loop counter `i`
is declared outside of the first loop. This is so that its value is retained for use in the second loop.
The second difference is in seen in the first loops termination condition. The loop is now terminated when
`i + pack_card <= size`. We do this to ensure that we never load data which is past the end of the array.
The third and final difference is the second loop. This is almost identical to the scalar loop at the start
of this tutorial. The remaining elements in the input array, which are not sufficient to fill a pack
are processed individually. A more elegant way of achieving this is demonstrated in the tutorial
@ref tutorial-algorithm .

