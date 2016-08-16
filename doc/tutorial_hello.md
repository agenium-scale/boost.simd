# A Simple SIMD Kernel {#tutorial-hello}

- [SIMD HelloWorld](@ref tutorial-hello)
- [Sum of Arrays](@ref tutorial-sum)
- [Reductions](@ref tutorial-reduction)
- [Processing Data the SIMD Way](@ref tutorial-data)
- [Runtime Extension Selection](@ref tutorial-runtime)

The following program is a basic demonstration of **Boost.SIMD**:

@snippet helloworld.cpp hello

This small code sample presents the basic building blocks of **Boost.SIMD**, which are explained below.

### The Boost.SIMD namespace ###

When using a **Boost.SIMD** type or function, it is necessary to use the boost::simd namespace. In order to simplify the code, you can assign it an alias:

@snippet helloworld.cpp hello-namespace

This saves you from having to type the full namespace every time you call a **Boost.SIMD** function.

### The boost::simd::pack abstraction

The basis of any code using **Boost.SIMD** is the boost::simd::pack class which is defined in:

@snippet helloworld.cpp hello-include-pack

The pack may be considered analagous to an _SIMD_ register on your (or any other) machine. Operations performed on packs - from elementary operations such as addition to complicated functions such as sin(x) - will be performed using _SIMD_ registers and operations if supported by your hardware. As shown in the following example, data must be manually loaded into and stored from these registers.

### Constructing a boost::simd::pack

One way to construct a boost::simd::pack is to simply declare (default-construct) it. Such boost::simd::pack are not zero-initialized and thus may contain arbitrary values.

@snippet helloworld.cpp hello-def-ctor

Another way to construct a boost::simd::pack is to fill it with a single value. This so-called splatting constructor takes one scalar value and replicates it in all elements of the pack.

@snippet helloworld.cpp hello-splat-ctor

You may also perform the splat explicitly if you wish

@snippet helloworld.cpp hello-splat-explicit

You may also construct a pack by passing a pointer to a block of contiguous, aligned memory.

@snippet helloworld.cpp hello-ptr-con

You may also construct a pack by passing a range of elements, however the length of this 
range must be equal to the cardinal of the pack.

@snippet helloworld.cpp hello-iter-con

Finally, you can also initializes every element of the boost::simd::pack itself by enumerating them.

@snippet helloworld.cpp hello-enum-ctor

Note that this constructor makes the strong assumption that the size of your boost::simd::pack is correct. Unless required, it's generally a good idea to try to avoid depending on a fixed size for boost::simd::pack unless
the algorithm requires it. The splat function is recommended over this usage wherenever possible.

**Operations on boost::simd::pack**

----------------------------------------------------------------------------------------------------

Once initialized, operations on boost::simd::pack instances are similar to operations on scalar as all operators and standard library math functions are provided. A simple pattern make those functions and operators available: if you need to use an arbitrary function or operator like boost::simd::plus, you need to include the boost/simd/function/plus.hpp file. We do the same for boost::simd::splat and boost::simd::multiplies.

@snippet helloworld.cpp hello-ops

Note that type checking is stricter than one may expect when scalar and _SIMD_ values are mixed. **Boost.SIMD** only allows mixing types of the same scalar kind, i.e reals with reals or integers with integers. Here, we have to multiply by `2.f` and not simply `2`.

Finally, we display the boost::simd::pack content by using the `operator<<` overload provided by the boost/simd/io.hpp header file.

@snippet helloworld.cpp hello-io


</br>
**Compiling the code**

The compilation of the code is rather straight-forward: just pass the path to **Boost.SIMD** and use your compiler options to activate the desired _SIMD_ extension support - in this case the sse2 extension triggered by `-msse2`. Due to the way **Boost.SIMD** is structured, it is highly recommended to use the `-O3` flag to take full advantage of compiler optimizations.

For example, on `gcc`:

`g++ my_code.cpp -O3 -o my_code -I/path/to/boost.simd/ -msse2`

Some compilers, like Microsoft Visual Studio, don't propagate the fact a given architecture specific option is triggered. In this case, you need to also defines an architecture specific preprocessor symbol.

## The result

We can then have a look at the program's output which should look like:

`{42,42,42,42}`

Now, let's have a look at the generated assembly code (using `objdump` for example) :

@code{.objdump}
movaps 0x300(%rip),%xmm0
addps  0x2e6(%rip),%xmm0
mulps  0x2ff(%rip),%xmm0
movaps %xmm0,(%rsp)
@endcode

This shows that we correctly emitted `*ps` instructions. Note how the abstractions introduced by boost::simd::pack don't incur any penalty.

[Top of Page](#topofpage)


