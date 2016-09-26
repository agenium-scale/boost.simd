Distance between Points {#tutorial-distance}
=========

@tableofcontents
In this tutorial we will examine how to calculate the cartesian distance
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

**@projectname** comes with many useful functions for performing vectorized computations. In this example
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

@section distance-speed-up Measuring the speed up
If you decide to develop software using **@projectname**, performance is clearly
very important to you. Therefore, it is necessary to be able to accurately measure
the speed-up achieved. In thsi example, we measure the time taken for the main
calculation loop using the timing utilities provided by `std::chrono`. Where available,
these functions use hardware timers.

@snippet distance.cpp distance-time

The speed-up can be then calculated by dividing the time taken for the scalar loop
by the time taken by the __SIMD__ loop. There are several factors to consider
when measuring the performance of code. Firstly, you should ensure that the size of
the input data is sufficient to fill the CPU cache. Otherwise, the cache will be "hot"
one entering the second loop. This means that all of the data required to complete
the calculation will already be loaded into the cache, significantly accelerating the
execution of the loop. You shoudl also run the code several times and take the average
of the execution times, as this may vary significantly between runs for many reasons.
In general, we are interested in the typical runtime of a section of code.

@section distance-performance-analysis Performance analysis

This code was run on an x86 machine with an Intel Xeon CPU E3-1240 v3 @ 3.40GHz. It was
compiled using g++-4.9 with all optimizations enabled and with the flag -msse4.2. A sample
size of 1024000 was used.

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>3894
<tr><td>SIMD                <td>846
<tr><td>SIMD Interleaved    <td>859 
</table>

An SSE vector contains four floats. Therefore, we should expect the speed-up to
a maximum of four. However, it is quicker then that. A possible explanation for
this is given in the next paragraph. The code was then re-compiled for AVX2 
using -mavx2 flag with the following results:

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>3868
<tr><td>SIMD                <td>856
<tr><td>SIMD Interleaved    <td>1407
</table>

Firstly, we note that as expected the scalar loop took approximately the same time
as for sse4.2. However, we would expect that both __SIMD__ loops would execute in
half of the time as on SSE4.2 as the register size is twice as large in AVX equipped
machines. In this case, the time taken is constant. There are several explanations
for this. Firstly, the SSE4.2 code was executed on an AVX equipped processor. Modern
processors are very sophisticated, and often they can "upgrade" SSE instruction to
its equivalent AVX instruction, if available. Therefore, the code may run twice
as fast as predicted. The conclusion of this is that it is not possible to accurately
measure the performance of SSE code on an AVX machine. So this begs the questions,
why was the SSE code not 8 times faster than the scalar code. Take for example the
SSE add intrinsic, which adds two SSE vectors, thus 4 floats in one instruction. Every
processor instruction has a latency and a throughput, which for Intel processor are
given in the Intel Intrinsics Guide. The latency and throughput for add for example
is not necessarily equal to that for the scalar add instruction. Therefore, the use
of the __SIMD__ intrinsics does not necessarily result in a 4 times speed-up.

We also can see that the __SIMD__ interleave loop took signicantly longer on AVX then on SSE. The reason
for this lies in the functions supported by AVX processors. Not all SSE functions
are supported by AVX processors, in this case, there is no corresponding deinterleave
first and second intrinsic on AVX/. Therefore, **@projectname** splits the avx vector
into two SSE vectors before performing the deinterleave operation. It is for this reason
that the code takes longer to execute on AVX than on SSE.

@section distance-full-code Full code
Here is the full code, should you wish to compile it:

@snippet distance.cpp distance-all
