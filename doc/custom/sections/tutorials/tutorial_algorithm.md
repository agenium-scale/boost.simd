@anchor topofpage_algorithm
# Algorithm {#tutorial-algorithm}
=========

@tableofcontents
In this tutorial we will examine how to use STL-like algorithms to use SIMD accelerations.

@section The SIMD Loop tutorial revisited

-------------------------------------

Let us suppose again we have a size N filled of `int32_t` array `array`, an output array `out` of the same size and a scalar
value `scalar`:

@snippet algo1.cpp init

To subtract the scalar to each element of the array, using STL, this can be writen in the following way:

@snippet algo1.cpp scalar1

In the SIMD case, it would be nice to merely have to replace `std::transform`
 by `boost::simd::transform` to have we job done.

However there is a slight more to do because the lambda function used in the scalar version is only defined on
`std::int32_t` and not on pack of `std::int32_t`.

If you use C++-14 this can be corrected using a generic lambda:

@snippet algo1.cpp lambda14

with the slight inconvenience that the scalar value will be splatted at each SIMD call in the loop.

In all cases (even with with C++-11) you can write a function object :

@snippet algo1.cpp funcobj11

Here the main point is that `f` has two overload of `operator()` devoted to the scalar and simd case.

Of course allmost all Boost.SIMD functors already behave on scalar and on SIMD vectors, so to take the square root
of all elements of the input, you can write:

@snippet algo1.cpp sqr1

after the include: `#include <boost/simd/function/sqrt.hpp>`


@section transform  How does boost::simd::transform works

-------------------------------------

The algorithm `boost::simd::transform` splits the range you gave to him by three ranges:

  - a prologue from the beginning of the initial range to the nearest correct alignement point
  - a main part from the aligned point to the maximum of the range allowing a whole SIMD vector position
  - an epilogue for the remaining scalars that do not fill a full SIMD vector

and applies a transform to the three ranges with the proper function objects.

The algorihm takes also care of possible misalignment of the output, the best performances
being obtained if input and output are correctly aligned and input has a size multiple of the
SIMD cardinal.


@section reduce An other example boost::simd::reduce

-------------------------------------

How to compute, in an simd efficient way, the product of input elements.
This operation can be vectorized, but less obviously than the previous one, as the
 good way is an out of order vectorization.


Let us suppose that our input is a vector of N SIMD vectors

In fact two ways are possible at first sight:

 - the wrong way: sum the 'horizontal' sums of each vector.

   This is the wrong way as SIMD hardware is generally not so good with horizontal operations and
   this process uses N such operations.

 - the good way: sum the 'vertical' sum of the squared SIMD vectors.

   This results  in N-1 'vertical' mutipliesin only 1 final 'horizontal' operation.

boost::simd::reduce acts the good way. and take also care of alignment problems as boost::simd::transform.
But this algorithm is more restricted than std::reduce on the variety of binary operators than can be used
in the process and also requires the knowledge of a neutral element for the operator.

Here is a full example that computes 10!. In fact it computes
 \f$10\prod_1^9 i\f$ (just to ilustrate the init value possibility) and uses the \f$Gamma\f$ function to
verify the result:

@snippet reduce.prod.cpp reduceprod

The possible output is:

@code
SIMD reduce    : 3.6288e+06
 10!           : 3.6288e+06
@endcode
