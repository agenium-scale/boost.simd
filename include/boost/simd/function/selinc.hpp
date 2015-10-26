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
#ifndef BOOST_SIMD_FUNCTION_SELINC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELINC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Increments a value by 1 if a predicate is true.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T1 r = selinc(a0,a1);
    @endcode

    is similar to:

    @code
    T1 r = a0 ? a1+one : a1;
    @endcode

    @par Alias:
    @c ifinc



    @return a value of the same type as the second parameter

**/
  template<typename T> auto selinc(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::selinc

      @see simd::selinc
    **/
    const boost::dispatch::functor<tag::selinc_> selinc = {};
  }
} }
#endif

#include <boost/simd/function/definition/selinc.hpp>
#include <boost/simd/arch/common/scalar/function/selinc.hpp>
//#include <boost/simd/arch/common/function/simd/selinc.hpp>

#endif
