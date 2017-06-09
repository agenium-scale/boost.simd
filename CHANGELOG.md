# Boost.SIMD Changelog

## Version 4.17.6.0 - 10/06/2017

This release is a maintenance release. Thanks to aminiussi, Fytch, raphaelbresson, bmmogensen, Tim
Blenchmann, serge-sans-paille, TobiasLudwig and kreuzerkrieg for their insignts and contributions.

### Breaking Changes
- SIMD Iterators are now intrinsically both Input and OutputIterator. This lead to a large
  simplification of ranges and algorithms design. All *_input_range and *_output_range
  related functions and helpers are now deprecated in favor of the simpler *_range version. (#490, #493)

### New features
- SIMD Iterators are now intrinsically both Input and OutputIterator. This lead to a large
  simplification of ranges and algorithms design (#490, #493).
- Introduces subadd and fmasubadd that maps over the add/sub like family of x86 intrinsics (#514, #511)
- Introduce raw_(nearbyint) as a way to generate a faster but sloppier nearbyint implementation (#513)
- Introduces SIMD-aware version of most standard algorithms (#480)
- Introduces new meta-function to access hardware specific informations about SIMD registers (#494, #425)

### Changes & Bug Fixes
- Change cmake/ location on WIN32 and WIN64 (#522)
- Improve combine codegen for aggregated packs on MSVC (#521)
- Correct behaviors of compare_less (#520)
- Improve combine min,max and sum performances on AVX integers (#519)
- Improve AVX2 interleave & deinterleave for integers (#515)
- Fix compilation with g++ 7.1 (#508)
- Fix precision in sinh for small x (#504)
- Improve lookup implementation by using permutevar8x32 (#474)
- Fix make inlining (#487)
- Fix extract for clang 3.9.1 (#483)
- Provides emulated support for masked aligned_store (#481)
- Constants documentation has been cleared up
- Other documentations fixes

## Version 4.17.3.0 - 03/06/2017

Maintenance release including some bug fixes reported by Tim Blenchmann.
Thanks a lot to our new contributors for their insights and patches for
the documentation and compiler supports.

### New features
- Added more benchmarks for integral based functions (#472)
- Added an scalar and SIMD implementation for clamp, mimicking C++17 std::clamp (#458)
- To support creation of object containing pack and still being properly aligned when dynamically allocated, we reintroduce the BOOST_SIMD_ALIGNED_OBJECT macro. (#440)

### Changes & Bug Fixes
- Improve AVX/AVX2 saturated group (#476)
- Fixed a bug where logical operators on pack may have produced an invalid logical<logical<T>> type (#471)
- Improved standard compliance of ilogb function (#470)
- Fixed AVX2 sum implementation on MSVC (#469)
- Improved documentation for library Cocnepts (#449)
- fma/fnms functions were underspecified in terms of overload (#467)
- Documentation (#468,#465,#459,#453,#452,#446,#441) has been cleaned up a bit more
- Improved copysign performance in scalar mode (#457)
- Performance of aggregated all,any,none have been improved (#456)
- Fixed some assertions that were overly broad and reinstated assert in unit tests (#462)
- Performance of hmsb has been improved on MSVC by providing a compressed implementation of
std::bitset to be used for small size of pack (#357)
- Tests and benchmarks subsystem are now downloaded on demand (#390)

## Version 4.17.1.0 - 01/31/2017

### Breaking Changes
- `negif` and `negifnot` function has been renamed `if_neg` and `ifnot_neg` to follow the pattern for `if_*` conditionnal functions (#407)
- `bitset` and `bitget` functions are deprecated.

### New features
- User-defined literals like `1_c` can be used in some context like `pack::operator[]`,`extract` and `insert` to use the optimized static variant without having to use the verbose `std::integral_constant`. (#351)
- Constants generation function can now be called using `as` to generate a constant of the same type than a given existing variable (#367)
- Provides a CMake find_package support for Boost.SIMD (#386)
- `pack_cast` function is introduced to allow casting between pack of different types but same cardinal, i.e turning a `pack<float,4>` into a `pack<int,4>`. Current implementation tries to provides intrinsics or optimized support for most cases. More will be done when the small pack optimisation feature will be added. (#376)

### Changes & Bug Fixes
- AVX and AVX2 `if_else` were not properly force-inlined (see e92100e and 75b7d5fc)
- Some trigonometric functions were unable to compile with some MSVC setup (#346) (Thanks @timblechmann)
- Fixed `inearbyint` bug with -Inf on clang (#353)
- Optimized code using `if_plus`or `if_minus` by using `if_inc`and `if_dec` whenever possible (#354)
- Generic code for shift on floating values were missing (see c92a29b7)
- Make scalar:pack operators more restrictive to not collide with user defined types (see d4c6b47e) (Thanks to @jeffamstutz)
- trunc, floor and ceil has been simplified and optimized (#348)
- Benchmarks files and logistics has been simplified
- Fix a bug with any and none when called on -0. (#393)
- any and none has been optimized on AVX/SSE4 (#396)
- The documentation has been improved for a lot of functions, including sample usage and expected output, various Doxygen quirks and more generally, HTML bugs
- Alain Miniussi( @aminiussi ) has made large improvement to ensure the usability of Boost.SIMD on a very specific icpc 15 + gcc combo that occurs on a large amount of super-computers. The work is still on going but progress is noticeable.
- Added missing support for clipped range for the sincos family (#417)

## Version 4.16.12.0 - 12/19/2016

This release is another polish & API fixes release to prepare the upcoming Boost review process.
The main point is the removal of the old and unstable Altivec support as it was considered to be
more noisy than valuable for the review.

In this release, we want to thank Alain Miniussi and @Fytch for their contributions.

### Breaking Changes
 - [API] Old Altivec support is deprecated
 - [API] frexp now returns a pair of floating point values to simplify interaction with ldexp
 - [API] The fast_ decorator is deprecated. The policy of using raw_,fast_ or conformant_ was blurry
   and led to bad user experience. The new rule is that now, the undecorated function is able to
   deliver good performance with reasonable precision/corner-case handling. raw_ may provide better
   performance but at the cost of reduced precision or lacking support for corner cases (like NaN,
   denormals or infinites). The pedantic_ decorator now replaces the conformant_ tag and express the
   fact that the decorated function will provides less performances for an exact support of all the
   functions input values.

### New features
 - ifrexp function is introduced to keep the old API of frexp that was returning a pair of
   integer/floating point values. The functions frexp/ifrexp covers all the use cases of the previous
   frexp API but simplify its interaction with ldexp.
 - ldexp can now process exponent passed as floating point values instead of integer.
 - A scalar optimized version of inearbyint is now available on SSE2 enabled CPUs.
 - toint now supports the pedantic_ flag to handle some corner-cases in double precision.

### Changes
 - Boost.SIMD can now compile using -pedantic
 - Documentation is now properly provided as a local HTML file bundle in doc/html
 - Trying to compile benchmarks or unit tests without using -DDEV as CMake options warns about it
   and fix its own behavior.
 - ICC supports has been improved
 - ICC usage of cpuid has been fixed to work with the ICC/MSVC combo

## Version 4.16.10.0 - 10/06/2016

This release is mostly a bug fixes release. The documentation also have been revamped and clarified in term of layout and contents. The documentation also moved to https://developer.numscale.com/boost.simd

### New features
 - Pack now supports assignment from a scalar, eg. `pack<T> x; x = 4; ` and behave like the splat constructor
 - Scatter is now supported by store: passing a pack of integers as store offset will perform scatter.
 - Boost.SIMD version is now accessible via the `BOOST_SIMD_VERSION` and `BOOST_SIMD_LIB_VERSION` macros

### Breaking Changes
- [API] hmsb is now returning std::bitset instead of a simple integer to take care of pack of more than 64 elements.

### Changes
- Made shuffle and related function documentation clearer
- Optimized ror and rol scalar performances
- Optimized (de)interleave)_* performances on AVX
- Optimized log performances on AVX
- Fixed documentation of insert that swapped value and index
- aligned_store behavior or large pack is fixed to call aligned_store again instead of store.
- bitwise_cast has been optimized in cases where internal storage can be salvaged and when it actually resolved as a no-op.
- Added an AVX version of toint
- Eps and eps(x) now both work properly
- Lots of small scale issues with ICC support has been fixed.


## Version 4.16.9.0 - 09/19/2016

This version is the first autonomous release of Boost.SIMD which is now
completely independent of its former parent project NT². It also features
a large clean-up, simplification and rationalization of its implementation.

### Changes

  - Boost.SIMD is now fully C++11 compliant.
  - Strong decrease in compile-time, including on MSVC
  - Local optimizations are now performed without expression templates.
  - Supported architectures now includes AVX2, XOP and FMA sub-extensions
  - The interface has been simplified to be based on pack only. The native type is deprecated.
  - simd::accumulate is now simd::reduce to be more close to C++17 semantic
  - Dispatching system is now an implementation detail
  - Function are now mostly function objects. This allows Boost.SIMD unctions to be used as a drop-in
    polymorphic function object for standard algorithm and to support decorators.

### New Features

  - Full support for exponential and logarithmic related functions
  - Full support for trigonometric and inverse trigonometric functions
  - Full support for hyperbolic and inverse hyperbolic functions
  - Emulation of pack with cardinal larger than the naturally supported one are now
    using aggregates of smaller, native pack. This speed-up large pack code by performing
    static unrolling over the sub-registers of the pack instead of using scalar emulation
  - Function like shuffle and other permutations now take advantage of more optimizations opportunities
  - Support for Range over SIMD data. Support for raw SIMD iterator is now deprecated
  - Added optional parameters to simd::reduce to take care of cases where a specific reduction function
    was to be used instead of main functor.
  - Optional behavior of some functions (precision, reduction of input, etc...) are now accessible
    via decorators. Decorators are function re-targeting a Boost.SIMD function to a new implementation
    without having to pass additional parameters. E.g the fast version of sqrt can now be called via
    fast_(sqrt)(x) where fast_(sqrt) is in fact a function object in itself.
