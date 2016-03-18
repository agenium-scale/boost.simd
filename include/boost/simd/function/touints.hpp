//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TOUINTS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TOUINTS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-arithmetic
    Function object implementing touints capabilities

    Convert to unsigned integer by saturated truncation.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer_t<T, unsigned> r = touint(x);
    @endcode

    The code is similar to:

    @code
    using T_t = as_integer_t<T,unsigned>;
    as_integer_t<T,unsigned> r = static_cast<T_t>(saturate<as_integer_t<T,unsigned> (x)))
    @endcode

    @par Notes:

    The @ref Inf, @ref Nan and negative values are treated properly and go respectively to
    @ref Valmax, and @ref Zero of the destination integral type.

    All values superior (resp. less) than @ref Valmax (resp. @ref Valmin) of the return type
    are saturated accordingly.

    If you do not care about invalid values or overflows toint is speedier.

    @see touint

  **/
  const boost::dispatch::functor<tag::touints_> touints = {};
} }
#endif

#include <boost/simd/function/scalar/touints.hpp>
#include <boost/simd/function/simd/touints.hpp>

#endif
