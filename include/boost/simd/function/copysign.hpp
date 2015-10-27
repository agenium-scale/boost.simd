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

    Returns a0 with the sign of a1

    @par Semantic:

    @code
    T r = copysign(a0,a1);
    @endcode

    is similar to:

    @code
    T r = (a1 >= 0) ? abs(a0) : -(abs(a0));
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto copysign(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::copysign

      @see simd::copysign
    **/
    const boost::dispatch::functor<tag::copysign_> copysign = {};
  }
} }
#endif

#include <boost/simd/function/definition/copysign.hpp>
#include <boost/simd/arch/common/scalar/function/copysign.hpp>
//#include <boost/simd/arch/common/function/simd/copysign.hpp>

#endif
