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
#ifndef BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

    The function multiply a floating entry \f$a_0\f$
    by \f$2^{a_1}\f$

    @par Semantic:

    @code
    T r = ldexp(a0,a1);
    @endcode

    is similar to:

    @code
    T r = a0*pow(2, a1);
    @endcode



    @return a value of same type as the inputs

**/
  template<typename T> auto ldexp(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::ldexp

      @see simd::ldexp
    **/
    const boost::dispatch::functor<tag::ldexp_> ldexp = {};
  }
} }
#endif

#include <boost/simd/function/definition/ldexp.hpp>
#include <boost/simd/arch/common/scalar/function/ldexp.hpp>
//#include <boost/simd/arch/common/function/simd/ldexp.hpp>

#endif
