# Boost.SIMD Changelog

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
