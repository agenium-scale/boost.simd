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
#ifndef BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELDEC_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean

    Decrements a value by 1 if a predicate is true.

    @par Semantic:

    For every parameters of types respectively T0, T1:

    @code
    T1 r = seldec(a0,a1);
    @endcode

    is similar to:

    @code
    T1 r = a0 : a1-one : a1;
    @endcode

    @par Alias:
    @c ifdec



    @return a value of the same type as the second parameter

**/
  template<typename T> auto seldec(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::seldec

      @see simd::seldec
    **/
    const boost::dispatch::functor<tag::seldec_> seldec = {};
  }
} }
#endif

#include <boost/simd/function/definition/seldec.hpp>
#include <boost/simd/arch/common/scalar/function/seldec.hpp>
//#include <boost/simd/arch/common/function/simd/seldec.hpp>

#endif
