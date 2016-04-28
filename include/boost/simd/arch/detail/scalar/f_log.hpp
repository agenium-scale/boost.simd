//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_DETAIL_SCALAR_F_LOG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_DETAIL_SCALAR_F_LOG_HPP_INCLUDED

#include <boost/simd/arch/detail/tags.hpp>
#include <boost/simd/arch/detail/scalar/horner.hpp>
#include <boost/simd/arch/detail/generic/f_log_kernel.hpp>
#include <boost/simd/function/scalar/is_ltz.hpp>
#include <boost/simd/function/scalar/is_eqz.hpp>
#include <boost/simd/function/scalar/fma.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mhalf.hpp>
#include <boost/simd/constant/log_2hi.hpp>
#include <boost/simd/constant/log_2lo.hpp>
#include <boost/simd/constant/log2_em1.hpp>
#include <boost/simd/constant/log10_ehi.hpp>
#include <boost/simd/constant/log10_elo.hpp>
#include <boost/simd/constant/log10_2hi.hpp>
#include <boost/simd/constant/log10_2lo.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

#ifndef BOOST_SIMD_NO_NANS
#include <boost/simd/function/scalar/is_nan.hpp>
#endif
#ifndef BOOST_SIMD_NO_INFINITIES
#include <boost/simd/constant/inf.hpp>
#endif
#ifndef BOOST_SIMD_NO_DENORMALS
#include <boost/simd/function/scalar/abs.hpp>
#include <boost/simd/constant/smallestposval.hpp>
#include <boost/simd/constant/twotonmb.hpp>
#include <boost/simd/constant/mlogtwo2nmb.hpp>
#include <boost/simd/constant/mlog2two2nmb.hpp>
#include <boost/simd/constant/mlog10two2nmb.hpp>
#endif

namespace boost { namespace simd
{
  namespace detail
  {
    namespace bd = boost::dispatch;
    template < class A0,
               class Style ,
               class base_A0 = bd::scalar_of_t<A0>
               >
               struct logarithm{};

    template < class A0 >
    struct logarithm< A0, tag::not_simd_type, float>
    {
      using kernel_t = kernel<A0, tag::not_simd_type, float>;

      static BOOST_FORCEINLINE A0 log(A0 a0) BOOST_NOEXCEPT
      {
      #ifndef BOOST_SIMD_NO_INFINITIES
        if (BOOST_UNLIKELY(a0 == Inf<A0>())) return a0;
      #endif
        if (BOOST_UNLIKELY(is_eqz(a0))) return Minf<A0>();
      #ifdef BOOST_SIMD_NO_NANS
        if (BOOST_UNLIKELY(is_ltz(a0))) return Nan<A0>();
      #else
        if (BOOST_UNLIKELY(is_nan(a0)||is_ltz(a0))) return Nan<A0>();
      #endif
        A0 z = a0;
      #ifndef BOOST_SIMD_NO_DENORMALS
        A0 t = Zero<A0>();
        if(BOOST_UNLIKELY(abs(z) < Smallestposval<A0>()))
        {
          z *= Twotonmb<A0>();
          t = Mlogtwo2nmb<A0>();
        }
      #endif
        A0 x, fe, x2, y;
        kernel_t::log(z, fe, x, x2, y);
        y = fma(fe, Log_2lo<A0>(), y);
        y = fma(Mhalf<A0>(), x2, y);
      #ifdef BOOST_SIMD_NO_DENORMALS
        return fma(Log_2hi<A0>(), fe, x+y);
      #else
        return fma(Log_2hi<A0>(), fe, x+y+t);
      #endif
      }

      static BOOST_FORCEINLINE  A0 log2(A0 a0) BOOST_NOEXCEPT
      {
#ifndef BOOST_SIMD_NO_INFINITIES
        if (BOOST_UNLIKELY(a0 == Inf<A0>())) return a0;
#endif
        if (BOOST_UNLIKELY(is_eqz(a0))) return Minf<A0>();
#ifdef BOOST_SIMD_NO_NANS
        if (BOOST_UNLIKELY(is_ltz(a0))) return Nan<A0>();
#else
        if (BOOST_UNLIKELY(is_nan(a0)||is_ltz(a0))) return Nan<A0>();
#endif
        A0 z = a0;
#ifndef BOOST_SIMD_NO_DENORMALS
        A0 t = Zero<A0>();
        if (BOOST_UNLIKELY(abs(z) < Smallestposval<A0>()))
        {
          z *= Twotonmb<A0>();
          t = Mlog2two2nmb<A0>();
        }
#endif
        A0 x, fe, x2, y;
        kernel_t::log(z, fe, x, x2, y);
        y = fma(Mhalf<A0>(),x2, y);
        z = fma(x,Log2_em1<A0>(),y*Log2_em1<A0>());
#ifdef BOOST_SIMD_NO_DENORMALS
        return ((z+y)+x)+fe;
#else
        return ((z+y)+x)+fe+t;
#endif
      }

      static BOOST_FORCEINLINE  A0 log10(A0 a0) BOOST_NOEXCEPT
      {
#ifndef BOOST_SIMD_NO_INFINITIES
        if (BOOST_UNLIKELY(a0 == Inf<A0>())) return a0;
#endif
        if (BOOST_UNLIKELY(is_eqz(a0))) return Minf<A0>();
#ifdef BOOST_SIMD_NO_NANS
        if (BOOST_UNLIKELY(is_ltz(a0))) return Nan<A0>();
#else
        if (BOOST_UNLIKELY(is_nan(a0)||is_ltz(a0))) return Nan<A0>();
#endif
        A0 z = a0;
#ifndef BOOST_SIMD_NO_DENORMALS
        A0 t = Zero<A0>();
        if (BOOST_UNLIKELY(abs(z) < Smallestposval<A0>()))
        {
          z *= Twotonmb<A0>();
          t = Mlog10two2nmb<A0>();
        }
#endif
        A0 x, fe, x2, y;
        kernel_t::log(z, fe, x, x2, y);
        y = fma(Mhalf<A0>(), x2, y);
        std::cout << "y " << y << std::endl;
//        y = amul(y, Mhalf<A0>(), x2);
        z = (x+y)*Log10_elo<A0>();
        z = fma( y, Log10_ehi<A0>(), z);
          //        z = amul(z, y, Log10_ehi<A0>());
        z = fma(Log10_ehi<A0>(),x, z);
//        z = amul(z, x, Log10_ehi<A0>());
        z = fma(Log10_2hi<A0>(), fe, z);
//        z = amul(z, fe, Log10_2hi<A0>());
#ifdef BOOST_SIMD_NO_DENORMALS
        return fma(Log10_2lo<A0>(),fe, z);
//        return amul(z, fe, Log10_2lo<A0>());
#else
        return fma(Log10_2lo<A0>(),fe, z+t);
//        return amul(z+t, fe, Log10_2lo<A0>());
#endif
      }
    };
  }
} }
#endif
