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

    For every parameters of types respectively COND, T:

    @code
    T1 r = selinc(cond,y);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t+one : t  ;
    @endcode

    @par Alias:
    @c ifinc



    @return a value of the same type as the second parameter

**/
  template<typename COND, typename T> auto selinc(COND const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Increments a value by 1 if a predicate is true.


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
