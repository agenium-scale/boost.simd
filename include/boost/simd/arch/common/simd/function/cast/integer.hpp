//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CAST_INTEGER_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CAST_INTEGER_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/dispatch/as.hpp>
#include <boost/simd/detail/traits.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/function/if_allbits_else_zero.hpp>
#include <boost/simd/function/deinterleave.hpp>
#include <boost/simd/function/interleave.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/function/slice.hpp>
#include <boost/simd/constant/zero.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  // -----------------------------------------------------------------------------------------------
  // downward cast with sign
  template<typename A0, typename A1>
  struct downward_cast
  {
    using result = typename A0::template rebind<typename A1::type>;
    static BOOST_FORCEINLINE result do_(const A0& a0 ) BOOST_NOEXCEPT
    {
      using sub = pack<typename A1::type, A0::static_size*2>;

      #if BOOST_ENDIAN_BIG_BYTE
      auto x = deinterleave_second(bitwise_cast<sub>(a0), Zero<sub>());
      #else
      auto x = deinterleave_first(bitwise_cast<sub>(a0), Zero<sub>());
      #endif

      return slice_low( x );
    }
  };

  // -----------------------------------------------------------------------------------------------
  // upward cast with sign
  template<typename A0, typename A1, bool Sign>
  struct upward_cast
  {
    using result = typename A0::template rebind<typename A1::type>;
    static BOOST_FORCEINLINE result do_(const A0& a0 ) BOOST_NOEXCEPT
    {
      using upw = pack<typename A1::type, A0::static_size/2>;

      #if BOOST_ENDIAN_BIG_BYTE
      auto x = interleave(if_allbits_else_zero(is_ltz(a0)),a0);
      #else
      auto x = interleave(a0,if_allbits_else_zero(is_ltz(a0)));
      #endif

      return combine(bitwise_cast<upw>(x[0]),bitwise_cast<upw>(x[1]));
    }
  };

  template<typename A0, typename A1>
  struct upward_cast<A0, A1, false>
  {
    using result = typename A0::template rebind<typename A1::type>;
    static BOOST_FORCEINLINE result do_(const A0& a0 ) BOOST_NOEXCEPT
    {
      using upw = pack<typename A1::type, A0::static_size/2>;

      #if BOOST_ENDIAN_BIG_BYTE
      auto x = interleave(Zero<A0>(),a0);
      #else
      auto x = interleave(a0,Zero<A0>());
      #endif

      return combine(bitwise_cast<upw>(x[0]),bitwise_cast<upw>(x[1]));
    }
  };
} } }

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  // -----------------------------------------------------------------------------------------------
  // int8 -> ints16
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints8_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints16_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return detail::upward_cast<A0, A1, std::is_signed<typename A0::value_type>::value>::do_(a0);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // int16 -> ints32
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints16_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints32_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return detail::upward_cast<A0, A1, std::is_signed<typename A0::value_type>::value>::do_(a0);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // int32 -> ints64
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints32_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints64_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return detail::upward_cast<A0, A1, std::is_signed<typename A0::value_type>::value>::do_(a0);
    }
  };

  // -----------------------------------------------------------------------------------------------
  // int64 -> ints32
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints64_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints32_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {puts("64->32");
      return detail::downward_cast<A0,A1>::do_( a0 );
    }
  };

  // -----------------------------------------------------------------------------------------------
  // int32 -> ints16
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints32_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints16_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return detail::downward_cast<A0,A1>::do_( a0 );
    }
  };

  // -----------------------------------------------------------------------------------------------
  // int16 -> ints8
  BOOST_DISPATCH_OVERLOAD_IF( cast_
                            , (typename A0, typename A1, typename X)
                            , (detail::is_native<X>)
                            , bd::cpu_
                            , bs::pack_<bd::ints16_<A0>, X>
                            , bd::target_< bd::scalar_< bd::ints8_<A1> > >
                            )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return detail::downward_cast<A0,A1>::do_( a0 );
    }
  };
} } }

#endif
