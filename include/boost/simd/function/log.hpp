//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_LOG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_LOG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-exponential

    Natural logarithm function.

    @par Semantic:

    For every parameter of floating type T

    @code
    T r = log(x);
    @endcode

    @see log10, log2, log1p


    @return a value of the same type as the parameter

**/
  template<typename T> auto log(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Natural logarithm function.


      Function object tied to simd::log

      @see simd::log
    **/
    const boost::dispatch::functor<tag::log_> log = {};
  }
} }
#endif

#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/function/simd/log.hpp>

#endif
