//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_ODD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of types respectively T0:

    @code
    T0 r = interleave_odd(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[1] b[1] a[3] b[3] ... a[n/2+1] b[n/2+1] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>


    @return a value of the same type as the parameters

**/
  template<typename T> auto interleave_odd(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      Computes a vector from a combination of the two inputs.


      Function object tied to simd::interleave_odd

      @see simd::interleave_odd
    **/
    const boost::dispatch::functor<tag::interleave_odd_> interleave_odd = {};
  }
} }
#endif

#include <boost/simd/function/scalar/interleave_odd.hpp>
#include <boost/simd/function/simd/interleave_odd.hpp>

#endif
