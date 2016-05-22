//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_DEINTERLEAVE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_DEINTERLEAVE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/shuffle.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    template<int I, int C, int ZP> struct deinterleave_checker;
    template<int I, int C> struct deinterleave_checker<I,C,+1> : brigand::bool_<(I>=C)> {};
    template<int I, int C> struct deinterleave_checker<I,C,+0> : std::true_type {};
    template<int I, int C> struct deinterleave_checker<I,C,-1> : brigand::bool_<(I<C)> {};

    // ---------------------------------------------------------------------------------------------
    // Generate variosu deitnerleave_* based pattern for later comparison
    template<int FirstSecond, int ZeroPosition, typename Rng> struct deinterleaved;

    template<int I, int Z, typename... Rng>
    struct deinterleaved<I, Z, brigand::list<Rng...>>
    {
      template<int N> using test = deinterleave_checker<N,sizeof...(Rng)/2,Z>;
      using type = brigand::integral_list<int,(test<Rng::value>::value ? (2*Rng::value+I) : -1)...>;
    };

    // ---------------------------------------------------------------------------------------------
    // Check if pattern performs some deinterleaving operations (0=first,1=second)
    template<int Type, typename Base, typename Pattern> struct deinterleave_status
    {
      // Do I perform a full deinterleave or do I put zero before or after the first half ?
      using fwd = std::is_same<typename deinterleaved<Type,+1,Pattern>::type,Base>;
      using reg = std::is_same<typename deinterleaved<Type,+0,Pattern>::type,Base>;
      using bwd = std::is_same<typename deinterleaved<Type,-1,Pattern>::type,Base>;

      using type  = std::integral_constant< int
                                          , (reg::value*1) + (fwd::value*2) + (bwd::value*4)
                                          >;
    };

    // ---------------------------------------------------------------------------------------------
    // Check if pattern performs some deinterleaving operations (0=first,1=second)
    template<int B, int... Ps> struct is_deinterleave
    {
      using base    = brigand::integral_list<int,Ps...>;
      using lrange  = brigand::range        <int,0                , sizeof...(Ps)/2 >;
      using hrange  = brigand::range        <int,sizeof...(Ps)/2  , sizeof...(Ps)   >;
      using range   = brigand::range        <int,0                , sizeof...(Ps)   >;
      using rrange  = brigand::append<hrange,lrange>;

      using fwd = typename deinterleave_status<B,base,range>::type;
      using bwd = typename deinterleave_status<B,base,rrange>::type;

      using type  = brigand::bool_<fwd::value || bwd::value>;
    };
  }

  // -----------------------------------------------------------------------------------------------
  // Deinterleaving pattern hierarchy
  template<int Idx, int Fwd, int Bwd, typename P>
  struct deinterleave_pattern : detail::any_pattern_<deinterleave_pattern<Idx,Fwd,Bwd,P>>
  {
    static const std::size_t static_size = P::static_size;
    using parent = detail::any_pattern_<deinterleave_pattern<Idx,Fwd,Bwd,P>>;
  };
} }

// -------------------------------------------------------------------------------------------------
// Hierarchize deinterleaving patterns
namespace boost { namespace dispatch { namespace ext
{
  // deinterleave_first patterns
  template<int... Ps,typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_<Ps...>,Origin
                          , typename std::enable_if < simd::detail
                                                          ::is_deinterleave<0,Ps...>::type::value
                                                    >::type
                          >
  {
    using fwd = typename simd::detail::is_deinterleave<0,Ps...>::fwd;
    using bwd = typename simd::detail::is_deinterleave<0,Ps...>::bwd;
    using type = boost::simd::deinterleave_pattern<1,fwd::value,bwd::value,bsd::pattern_<Ps...>>;
  };

  // deinterleave_second patterns
  template<int... Ps,typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_<Ps...>,Origin
                          , typename std::enable_if < simd::detail
                                                          ::is_deinterleave<1,Ps...>::type::value
                                                    >::type
                          >
  {
    using fwd = typename simd::detail::is_deinterleave<1,Ps...>::fwd;
    using bwd = typename simd::detail::is_deinterleave<1,Ps...>::bwd;

    using type = boost::simd::deinterleave_pattern<2,fwd::value,bwd::value,bsd::pattern_<Ps...>>;
  };
} } }

#endif
