//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_FREXP_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_FREXP_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/simd/cardinal_of.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( frexp_
                          , (typename A0, typename A2)
                          , bd::cpu_
                          , bd::generic_< bd::floating_<A0> >
                          , bd::generic_< bd::integer_<A2> >
                            )
  {
    static_assert
      ( bd::cardinal_of<A0>::value == bd::cardinal_of<A2>::value
      , "boost.simd cardinalities are inconsistent in frexp call"
      );

    BOOST_FORCEINLINE A0 operator() ( A0 const& a0,A2 & a2) const BOOST_NOEXCEPT
    {
      A0 a1;
      bs::frexp(a0, a1, a2);
      return a1;
    }
  };

  BOOST_DISPATCH_OVERLOAD ( frexp_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_<bd::floating_<A0> >
                          )
  {
    using exponent_t = bd::as_integer_t<A0, signed>;
    using result_t = std::pair<A0,exponent_t>                               ;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const BOOST_NOEXCEPT
    {
      A0 first;
      exponent_t second;
      bs::frexp( a0, first, second );
      return result_t(first, second);
    }
  };
} } }


#endif
