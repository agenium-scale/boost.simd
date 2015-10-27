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
#ifndef BOOST_SIMD_FUNCTION_RROL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RROL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry rotated left or right
    by the absolute value of the second entry,
    according to its sign.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = rrol(x, n);
    @endcode

    @par Note
    This function asserts if the integral parameter is out of range

    @return      a value of the same type as the first input.


**/
  template<typename T, template N> auto rrol(T const& x,  N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rrol

      @see simd::rrol
    **/
    const boost::dispatch::functor<tag::rrol_> rrol = {};
  }
} }
#endif

#include <boost/simd/function/definition/rrol.hpp>
#include <boost/simd/arch/common/scalar/function/rrol.hpp>
//#include <boost/simd/arch/common/function/simd/rrol.hpp>

#endif
