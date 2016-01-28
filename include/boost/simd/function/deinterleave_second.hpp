//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_SECOND_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of type T:

    @code
    T0 r = deinterleave_second(x,y);
    @endcode

    is equivalent to :

    @code
    r = [ x[1] x[3] ... x[n/2+1] y[1] y[3] ... y[n/2+1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>



    @return a value of the same type as the parameters

**/
  template<typename T> auto deinterleave_second(T const& x, T const&y ) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      Computes a vector from a combination of the two inputs.


      Function object tied to simd::deinterleave_second

      @see simd::deinterleave_second
    **/
    const boost::dispatch::functor<tag::deinterleave_second_> deinterleave_second = {};
  }
} }
#endif

#include <boost/simd/function/scalar/deinterleave_second.hpp>
#include <boost/simd/function/simd/deinterleave_second.hpp>

#endif
