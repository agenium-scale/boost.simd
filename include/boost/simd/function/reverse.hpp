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
#ifndef BOOST_SIMD_FUNCTION_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REVERSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    returns a vector the elements of which are
    those of a0 in reverse order

    @par Semantic:

    For every parameter of type T0

    @code
    T0 r = reverse(a0);
    @endcode

    is similar to:

    @code
    T0 r = ;
    for(size_t i=0;i<cardinal_of<T0>;++i)
    r[i] = a0[cardinal_of<T0>-i-1];
    @endcode


    @return a value of the same type as the parameter

**/
  template<typename T> auto reverse(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-swar

      Function object tied to simd::reverse

      @see simd::reverse
    **/
    const boost::dispatch::functor<tag::reverse_> reverse = {};
  }
} }
#endif

#include <boost/simd/function/definition/reverse.hpp>
#include <boost/simd/arch/common/scalar/function/reverse.hpp>
//#include <boost/simd/arch/common/function/simd/reverse.hpp>

#endif
