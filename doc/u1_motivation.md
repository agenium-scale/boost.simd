Motivation {#motivation}
==========

@tableofcontents

The following function calculates the sum of two vectors of (`size=16`) `float` elements:

@snippet addvector.cpp scalar-loop

Each element of the results vector is independent of every other element - therefore this function may easily be vectorized.
To vectorize this for a processor which has sse instructions, one could write the following code:

@snippet addvector.cpp sse2-simd-loop

To vectorize this for a processor which has avx instructions, one could write the following code:

@snippet addvector.cpp avx-simd-loop

To vectorize this for an ARM processor which has neon instructions, one could write the following code:

@snippet addvector.cpp arm-simd-loop

In each of these examples, we have written code for two different generations of intel processors and an ARM processors. Each of these functions
are non-portable to other architectures, for example, the intel code will not run on intel processors which do not support these instruction sets or
ARM or IBM processors. This means that a different version of this function must be written for each target architecture. Note also the fact that writing
code using intrinsics functions requires hard coding variables such as the number of elements in a SIMD register. Clearly, coding in such a manner is
time-consuming, error-prone and difficult to maintain and debug. It also requires being intimately familiar with the details of each processor manufacturer's
API.

Another disadvantage of using raw intrinsics is the fact that compiler support varies greatly between vendor, operating system and architecture. For example,
an SSE code which performs as expected on Linux may suffer from performance degradation, bugs or compiler warnings when compiled on Windows and vice-versa.
The goal of **Boost.SIMD** is to abstract all of these disadvantages, leaving the user with one API, regardless of architecture, compiler or operating system.
All known compiler bugs are also managed by **Boost.SIMD** to ensure the quick and efficient development of high performance portable software.

For example, take the function to add two vectors. It may be written using **Boost.SIMD** as follows:

@snippet addvector.cpp bs-simd-loop

In order to obtain maximum performance on any architecture, the user must only re-compile the code specifying the correct architecture flag to the compiler.
