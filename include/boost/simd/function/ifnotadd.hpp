//==================================================================================================
/*!
  @file

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

    For every parameters of types respectively COND, T1, T1:

    @code
    T1 r = ifnotadd(cond,t1,t2);
    @endcode

    is similar to:

    @code
    T1 r = cond ? t1 :  t1+t2;
    @endcode

    @see seladd

    @return a value of the same type as the second parameter

**/
  template<typename COND typename T1, typename T2>
  auto ifnotadd(COND const& cond, T1 const& t1, T2 const& t2 );

  namespace functional
  {
    /*!
      @ingroup group-callable-boolean



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
