NSIMD
=====

NSIMD is a vectorization library that abstracts SIMD programming
(<https://en.wikipedia.org/wiki/SIMD>). It was especially designed to allow
developers to exploit the maximum power of processors at a low development
cost.

To get maximum performances NSIMD counts mainly on the inline optimization pass
of the compiler. Therefore using any mainstream compiler such as GCC, Clang,
MSVC, Xlc, ICC, … with NSIMD will give you a zero-overhead SIMD abstraction
library.

To allow the inlining, a lot of code is placed in header files. Essentially
"small" functions such as addition, multiplication, square root, … are all
present in header files whereas big functions such as I/O are put in source
files that are compiled as a `.so`/`.dll` library.

NSIMD provides C89, C++98, C++11 and C++14 APIs. All APIs allow the user to
write generic code. For the C API this genericity is achieved through a thin
layer of macros whereas for the C++ APIs it is achieved through the use of
templates and function overloading. The C++ API is split into two parts. One
part is a C-like API with only function calls and direct typedefs for SIMD
types whereas the second one provides operator overloading, higher level
typedefs that allows unrolling. The differences between C++98 and C++11, 14
APIs concerns for example templated typedefs, templated constant.

The compatibility of the binary is guaranteed by the fact that only a C ABI is
exposed. The use of the binary by the C++ APIs is wrapped by code in the
header files.

Supported SIMD instruction sets
-------------------------------

- Intel:
  + SSE2
  + SSE4.2
  + AVX
  + AVX2
  + AVX-512 as found on KNLs
  + AVX-512 as found on Xeon Skylake CPUs
- Arm
  + NEON 128 bits as found on ARMv7 CPUs
  + NEON 128 bits as foudn on Aarch64 CPUs
  + SVE

Supported compilers
-------------------

We have tested NSIMD with GCC, Clang and MSVC. As we provide a C89 and a C++98
API other compilers should work fine. Also old compiler versions should work as
long as they support the SIMD targeted extension. We have tested with success
NSIMD for SSE4.2 on MSVC 2010.

Build the library
=================

The library can be built with CMake (<https://gitlab.kitware.com/cmake/cmake>).

```bash
mkdir build
cd build
cmake ..
make
```

You can also set the SIMD instruction using the `-DSIMD=<simd>` option when
generating with cmake like:

```bash
# Enable AVX2 support for nsimd
cmake .. -DSIMD=AVX2
make
```

Some SIMD instructions are optional like for FMA (Fused Multiply-Add), you
can enable them using the option `-DSIMD_OPTIONALS=<simd-optional>...`:

```bash
# Enable AVX2 with FMA support for nsimd
cmake .. -DSIMD=AVX2 -DSIMD_OPTIONALS=FMA
make
```

The generated sources might be big, so using `ninja` over `make` is generally
better:

```bash
cmake .. -GNinja
ninja
```

Philosophy
==========

The philosophy of the library is to provide a zero-overhead abstraction to SIMD
disregarding the underlying SIMD vector length in order to be as much portable
as possible. To allow the compiler to perform as much optimizations as possible
we also keep the code simple.

Of course wrapping intrinsics that require to know at compile time the
underlying vector length is not forbidden but must be done with caution.

When wrapping intrinsics that do not exist for all types it is difficult (and
in some cases impossible) to propose the best possible implementation. Let's
take for example the multiplication of two SSE2 vectors containing 8 bits
integers. There is no intrinsics for this so we have to use either an emulation
technique like processing each element individually or use some combination of
intrinsics. In the second case, one possibility is upcast the `char`'s to
`short`'s, use `_mm_mullo_epi16` and then downcast back to `char`'s. But in
this case if one wants to chain several multiplications then an unecessary
amount of upcasts and downcasts is present.

NSIMD was designed following as closely as possible theses guidelines:

- Do not try to have fully IEEE compliant library, rely on intrinsics, errors
  induced by non compliance are small and acceptable.
- If the use of one function does compute wrong results and that it is not an
  almost good result, that it is plain wrong, in that case, do something slow
  but correct.
- Emulate with tricks and intrinsics integer arithmetic when not available.
- Use common names as found in common computation libraries.
- Do not hide SIMD registers, one variable (of type such as `nsimd::pack`)
  matches one register.

In order not to hide things to the user, overloads of operators involving scalars
and SIMD vectors are not provided by default. The user must include them
explicitely in the hope that he will realize that he can have a optimization
penalty using expressions like `scalar + vector`.

The use of `nsimd::pack`'s is subject to one condition and is therefore not
provided by default. This condition concerns Arm SVE that makes use of sizeless
strucs (`__sizeless_struct`). This feature is (as of 2019/04/05) supported only
by the Arm compiler and we do not know if other compilers will use the same
keyword to support SVE. Therefore one has to include the proper header
explicitely in the hope that he realizes that code using packs may not be
fully portable. For now this concerns only Arm SVE.

Contributing
============

Anyone is welcome to contribute to NSIMD.

The way NSIMD is organized into directories is very simple. We let the user
browse source files by himself. The wrapping of intrinsics, the writing of
tests and benches files is a tedious and repetitive task therefore most of it
is generated by Python scripts that can be found in `egg`. The Python
organization is also really simple and we let the user browse this code.

- Intrinsics that do not require to known the vector length can be wrapped and
  will be accepted with no problem.
- Intrinsics that do require the vector length at compile time can be wrapped
  but it is up to the maintainer to accept it.
- Use `clang-format` when writing C or C++ code.
- The `.cpp` files are written in C++14.
- The headers files must be compatible with C89 (when possible otherwise
  C99), C++98, C++11 and C++14.

LICENSE
=======

Copyright (c) 2019 Agenium Scale

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
