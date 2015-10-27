//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MINNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-ieee

     Returns the minimum value, ignoring nans.

    @par Semantic:

    @code
    T r = minnum(a0,a1);
    @endcode

    is similar to:

    @code
    T r =     T r = (is_nan(a0) ? a1 : (isnan(a1) ? a0 : min(a0, a1));;
    @endcode

    @par Alias:
    @c fmin



    @return a value of same type as the inputs

**/
  template<typename T> auto minnum(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-ieee

      Function object tied to simd::minnum

      @see simd::minnum
    **/
    const boost::dispatch::functor<tag::minnum_> minnum = {};
  }
} }
#endif

#include <boost/simd/function/definition/minnum.hpp>
#include <boost/simd/arch/common/scalar/function/minnum.hpp>
//#include <boost/simd/arch/common/function/simd/minnum.hpp>

#endif
