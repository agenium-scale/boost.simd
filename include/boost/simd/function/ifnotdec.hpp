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
#ifndef BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Decrements a value by 1 if a predicate is False.

    @par Semantic:

    For every parameters of types respectively COND, T:

    @code
    T r = ifnotdec(cond,t);
    @endcode

    is similar to:

    @code
    T r = cond : t : t-one;
    @endcode

    @return a value of the same type as the second parameter

**/
  template<typename T> auto ifnotdec(T const& cond, T const& t) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      Decrements a value by 1 if a predicate is False.


      Function object tied to simd::ifnotdec

      @see simd::ifnotdec
    **/
    const boost::dispatch::functor<tag::ifnotdec_> ifnotdec = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotdec.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotdec.hpp>
#include <boost/simd/function/simd/ifnotdec.hpp>

#endif
