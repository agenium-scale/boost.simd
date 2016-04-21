//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing negif capabilities

    The function returns -x if cond is @ref True and x otherwise.

    @par Semantic:

    For every parameters of types respectively C, T:

    @code
    T r = negif(cond,x);
    @endcode

    is similar to:

    @code
    T r = cond ? -x : x;
    @endcode

  **/
  const boost::dispatch::functor<tag::negif_> negif = {};
} }
#endif

#include <boost/simd/function/scalar/negif.hpp>
#include <boost/simd/function/simd/negif.hpp>

#endif
