//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/simd/function/simd/bitwise_select.hpp>
#include <boost/simd/function/simd/is_nez.hpp>
#include <boost/simd/function/simd/genmask.hpp>
#include <boost/simd/function/simd/logical_or.hpp>
#include <boost/simd/function/simd/logical_and.hpp>
#include <boost/simd/function/simd/logical_andnot.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/sdk/is_bitwise_logical.hpp>
//#include <boost/dispatch/meta/as_arithmetic.hpp>
#include <boost/utility/enable_if.hpp>


namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;

   BOOST_DISPATCH_OVERLOAD(if_else_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>,X>
                          , bs::pack_<bd::arithmetic_<A1>,X>
                          , bs::pack_<bd::arithmetic_<A1>,X>
                          )

  {
    BOOST_FORCEINLINE A1 operator()(const A0& a0, const A1& a1, const A1&a2) const BOOST_NOEXCEPT
    {
      return bitwise_select(genmask(a0), a1, a2);
    }
  };

   BOOST_DISPATCH_OVERLOAD(if_else_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>,X>
                          , bs::pack_<bd::arithmetic_<A1>,X>
                          , bs::pack_<bd::arithmetic_<A1>,X>
                          )

  {
    BOOST_FORCEINLINE A1 operator()(const A0& a0, const A1& a1, const A1&a2) const BOOST_NOEXCEPT
    {
         A1 r;
         for(unsigned int i=0; i < bs::cardinal_of<A0>::value; ++i)
         {
           r[i] =  a0[i] ? a1[i] : a2[i];
         }
         return r;

      // TODO     return if_else(is_nez(a0), a1, a2 );
    }
  };

   BOOST_DISPATCH_OVERLOAD(if_else_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bd::arithmetic_<A0>,X>
                          , bs::pack_<bs::logical_<A1>,X>
                          , bs::pack_<bs::logical_<A1>,X>
                          )

  {
    BOOST_FORCEINLINE A1 operator()(const A0& a0, const A1& a1, const A1&a2) const BOOST_NOEXCEPT
    {
      return if_else( is_nez(a0), a1, a2 );
    }
  };

   BOOST_DISPATCH_OVERLOAD(if_else_
                          , (typename A0,typename A1,typename X)
                          , bd::cpu_
                          , bs::pack_<bs::logical_<A0>,X>
                          , bs::pack_<bs::logical_<A1>,X>
                          , bs::pack_<bs::logical_<A1>,X>
                          )

  {

    template<class A0_> BOOST_FORCEINLINE
    typename enable_if< bs::is_bitwise_logical<A0_>, A1>::type
    operator()(const A0_& a0, const A1& a1, const A1&a2) const BOOST_NOEXCEPT
    {
//      typedef typename meta::as_arithmetic<A1>::type atype;
      using atype =  pack < typename A1::value_type>;
      return bitwise_cast<A1>(if_else(a0,bitwise_cast<atype>(a1),bitwise_cast<atype>(a2)));
    }

    template<class A0_> BOOST_FORCEINLINE
    typename disable_if< bs::is_bitwise_logical<A0_>, A1>::type
     operator()(const A0_& a0, const A1& a1, const A1&a2) const
    {
      return logical_or(logical_and(a1,a0),logical_andnot(a2,a0));
    }
  };


} } }

#endif

