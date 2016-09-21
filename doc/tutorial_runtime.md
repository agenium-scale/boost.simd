# Runtime Extension Selection {#tutorial-runtime}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)


Using **@projectname** requires compiling for a particular target machine with specific _SIMD_
instructions available. For many architectures (x86 in particular), _SIMD_ instructions may be conditionally supported depending on the exact hardware being used, with more recent hardware
typically supporting more _SIMD_ instructions than older ones.

In this tutorial, we will demonstrate how to switch between `SSE` and `AVX` for the same code
depending on the capabilities of the x86 hardware that the program is running on.

## The result



