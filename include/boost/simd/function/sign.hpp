//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns the sign of x. i.e. -1, 0 or 1, according
    x is less than zero, zero or greater than zero.

    For floating,  the sign of nan is nan

    @par Semantic:

    @code
    T r = sign(x);
    @endcode

    is similar to:

    @code
    T r = (x > 0) ? T(1) : ((x < 0) ? T(-1) : ((x == 0) ? 0 : Nan<T>()));
    @endcode


    @return a value of same type as the input

**/
  template<typename T> auto sign(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::sign

      @see simd::sign
    **/
    const boost::dispatch::functor<tag::sign_> sign = {};
  }
} }
#endif

#include <boost/simd/function/definition/sign.hpp>
#include <boost/simd/arch/common/scalar/function/sign.hpp>
//#include <boost/simd/arch/common/function/simd/sign.hpp>

#endif
