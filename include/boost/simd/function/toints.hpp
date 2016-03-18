//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

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
    Function object implementing toints capabilities

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

    - The @ref Inf, @ref Minf and @ref Nan values are treated properly and go respectively to
    @ref Valmax, @ref Valmin and @ref Zero of the destination integral type.

    - All values superior (resp.) less than @ref Valmax (resp. @ref Valmin) of the return type
    are saturated accordingly.

    - If you do not care about invalid values or overflows, toint is faster.

    @par Alias

    @c ifix,  @c itrunc

    @see  toint
  **/
  const boost::dispatch::functor<tag::toints_> toints = {};
} }
#endif

#include <boost/simd/function/scalar/toints.hpp>
#include <boost/simd/function/simd/toints.hpp>

#endif
