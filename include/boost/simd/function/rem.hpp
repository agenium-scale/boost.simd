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
#ifndef BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_REM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Computes the remainder of division.
    The return value is x-n*y, where n is the value x/y,
    rounded toward zero.

    @par semantic:
    For any given value @c x, @c y of type @c T:

    @code
    T r = rem(x, y);
    @endcode

    For floating point values the code is equivalent to:

    @code
    T r = x-divfix(x, y)*y;
    @endcode

    @par Alias

    @c fmod,  @c remfix

    @see remainder, mod, modulo

    @return      a value of the same type as the input.


**/
  template<typename T> auto rem(T const& x, T const & y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Computes the remainder of division.
      The return value is x-n*y, where n is the value x/y,
      rounded toward zero.


      Function object tied to simd::rem

      @see simd::rem
    **/
    const boost::dispatch::functor<tag::rem_> rem = {};
  }
} }
#endif

#include <boost/simd/function/definition/rem.hpp>
#include <boost/simd/arch/common/scalar/function/rem.hpp>
#include <boost/simd/function/simd/rem.hpp>

#endif
