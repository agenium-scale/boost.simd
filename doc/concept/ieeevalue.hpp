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

  A IEEEValue type is a type which satisfies either Vectorizable or Vectorized and which
  underlying scalar type behaves like a IEEE754 floating point value.

  @par Requirements

  A type @c T satisfies IEEEValue if:

    - @c T satisfies Vectorizable

  or if:

    - @c T satisfies Vectorized

  and if:

    - the scalar type associated to T must be floating

  @par Example

  - @c float
  - @c double
  - @c boost::simd::pack<double>

**/
struct IEEEValue {};
