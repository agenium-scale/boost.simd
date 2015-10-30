//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean


    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being @ref False or
    @ref True

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T r = seladd(cond,t1,t2);
    @endcode

    is similar to:

    @code
    T r = cond ? t1+t2 : t1;
    @endcode

    @par Alias:
    @c if_add

    @return a value of the same type as the second parameter

**/
  template<typename C, typename T> auto seladd(C const& cond, T const& t1, T const& t2) {}


  namespace functional
  {
    /*!
      @ingroup group-callable-boolean



      Function object tied to simd::seladd

      @see simd::seladd
    **/
    const boost::dispatch::functor<tag::seladd_> seladd = {};
  }
} }
#endif

#include <boost/simd/function/definition/seladd.hpp>
#include <boost/simd/arch/common/scalar/function/seladd.hpp>
#include <boost/simd/function/simd/seladd.hpp>

#endif
