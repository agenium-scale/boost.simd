//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_REVERSE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_REVERSE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/arch/common/simd/function/shuffle/pattern/reverse.hpp>
#include <boost/simd/function/reverse.hpp>

namespace boost { namespace simd { namespace ext
{
  // -----------------------------------------------------------------------------------------------
  // Unary reverse macro
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename Ps, typename A0, typename X)
                          , bd::cpu_
                          , bs::reverse_pattern<0,Ps>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( Ps::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(Ps const&, A0 const& a0) const BOOST_NOEXCEPT
    {
      return reverse(a0);
    }
  };

   // -----------------------------------------------------------------------------------------------
  // Binary common cases
  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename Ps, typename A0, typename X)
                          , bd::cpu_
                          , bs::reverse_pattern<0,Ps>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( Ps::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(Ps const&, A0 const& a0, A0 const&) const BOOST_NOEXCEPT
    {
      return reverse(a0);
    }
  };

  BOOST_DISPATCH_OVERLOAD ( shuffle_
                          , (typename Ps, typename A0, typename X)
                          , bd::cpu_
                          , bs::reverse_pattern<1,Ps>
                          , bs::pack_< bd::unspecified_<A0>, X >
                          , bs::pack_< bd::unspecified_<A0>, X >
                          )
  {
    static_assert ( Ps::static_size == std::size_t(A0::static_size)
                  , "boost::simd::shuffle - Invalid number of permutation indices"
                  );

    BOOST_FORCEINLINE
    A0 operator()(Ps const&, A0 const& , A0 const& a1) const BOOST_NOEXCEPT
    {
      return reverse(a1);
    }
  };
} } }

#endif
