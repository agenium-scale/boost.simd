SIMD Branching {#tutorial-branching-split}
=========

<div style="text-align: right;" markdown="1">Prev: [SIMD Branching](@ref tutorial-branching)</div>
<div style="text-align: right;" markdown="1">Next: [Evaluation of a Neural Network](@ref tutorial-neural)</div>

@tableofcontents
In this tutorial we will extend the previous tutorial which dealt with branching to
show how to reduce the quantity of data transferred between the processor and memory.
This technique can result in a significant performance increase as memory bandwidth
is often the bottleneck in many applications. This effect is further multiplied in
multithreaded applications where the memory bandwidth is under greater stress.
The following steps in such an application may also be accelerated as less data must be
transferred from memory.

@section branching-split-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Demonstrate a useful technique for reducing data transfer between processor and memory](#branching-split-transfer)

@section branching-split-transfer Minimizing the transfer of data between the processor and memory

Many algorithms are memory bound, meaning that the time required to complete the function is mostly
determined by the time taken to transfer the data from memory to the processor and back again. Therefore,
any operation which reduces the quantity of data to be transferred could significantly accelerate the
execution of the code. As you are using **@projectname** you are clearly concerned about performance!
In this example, the input image is a 16 bit image. However, the output of the thresholding operation
is a binary image. Therefore, the output image can safely be stored as an 8 bit image without any loss
of data, cutting in half the quantity of data to be transferred from the processor to memory!
**@projectname** includes many functions to upgrade and downgrade or `split` and `group` data:

@snippet thresholding_downgrade.cpp simd-threshold-downgrade

This extract of code assumes that the input image is a multiple of the output vector size for clarity.
This assumption is often false, @ref tutorial-dot shows how to handle this
by adding a scalar loop at the end to process all remaining pixels.

Here is a full code, should you wish to try it:

@snippet thresholding_downgrade.cpp threshold

<div style="text-align: right;" markdown="1">Prev: [SIMD Branching](@ref tutorial-branching)</div>
<div style="text-align: right;" markdown="1">Next: [Evaluation of a Neural Network](@ref tutorial-neural)</div>

