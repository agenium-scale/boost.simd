//==================================================================================================
/*!
  @file

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

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



    @return a value of the same type as the parameter

**/
  template<typename T> auto realpow(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-exponential


      Returns power function,  but
      asserts if the result is to be complex


      Function object tied to simd::realpow

      @see simd::realpow
    **/
    const boost::dispatch::functor<tag::realpow_> realpow = {};
  }
} }
#endif

#include <boost/simd/function/scalar/realpow.hpp>
#include <boost/simd/function/simd/realpow.hpp>

#endif
