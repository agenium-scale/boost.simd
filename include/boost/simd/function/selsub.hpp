//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SELSUB_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SELSUB_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing selsub capabilities

    The function returns the second entry or the difference of the
    second and third entries, according to the first entry being @ref False
    or @ref True

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T1 r = selsub(x,y,a2);
    @endcode

    is similar to:

    @code
    T1 r = x ? y-a2 : y;
    @endcode

    @par Alias:
    @c if_sub

  **/
  const boost::dispatch::functor<tag::selsub_> selsub = {};
} }
#endif

#include <boost/simd/function/scalar/selsub.hpp>
#include <boost/simd/function/simd/selsub.hpp>

#endif
