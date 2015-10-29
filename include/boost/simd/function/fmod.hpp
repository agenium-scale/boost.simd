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
#ifndef BOOST_SIMD_FUNCTION_FMOD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_FMOD_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward zero.

    This is a convenient alias of rem
**/
  template<typename T> auto fmod(T const& x, const T& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the remainder of division.
      The return value is x-n*y, where n is the value x/y,
      rounded toward zero.


      Function object tied to simd::fmod

      @see simd::fmod
    **/
    const boost::dispatch::functor<tag::fmod_> fmod = {};
  }
} }
#endif

#include <boost/simd/function/definition/fmod.hpp>
#include <boost/simd/arch/common/scalar/function/rem.hpp>
#include <boost/simd/function/simd/fmod.hpp>

#endif
