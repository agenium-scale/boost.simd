//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_PROD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar


**/
  template<typename T> auto splatted_prod(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar



      Function object tied to simd::splatted_prod

      @see simd::splatted_prod
    **/
    const boost::dispatch::functor<tag::splatted_prod_> splatted_prod = {};
  }
} }
#endif

#include <boost/simd/function/definition/splatted_prod.hpp>
#include <boost/simd/arch/common/scalar/function/splatted_prod.hpp>
#include <boost/simd/function/simd/splatted_prod.hpp>

#endif
