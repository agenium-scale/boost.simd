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
#ifndef BOOST_SIMD_FUNCTION_CHOP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_CHOP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic


  chop (x, ndigits, base)
  truncate elements of x to a length of ndigits such that the
  resulting numbers are exactly divisible by base.  if base is not
  specified it defaults to 10.
  chop(x,n) chops aways from 0 to n digits:

  @return      a value of the same type as the input.


**/
  template<typename T> auto chop(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic



      Function object tied to simd::chop

      @see simd::chop
    **/
    const boost::dispatch::functor<tag::chop_> chop = {};
  }
} }
#endif

#include <boost/simd/function/definition/chop.hpp>
#include <boost/simd/arch/common/scalar/function/chop.hpp>
//#include <boost/simd/arch/common/function/simd/chop.hpp>

#endif
