Evaluation of a Neural Network {#tutorial-neural}
=========
<div style="text-align: right;" markdown="1">Prev: [SIMD Branching Part 2 - Computations with different types](@ref tutorial-branching-split)</div>
<div style="text-align: right;" markdown="1">Next: [Evaluation of the N-Body problem](@ref tutorial-nbody)</div>

@tableofcontents
In this tutorial we will demonstrate how the evaluation of neural network
can be significantly accelerated using **@projectname**.

@section neural-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Introduce the problem of neural network activation function evaluation using **@projectname**](#neural-intro)
- [Demonstrate various methods of calculating a neural network activation function using **@projectname**](#neural-methods)
- [Benchmark the various methods introduced in the previous section](#neural-bench)
- [Discuss the performance of each method](#neural-conc)

@section neural-intro Neural Network Activation Function

The activation function of a neural network is typically a sigmoid function
of the form:

<CENTER>\f[\sigma = \frac{1}{1+e^{-z}}\f]</CENTER>

This is a function that could significantly benefit from vectorization. We vectorize this function
using bs::transform as this handles the case where the input size is not an exact multiple of the
__SIMD__ vector size.

The following scalar code is used for this calculation:

@snippet neural_net.cpp neural-scalar

@section neural-methods Vectorization of Neural Network Activation Function

The above code is vectorized as follows:

@snippet neural_net.cpp neural-transform

The actual calculation is performed in the following functor:

@snippet neural_net.cpp neural-struct

A functor must be used for bs::transform as c++11 does not support generic lambda
functions. If you are using a C++14 compiler, you may place this code inside a lambda
function.

This calculation may also be performed using bs::rec, which is the equivalent of
<CENTER>\f[\frac{1}{x}\f]</CENTER>

@snippet neural_net.cpp neural-rec

The scalar computation may also be performed using bs::exp as follows:

@snippet neural_net.cpp neural-scalar-bs


@section neural-bench Performance

Each code was run using a sample size of 16000000. The code was compiled using g++-6.0 using the compiler flag
-msse2 and executed on an Intel Xeon CPU E3-1240 v3 @ 3.40GHz.

<table align=center width=100% class="table-striped table-bordered">
<tr><th>Calculation         <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>143
<tr><td>Scalar - bs::exp    <td>102
<tr><td>SIMD                <td>38
<tr><td>SIMD rec            <td>38
</table>

There are some very interesting results observed here. Firstly, when std::exp is replaced by bs::exp,
a 50 % speed-up is observed, although the code is not vectorized. This is due to the implementation of
bs::exp. It is a much more efficient implementation that the standard library exp, whilst maintaining
the same or better precision. Therefore, the use of the **@projectname** standard library replacement
functions in non-vectorized code may be very advantageous. A speed-up of 3.76 is observed between the
the scalar and SIMD versions of this calculation, which is in line with the theoretical maximum for an SSE
code.

This test was repeated compiling for AVX:
<table align=center width=100% class="table-striped table-bordered">
<tr><th>Calculation         <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>1058
<tr><td>Scalar - bs::exp    <td>99
<tr><td>SIMD                <td>36
<tr><td>SIMD rec            <td>36
</table>

When the same code us re-compiled for AVX, we note that there is a large regression in the performance
of std::exp, while the time taken by the other computations remains unchanged. The reason for the large
regression in the performance of std::exp is explained by the fact that this code mixes legacy SSE instructions
with AVX instructions. The reasons behind this are explained by
[Intel](https://software.intel.com/en-us/articles/intel-avx-state-transitions-migrating-sse-code-to-avx). This
may be rectified by adding the instruction _mm256_zeroupper() before each call to std::exp. However, this will
erase any AVX register that you may be using. The much safer solution is to replace all calls to std::exp by calls
to bs::exp when your code is compiled for AVX and above. This is true for all standard library functions which are
provided **@projectname**.

There is no performance gain for the vectorized functions when changing from SSE4.2 and AVX. Although of all the calculations
performed in this tutorial are performed using floating point numbers, the calculation of bs::exp requires the use of
integers. Therefore, parts of the exponential calculation are performed using SSE instructions. We expect to see a performance
gain between AVX and AVX2

<table align=center width=100% class="table-striped table-bordered">
<tr><th>Calculation         <th>Time (\f$\mu s\f$)
<tr><td>Scalar              <td>1063
<tr><td>Scalar - bs::exp    <td>100
<tr><td>SIMD                <td>21
<tr><td>SIMD rec            <td>21
</table>

We observe a speed-up of 1.5 between AVX and AVX2 in this calculation. Although the theoretical maximum
speed-up is 2, it is often difficult to achieve this in practice.

@section neural-conc Conclusions

We observed significant speed-ups by vectorizing this code using **@projectname**. Using SSE4.2, a speed-up of
3.76 was observed and using AVX2, a speed-up of 6.81 was observed. If we compare the results obtained using std::exp
in AVX2 with that obtained using **@projectname**, the speed-up is 50.6!. It is clear that the use of **@projectname**
in any project involving vectorization is very beneficial, not just for the ease of vectorization and portability between
architectures, compilers and operating systems, but also because of the performance of its standard library replacement
functions.

<div style="text-align: right;" markdown="1">Prev: [SIMD Branching Part 2 - Computations with different types](@ref tutorial-branching-split)</div>
<div style="text-align: right;" markdown="1">Next: [Evaluation of the N-Body problem](@ref tutorial-nbody)</div>
