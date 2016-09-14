SIMD Branching {#tutorial-branching}
=========

@tableofcontents
In this tutorial we will examine how to handle branches in SIMD programs.

@section branching-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Show how to efficiently handle branches in SIMD programs](#branching-intro)
- [Demonstrate a useful technique for reducing data transfer](#branching-transfer)
- [Discuss possible reasons for lower speed-up than expected](#branching-speed)

@section branching-intro Branching

One of the fundamental principles of __SIMD__ programming is that the same operation must be performed
on each element of the __SIMD__ vector. At first glance, this means that vectorized programs do not
support conditional statements. Let's take a common image processing operation known as thresholding
as an example. Thresholding is an operation to separate a digital image into its background and foreground
pixels. Any pixel whose value is less than the choosen threshold is considered to be a background pixel and
conversely, any pixel whose value is greater or equal to the threshold is considered to be a foreground
pixel. For example:

@snippet thresholding.cpp scalar-threshold

Here we have a very clear branch in the code. How can we vectorize this loop?

@snippet thresholding.cpp simd-threshold

In this example, we introduce a new type, `bs::logical`, which is an abstraction for the equivalent of
a `bool` on a particular architecture. Therefore, a pack of `bs::logical` or a `logical_t` is the equivalent of a pack
of `bool`. This abstraction is necessary to ensure that any code written using **Boost.SIMD** is portable
due to the differences between how various processors handle operations requiring logical values.(Note that most of the time
you do not need to define yourself the logical type as `auto` can do the job).

The return type of a comparison operation in C++ is a `bool`, therefore the return type of the function
`bs::is_less` is a `logical_t`. This `logical_t` is then used to generate a __SIMD__ vector of zeros
or ones using the function `bs::if_zero_else_one`. All that's left to do now is to store this vector
in its correct location in memory.

@section branching-transfer Minimizing the transfer of data between the processor and memory

Many algorithms are memory bound, meaning that the time required to complete the function is mostly
determined by the time taken to transfer the data from memory to the processor and back again. Therefore,
any operation which reduces the quantity of data to be transferred could significantly accelerate the
execution of the code. As you are using **Boost.SIMD** you are clearly concerned about performance!
In this example, the input image is a 16 bit image. However, the output of the thresholding operation
is a binary image. Therefore, the output image can safely be stored as an 8 bit image, halfing the
quantity of data to be transferred from the processor to memory! **Boost.SIMD** includes many functions
to upgrade and downgrade or `split` and `group` data:

@snippet thresholding.cpp simd-threshold-downgrade

This extract of code assumes that the input image is a multiple of the output vector size for clarity.
This assumption is often false, the previous example, @ref tutorial-dot shows how to handle this
by adding a scalar loop at the end to process all remaining pixels.

Here is a full code, should you wish to try it:

@snippet thresholding.cpp threshold
