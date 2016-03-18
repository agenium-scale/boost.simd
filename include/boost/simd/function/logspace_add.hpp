//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOGSPACE_ADD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-exponential
    Function object implementing logspace_add capabilities

     Compute the log of a sum from logs of terms
     properly compute \f$\log (\exp (\log x) + \exp (\log y))\f$

    @par Semantic:

    For every parameters of floating types T:

    @code
    T r = logspace_add(x, y);
    @endcode

    is similar to:

    @code
    T r = log(exp(log(x)) + exp(log(y)));
    @endcode

  **/
  const boost::dispatch::functor<tag::logspace_add_> logspace_add = {};
} }
#endif

#include <boost/simd/function/scalar/logspace_add.hpp>
#include <boost/simd/function/simd/logspace_add.hpp>

#endif
