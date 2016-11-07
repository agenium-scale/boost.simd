Memory Alignment {#tutorial-memory}
=========

@tableofcontents
All of the previous tutorials assumed that the memory allocated for the input and output
buffers was correctly aligned. Depending on your memory allocator and architecture,
this may not always be true. In this tutorial we will discuss memory alignment
and demonstrate how to ensure that your memory is always correctly aligned.

@section hello-objectives Objectives

-------------------------------------

In this tutorial we will:
- [Explain what memory alignemnt is](#memory-what-is)
- [Demonstrate how to align memory](#memory-how-to-align)
- [Demonstrate how to align memory using @projectname](#memory-boost-simd-align)
- [Demonstrate how to use an aligned memory allocator with STL containers](#memory-vector)

@section memory-what-is What is Memory Alignment

In order to fully understand memory alignment and how to maximise performance of your software by
ensuring memory alignment, please read this excellent article by [IBM](http://www.ibm.com/developerworks/library/pa-dalign/).
Although this article focuses on PowerPC processors, its conclusions are valid on many other architectures.
**@projectname** gives you portabililty accross many architectures, in order to have the best
performance possible across a range of architectures, it is worth considering the alignment requirements
of all target architectures.

@section memory-how-to-align How to Align Memory Manually?

It is possible to align memory yourself using `std::align`. In the following example, we allocate memory
and store it in a unique_ptr. This pointer is then shifted until it is aligned on the requested boundary.
This means that the allocated buffer must be larger than the size required, at least `pack_t::alignment`
(the required alignment for a pack of this type on the target architecture) bytes larger.

@snippet alignment.cpp align-manual

As you can see, this is errorprone, difficult and quite annoying to do. Also, `std::align`
is not unviersally supported even among modern compilers! Therefore, the easiest
way to align memory is to use the aligned memory allocator provided by **@projectname**.

@section memory-boost-simd-align How to Align Memory using @projectname aligned allocator

The allocator provided by **@projectname** guarantees to return a pointer with the correct
alignment so that you need not worry about
allocating extra space in the buffer to account for the required alignment as in
the previous section.

@notebox{The additional template parameter passed to the `std::unique_ptr`,
this is the associated delete function corresponding to
the aligned allocator.
}

@snippet alignment.cpp align-allocator

@section memory-vector How to use an aligned memory allocator with std::vector

The C++ STL containers allow you to use a custom memory allocator by passing
an additional template argument during the declaration, in a similar manner
to the previous example using `std::unique_ptr`. You can
use Boost.Align with an `std::vector` as follows:

@snippet alignment.cpp align-vector

The data stored in this vector may be used by @projectname as an input or
output buffer.
