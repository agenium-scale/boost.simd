//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SPLATTED_MINIMUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SPLATTED_MINIMUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar


**/
  template<typename T> auto splatted_minimum(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::splatted_minimum

      @see simd::splatted_minimum
    **/
    const boost::dispatch::functor<tag::splatted_minimum_> splatted_minimum = {};
  }
} }
#endif

#include <boost/simd/function/definition/splatted_minimum.hpp>
#include <boost/simd/arch/common/scalar/function/splatted_minimum.hpp>
//#include <boost/simd/arch/common/function/simd/splatted_minimum.hpp>

#endif
