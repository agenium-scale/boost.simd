//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#error This file is documentation-only and must not be included

/*!
  @ingroup group-concept-types

  A Vectorizable type is usable as the template parameter of other components like boost::simd::pack
  to produce a Vectorized type.

  @par Requirements

  A type @c T satisfies Vectorizable if it refines Logical or if:

    - <tt>sizeof(T) <= sizeof(double)</tt> and
    - <tt>std::is_arithmetic<T>::value</tt> evaluates to @c true and
    - <tt>std::is_same<T, bool>::value</tt> evaluates to @c false.

  @par Example

  - @c float
  - @c double
  - @c int
  - @c char
  - @c std::uint16_t
  - @c boost::simd::logical<short>
**/
struct Vectorizable {};
