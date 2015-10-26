//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ROR_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns the first entry rotated right
    by the absolute value of the second entry.

    @par semantic:
    For any given value @c x of type @c T, n  of type @c I:

    @code
    T r = ror(x, n);
    @endcode

    @see  rol, rror, rrol

    @return      a value of the same type as the first input.


**/
  template<typename T> auto ror(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-bitwise

      Function object tied to simd::ror

      @see simd::ror
    **/
    const boost::dispatch::functor<tag::ror_> ror = {};
  }
} }
#endif

#include <boost/simd/function/definition/ror.hpp>
#include <boost/simd/arch/common/generic/function/ror.hpp>
//#include <boost/simd/arch/common/function/simd/ror.hpp>

#endif
