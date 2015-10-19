//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_NAN_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-constant

    Generate the Not a Number (NaN) constant.

    @par Semantic

    For any type @c T,

    @code
    T x = NaN<T>();
    @endcode

    return the NaN representation for this type, i.e QuietNaN for IEEE reals and
    0 for integers.

    @return The NaN constant for the proper type
  **/
  template<typename T> T NaN();

  namespace functional
  {
    /*!
      @ingroup group-constant
      Generate the Not a Number (NaN) constant.

      @par Semantic

      For any type @c T,

      @code
      T x = nan(as(T{}));
      @endcode

      return the NaN representation for this type, i.e QuietNaN for IEEE reals and
      0 for integers.

      @return The NaN constant for the proper type
    **/
    const boost::dispatch::functor<tag::nan_> nan = {};
  }
} }
#endif

#include <boost/simd/constant/definition/nan.hpp>
#include <boost/simd/arch/common/scalar/constant/constant_value.hpp>

#endif
