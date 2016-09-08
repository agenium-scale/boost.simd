# Distance between Points {#tutorial-distance}

In this tutorial we will look at how to calculate the cartesian distance between a 2D reference point
and a vector of 2D points. This could be used for example in a clustering algorithm such as dbscan.

We first declare our input data. The X and Y coordinates are stored in two separate vectors. These
vectors are assumed to be filled with the correct input data.

@snippet distance.cpp distance-declare

**Boost.SIMD** comes with many useful functions for performing vectorized computations. In this example
we use the `+`, `-`, `sqr` and `sqrt` functions. The `sqr` functions calculates the square of each element
of a __SIMD__ vector. The first step is to fill a `pack_t` with the X and Y coordinates of the reference
point. We then apply the standard formula for calculating the distance betweemn two points.

@snippet distance.cpp distance-calc

What about the more compelx case where the X and Y coordinates are interleaved in memory. For example,
the input data is as follows: `x0, y0, x1, y1, ..., xn, yn`. We could sort the input data before calculating
the distance but the cost of doing this would negate any gain from using __SIMD__ instructions. To
solve this problem, we use the functions `bs:deinterleave_first` and `bs::deinterleave_second` as follows:

@snippet distance.cpp distance-interleave

After loading the data into packs v0 and v1, they contain the following elements:

v0 = x<SUB>0</SUB>, y<SUB>0</SUB> x<SUB>1</SUB>, y<SUB>1</SUB> , ..., x<SUB>c/2-1</SUB>, y<SUB>c/2-1</SUB>

v1 = x<SUB>c/2</SUB>, y<SUB>c/2</SUB> x<SUB>c/2+1</SUB>, y<SUB>c/2+1</SUB> , ..., x<SUB>c-1</SUB>, y<SUB>c-1</SUB>

where c = pack_t::static_size

In order to efficiently calculate the distance between our reference point and all of the other points,
the data must be re-ordered as follows:

vX = x<SUB>0</SUB>, x<SUB>1</SUB> x<SUB>2</SUB>, ..., x<SUB>c-1</SUB>

vY = y<SUB>0</SUB>, y<SUB>1</SUB> y<SUB>2</SUB>, ..., y<SUB>c-1</SUB>

This is achieved using the functions `bs::deinterleave_first` and `bs::deinterleave_second`. which
efficiently re-order the data in the processor's registers.
