Julia Set {#tutorial-julia}
=========

@tableofcontents
In this tutorial we will calculate a Julia set using **@projectname**. This example is interesting because
the number of iterations required for each pixel of the image is different. This means that we need a method
of exiting the calculation loop when all of the pixels currently being worked on have converged.

@section branching-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Demonstrate how to vectorize a calculation where eaach pixel requires a varying amount of calculation](#branching-calculation)

@section branching-intro Julia Set

The calculation of the Julia set is a example of a problem which is completely compute bound, therefore
we expect to observe significant speed-up using **@projectname**. This code is vectorized as follows:

@snippet mandelbrot.cpp mandelbrot-simd

The function of interest here is bs::if_inc, which increments each element of the iter vector which has
not yet converged. This allows us to continue our calculation on the relevant elements.

@section branching-performance Performance

This code was run using an image size of 1024 pixels square. The code was compiled using g++-6.0
for both SSE4.2 and AVX2 and executed on an Intel Xeon CPU E3-1240 v3 @ 3.40GHz.

<table align=cen<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$) <th> Speed-up
<tr><td>Scalar              <td>768              <td> 
<tr><td>SIMD SSE4.2         <td>210              <td> x3.65
<tr><td>SIMD AVX2           <td>119              <td> x6.45
</table>

