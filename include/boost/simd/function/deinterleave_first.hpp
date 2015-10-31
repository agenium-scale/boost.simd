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
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of type T
    @code
    T0 r = deinterleave_first(x,y);
    @endcode

    is equivalent to :

    @code
    r = [ x[0] x[2] ... x[n/2] y[0] y[2] ... y[n/2] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>


    @return a value of the same type as the parameters

**/
  template<typename T> auto deinterleave_first(T const& x, T const&y ) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      Computes a vector from a combination of the two inputs.


      Function object tied to simd::deinterleave_first

      @see simd::deinterleave_first
    **/
    const boost::dispatch::functor<tag::deinterleave_first_> deinterleave_first = {};
  }
} }
#endif

#include <boost/simd/function/definition/deinterleave_first.hpp>
#include <boost/simd/arch/common/scalar/function/deinterleave_first.hpp>
#include <boost/simd/function/simd/deinterleave_first.hpp>

#endif
