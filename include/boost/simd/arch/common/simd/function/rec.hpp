//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_REC_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/bitwise_or.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/if_one_else_zero.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/is_denormal.hpp>
#include <boost/simd/function/is_eqz.hpp>
#include <boost/simd/function/refine_rec.hpp>
#include <boost/simd/function/abs.hpp>
#include <boost/simd/function/fast.hpp>
#include <boost/simd/function/raw.hpp>
#include <boost/simd/constant/valmax.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/mzero.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/inveps.hpp>


namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF( rec_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::uint_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
    {
      return if_else_allbits(a0, if_one_else_zero(a0 == One<A0>()));
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( rec_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::int_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a0) const BOOST_NOEXCEPT
    {
      return if_else(a0, if_else_zero(bs::abs(a0) == One<A0>(), a0), Valmax<A0>());
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF( rec_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::floating_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()( const A0& a00) const BOOST_NOEXCEPT
    {
      A0 a0 = a00;
      #ifndef BOOST_SIMD_NO_DENORMALS
      auto is_den = is_denormal(a00);
      auto any_is =  any(is_den);
      A0 fac;
      if (BOOST_UNLIKELY((any_is)))
      {
        fac = if_else(is_den, Inveps<A0>(), One<A0>());
        a0 *=  fac;
      }

      #endif
      a0 =  if_else(is_eqz(a0),
                    bitwise_or(a0, Inf<A0>()),
                    fast_(rec)(a0)
                   );
      #ifndef BOOST_SIMD_NO_INFINITIES
      a0 = if_else(is_inf(a00),
                      bitwise_and(a00, Zero<A0>()),
                      a0
                     );
      #endif
      #ifndef BOOST_SIMD_NO_DENORMALS
      if (BOOST_UNLIKELY((any_is))) a0 *= fac;
      #endif
      return a0;
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Single precision fast_rec is computable from the raw_rec + 1 NR step
  BOOST_DISPATCH_OVERLOAD_IF( rec_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::fast_tag
                            , bs::pack_<bd::single_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()(bs::fast_tag const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return  refine_rec(a0, refine_rec(a0, raw_(rec)(a0) ));
    }
  };


  BOOST_DISPATCH_OVERLOAD_IF( rec_
                            , (typename A0, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::fast_tag
                            , bs::pack_<bd::double_<A0>, X>
                            )
  {
    BOOST_FORCEINLINE A0 operator()(bs::fast_tag const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return refine_rec(a0, refine_rec(a0, refine_rec(a0, raw_(rec)(a0) )));
    }
  };




  BOOST_DISPATCH_OVERLOAD_IF ( rec_
                             , (typename T, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::fast_tag
                             , bs::pack_<bd::unspecified_<T>, X>
                             )
  {
    BOOST_FORCEINLINE T operator()(const fast_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF ( rec_
                             , (typename T, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::raw_tag
                             , bs::pack_<bd::unspecified_<T>, X>
                             )
  {
    BOOST_FORCEINLINE T operator()(const raw_tag &, T const& a) const BOOST_NOEXCEPT
    {
      return rec(a);
    }
  };
} } }

#endif
