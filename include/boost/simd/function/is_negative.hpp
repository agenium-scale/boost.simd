//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IS_NEGATIVE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IS_NEGATIVE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-predicates

    Returns True if x is negative else False.

    This function differs from is_ltz from floating point argument,
    because Mzero is negative but not less than zero.  and Mzero is
    not positive and not greater than zero, It's probably is_ltz that
    you want.

    @par Semantic:

    @code
    as_logical_t<T> r = is_negative(x);
    @endcode

    is similar to:

    @code
    if T is signed
      as_logical_t<T> r = bitofsign(x) == 1;
    else
      as_logical_t<T> r = False;
    @endcode

    @par Note:

    Mzero is the floating point 'minus zero',
    i.e. all bits are zero but the sign bit.
    Such a value is treated as zero by ieee standards.

    behaviour of is_negative on nan is undefined.

    @return a logical value

**/
  template<typename T> auto is_negative(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-predicates

      Returns True if x is negative else False.


      Function object tied to simd::is_negative

      @see simd::is_negative
    **/
    const boost::dispatch::functor<tag::is_negative_> is_negative = {};
  }
} }
#endif

#include <boost/simd/function/definition/is_negative.hpp>
#include <boost/simd/arch/common/scalar/function/is_negative.hpp>
#include <boost/simd/function/simd/is_negative.hpp>

#endif
