//==================================================================================================
/*!
  @file

  Copyright 2015 NumScale SAS
  Copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_NEG_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_NEG_HPP_INCLUDED

#include <boost/simd/function/neg_s.hpp>
#include <boost/simd/function/saturated.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>


  BOOST_DISPATCH_OVERLOAD ( neg_
                          , (typename T)
                          ,  bd::cpu_
                          ,  bd::generic_<bd::fundamental_<T>>
                          ,  bs::saturated_tag
                          )
  {
    BOOST_FORCEINLINE T operator()(const T& a
                                  , const saturated_tag &) const BOOST_NOEXCEPT
    {
      return neg_s(a);
    }
  };
} } }


#endif
