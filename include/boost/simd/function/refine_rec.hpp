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
#ifndef BOOST_SIMD_FUNCTION_REFINE_REC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REFINE_REC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Performs a Newton-Raphson step to improve precision of reciprocate estimate.
    This function can be used in conjunction with raw_rec or
    fast_rec to add more precision to the estimate if their default
    precision is not enough.


    @see rec

    @return  A value estimating rec(x) with twice as much precision


**/
  template<typename T> auto refine_rec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Performs a Newton-Raphson step to improve precision of reciprocate estimate.
      This function can be used in conjunction with raw_rec or
      fast_rec to add more precision to the estimate if their default
      precision is not enough.


      Function object tied to simd::refine_rec

      @see simd::refine_rec
    **/
    const boost::dispatch::functor<tag::refine_rec_> refine_rec = {};
  }
} }
#endif

#include <boost/simd/function/definition/refine_rec.hpp>
#include <boost/simd/arch/common/scalar/function/refine_rec.hpp>
#include <boost/simd/function/simd/refine_rec.hpp>

#endif
