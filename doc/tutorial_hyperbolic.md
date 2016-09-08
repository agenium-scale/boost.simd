# Hyperbolic Functions {#tutorial-hyperbolic}

So you need to calculate the sine or cosine of a large amount of data. These functions are very
expensive, but luckily **Boost.SIMD** has your back as it comes with vectorized versions of these
functions! The developers of **Boost.SIMD** take numerical precisions very seriously, so all of our
functions are extremely accurate despite being highly optimized! Please refer to the section
@ref numerical-precision and @ref performance for further details.

The standard way to calculate the sine ror cosine of a vector of data is to to loop over the data
and calculate the sine and cosine of each element:

@snippet hyperbolic.cpp hyperbolic-scalar

This type of calculation is the perfect candidate for vectorization!

@snippet hyperbolic.cpp hyperbolic-calc-individ

In this example we are calculating the sine and the cosine of the same input vector X. The calculation
of a sine and cosine contain many common steps, so it is possible to calculate them both simultaneously
and thus save precious cpu cycles!

@snippet hyperbolic.cpp hyperbolic-calc-combine

