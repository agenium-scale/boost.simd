Julia Set {#tutorial-julia}
=========

<div style="text-align: right;" markdown="1">Prev:  [Distance between 2D Points Part 2](@ref tutorial-distance-hypot)</div>

@tableofcontents
In this tutorial we will calculate a Julia set using **@projectname**. This example is interesting because
the number of iterations required for each pixel of the image is different. This means that we need a method
of exiting the calculation loop when all of the pixels currently being worked on have converged.

@section julia-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Demonstrate how to vectorize a calculation where each pixel requires a varying amount of calculation](#julia-calculation)

@section julia-intro Julia Set

The calculation of the Julia set is a example of a problem which is completely compute bound, therefore
we expect to observe significant speed-up using **@projectname**.

Here is the scalar version:

@snippet mandelbrot.cpp mandelbrot-scalar

This code is vectorized as follows:

@snippet mandelbrot.cpp mandelbrot-simd

The function of interest here is bs::if_inc, which increments each element of the iter vector which has
not yet converged. This allows us to continue our calculation on the relevant elements.

We have also used the function bs::any returns a boolean value if any of its parameter element is non zero,
We have also used the bs::sqr function which squares its argument and the bs::fma function (fused multiply add) which
can accelerate and increase accuracy "a*b+c" computations on some architectures.

@section julia-performance Performance

This code was run using an image size of 1024 pixels square. The code was compiled using g++-6.0
for both SSE4.2 and AVX2 and executed on an Intel Xeon CPU E3-1240 v3 @ 3.40GHz.

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$) <th> Speed-up
<tr><td>Scalar              <td>768              <td>
<tr><td>SIMD SSE4.2         <td>210              <td> x3.65
<tr><td>SIMD AVX2           <td>119              <td> x6.45
</table>


<div style="text-align: right;" markdown="1">Prev:  [Distance between 2D Points Part 2](@ref tutorial-distance-hypot)</div>
