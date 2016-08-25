Distance between Points {#tutorial-distance}
=========

@tableofcontents
In this tutorial we will examine how to calculate the cartesian distance
between a 2D reference point and a vector of 2D points. This could be used
for example in a clustering algorithm such as dbscan.

@section distance-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Introduce the Boost.SIMD vectorized versions of standard library functions](#distance-intro)
- [Demonstrate how to achieve significant speed up of expensive calculations using Boost.SIMD](#distance-simd)
- [Show you how to use data which is not in the required order](#distance-interleave)
- [Demonstrate the speed up achieved using Boost.SIMD](#distance-speed-up)

@section distance-intro Distance between two points

The distance between two points \f$(x_1,y_1)\f$, \f$(x_2,y_2)\f$ in the Cartesian plane is calculated as follows:

<CENTER>\f$\sqrt{(x_2-x_1)^2+(y_2-y_1)^2}\f$.</CENTER>

We can see that we must use the standard library functions `std::sqrt` and `std::pow`
in this calculation. So, in order to vectorize this code, we require vectorized
versions of these functions.  We wish to vectorize the following scalar code

@snippet distance.cpp distance-scalar

@subsection distance-simd The SIMD Calculation

We first declare our input data. The X and Y coordinates are stored in two separate vectors. These
vectors are assumed to be filled with the correct input data.

@snippet distance.cpp distance-declare

\notebox{We use aligned memory to ensure correct behaviour and highest performance}

**Boost.SIMD** comes with many useful functions for performing vectorized computations. In this example
we use the `+`, `-`, `sqr` and `sqrt` functions. The `sqr` functions calculates the square of each element
of a __SIMD__ vector. The first step is to fill a `pack_t` with the X and Y coordinates of the reference
point. We then apply the formula shown above for calculating the distance between two points.

@snippet distance.cpp distance-calc
@subsection distance-interleave How to deal with input data which is not properly ordered 

In the above example, we examined the case where the input data was stored in two
separate buffers, one each for the \f X\f and \f Y\f coordinates.

However, coordinates are often stored interleaved in memory as follows: \f$x_0, y_0, x_1, y_1... , x_n, y_{n-1}\f$

We could sort the input data before calculating the distance, however the cost of
doing this would negate any gain from using __SIMD__ instructions. To
solve this problem, we use the functions boost::simd::deinterleave_first
and boost::simd::deinterleave_second to sort the data in the requied order in
__SIMD__ register.

After loading the data into packs v0 and v1, they contain the following elements:

\f$v_0 = x_0, y_0, x_1, y_1... , x_{\frac{c}{2}-1}, y_{\frac{c}{2}-1}\f$

\f$v_1 = x_{\frac{c}{2}}, y_{\frac{c}{2}}, x_{\frac{c}{2}+1}, y_{\frac{c}{2}+1}, ...  x_{c-1}, y_{c-1}\f$

where c = pack_t::static_size or the number of elements in the pack.

In order to efficiently calculate the distance between our reference point and all of the other points,
the data must be re-ordered as follows:

\f$v_X = x_0, x_1, ... , x_{c-1} \f$

\f$v_Y = y_0, y_1, ... , y_{c-1} \f$


This is done as follows:

@snippet distance.cpp distance-interleave

