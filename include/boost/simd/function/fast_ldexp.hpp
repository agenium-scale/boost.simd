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
#ifndef BOOST_SIMD_FUNCTION_FAST_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FAST_LDEXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-ieee

    Computes fast_ldexp value of its parameter.

  **/
  template<typename T> auto fast_ldexp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-ieee

      Computes fast_ldexp value of its parameter.


      Function object tied to simd::fast_ldexp

      @see simd::fast_ldexp
    **/
    const boost::dispatch::functor<tag::fast_ldexp_> fast_ldexp = {};
  }
} }
#endif

#include <boost/simd/function/definition/fast_ldexp.hpp>
#include <boost/simd/arch/common/scalar/function/fast_ldexp.hpp>
//#include <boost/simd/arch/common/function/simd/fast_ldexp.hpp>

#endif
