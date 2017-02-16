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

  A Value type is a type which refines IEEEValue or IntegerValue.

  @par Example

  - @c float
  - @c int
  - @c boost::simd::pack<short>
  - @c boost::simd::pack<double>

**/
struct Value {};
