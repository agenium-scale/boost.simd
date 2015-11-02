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
#ifndef BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_EXPRECNEGC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-trigonometry

    Computes exprecnegc value of its parameter.

  **/
  template<typename T> auto exprecnegc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-trigonometry

      Function object tied to simd::exprecnegc

      @see simd::exprecnegc
    **/
    const boost::dispatch::functor<tag::exprecnegc_> exprecnegc = {};
  }
} }
#endif

#include <boost/simd/function/definition/exprecnegc.hpp>
#include <boost/simd/arch/common/generic/function/exprecnegc.hpp>
#include <boost/simd/function/simd/exprecnegc.hpp>

#endif
