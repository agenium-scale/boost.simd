//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ILOG2_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the integer part of the base 2
    logarithm of the input.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = ilog2(x);
    @endcode

    The code is similar to

    @code
    as_integer_t<T> r = toints(log2(x));
    @endcode

    @par Note
    This function asserts for negative or null values.

    @see  twopower, exponent

    @return      a value of the integer
                 type associated to the input.


**/
  template<typename T> auto ilog2(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::ilog2

      @see simd::ilog2
    **/
    const boost::dispatch::functor<tag::ilog2_> ilog2 = {};
  }
} }
#endif

#include <boost/simd/function/definition/ilog2.hpp>
#include <boost/simd/arch/common/scalar/function/ilog2.hpp>
//#include <boost/simd/arch/common/function/simd/ilog2.hpp>

#endif
