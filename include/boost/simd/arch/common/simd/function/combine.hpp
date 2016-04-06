//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMBINE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_COMBINE_HPP_INCLUDED

// #include <boost/simd/sdk/hierarchy/simd.hpp>
// #include <boost/simd/sdk/is_bitwise_logical.hpp>
// #include <boost/simd/sdk/meta/iterate.hpp>
// #include <boost/simd/sdk/simd/meta/vector_of.hpp>
// #include <boost/simd/sdk/meta/is_bitwise_logical.hpp>
// #include <boost/simd/sdk/meta/iterate.hpp>
// #include <boost/simd/sdk/simd/meta/vector_of.hpp>
// #include <boost/simd/function/simd/bitwise_cast.hpp>
// #include <boost/simd/function/simd/extract.hpp>
// #include <boost/simd/function/simd/insert.hpp>
// #include <boost/dispatch/meta/fusion.hpp>
// #include <boost/fusion/at.hpp>
// #include <boost/fusion/size.hpp>
// #include <boost/mpl/sizeof.hpp>

// namespace boost { namespace simd { namespace ext
// {
//    namespace bd = boost::dispatch;
//    namespace bs = boost::simd;
//    BOOST_DISPATCH_OVERLOAD(combine_

//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bd::unspecified_<A0>, X>
//                           , bs::pack_<bd::unspecified_<A0>, X>
//                           )
//    {
//   using  = ;
//      BOOST_FORCEINLINE result operator()(A0 const& a0, A0 const& a1) const
//       {
//         result that;
//         for(size_t i=0; i!=A0::static_size; ++i)
//         {
//           that[i]                 = a0[i];
//           that[i+A0::static_size] = a1[i];
//         }
//         return that;
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD(combine_

//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bs::logical_<A0>, X>
//                           , bs::pack_<bs::logical_<A0>, X>
//                           )
//    {
//   using  = ;
//      BOOST_FORCEINLINE result operator()(A0 const& a0, A0 const& a1) const
//       {
//         return eval( a0, a1
//                    , boost::mpl::bool_<   simd::meta::is_bitwise_logical<A0>::value
//                                       &&  simd::meta::is_bitwise_logical<result>::value
//                                       >()
//                    );
//       }
//       BOOST_FORCEINLINE result eval(A0 const& a0, A0 const& a1, boost::mpl::true_ const&) const
//       {
//         using type = A0;
//         return bitwise_cast<result>( bs::combine( bitwise_cast<type>(a0)
//                                                               , bitwise_cast<type>(a1)
//                                                               )
//                                         );
//       }
//       BOOST_FORCEINLINE result eval(A0 const& a0, A0 const& a1, boost::mpl::false_ const&) const
//       {
//         result that;
//         for(size_t i=0; i!=A0::static_size; ++i)
//         {
//           that[i]                 = a0[i];
//           that[i+A0::static_size] = a1[i];
//         }
//         return that;
//       }
//    };

//    BOOST_DISPATCH_OVERLOAD(combine_

//                           , (typename A0, typename X)
//                           , bd::cpu_
//                           , bs::pack_<bd::fusion_<A0>, X>
//                           , bs::pack_<bd::fusion_<A0>, X>
//                           )
//    {
//   using  = ;
//        template<int I> BOOST_FORCEINLINE void operator()() const
//         {
//           boost::fusion::at_c<I>(that) = bs::combine ( boost::fusion::at_c<I>(a0)
//                                                               , boost::fusion::at_c<I>(a1)
//                                                               );
//         }
//         result& that;
//         A0 const& a0;
//         A0 const& a1;
//         private:
//         impl& operator=(impl const&);
//       };
//       {
//         static const int N = fusion::result_of::size<A0>::type::value;
//         result that;
//         meta::iterate<N>(impl(that, a0, a1));
//         return that;
//       }
//    };

// } } }

#endif

