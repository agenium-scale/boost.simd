Distance between Points Part 1{#tutorial-distance}
=========
<div style="text-align: right;" markdown="1">Prev: [Runtime Extension Selection](@ref tutorial-runtime)</div>
<div style="text-align: right;" markdown="1">Next: [Distance between 2D Points Part 2](@ref tutorial-distance-hypot)</div>

@tableofcontents
In this tutorial we will examine how to calculate the Cartesian distance
between a 2D reference point and a vector of 2D points. This could be used
for example in a clustering algorithm such as dbscan.

@section distance-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Introduce the @projectname vectorized versions of standard library functions](#distance-intro)
- [Demonstrate how to achieve significant speed up of expensive calculations using @projectname](#distance-simd)
- [Show you how to use data which is not in the required order](#distance-interleave)
- [Show how to measure the speed up achieved using @projectname](#distance-speed-up)
- [Introduce detailed performance analysis](#distance-performance-analysis)

@section distance-intro Distance between two points

The distance between two points \f[(x_1,y_1), (x_2,y_2)\f] in the Cartesian plane is calculated as follows:

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

**@projectname** comes with many useful functions for performing vectorized computations. In this example
we use the `+`, `-`, `sqr` and `sqrt` functions. The `sqr` functions calculates the square of each element
of a __SIMD__ vector. The first step is to fill a `pack_t` with the X and Y coordinates of the reference
point. We then apply the formula shown above for calculating the distance between two points.

@snippet distance.cpp distance-calc

@subsection distance-interleave How to deal with input data which is not properly ordered

In the above example, we examined the case where the input data was stored in two
separate buffers, one each for the \f$ X\f$ and \f$ Y\f$ coordinates.

However, coordinates are often stored interleaved in memory as follows: \f$x_{0}, y_0, x_1, y_1, \ldots , x_n, y_{n-1}\f$

We could sort the input data before calculating the distance, however the cost of
doing this would negate any gain from using __SIMD__ instructions. To
solve this problem, we use the function boost::simd::deinterleave
to sort the data in the required order in __SIMD__ register.

After loading the data into packs v0 and v1, they contain the following elements:

\f[v_{0} = x_0, y_0, x_1, y_1, \ldots , x_{\frac{c}{2}-1}, y_{\frac{c}{2}-1}\f]

\f[v_1 = x_{\frac{c}{2}}, y_{\frac{c}{2}}, x_{\frac{c}{2}+1}, y_{\frac{c}{2}+1}, \ldots, x_{c-1}, y_{c-1}\f]

where c = pack_t::static_size or the number of elements in the pack.

In order to efficiently calculate the distance between our reference point and all of the other points,
the data must be re-ordered as follows:

\f[v_x = x_0, x_1, \ldots , x_{c-1} \f]

\f[v_y = y_0, y_1, \ldots , y_{c-1} \f]


This is done as follows:

@snippet distance.cpp distance-interleave

@section distance-speed-up Measuring the speed up
If you decide to develop software using **@projectname**, performance is clearly
very important to you. Therefore, it is necessary to be able to accurately measure
the speed-up achieved. In this example, we measure the time taken for the main
calculation loop using the timing utilities provided by `std::chrono`. Where available,
these functions use hardware timers.

@snippet distance.cpp distance-time

The speed-up can be then calculated by dividing the time taken for the scalar loop
by the time taken by the __SIMD__ loop. There are several factors to consider
when measuring the performance of code. Firstly, you should ensure that the size of
the input data is sufficient to fill the CPU cache. Otherwise, the cache will be "hot"
one entering the second loop. This means that all of the data required to complete
the calculation will already be loaded into the cache, significantly accelerating the
execution of the loop. You should also run the code several times and take the average
of the execution times, as this may vary significantly between runs for many reasons.
In general, we are interested in the typical runtime of a section of code.

@section distance-performance-analysis Performance analysis

This code was run on an x86 machine with an Intel Xeon CPU E3-1240 v3 @ 3.40GHz. It was
compiled using g++-6.0 with all optimizations enabled and with the flag -msse4.2. A sample
size of 1600000 was used.

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>3174
<tr><td>SIMD                <td>1301
<tr><td>SIMD Interleaved    <td>1401
</table>

An SSE vector contains four floats. Therefore, we should expect the speed-up to
a maximum of four. However, it is less then that. There are several reasons for
this. The first is that the time taken to load the data from memory accounts for
a significant amount of the total time.

The code was then re-compiled for AVX2 using -mavx2 flag with the following results:

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>3142
<tr><td>SIMD                <td>1364
<tr><td>SIMD Interleaved    <td>1575
</table>

Firstly, we note that as expected the scalar loop took approximately the same time
as for sse4.2. However, we would expect that the __SIMD__ loops would execute in
half of the time as on SSE4.2 as the register size is twice as large in AVX equipped
machines. In this case, the time taken is approximately constant. The answer to this question lies
in the Intel processor documentation. On an SSE4.2 processor the number of cycles taken to compute
the square root of a vector of single precision (sqrtps instruction) floating point number is between
10 and 14 cycles, depending on the exact processor. On AVX enabled processor, the number of cycles
required to perform the same operation on an AVX vector of single precision floating point
numbers is between 21 and 28 cycles. Therefore, for this particular instruction, there is little
advantage in using an AVX enabled processor. Please note that this is not true for most other
instructions, which generally require the same number cycles as an SSE equipped processor
for the same operation.

We also can see that the __SIMD__ interleave loop took slightly longer on AVX then on SSE. The reason
for this lies in the functions supported by AVX processors. Not all SSE functions
are supported by AVX processors, in this case, there is no corresponding deinterleave
intrinsic on AVX. Therefore, **@projectname** splits the avx vector
into two SSE vectors before performing the deinterleave operation. It is for this reason
that the code takes longer to execute on AVX than on SSE.

@section distance-full-code Full code
Here is the full code, should you wish to compile it:

@snippet distance.cpp distance-all

<div style="text-align: right;" markdown="1">Prev: [Runtime Extension Selection](@ref tutorial-runtime)</div>
<div style="text-align: right;" markdown="1">Next: [Distance between 2D Points Part 2](@ref tutorial-distance-hypot)</div>
