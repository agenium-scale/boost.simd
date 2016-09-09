Transcendental Functions {#tutorial-transcendental}
=========

@tableofcontents
In this tutorial we will demonstrate the use of SIMD transcendental functions
such as boost::simd::sin and boost::simd::cos.

@section data-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Demonstrate the use of SIMD transcendental functions](#tutorial-trans-intro)
- [Introduce functions decorators which control the precision and speed of certain functions](#tutorial-trans-decorators)

@section tutorial-trans-intro SIMD Transcendental Functions

-------------------------------------

Transcendental functions are very expensive, so using a vectorized version of
these functions is of great benefit, especially if you have a large input array.
**Boost.SIMD**  includes vectorized versions of all common transcendental functions
The developers of **Boost.SIMD** take numerical precisions very seriously, so all of these
functions are extremely accurate despite being highly optimized Please refer to the section
@ref numerical-precision and @ref performance for further details.

The standard way to calculate the sine or cosine of a vector of data is to to loop over the data
and calculate the sine and cosine of each element:

@snippet transcendental.cpp transcendental-scalar

This type of calculation is the perfect candidate for vectorization!

@snippet transcendental.cpp transcendental-calc-individ

In this example we are calculating the sine and the cosine of the same input vector X. The calculation
of a sine and cosine contain many common steps, so it is possible to calculate them both simultaneously
and thus save precious cpu cycles!

@snippet transcendental.cpp transcendental-calc-combine

@section tutorial-trans-decorators Boost.SIMD functions decorators

There are several different versions of many **Boost.SIMD** functions. For
example, if the input angle is guaranteed to be within the range 
\f$ [-20\pi,  20\pi]\f$
you may use the boost::simd::tag::small_ function decorator on transcendental functions
which returns a result of the same precision, but consumes fewer cup cycles.

@snippet transcendental.cpp transcendental-calc-small

Please refer to boost::simd::cos for an explanation of all available decorators.

