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
#ifndef BOOST_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOTADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean


    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being True or
    False

    @par Semantic:

    For every parameters of types respectively T0, T1, T1:

    @code
    T1 r = ifnotadd(a0,a1,a2);
    @endcode

    is similar to:

    @code
    T1 r = a0 ? a1 :  a1+a2;
    @endcode

    @par Alias:
    @c selnotadd

    @see seladd

    @return a value of the same type as the second parameter

**/
  template<typename T> auto ifnotadd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::ifnotadd

      @see simd::ifnotadd
    **/
    const boost::dispatch::functor<tag::ifnotadd_> ifnotadd = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotadd.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotadd.hpp>
//#include <boost/simd/arch/common/function/simd/ifnotadd.hpp>

#endif
