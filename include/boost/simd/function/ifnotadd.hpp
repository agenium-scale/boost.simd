//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
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
    and third entries, according to the first entry being @ref True or
    @ref False

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T r = ifnotadd(cond,t1,t2);
    @endcode

    is similar to:

    @code
    T r = cond ? t1 :  t1+t2;
    @endcode

    @see seladd

    @return a value of the same type as the second parameter

**/
  template<typename C typename T>
  auto ifnotadd(C const& cond, T const& t1, T const& t2 );

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean

      The function returns the second entry or the sum of the second
      and third entries, according to the first entry being @ref True or
      @ref False

      Function object tied to simd::ifnotadd

      @see simd::ifnotadd
    **/
    const boost::dispatch::functor<tag::ifnotadd_> ifnotadd = {};
  }
} }
#endif

#include <boost/simd/function/definition/ifnotadd.hpp>
#include <boost/simd/arch/common/scalar/function/ifnotadd.hpp>
#include <boost/simd/function/simd/ifnotadd.hpp>

#endif
