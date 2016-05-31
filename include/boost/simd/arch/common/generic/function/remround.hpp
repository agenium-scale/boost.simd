//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REMROUND_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_REMROUND_HPP_INCLUDED

#include <boost/simd/function/div.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/if_minus.hpp>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
////////////////////////////////////////////////////////////////////////////
// The remround() function computes the remround of dividing x by y.  The
// return value is x-n*y, where n is the value x / y, rounded to the nearest
// integer.
// As the result can be negative the functor is not defined for unsigned
// entries
/////////////////////////////////////////////////////////////////////////////

  BOOST_DISPATCH_OVERLOAD ( remround_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::signed_<A0> >
                          , bd::generic_< bd::signed_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return if_minus(is_nez(a1),a0,
                    simd::multiplies(div(iround, a0, a1), a1));
    }
  };

  BOOST_DISPATCH_OVERLOAD ( remround_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0-div(round, a0, a1)*a1;
    }
  };
} } }


#endif
