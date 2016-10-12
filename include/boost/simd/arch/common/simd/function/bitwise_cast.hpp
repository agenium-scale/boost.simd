//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_CAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_BITWISE_CAST_HPP_INCLUDED

#include <boost/simd/detail/dispatch/as.hpp>
#include <boost/simd/detail/dispatch/hierarchy.hpp>
#include <boost/simd/logical.hpp>
#include <cstring>
#include <type_traits>
#include <boost/simd/detail/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <boost/simd/detail/traits.hpp>

namespace boost { namespace simd { namespace ext
{
 namespace bd = boost::dispatch;
 namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_IF ( bitwise_cast_
                             , (typename A0, typename A1, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::pack_< bd::arithmetic_<A0>, X>
                             , bd::target_< bs::pack_< bs::logical_<A1>, X> >
                             )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      //      std::cout << "ARITHMETIC --> LOGICAL" << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      return a0.storage();
    }
  };

  BOOST_DISPATCH_OVERLOAD_IF ( bitwise_cast_
                             , (typename A0, typename A1, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::pack_< bs::logical_<A0>, X >
                             , bd::target_< bs::pack_< bd::arithmetic_<A1>, X > >
                             )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return do_(a0, typename std::is_same<A0, result_t>::type());
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
    {
//      std::cout << "LOGICAL --> UNSPECIFIED" << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      return a0.storage();
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
    {
      return a0;
    }

  };

  BOOST_DISPATCH_OVERLOAD_IF ( bitwise_cast_
                             , (typename A0, typename A1, typename X)
                             , (detail::is_native<X>)
                             , bd::cpu_
                             , bs::pack_< bs::logical_<A0>, X >
                             , bd::target_< bs::pack_< bs::logical_<A1>, X > >
                             )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const& ) const BOOST_NOEXCEPT
    {
      return do_(a0, typename std::is_same<A0, result_t>::type());
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::false_type ) const BOOST_NOEXCEPT
    {
//     std::cout << "LOGICAL --> UNSPECIFIED" << type_id<A0>() << " --> " << type_id<result_t>() << std::endl;
      return a0.storage();
    }

    BOOST_FORCEINLINE result_t do_(A0 const& a0, std::true_type const& ) const BOOST_NOEXCEPT
    {
      return a0;
    }

  };

} } }

#endif
