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

  A Logical type is representing a boolean value while keeping track of the type used
  to generate those boolean.

  @par Requirements

  A type @c T satisfies Logical if it refines Regular, is convertible to @c bool and if :

    - @c T::value_type evaluates to a Vectorizable type that represent the original type used to
      generate this instance of @c T.

    - @c T is constructible from any type convertible to bool
    - For any @c a of type @c T and any @c u of any type convertible to bool, <tt>a = u</tt> is a valid expression of Logical type
    - For any @c a of type @c T, @c !a is a valid expression of Logical type
    - For any @c a of type @c T, @c ~a is a valid expression of Logical type
    - For any @c a and @c b of type @c T, <tt>a && b</tt> is a valid expression of Logical type
    - For any @c a and @c b of type @c T, <tt>a || b</tt> is a valid expression of Logical type

  @par Example

  - @c boost::simd::logical<short>
**/
struct Logical {};
