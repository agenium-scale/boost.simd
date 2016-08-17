# Memory Alignment {#tutorial-memory}

All of the previous tutorials assumed that the input and output buffers were correctly aligned.
Depending on your memory allocator and architecture, this may not always be true.

###What is Memory Alignment?
In order to fully understand memory alignment and how to maximise performance of your software by
ensuring mempry alignment, please read this excellent article by [IBM](http://www.ibm.com/developerworks/library/pa-dalign/).
Although this article focuses on PowerPC processors, its conclusions are valid on many other architectures.
**Boost.SIMD** gives you portabililty accross many architectures for free, in order to have the best
performance possible across a range of architectures, it is worth considering the alignment requirements
of all target architectures.

###How to align your buffers
It is possible to align memory yourself using `std::align`. In the following example, we allocate memory
and store it in a unique_ptr. This pointer is then shifted until it is aligned on the requested boundary.
This means that the allocated buffer must be larger than the size required, at least `pack_t::alignment`
(the required alignment for a pack of this type on the target architecture) bytes larger.

@snippet alignment.cpp align-manual

As you can see, this is errorprone, difficult and quite annoying to do. The easiest way to align your memory
is to use an aligned memory allocator such as that provided by Boost.Align. Such an allocator
guarantees to return a pointer which is aligned on the given boundary and you need not worry about
allocating extra space in the buffer to account for the required alignement. Note the additional template
parameter passed to the `std::unique_ptr`, this is the associated delete function corresponding to
the aligned allocator.

@snippet alignment.cpp align-allocator

You may also pass an additional parameter to an std::vector so that any memory allocated by it will
be correctly aligned:
@snippet alignment.cpp align-vector
