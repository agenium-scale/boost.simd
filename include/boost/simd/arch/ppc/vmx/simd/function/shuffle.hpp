//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_PPC_VMX_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/sdk/meta/cardinal_of.hpp>
#include <boost/simd/swar/function/details/perm.hpp>
#include <boost/simd/swar/function/details/shuffler.hpp>
#include <boost/simd/swar/function/details/topology.hpp>
#include <boost/simd/swar/function/simd/vmx/altivec/details/permutation.hpp>
#include <boost/simd/function/simd/bitwise_cast.hpp>
#include <boost/simd/function/simd/make.hpp>
#include <boost/simd/detail/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
   namespace bd = boost::dispatch;
   namespace bs = boost::simd;
   BOOST_DISPATCH_OVERLOAD( shuffle_
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_>
                          , target_< unspecified_<P>>
                          )
   {
      using result = T;
     BOOST_FORCEINLINE result operator()(T const& a0,P const&) const
      {
        typename P::type p;
        return detail::shuffler< detail::default_matcher
                                , detail::vmx_permute<meta::cardinal_of<T>::value>
                                , meta::cardinal_of<T>::value
                                , 16
                                >::process(a0,p);
      }
   };

   BOOST_DISPATCH_OVERLOAD( shuffle_
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_>
                          , bs::pack_< bd::arithmetic_<T>, bs::vmx_>
                          , target_< unspecified_<P>>
                          )
   {
      using result = T;
     result operator()(T const& a0,T const& a1, P const&) const
      {
        typename P::type p;
        return detail::shuffler< detail::default_matcher
                                , detail::vmx_permute<meta::cardinal_of<T>::value>
                                , meta::cardinal_of<T>::value
                                , 16
                                >::process(a0,a1,p);
      }
   };

} } }

#endif
