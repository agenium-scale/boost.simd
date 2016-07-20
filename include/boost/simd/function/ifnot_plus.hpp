//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_PLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing ifnot_plus capabilities

    The function returns the second entry or the sum of the second
    and third entries, according to the first entry being @ref True or
    @ref False

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T r = ifnot_plus(cond,t1,t2);
    @endcode

    is similar to:

    @code
    T r = cond ? t1 :  t1+t2;
    @endcode

    @see if_plus

  **/
  const boost::dispatch::functor<tag::ifnot_plus_> ifnot_plus = {};
} }
#endif

#include <boost/simd/function/scalar/ifnot_plus.hpp>
#include <boost/simd/function/simd/ifnot_plus.hpp>

#endif
