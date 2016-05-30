//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_SUB_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_SUB_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_sub capabilities

    The function returns the second entry or the difference of the
    second and third entries, according to the first entry being @ref False
    or @ref True

    @par Semantic:

    For every parameters of types respectively C, T, T:

    @code
    T1 r = if_sub(x,y,a2);
    @endcode

    is similar to:

    @code
    T1 r = x ? y-a2 : y;
    @endcode

    @par Alias:
    @c if_sub

  **/
  const boost::dispatch::functor<tag::if_sub_> if_sub = {};
} }
#endif

#include <boost/simd/function/scalar/if_sub.hpp>
#include <boost/simd/function/simd/if_sub.hpp>

#endif
