//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ICEIL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the integer conversion of the ceil of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = iceil(x);
    @endcode

    is equivalent to:

    @code
    as_integer_t<T> r = toints(ceil(x));
    @endcode

    @par Note:
    This operation is properly saturated

    @return an integral value of the integral type associated to the input.


**/
  template<typename T> auto iceil(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-arithmetic

      Function object tied to simd::iceil

      @see simd::iceil
    **/
    const boost::dispatch::functor<tag::iceil_> iceil = {};
  }
} }
#endif

#include <boost/simd/function/definition/iceil.hpp>
#include <boost/simd/arch/common/generic/function/iceil.hpp>
//#include <boost/simd/arch/common/function/simd/iceil.hpp>

#endif
