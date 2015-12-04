//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMAINDER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_REMAINDER_HPP_INCLUDED

#include <boost/simd/function/divround2even.hpp>
#include <boost/simd/function/idivround2even.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/selsub.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
// As the result can be negative the functor is not defined for unsigned
// The drem function is just an alias for the same thing.
// The remainder() function computes the remainder of dividing x by y.  The
// entries
// integer.  If the boost::simd::absolute value of x-n*y is 0.5, n is chosen
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// to be even.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( remainder_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return selsub(is_nez(a1),a0,
                    simd::multiplies(idivround2even(a0, a1), a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( remainder_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-divround2even(a0, a1)*a1;
    }
  };
} } }


#endif
