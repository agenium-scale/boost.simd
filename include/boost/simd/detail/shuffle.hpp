//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_SHUFFLE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>

namespace boost { namespace simd
{
  // -----------------------------------------------------------------------------------------------
  // normalized const-expr pattern holder - prevent MSVC 2015 shenanigans
  template<int (*M)(int,int)> struct pattern {};

  namespace detail
  {
    // -----------------------------------------------------------------------------------------------
    // normalized permutation pattern holder - also acts as its own hierarchy
    template<int... Ps> struct pattern_ : boost::dispatch::unspecified_<pattern_<Ps...>>
    {
      using parent = boost::dispatch::unspecified_<pattern_<Ps...>>;
    };

    // -----------------------------------------------------------------------------------------------
    // take a meta-function class and build a pattern
    template<typename M, typename C, typename L> struct make_meta_pattern;

    template<typename M, typename C, typename... Ps>
    struct make_meta_pattern<M, C, brigand::list<Ps...> >
    {
      template<typename P> using idx = typename brigand::apply<M, P, C>::type;

      using type = pattern_< idx<Ps>::value... >;
    };

    template<typename M, typename T>
    struct meta_pattern
    {
      using card = cardinal_of<T>;
      using type = typename make_meta_pattern<M, card, brigand::range<int,0,card::value>>::type;
    };

    // -----------------------------------------------------------------------------------------------
    // take a constexpr function and build a pattern
    template<int (*M)(int,int), typename C, typename L> struct make_constexpr_pattern;

    template<int (*M)(int,int), typename C, typename... Ps>
    struct make_constexpr_pattern<M, C, brigand::list<Ps...> >
    {
      using type = pattern_< M(Ps::value,C::value)... >;
    };

    template<int (*M)(int,int), typename T>
    struct meta_pattern<pattern<M>,T>
    {
      using card = cardinal_of<T>;
      using type = typename make_constexpr_pattern<M, card, brigand::range<int,0,card::value>>::type;
    };
  } }
}

#endif
