//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_COMMON_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_COMMON_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/permutation.hpp>
#include <boost/simd/function/extract.hpp>
#include <boost/simd/constant/zero.hpp>
#include <iostream>

namespace boost { namespace simd { namespace ext
{
  namespace bd  = boost::dispatch;
  namespace bs  = boost::simd;
  namespace bsd = boost::simd::detail;

  // -----------------------------------------------------------------------------------------------
  // Unary common cases
  BOOST_DISPATCH_OVERLOAD_IF( shuffle_
                            , (int... Ps, typename A0, typename X)
                            , (brigand::bool_<A0::static_size==sizeof...(Ps)>)
                            , bs::simd_
                            , bsd::any_pattern_<bsd::pattern_<Ps...>>
                            , bs::pack_< bd::unspecified_<A0>, X >
                            )
  {
    using pattern_t = bsd::any_pattern_<bsd::pattern_<Ps...>>;

    BOOST_FORCEINLINE A0 operator()(pattern_t const&, A0 const& a0) const BOOST_NOEXCEPT
    { puts("YO DAWG COMMON UNARY");
      return do_(a0, typename A0::traits::element_range{});
    }

    template<int I> using idx = std::integral_constant<int,(I<0?0:I)>;

    template<typename... N>
    BOOST_FORCEINLINE A0 do_(A0 const& a0, brigand::list<N...> const&) const BOOST_NOEXCEPT
    {
      typename A0::value_type z = 0;
      return A0{ (Ps == -1 ? z : bs::extract<idx<Ps>::value>(a0))... };
    }
  };

  // -----------------------------------------------------------------------------------------------
  // Binary common cases
  BOOST_DISPATCH_OVERLOAD_IF( shuffle_
                            , (int... Ps, typename A0, typename X)
                            , (brigand::bool_<A0::static_size==sizeof...(Ps)>)
                            , bs::simd_
                            , bsd::any_pattern_<bsd::pattern_<Ps...>>
                            , bs::pack_< bd::unspecified_<A0>, X >
                            , bs::pack_< bd::unspecified_<A0>, X >
                            )
  {
    using pattern_t = bsd::any_pattern_<bsd::pattern_<Ps...>>;

    BOOST_FORCEINLINE A0 operator()(pattern_t const&, A0 const& a0, A0 const& a1) const BOOST_NOEXCEPT
    {
      return side(a0, a1,typename detail::which_side<Ps...>::type{});
    }

    // This binary shuffle is actually unary on a0
    BOOST_FORCEINLINE A0 side(A0 const& a0, A0 const&, detail::a0_side const&) const BOOST_NOEXCEPT
    {
      return shuffle<Ps...>(a0);
    }

    // This binary shuffle is actually unary on a1
    BOOST_FORCEINLINE A0 side(A0 const&, A0 const& a1, detail::a1_side const&) const BOOST_NOEXCEPT
    {
      using card = std::integral_constant<int,sizeof...(Ps)>;
      return shuffle<(Ps!=-1?Ps-card::value:Ps)...>(a1);
    }

    // This binary shuffle is actually binary
    BOOST_FORCEINLINE A0 side(A0 const& a0, A0 const& a1, detail::mixed_side const&) const BOOST_NOEXCEPT
    { puts("YO DAWG COMMON BINARY");
      return do_(a0,a1, typename A0::traits::element_range{});
    }

    template<int I> using idx = std::integral_constant<int,(I<0?0:(I&(A0::static_size-1)))>;

    template<typename... N> BOOST_FORCEINLINE
    A0 do_(A0 const& a0, A0 const& a1, brigand::list<N...> const&) const BOOST_NOEXCEPT
    {
      typename A0::value_type z = 0;
      return A0 { ( Ps == -1  ? z : ( Ps<A0::static_size  ? bs::extract<idx<Ps>::value>(a0)
                                                          : bs::extract<idx<Ps-A0::static_size>::value>(a1)
                                    )
                  )...
                };
    }
  };
} } }

#endif
