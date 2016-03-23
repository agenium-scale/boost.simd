//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_REALPOW_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REALPOW_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-exponential
    Function object implementing realpow capabilities

    Returns power function,  but
    asserts if the result is to be complex.

    @par Semantic:

    For every parameters of floating type T:

    @code
    T r = realpow(x,y);
    @endcode

    is similar to:

    @code
    T r = pow(x, y);
    @endcode

  **/
  const boost::dispatch::functor<tag::realpow_> realpow = {};
} }
#endif

#include <boost/simd/function/scalar/realpow.hpp>
#include <boost/simd/function/simd/realpow.hpp>

#endif
