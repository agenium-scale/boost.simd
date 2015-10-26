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
#ifndef BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-boolean


    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being False or
    True

    @par Semantic:

    For every parameters of types respectively T0, T1, T1:

    @code
    T1 r = seladd(a0,a1,a2);
    @endcode

    is similar to:

    @code
    T1 r = a0 ? a1+a2 : a1;
    @endcode

    @par Alias:
    @c ifadd




    @return a value of the same type as the second parameter

**/
  template<typename T> auto seladd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-boolean

      Function object tied to simd::seladd

      @see simd::seladd
    **/
    const boost::dispatch::functor<tag::seladd_> seladd = {};
  }
} }
#endif

#include <boost/simd/function/definition/seladd.hpp>
#include <boost/simd/arch/common/scalar/function/seladd.hpp>
//#include <boost/simd/arch/common/function/simd/seladd.hpp>

#endif
