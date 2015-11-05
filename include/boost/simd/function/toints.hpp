//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOINTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOINTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Convert to integer by saturated truncation.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T> r = toints(x);
    @endcode

    The code is similar to:

    @code
    as_integer_t<T> r = static_cast<as_integer_t<T> >(saturate<as_integer_t<T> >(x))
    @endcode

    @par Notes:

    The @ref Inf, @ref Minf and @ref Nan values are treated properly and go respectively to
    @ref Valmax, @ref Valmin and @ref Zero of the destination integral type
    All values superior (resp.) less than @ref Valmax (resp. @ref Valmin) of the return type
    are saturated accordingly.

    If you do not care about invalid values or overflows toint is speedier.

    @par Alias

    @c ifix,  @c itrunc

    @see  toint
    @return      a value of the integer same type associated to the input.


**/
  template<typename T> auto toints(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Convert to integer by saturated truncation.


      Function object tied to simd::toints

      @see simd::toints
    **/
    const boost::dispatch::functor<tag::toints_> toints = {};
  }
} }
#endif

#include <boost/simd/function/definition/toints.hpp>
#include <boost/simd/arch/common/scalar/function/toints.hpp>
#include <boost/simd/function/simd/toints.hpp>

#endif
