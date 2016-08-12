# Processing Data the SIMD Way {#tutorial-data}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

This tutorial will present how data can be processed using **Boost.SIMD** by writing a naive dot
product using **Boost.SIMD**.

A simple sequential, scalar dot product could be coded like this:

@snippet dot.cpp scalar-dot

dot simply iterates over data pointed by first1 and first2, computes the product of this
data and then sums them.

**Transition from scalar to SIMD code**

In this case the algorithm is clearly vectorizable, let's unroll the loop arbitrarily to show the
inherent data parallelism:

@snippet dotunroll.cpp scalar-dot-unroll

The algorithm is split into two parts:

First, we loop over each element inside both datasets and multiply them and then, we sum the
intermediate values into the final result.

By unrolling this pattern arbitrarily, we expose the fact that the multiplication between the two
dataset is purely "vertical" and so, is vectorizable. The sum of the partial results itself is a
"horizontal" operation, i.e a vectorizable computation operating across the elements of a single
vector (see @intra-register operation).

**Building a SIMD loop**

We are now going to use `boost::simd::pack` to vectorize this loop. The main idea is to compute
partial sums inside an instance of `boost::simd::pack` and then perform a final summation. To do so,
we will use `boost::simd::load` to load data from first1 and first2, process these `boost::simd::pack`
instances using the proper operators and then advance the pointers by the cardinal of `boost::simd::pack`.

@snippet dotsimd.cpp scalar-dot-simd
That's it! Look at how similar the computation code is to the scalar version, we simply jump over data
using a larger step size and at the end we account for the data which does not fit inside a __SIMD__
vector.

# Note:

The code line `tmp = tmp + x1 * x2;` may replaced by
`tmp += x1 * x2;` or even `tmp = fma(x1, x2,tmp);` (after having included `boost/simd/function/fma.hpp`)
which may generate even more efficient code as many processors have special instructions for performing
this operation. If the target processor is not equipped such an instruction, high quality vectrized
code will nevertheless be generated.
