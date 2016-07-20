//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_ODD_EVEN_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_ODD_EVEN_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/shuffle.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    // Generate values based on what we wait, a0,a1 or zero
    template<int I, int C, int M> struct oe_value;

    // awaits 0
    template<int I, int C> struct oe_value<I,C,0> : std::integral_constant<int,-1> {};

    // awaits a0
    template<int I, int C> struct oe_value<I,C,1> : std::integral_constant<int,I> {};

    // awaits a1
    template<int I, int C> struct oe_value<I,C,2> : std::integral_constant<int,I+C-1> {};

    // ---------------------------------------------------------------------------------------------
    // Generate interleave_odd/even pattern for later comparisons
    template<int OddEven, typename Rng, typename A0, typename A1>
    struct odd_even;

    template<int OE, typename... Rng, typename A0, typename A1>
    struct odd_even<OE, brigand::list<Rng...>, A0, A1>
    {
      using card = std::integral_constant<int,sizeof...(Rng)/2>;
      using type = brigand::integral_list<int , (( Rng::value%2  ? A0<Rng::value,card::value>::value
                                                                : A1<Rng::value,card::value>::value
                                                )+OE)...
                                          >;
    };

    // ---------------------------------------------------------------------------------------------
    // Check if pattern performs some interleaving operations (0=first,1=second)
    template<int Type, typename Base, typename Pattern> struct odd_even_status
    {
      // Do I perform a full deinterleave or do I put zero before or after the first half ?


      using type  = std::integral_constant< int
                                          , (reg::value*1) + (fwd::value*2) + (bwd::value*4)
                                          >;
    };

    // ---------------------------------------------------------------------------------------------
    // Check if pattern performs some deinterleaving operations (0=first,1=second)
    template<int B, int... Ps> struct is_odd_even
    {
      using base    = brigand::integral_list<int,Ps...>;
      using range   = brigand::range        <int,0                , sizeof...(Ps)   >;

      using fwd = typename odd_even_status<B,base,range>::type;
      using bwd = typename odd_even_status<B,base,rrange>::type;

      using type  = brigand::bool_<fwd::value || bwd::value>;
    };
  }

  // -----------------------------------------------------------------------------------------------
  // Deinterleaving pattern hierarchy
  template<int Idx, int Fwd, int Bwd, typename P>
  struct odd_even_pattern : detail::any_pattern_<odd_even_pattern<Idx,Fwd,Bwd,P>>
  {
    static const std::size_t static_size = P::static_size;
    using parent = detail::any_pattern_<odd_even_pattern<Idx,Fwd,Bwd,P>>;
  };
} }

// -------------------------------------------------------------------------------------------------
// Hierarchize odd/even patterns
namespace boost { namespace dispatch { namespace ext
{
  // interleave_odd patterns
  template<int... Ps,typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_<Ps...>,Origin
                          , typename std::enable_if < simd::detail
                                                          ::is_odd_even<0,Ps...>::type::value
                                                    >::type
                          >
  {
    using fwd = typename simd::detail::is_deinterleave<0,Ps...>::fwd;
    using bwd = typename simd::detail::is_deinterleave<0,Ps...>::bwd;
    using type = boost::simd::odd_even_pattern<1,fwd::value,bwd::value,bsd::pattern_<Ps...>>;
  };

  // interleave_even patterns
  template<int... Ps,typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_<Ps...>,Origin
                          , typename std::enable_if < simd::detail
                                                          ::is_odd_even<1,Ps...>::type::value
                                                    >::type
                          >
  {
/*    using fwd = typename simd::detail::is_deinterleave<1,Ps...>::fwd;
    using bwd = typename simd::detail::is_deinterleave<1,Ps...>::bwd;*/

    using type = boost::simd::odd_even_pattern<2,fwd::value,bwd::value,bsd::pattern_<Ps...>>;
  };
} } }

#endif
