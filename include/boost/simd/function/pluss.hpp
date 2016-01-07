//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_PLUSS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_PLUSS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-arithmetic

    Computes the saturated sum of its parameters.

    This is a convenient alias of @ref adds
  **/
  template<typename T> auto pluss(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the saturated sum of its parameters.


      Function object tied to simd::pluss

      @see simd::pluss
    **/
    const boost::dispatch::functor<tag::pluss_> pluss = {};
  }
} }
#endif

#include <boost/simd/function/definition/pluss.hpp>
#include <boost/simd/arch/common/scalar/function/adds.hpp>
#include <boost/simd/function/simd/pluss.hpp>

#endif
