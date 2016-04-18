//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_GROUP_HPP_INCLUDED
#include <boost/simd/detail/overload.hpp>

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/deinterleave_first.hpp>
#include <boost/simd/function/simd/deinterleave_second.hpp>
#include <boost/simd/function/simd/extract.hpp>
#include <boost/simd/function/simd/slice.hpp>
#include <boost/dispatch/meta/downgrade.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD(group_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
     using base_t = bd::downgrade_t<typename A0::value_type>; //I smell a problem here
      static const std::size_t M = 2*bs::cardinal_of<base_t>::value;
      using result =  pack<base_t, M>;
      BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
      {
        return eval(a0, boost::is_same<A0, result>());
      }
      BOOST_FORCEINLINE
      result eval(A0 const& a0, std::false_type const&) const
      {
        return eval2(a0, brigand::bool_<(A0::static_size>=4)>());
      }
      BOOST_FORCEINLINE
      result eval(A0 const& a0, std::true_type const&) const
      {
        return a0;
      }
      BOOST_FORCEINLINE
      result eval2(A0 const& a0, std::true_type const&) const
      {
        pack<base_t, bs::cardinal_of<A0>::value/2> a00, a01;
        bs::slice(a0,a00,a01);
        return bs::group(a00,a01);
      }
      BOOST_FORCEINLINE
      result eval2(A0 const& a0, std::false_type const&) const
      {
        return { static_cast<base_t>( a0[0] )
               , static_cast<base_t>( a0[1])
               };
      }
   };

   BOOST_DISPATCH_OVERLOAD(group_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          , bs::pack_<bd::arithmetic_<A0>, X>
                          )
   {
      using result = bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        static const size_t size = bs::cardinal_of<A0>::value;
        using sR = bd::scalar_of_t<result>;
        result that;
        for(size_t i = 0; i != size; ++i)
          that[i]      = static_cast<sR>(a0[i]);
        for(size_t i = 0; i != size; ++i)
          that[i+size] = static_cast<sR>(a1[i]);
        return that;
      }
   };

   BOOST_DISPATCH_OVERLOAD(group_
                          , (typename A0, typename X)
                          , bd::cpu_
                          , bs::pack_<bd::integer_<A0>, X>
                          , bs::pack_<bd::integer_<A0>, X>
                          )
   {
      using result = bd::downgrade_t<A0>;
      BOOST_FORCEINLINE result operator()( const A0& a0, const A0& a1) const BOOST_NOEXCEPT
      {
        #ifdef BOOST_LITTLE_ENDIAN
        return deinterleave_first(bitwise_cast<result>(a0), bitwise_cast<result>(a1));
        #else
        return deinterleave_second(bitwise_cast<result>(a0), bitwise_cast<result>(a1));
        #endif
      }
   };

} } }
#endif

