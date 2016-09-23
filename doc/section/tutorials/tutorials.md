Tutorials {#tutorials}
=========

The general principles of **@projectname** are introduced in the following tutorials.

  + using the pack abstraction of a native _SIMD_ vector.
  + compiling a program written using **@projectname**.
  + using _SIMD_ specific idioms such as reduction, branching and shuffling
  + vectorizing code using the Standard Template Library(transform and accumulate)
  + _SIMD_ runtime dispatching

In the following tutorials, we will assume the use of a 128 bit wide _SIMD_ extensions (such as SSE or Altivec), however
all of the examples will work on any supported architecture. Depending on your actual architecture, the output of the
following tutorials applications may vary.

@section basic-tut Basic Tutorials

------------------------------

  1. [The SIMD Hello World](@ref tutorial-hello)
  2. [A Basic SIMD Loop](@ref tutorial-simd-loop)
  3. [Memory Alignment](@ref tutorial-memory)
  4. [Using Mathematical Functions](@ref tutorial-mathematical)

@section inter-tut Intermediate Tutorials

------------------------------

  1. [Writing a dot product the SIMD Way](@ref tutorial-dot)
  2. [SIMD Branching](@ref tutorial-branching)

@section adv-tut Advanced Tutorials

------------------------------

  1. [Runtime Extension Selection](@ref tutorial-runtime)
  2. [Computations with different types](@ref tutorial-distance)
