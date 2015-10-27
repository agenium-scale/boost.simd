//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_SUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_SUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar


**/
  template<typename T> auto splatted_sum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::splatted_sum

      @see simd::splatted_sum
    **/
    const boost::dispatch::functor<tag::splatted_sum_> splatted_sum = {};
  }
} }
#endif

#include <boost/simd/function/definition/splatted_sum.hpp>
#include <boost/simd/arch/common/scalar/function/splatted_sum.hpp>
//#include <boost/simd/arch/common/function/simd/splatted_sum.hpp>

#endif
