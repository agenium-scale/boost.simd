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
#ifndef BOOST_SIMD_FUNCTION_RSHL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_RSHL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry shifted left or right
    by the absolute value of the second entry,
    according to its sign.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = rshl(x, n);
    @endcode

    @see  rshr, shr, shl

    @return      a value of the same type as the first input.


**/
  template<typename T> auto rshl(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::rshl

      @see simd::rshl
    **/
    const boost::dispatch::functor<tag::rshl_> rshl = {};
  }
} }
#endif

#include <boost/simd/function/definition/rshl.hpp>
#include <boost/simd/arch/common/scalar/function/rshl.hpp>
//#include <boost/simd/arch/common/function/simd/rshl.hpp>

#endif
