//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_BROADCAST_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_BROADCAST_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/arch/common/simd/function/shuffle/pattern/broadcast.hpp>
#include <boost/simd/function/broadcast.hpp>

namespace boost { namespace simd { namespace ext
{
  // -----------------------------------------------------------------------------------------------
  // Unary identity macro
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int P0, typename P, typename A0, typename X)
                          , bd::cpu_
                          , bs::broadcast_pattern<P0, P>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( P::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(P const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return broadcast<P0>(a0);
    }
  };

   // -----------------------------------------------------------------------------------------------
  // Binary common cases
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (int P0, typename P, typename A0, typename X)
                          , bd::cpu_
                          , bs::broadcast_pattern<P0, P>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( P::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(P const&, A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return do_(a0,a1, brigand::bool_<(P0 < A0::static_size)>{});
    }

    BOOST_FORCEINLINE
    A0 do_(A0 const& a0, A0 const&, std::true_type const&) const BOOST_NOEXCEPT
    {
      return broadcast<P0>(a0);
    }

    BOOST_FORCEINLINE
    A0 do_(A0 const&, A0 const& a1, std::false_type const&) const BOOST_NOEXCEPT
    {
      return broadcast<P0-A0::static_size>(a1);
    }
  };
} } }

#endif
