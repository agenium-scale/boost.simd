//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_TWOPOWER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-bitwise

    Returns \f$2^n\f$ (or 0 if n is less than zero)

    @par semantic:
    For any given value n  of integral type @c N:

    @code
    N r = twopower(n);
    @endcode

    code is similar to:

    @code
    N r = 1 << n;
    @endcode

    @par Note:

    This function is not defined for floating entries

    @see  ilog2

    @return      a value of the same type as the input.


**/
  template<typename T> auto twopower(N const& n) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-bitwise

      Returns \f$2^n\f$ (or 0 if n is less than zero)


      Function object tied to simd::twopower

      @see simd::twopower
    **/
    const boost::dispatch::functor<tag::twopower_> twopower = {};
  }
} }
#endif

#include <boost/simd/function/scalar/twopower.hpp>
#include <boost/simd/function/simd/twopower.hpp>

#endif
