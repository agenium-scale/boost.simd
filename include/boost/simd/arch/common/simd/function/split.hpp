//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLIT_HPP_INCLUDED

// #include <boost/simd/pack.hpp>
// #include <boost/simd/function/simd/combine.hpp>
// #include <boost/simd/function/simd/extract.hpp>
// #include <boost/simd/function/simd/split_high.hpp>
// #include <boost/simd/function/simd/split_low.hpp>

// namespace boost { namespace simd { namespace ext
// {
//    namespace bd = boost::dispatch;
//    namespace bs = boost::simd;
//    BOOST_DISPATCH_OVERLOAD_IF(split_

//                              , (typename A0, typename A1, typename X, typename Y)
//                              , bd::cpu_
//                              , bs::pack_<bd::arithmetic_<A0>, X>
//                              , bs::pack_<bd::arithmetic_<A1>, X>
//                              , bs::pack_<bd::arithmetic_<A1>, X>
//                              )
//    {
//       using result = ;
//      BOOST_FORCEINLINE result operator()(A0 const& a0,A1& a1, A1& a2) const
//       {
//         a1 = split_low(a0);
//         a2 = split_high(a0);
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD(split_

//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bd::arithmetic_<A0>, X>
//                           )
//    {
//   using  = ;
//       BOOST_FORCEINLINE result operator()( const A0& a0) const BOOST_NOEXCEPT
//       {
//         return eval(a0, simd::meta::is_upgradable<A0>());
//       }
//       BOOST_FORCEINLINE result eval2(A0 const& a0, boost::mpl::true_) const
//       {
//         typename simd::meta::vector_of< base_t
//                                       , A0::static_size/2
//                                       >::type a00,a01;
//         split(a0, a00, a01);
//         return bs::combine(a00,a01);
//       }
//       BOOST_FORCEINLINE result eval2(A0 const& a0, boost::mpl::false_) const
//       {
//         return make<result>( static_cast<base_t>( extract<0>(a0) )
//                                 , static_cast<base_t>( extract<1>(a0) )
//                                 );
//       }
//       BOOST_FORCEINLINE result eval(A0 const& a0, boost::mpl::false_) const
//       {
//         return a0;
//       }
//       BOOST_FORCEINLINE result eval(A0 const& a0, boost::mpl::true_) const
//       {
//         return eval2(a0, boost::mpl::bool_<(A0::static_size>=4)>());
//       }
//    };

// } } }

#endif

