//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TENPOWER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-arithmetic

    Returns \f$10^n\f$ in the floating type  corresponding to A0

    @par semantic:
    For any given value n  of integral type @c I

    @code
    as_floating_t<I> r = tenpower(n);
    @endcode

    code is similar to:

    @code
    auto r = exp10(as_floating_t<I>(n));
    @endcode

    @par Note:

    This function is not defined for floating entries and intended to be used for
    small integer values.

    @see exp10

    @return a value of the floating associated type.


**/
  template<typename T> auto tenpower(T const& x) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-arithmetic

      Returns \f$10^n\f$ in the floating type  corresponding to A0


      Function object tied to simd::tenpower

      @see simd::tenpower
    **/
    const boost::dispatch::functor<tag::tenpower_> tenpower = {};
  }
} }
#endif

#include <boost/simd/function/definition/tenpower.hpp>
#include <boost/simd/arch/common/scalar/function/tenpower.hpp>
#include <boost/simd/function/simd/tenpower.hpp>

#endif
