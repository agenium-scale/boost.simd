//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LDEXP_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing ldexp capabilities

    The function multiply a floating entry \f$x\f$
    by \f$2^{n}\f$

    @ref cardinal_of the types of x and n must be identical

    @par Semantic:

    @code
    T r = ldexp(x,n);
    @endcode

    is similar to:

    @code
    T r = x*pow(2, n);
    @endcode

  **/
  const boost::dispatch::functor<tag::ldexp_> ldexp = {};
} }
#endif

#include <boost/simd/function/scalar/ldexp.hpp>
#include <boost/simd/function/simd/ldexp.hpp>

#endif
