//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_INTERLEAVE_EVEN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of types respectively T0:

    @code
    T0 r = interleave_even(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[0] b[0] a[2] b[2] ... a[n/2] b[n/2] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>


    @return a value of the same type as the parameters

**/
  template<typename T> auto interleave_even(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::interleave_even

      @see simd::interleave_even
    **/
    const boost::dispatch::functor<tag::interleave_even_> interleave_even = {};
  }
} }
#endif

#include <boost/simd/function/definition/interleave_even.hpp>
#include <boost/simd/arch/common/scalar/function/interleave_even.hpp>
//#include <boost/simd/arch/common/function/simd/interleave_even.hpp>

#endif
