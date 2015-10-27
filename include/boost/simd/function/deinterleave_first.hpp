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
#ifndef BOOST_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DEINTERLEAVE_FIRST_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    Computes a vector from a combination of the two inputs.

    @par Semantic:

    For every parameters of type T0
    @code
    T0 r = deinterleave_first(a,b);
    @endcode

    is equivalent to :

    @code
    r = [ a[0] a[2] ... a[n/2] b[0] b[2] ... b[n/2] ]
    @endcode

    with <tt> n = cardinal_of<T>::value </tt>


    @return a value of the same type as the parameters

**/
  template<typename T> auto deinterleave_first(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::deinterleave_first

      @see simd::deinterleave_first
    **/
    const boost::dispatch::functor<tag::deinterleave_first_> deinterleave_first = {};
  }
} }
#endif

#include <boost/simd/function/definition/deinterleave_first.hpp>
#include <boost/simd/arch/common/scalar/function/deinterleave_first.hpp>
//#include <boost/simd/arch/common/function/simd/deinterleave_first.hpp>

#endif
