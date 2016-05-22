//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_SLIDE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SHUFFLE_SLIDE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/permutation.hpp>
#include <boost/simd/function/slide.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd  =  boost::dispatch;
  namespace bs  =  boost::simd;
  namespace bsd =  boost::simd::detail;

  // -----------------------------------------------------------------------------------------------
  // slide shuffling for cardinal 2
  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<-1, 0>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<-1>(a0), -1, 0 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<1,-1>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<+1>(a0), 1,-1 );

  // -----------------------------------------------------------------------------------------------
  // slide shuffling for cardinal 4
  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<-1,-1,-1, 0>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<-3>(a0), -1,-1,-1, 0 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<-1,-1, 0, 1>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<-2>(a0), -1,-1, 0, 1 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<-1, 0, 1, 2>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<-1>(a0), -1, 0, 1, 2 );

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<1, 2, 3,-1>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<+1>(a0), 1, 2, 3,-1);

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<2, 3,-1,-1>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<+2>(a0), 2, 3,-1,-1);

  BOOST_DISPATCH_OVERLOAD ( shuffle_, (typename A0, typename X)
                          , bs::simd_,bsd::pattern_<3,-1,-1,-1>
                          , bs::pack_<bd::unspecified_<A0>, X>
                          )
  BOOST_SIMD_GENERIC_PATTERN(bs::slide<+3>(a0), 3,-1,-1,-1);
} } }

#endif
