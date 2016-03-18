//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COPYSIGN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing copysign capabilities

    Returns x with the sign of y

    @par Semantic:

    @code
    T r = copysign(x,y);
    @endcode

    is similar to:

    @code
    T r = (y >= 0) ? abs(x) : -(abs(x));
    @endcode

  **/
  const boost::dispatch::functor<tag::copysign_> copysign = {};
} }
#endif

#include <boost/simd/function/scalar/copysign.hpp>
#include <boost/simd/function/simd/copysign.hpp>

#endif
