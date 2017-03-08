Distance between Points Part 2{#tutorial-distance-hypot}
=========

<div style="text-align: right;" markdown="1">Prev:  [Distance between 2D Points](@ref tutorial-distance)</div>
<div style="text-align: right;" markdown="1">Next:[Vectorizing the Julia Set Calculation](@ref tutorial-julia)</div>

@tableofcontents
In this tutorial we will extend the previous tutorial which demonstrated how to
calculate the distance between between a 2D reference point and a vector of 2D points by
introducing several other methods of performing the same calculation. These additional methods
are not just syntactic changes - they have a significant effect on the performance and precision
of the calculation.

@section distance-hypot-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Compare scalar and SIMD calculations using hypot function](#distance-hypot-intro)
- [Introduce the 'fast' versions of @projectname functions](#distance-hypot-fast)

@section distance-hypot-intro Using the hypot function

Both the C++ standard library and **@projectname** provide the function hypot, which calculates the
the square root of the sum of the squares of \f$x\f$ and \f$y\f$, without undue overflow or underflow
at intermediate stages of the computation, [cppreference.](http://en.cppreference.com/w/cpp/numeric/math/hypot)

We wish to vectorize the following scalar code

@snippet distance_hypot.cpp distance-hypot-scalar

@subsection distance-hypot-simd The SIMD Calculation

This code is trivial to vectorize using **@projectname**

@snippet distance_hypot.cpp distance-hypot-calc

Note that in this version we have used the @c pedantic_ decorator to use the boost.simd version of hypot that is the closest to
the @c std::hypot function behaviour.

@subsection distance-hypot-performance Performance

As was done in the previous example, this code was compiled using g++-6.0 with all optimizations
enabled and run on an Intel Xeon CPU E3-1240 v3 @ 3.40GHz. The following results were obtained when
the code was compiled for SSE4.2

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>8639
<tr><td>SIMD                <td>6417
</table>

We note that the performance of both the scalar and SIMD versions is much slower than in the previous
tutorial - this is the price paid for increased precision and detection of under and overflow at intermediate
stages of the computation.

@subsection distance-hypot-fast Fast @projectname functions

In many cases, the detection of under or overflow at intermediate stages of the computation is not
required, for example, if the input data is known to be in a certain range. Therefore, **@projectname**
provides regular versions of certain functions which omit these checks.

@snippet distance_hypot.cpp distance-hypot-fast-hypot

Again, using SSE4.2 instructions, the following performance was observed:

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>8639
<tr><td>SIMD                <td>6417
<tr><td>SIMD 'fast'         <td>1328
</table>

We note here that the performance using regular hypot is equal to that obtained
in the previous tutorial's SIMD calculation.

<div style="text-align: right;" markdown="1">Prev:  [Distance between 2D Points](@ref tutorial-distance)</div>
<div style="text-align: right;" markdown="1">Next:[Vectorizing the Julia Set Calculation](@ref tutorial-julia)</div>
