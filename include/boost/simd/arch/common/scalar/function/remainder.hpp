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
#include <boost/simd/function/fnms.hpp>
#include <boost/simd/function/idivround2even.hpp>
#include <boost/simd/function/if_nan_else.hpp>
#include <boost/simd/function/is_finite.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/selsub.hpp>
#include <boost/simd/options.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
/////////////////////////////////////////////////////////////////////////////
// The remainder() function computes the remainder of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// integer.  If the absolute value of x-n*y is 0.5, n is chosen to be even.
// The drem function is just an alias for the same thing.
// As the result can be negative the functor is not defined for unsigned
// entries
// For floating entries:
// if x is +/-inf , Nan is returned
// If y is +-0    , Nan is returned
// If either argument is NaN, Nan is returned
// If the returned value is 0, it will have the same sign as x.
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
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          , bs::fast_tag
                           )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, fast_tag const&) const BOOST_NOEXCEPT
    {
      return fnms(idivround2even(a0, a1), a1, a0);
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
      return if_nan_else(is_inf(a0), selsub(is_finite(a1), a0, divround2even(a0, a1)*a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( remainder_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          , bs::fast_tag
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1, fast_tag const&) const BOOST_NOEXCEPT
    {
      return fnms(divround2even(a0, a1), a1, a0);
    }
  };
} } }


#endif
