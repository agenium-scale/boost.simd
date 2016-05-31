//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_OPERATOR_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup group-functions
    @defgroup group-operator Operators

    Those functions provides scalar and SIMD version of the native C and C++ operators.

    Operators are provided in infix and prefix notations,  with exceptions for scalar floating types
    for which C++ does not allow overloading nor implement &, |, ~,  % and the ternary operator ?:.
    In These seldom used cases prefix  bitwise_and, bitwise_or, complement (or its alias bitwise_not)
    and if_else are mandatory.

    Here is the list of of operators and their infix associated notation.
    The remarks only applies if the prefix notation is used and at least one parameter is a pack:
    of course infix operators on scalars are regulated by usual C++ langage rules.

    |--------------------|-----|-------|--------------|-----------------------------------------------|
    | Name               | op  | arity |   types      |  precondition/result                          |
    |--------------------|-----|-------|--------------|-----------------------------------------------|
    | bitwise_and        | &   |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | bitwise_not        | ~   |  2    |  T1, T2      |                                               |
    | bitwise_or         | |   |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | bitwise_xor        | ^   |  2    |  T1, T2      |  same bit size for T1 and T2    (1)           |
    | comma              | ,   |  2    |  T1, T2      |                                               |
    | complement         | ~   |  1    |  T1          |                                               |
    | divides,  div      | /   |  2    |  T1, T1      |  arithmetic types               (2)           |
    | if_else            | NA  |  3    |  T1, T2, T2  |                                               |
    | is_equal           | ==  |  2    |  T1, T1      |                                               |
    | is_greater         | >   |  2    |  T1, T1      |                                               |
    | is_greater_equal   | >=  |  2    |  T1, T1      |                                               |
    | is_less            | <   |  2    |  T1, T1      |                                               |
    | is_less_equal      | <=  |  2    |  T1, T1      |                                               |
    | is_not_equal       | !=  |  2    |  T1, T1      |                                               |
    | logical_and        | &&  |  2    |  T1, T1      |  returns a @ref logical                       |
    | logical_not        | !   |  1    |  T1, T1      |  returns a @ref logical                       |
    | logical_or         | ||  |  2    |  T1, T1      |  returns a @ref logical                       |
    | minus              | -   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | rem                | %   |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | multiplies         | *   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | plus               | +   |  2    |  T1, T1      |  arithmetic types                (2)          |
    | shift_left, shl    | <<  |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | shift_right        | >>  |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | shr (logical shift)|     |  2    |  T1, T2      |  T2 is integral scalar or associated to T1 (3)|
    | unary_minus        | -   |  1    |  T1          |  signed arithmetic types         (2)          |
    | unary_plus         | +   |  1    |  T1          |  arithmetic types                (2)          |
    |--------------------|-----|-------|--------------|-----------------------------------------------|


    Notes:
     -(1)  This precisely means sizeof(T1) == sizeof(T2) or one is scalar and its size in bits is the same as
           the element of the other (which is a pack).

     -(2)  arithmetic types are std::int8_t, std::int16_t, std::int32_t, std::int64_t,
           std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t, float double and their pack.

           The use of implementation dependent types as char, int, long, long long and their unsigned conterpart
           is discouraged and even can lead to inconsistencies.

           Also it must be noted that "arithmetic" operators can not mix types. This is to ensure good SIMD
           performances if the types are hardware supported.

     -(3)  This  precisely means T2 is scalar and integral or T2 is as_integer_t<T1>. Note that if T2 scalar
           is always simd hardware supported, the other case is often emulated.

   Extensions:

      @ref division and @ref remainder operators have extensions.




  **/
} }

#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/bitwise_not.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_xor.hpp>
#include <boost/simd/function/comma.hpp>
#include <boost/simd/function/complement.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_equal.hpp>
#include <boost/simd/function/is_greater.hpp>
#include <boost/simd/function/is_greater_equal.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/is_less_equal.hpp>
#include <boost/simd/function/is_not_equal.hpp>
#include <boost/simd/function/logical_and.hpp>
#include <boost/simd/function/logical_not.hpp>
#include <boost/simd/function/logical_or.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/rem>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/shift_left.hpp>
#include <boost/simd/function/shift_right.hpp>
#include <boost/simd/function/shl.hpp>
#include <boost/simd/function/unary_minus.hpp>
#include <boost/simd/function/unary_plus.hpp>

#endif
