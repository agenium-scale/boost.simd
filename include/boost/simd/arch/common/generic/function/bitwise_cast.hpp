//==================================================================================================
/*!
  @file

  Copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITWISE_CAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_BITWISE_CAST_HPP_INCLUDED

#include <boost/dispatch/as.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <cstring>

namespace boost { namespace simd { namespace ext
{
 namespace bd = boost::dispatch;
#ifdef BOOST_SIMD_NO_STRICT_ALIASING

  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::unspecified_<A0> >
                          , bd::target_< bd::generic_< bd::unspecified_<A1> > >
                          )
  {
    using result_t = typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const&
                                         , typename std::enable_if< sizeof(A0)
                                          == sizeof(typename A1::type) >::type* = 0
                                         ) const BOOST_NOEXCEPT
    {
      return reinterpret_cast<result_t>(a0);
    }
  };

#else

  BOOST_DISPATCH_OVERLOAD ( bitwise_cast_
                          , (typename A0, typename A1)
                          , bd::cpu_
                          , bd::generic_< bd::unspecified_<A0> >
                          , bd::target_<  bd::generic_< bd::unspecified_<A1> > >
                          )
  {
    using result_t =  typename A1::type;

    static_assert
    ( (sizeof(A0) == sizeof(typename A1::type))
    , "boost.simd target is not same size as source in bitwise_cast"
    );

    BOOST_FORCEINLINE result_t operator()(A0 const& a0, A1 const&
                                         , typename std::enable_if< sizeof(A0)
                                          == sizeof(typename A1::type) >::type* = 0
                                         ) const BOOST_NOEXCEPT
    {
      result_t that;
      std::memcpy(&that, &a0, sizeof(a0));
      return that;
    }
  };

#endif

} } }

#endif
