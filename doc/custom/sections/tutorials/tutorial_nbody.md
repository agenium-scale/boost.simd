N-Body Problem {#tutorial-nbody}
=========

<div style="text-align: right;" markdown="1">Prev: [Evaluation of a Neural Network](@ref tutorial-neural)</div>
<div style="text-align: right;" markdown="1">Next: [Runtime Extension Selection](@ref tutorial-runtime)</div>

@tableofcontents
In this tutorial we will show you how to optimize an n-body
simulation using **@projectname**,

@section tutorial-nbody-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Introduce the N-body Problem](#tutorial-nbody-intro)
- [Demonstrate how to perform an N-body simulation ysing @projectname](#tutorial-nbody-calc)

@section tutorial-nbody-intro N-Body Problem

-------------------------------------

This problem is concerned with the calculation of the individual motion of celestial objects caused
by gravity. This is an example of a problem of \f$N^2\f$ complexity. The formula to calculate the
gravitational force between two objects is:

\f[F=\frac{Gm_im_j(q_i - q_j)}{{\|q_i-q_j\|}^3}\f]

Where:
  \f$\mathbf{q_i}\f$ is the position vector of object \f$i\f$
  \f$\mathbf{m_i}\f$ is the mass of object \f$i\f$
  \f$G\f$ is the gravitational constant

@section tutorial-nbody-calc Calculation

-------------------------------------

The scalar calculation of this problem is done as follows:

@snippet nbody-struct-soa-bs.cpp nbody-scalar

Note the use of a small constant, \f$\epsilon\f$. This is referred to as \a softening, a numerical trick
to prevent division by zero if two particles are too close together.

This calculation is trivially vectorizable as follows:

@snippet nbody-struct-soa-bs.cpp nbody-simd

\notebox{All constants are loaded into __SIMD__ vectors outside of the main loop, so that these vectors are
not generated each iteration of the calculation.
}

It is not possible to use aligned stores in the interior loop as these stores will not be aligned for each
store.

@section tutorial-nbody-performance Performance

This code as compiled using g++6.0 for sse4.2 and avx2. It was executed on an Intel Xeon CPU E3-1240 v3 @ 3.40GHz.
The following results were obtained:

<table align=center width=25% class="table-striped table-bordered">
<tr><th>Loop                <th>Time (\f$\mu s\f$) <th> Speed-up
<tr><td>Scalar              <td>13185              <td>
<tr><td>SIMD SSE4.2         <td>4104               <td> x3.21
<tr><td>SIMD AVX2           <td>2321               <td> x5.68
</table>

The performance obtained is broadly in line with the theoretical maximum possible speed-ups of x4 for SSE4.2 and x8 for AVX2.
There are very few problems where these theoretical speed-ups are obtainable.

<div style="text-align: right;" markdown="1">Prev: [Evaluation of a Neural Network](@ref tutorial-neural)</div>
<div style="text-align: right;" markdown="1">Next: [Runtime Extension Selection](@ref tutorial-runtime)</div>
