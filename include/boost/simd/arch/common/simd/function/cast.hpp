//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_CAST_HPP_INCLUDED

#include <boost/simd/arch/common/simd/function/cast/basic.hpp>
#include <boost/simd/arch/common/simd/function/cast/sign.hpp>

/*
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/combine.hpp>
#include <boost/simd/function/slice_low.hpp>
#include <boost/simd/function/if_allbits_else_zero.hpp>
#include <boost/simd/function/interleave.hpp>
#include <boost/simd/function/interleave_first.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/is_ltz.hpp>
#include <boost/simd/constant/zero.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  //////////////////////////////////////////////////////////////////////////////////////////////////
  // double to something
  //////////////////////////////////////////////////////////////////////////////////////////////////
  // double --> uint64
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::double_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint64_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 00" << std::endl;
      return bitwise_cast<result>(cast<bd::as_integer_t<typename A1::type, signed>>(a0));
    }
  };

 //////////////////////////////////////////////////////////////////////////////////////////////////
 // float to something
 //////////////////////////////////////////////////////////////////////////////////////////////////
 // float --> uint32
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::single_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint32_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    using siA1 = bd::as_integer_t<typename A1::type, signed>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 9" << std::endl;
      return cast<siA1>(a0).storage();
    }
  };


 //////////////////////////////////////////////////////////////////////////////////////////////////
 // (u)int64 to something
 //////////////////////////////////////////////////////////////////////////////////////////////////

  // (u)int64 --> int32
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints64_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int32_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 1" << std::endl;
      using p32 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(p32(a0.storage()), Zero<p32>()));
    }
  };

  // (u)int64 --> uint32
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints64_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint32_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 2" << std::endl;
      using pu32 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(pu32(a0.storage()), Zero<pu32>()));
    }
  };

//  //////////////////////////////////////////////////////////////////////////////////////////////////
//  // int32 to something
//  //////////////////////////////////////////////////////////////////////////////////////////////////

  // (u)int32 --> int64
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints32_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int64_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 3" << std::endl;
       using p64 = pack<typename A1::type, A0::static_size/2>;
       auto x = interleave(a0, if_allbits_else_zero(is_ltz(a0)));
       return combine(p64(x[0].storage()), p64(x[1].storage()));
    }
  };

  // (u)int32 --> uint64
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints32_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint64_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 4" << std::endl;
       using pu64 = pack<typename A1::type, A0::static_size/2>;
       auto x = interleave(a0, if_allbits_else_zero(is_ltz(a0)));
       return combine(pu64(x[0].storage()), pu64(x[1].storage()));
    }
  };

  // (u)int32 --> int16
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints32_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int16_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 5" << std::endl;
      using p16 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(p16(a0.storage()), Zero<p16>()));
    }
  };

  // (u)int32 --> uint16
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints32_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint16_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 6" << std::endl;
      using pu16 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(pu16(a0.storage()), Zero<pu16>()));
    }
  };

 //////////////////////////////////////////////////////////////////////////////////////////////////
 // (u)int16 to something
 //////////////////////////////////////////////////////////////////////////////////////////////////

  // (u)int16 --> int32
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints16_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int32_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 7" << std::endl;
       using p32 = pack<typename A1::type, A0::static_size/2>;
       auto x = interleave(a0, if_allbits_else_zero(is_ltz(a0)));
       return combine(p32(x[0].storage()), p32(x[1].storage()));
    }
  };
  // (u)int16 --> uint32
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints16_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint32_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 8" << std::endl;
       using pu32 = pack<typename A1::type, A0::static_size/2>;
       auto x = interleave(a0, if_allbits_else_zero(is_ltz(a0)));
       return combine(pu32(x[0].storage()), pu32(x[1].storage()));
    }
  };

  // (u)int16 --> int8
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints16_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int8_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 9" << std::endl;
      using p8 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(bitwise_cast<p8>(a0), Zero<p8>()));
    }
  };

  // (u)int16 --> uint8
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints16_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint8_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 10" << std::endl;
      using pu8 = pack<typename A1::type, A0::static_size*2>;
      return slice_low( deinterleave_first(pu8(a0.storage()), Zero<pu8>()));
    }
  };

 //////////////////////////////////////////////////////////////////////////////////////////////////
 // (u)int8 to something
 //////////////////////////////////////////////////////////////////////////////////////////////////


  // int8 --> int16
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::int8_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int16_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "YYYYtarget " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 11" << std::endl;
      using p16 = pack<typename A1::type, A0::static_size/2>;
      auto x = interleave(if_allbits_else_zero(is_ltz(a0)),a0);

      return combine(bitwise_cast<p16>(x[0]), bitwise_cast<p16>(x[1]));
    }
  };

  // uint8 --> int16
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::uint8_<A0>, X>
                          , bd::target_< bd::scalar_< bd::int16_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "XXXtarget " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 11" << std::endl;
      using p16 = pack<typename A1::type, A0::static_size/2>;
      auto x = interleave(Zero<A0>(),a0);

      return combine(bitwise_cast<p16>(x[0]), bitwise_cast<p16>(x[1]));
    }
  };

  // (u)int8 --> uint16
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                          , (typename A0, typename A1, typename X)
                          , (detail::is_native<X>)
                          , bd::cpu_
                          , bs::pack_<bd::ints8_<A0>, X>
                          , bd::target_< bd::scalar_< bd::uint16_<A1> > >
                         )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 12" << std::endl;
      using pu16 = pack<typename A1::type, A0::static_size/2>;
      auto x = interleave(a0, if_allbits_else_zero(is_ltz(a0)));
      return combine(bitwise_cast<pu16>(x[0]), bitwise_cast<pu16>(x[1]));
    }
  };

  // type8 --> type32  and type16 -> type64
  BOOST_DISPATCH_OVERLOAD_IF ( cast_
                             , (typename A0, typename A1, typename X)
                             , (detail::sizeof_ratio_is_greater<typename A1::type, typename A0::value_type, 2>)
                             , bd::cpu_
                             , bs::pack_<bd::integer_<A0>, X>
                             , bd::target_< bd::scalar_< bd::integer_<A1> > >
                             )
  {
    using result = typename A0::template rebind<typename A1::type>;
    BOOST_FORCEINLINE result operator() ( const A0 & a0, A1 const& ) const BOOST_NOEXCEPT
    {
      std::cout << "target " << detail::type_id<typename A1::type>() <<  " from " << detail::type_id<typename A0::value_type>() <<  " in 13" << std::endl;
      using sA1 = typename A1::type;
      using sdA1 = bd::as_integer_t< bd::downgrade_t<sA1>, signed>;
      return cast<sA1>(cast<sdA1>(a0));
    }
  };
} } }
*/

#endif
