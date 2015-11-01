//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_EXPRECNEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPRECNEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes exprecneg value of its parameter.

  **/
  template<typename T> auto exprecneg(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::exprecneg

      @see simd::exprecneg
    **/
    const boost::dispatch::functor<tag::exprecneg_> exprecneg = {};
  }
} }
#endif

#include <boost/simd/function/definition/exprecneg.hpp>
#include <boost/simd/arch/common/scalar/function/exprecneg.hpp>
#include <boost/simd/function/simd/exprecneg.hpp>

#endif
