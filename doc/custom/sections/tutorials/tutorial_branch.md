SIMD Branching {#tutorial-branching}
=========
<div style="text-align: right;" markdown="1">Prev: [Writing a dot product the SIMD Way](@ref tutorial-dot)</div>
<div style="text-align: right;" markdown="1">Next: [SIMD Branching Part 2 - Computations with different types](@ref tutorial-branching-split)</div>

@tableofcontents
In this tutorial we will examine how to handle branches in SIMD programs.

@section branching-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Show how to efficiently handle branches in SIMD programs](#branching-intro)
- [Introduce the type bs::logical_t](#branching-logical)

@section branching-intro Branching

One of the fundamental principles of __SIMD__ programming is that the same operation must be performed
on each element of the __SIMD__ vector. At first glance, this means that vectorized programs do not
support conditional statements, however this is not true. Let's take a common image processing operation
known as thresholding as a counter example. Thresholding is an operation to separate a digital image into
its background and foreground pixels. Any pixel whose value is less than the chosen threshold is
considered to be a background pixel and conversely, any pixel whose value is greater or equal to
the threshold is considered to be a foreground pixel. The scalar version of this algorithm is
simply:

@snippet thresholding.cpp scalar-threshold

Here we have a very clear branch in the code. How can we vectorize this loop?

@section branching-logical Logical SIMD type
In this example, we need a new type, `bs::logical`, which is an abstraction for the equivalent of
a `bool` on a particular architecture. Therefore, a pack of `bs::logical` or a `logical_t` is the equivalent of a pack
of `bool`. This abstraction is necessary to ensure that any code written using **@projectname** is portable
due to the differences between how various processors handle operations requiring logical values.(Note that most of the time
you do not need to define the logical type as `auto` can do the job).

The return type of a comparison operation in C++ is a `bool`, therefore the return type of the function
`bs::is_less` is a `logical_t`. This `logical_t` is then used to generate a __SIMD__ vector of zeros
or ones using the function `bs::if_zero_else_one`. All that's left to do now is to store this vector
in its correct location in memory.

@snippet thresholding.cpp simd-threshold

Here is a full code, should you wish to try it:

@snippet thresholding.cpp threshold

<div style="text-align: right;" markdown="1">Prev: [Writing a dot product the SIMD Way](@ref tutorial-dot)</div>
<div style="text-align: right;" markdown="1">Next: [SIMD Branching Part 2 - Computations with different types](@ref tutorial-branching-split)</div>
