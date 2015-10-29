//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    Returns x with the sign of y

    @par Semantic:

    @code
    T r = copysign(x,y);
    @endcode

    is similar to:

    @code
    T r = (y >= 0) ? abs(x) : -(abs(x));
    @endcode

    @return a value of same type as the inputs

**/
  template<typename T> auto copysign(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Returns x with the sign of y


      Function object tied to simd::copysign

      @see simd::copysign
    **/
    const boost::dispatch::functor<tag::copysign_> copysign = {};
  }
} }
#endif

#include <boost/simd/function/definition/copysign.hpp>
#include <boost/simd/arch/common/scalar/function/copysign.hpp>
#include <boost/simd/function/simd/copysign.hpp>

#endif
