//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing seladd capabilities

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

  **/
  const boost::dispatch::functor<tag::seladd_> seladd = {};
} }
#endif

#include <boost/simd/function/scalar/seladd.hpp>
#include <boost/simd/function/simd/seladd.hpp>

#endif
