//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTAFTER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_NEXTAFTER_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/scalar/oneplus.hpp>
#include <boost/simd/function/scalar/minusone.hpp>
#include <boost/simd/function/scalar/sign.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/math/special_functions/next.hpp>
#include <boost/simd/math.hpp>

// workaround for boost.math bug #5823
namespace boost { namespace simd {
  namespace detail
  {
    template<typename T>
    BOOST_FORCEINLINE T nextafter(T a0, T a1)
    {
      if(a0 > a1 && a0 == Inf<T>())
        return Valmax<T>();
      if(a0 < a1 && a0 == Minf<T>())
        return Valmin<T>();

      using namespace boost::math::policies;
      typedef policy<
        domain_error<errno_on_error>,
        pole_error<errno_on_error>,
        overflow_error<errno_on_error>,
        evaluation_error<errno_on_error>,
        rounding_error<errno_on_error>
        > c_policy;

      return boost::math::nextafter(a0, a1, c_policy());
    }
  }

  namespace ext
  {
    namespace bd = boost::dispatch;
    BOOST_DISPATCH_OVERLOAD ( nextafter_
                            , (typename A0)
                            , bd::cpu_
                            , bd::scalar_< bd::arithmetic_<A0> >
                            , bd::scalar_< bd::arithmetic_<A0> >
                            )
    {
      BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
      {
        return a0+sign(a1-a0);
      }
    };

    BOOST_DISPATCH_OVERLOAD ( nextafter_
                            , (typename A0)
                            , bd::cpu_
                            , bd::scalar_< bd::double_<A0> >
                            , bd::scalar_< bd::double_<A0> >
                            )
    {
      BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
      {
#ifdef BOOST_SIMD_HAS_NEXTAFTER
        return ::nextafter(a0, a1);
#elif defined(BOOST_SIMD_HAS__NEXTAFTER)
        return ::_nextafter(a0, a1);
#else
        return detail::nextafter(a0, a1);
#endif
      }
    };

    BOOST_DISPATCH_OVERLOAD ( nextafter_
                            , (typename A0)
                            , bd::cpu_
                            , bd::scalar_< bd::single_<A0> >
                            , bd::scalar_< bd::single_<A0> >
                            )
    {
      BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
      {
#ifdef BOOST_SIMD_HAS_NEXTAFTERF
        return ::nextafterf(a0, a1);
#elif defined(BOOST_SIMD_HAS__NEXTAFTERF)
        return ::_nextafterf(a0, a1);
#else
        return detail::nextafter(a0, a1);
#endif
      }
    };

    BOOST_DISPATCH_OVERLOAD ( nextafter_
                            , (typename A0)
                            , bd::cpu_
                            , bd::scalar_< bd::unsigned_<A0> >
                            , bd::scalar_< bd::unsigned_<A0> >
                            )
    {
      BOOST_FORCEINLINE A0 operator() ( A0 a0, A0 a1) const BOOST_NOEXCEPT
      {
        return (a1 == a0) ? a0 : (a1 > a0) ? oneplus(a0) : minusone(a0);
      }
    };
  }
} }


#endif
