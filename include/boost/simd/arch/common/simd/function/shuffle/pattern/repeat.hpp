//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_REPEAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_PATTERN_REPEAT_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/shuffle.hpp>

namespace boost { namespace simd
{
  // -----------------------------------------------------------------------------------------------
  // Identity pattern hierarchy
  template<int Side, int Idx, typename P>
  struct repeat_pattern : detail::any_pattern_<repeat_pattern<Side, Idx,P>>
  {
    static const std::size_t static_size = P::static_size;
    using parent = detail::any_pattern_<repeat_pattern<Side, Idx,P>>;
  };
} }

// -------------------------------------------------------------------------------------------------
// Hierarchize identity patterns
namespace boost { namespace dispatch { namespace ext
{
  // repeat lower half patterns
  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<0,1,0,1>,Origin>
  {
    using type = boost::simd::repeat_pattern<0,0,boost::simd::detail::pattern_<0,1,0,1>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<4,5,4,5>,Origin>
  {
    using type = boost::simd::repeat_pattern<1,0,boost::simd::detail::pattern_<4,5,4,5>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<0,1,2,3,0,1,2,3>,Origin>
  {
    using type = boost::simd::repeat_pattern<0,0,boost::simd::detail::pattern_<0,1,2,3,0,1,2,3>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<8,9,10,11,8,9,10,11>,Origin>
  {
    using type = boost::simd::repeat_pattern<1,0,boost::simd::detail::pattern_<8,9,10,11,8,9,10,11>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7>,Origin>
  {
    using type = boost::simd::repeat_pattern<0,0
                                    ,boost::simd::detail::pattern_<0,1,2,3,4,5,6,7,0,1,2,3,4,5,6,7>
                                    >;
  };

  template<typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_ < 16,17,18,19,20,21,22,23
                                                          , 16,17,18,19,20,21,22,23
                                                          >
                          , Origin
                          >
  {
    using type = boost::simd::repeat_pattern<1,0
                                    ,boost::simd::detail::pattern_< 16,17,18,19,20,21,22,23
                                                                  , 16,17,18,19,20,21,22,23
                                                                  >
                                    >;
  };

  // repeat upper half patterns
  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<2,3,2,3>,Origin>
  {
    using type = boost::simd::repeat_pattern<0,1,boost::simd::detail::pattern_<2,3,2,3>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<6,7,6,7>,Origin>
  {
    using type = boost::simd::repeat_pattern<1,1,boost::simd::detail::pattern_<6,7,6,7>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<4,5,6,7,4,5,6,7>,Origin>
  {
    using type = boost::simd::repeat_pattern<0,1,boost::simd::detail::pattern_<4,5,6,7,4,5,6,7>>;
  };

  template<typename Origin>
  struct pattern_hierarchy<boost::simd::detail::pattern_<12,13,14,15,12,13,14,15>,Origin>
  {
    using type = boost::simd::repeat_pattern<1,1,boost::simd::detail::pattern_<12,13,14,15,12,13,14,15>>;
  };

  template<typename Origin>
  struct pattern_hierarchy< boost::simd::detail::pattern_ < 24,25,26,27,28,26,30,31
                                                          , 24,25,26,27,28,26,30,31
                                                          >
                          , Origin
                          >
  {
    using type = boost::simd::repeat_pattern<1,1
                                    ,boost::simd::detail::pattern_< 24,25,26,27,28,26,30,31
                                                                  , 24,25,26,27,28,26,30,31
                                                                  >
                                    >;
  };
} } }

#endif
