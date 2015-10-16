//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ULP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes ulp value of its parameter.

  **/
  template<typename T> auto ulp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::ulp

      @see simd::ulp
    **/
    const boost::dispatch::functor<tag::ulp_> ulp = {};
  }
} }
#endif

#include <boost/simd/function/definition/ulp.hpp>
#include <boost/simd/arch/common/scalar/function/ulp.hpp>
//#include <boost/simd/arch/common/function/simd/ulp.hpp>

#endif
