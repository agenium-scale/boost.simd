//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_DIVS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/dispatch/meta/as_unsigned.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4723) // potential divide by 0
#endif

  BOOST_DISPATCH_OVERLOAD ( divs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::floating_<A0> >
                          , bd::scalar_< bd::floating_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a0/a1;
    }
  };

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

  BOOST_DISPATCH_OVERLOAD ( divs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::int_<A0> >
                          , bd::scalar_< bd::int_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      typedef bd::as_unsigned_t<A0> utype;
      A0 const aa0 = a0 + !((a1 + One<A0>()) | ((utype)a0 + Valmin<A0>()));
      if (a1)
        return aa0/a1;
      else if (a0)
        return Valmax<A0>() + ((utype)a0 >> (sizeof(A0)*CHAR_BIT-1));
      else
        return Zero<A0>();
    }
  };

  BOOST_DISPATCH_OVERLOAD ( divs_
                          , (typename A0)
                          , bd::cpu_
                          , bd::scalar_< bd::uint_<A0> >
                          , bd::scalar_< bd::uint_<A0> >
                          )
  {
    BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
    {
      return a1 ? a0/a1 : genmask(a0);
    }
  };
} } }


#endif
