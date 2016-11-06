Mathematical Functions {#tutorial-mathematical}
=========

@tableofcontents
In this tutorial we will demonstrate the use of SIMD mathematical functions
such as boost::simd::sin and boost::simd::cos.

@section data-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Demonstrate the use of SIMD mathematical functions](#tutorial-math-intro)
- [Introduce functions decorators which control the precision and speed of certain functions](#tutorial-math-decorators)

@section tutorial-math-intro SIMD Mathematical Functions

-------------------------------------

Mathematical functions can be very expensive, so using a vectorized version of
these functions is of great benefit, especially if you have a large input array.
**@projectname**  includes vectorized versions of all common mathematical functions
The developers of **@projectname** take numerical precisions very seriously, so all of these
functions are extremely accurate despite being highly optimized. Please refer to the section
@ref numerical-precision and @ref performance for further details.

The standard way to calculate the sine or cosine of a vector of data is to to loop over the data
and calculate the sine and cosine of each element:

@snippet mathematical.cpp mathematical-scalar

This type of calculation is the perfect candidate for vectorization!

@snippet mathematical.cpp mathematical-calc-individ

In this example we are calculating the sine and the cosine of the same input vector X. The calculations
of a sine and cosine contain many common steps, so it is possible to calculate them both simultaneously
and thus save precious cpu cycles!

@snippet mathematical.cpp mathematical-calc-combine

@section tutorial-math-decorators @projectname functions decorators

There are several different versions of many **@projectname** functions. For
example, if the input angle is guaranteed to be within the range
\f$ [-\pi/4, \pi/4]\f$ (Oh! its just the case in the initialization we choose, what a coincidence!)
you may use the `restricted_` function decorator on the mathematical functions
which returns a result of the same precision, but consumes fewer cpu cycles.

@snippet mathematical.cpp mathematical-calc-restricted

Please refer to boost::simd::decorator for an explanation of available decorators.

Here is a full code, should you wish to try it:

@snippet mathematical.cpp mathematical-all

The test done in this file asserts (if it succeeds) that each compared values differs
at most of 0.5 ulp (unit in the last place). Refer to boost::simd::ulpdist for more informations.

