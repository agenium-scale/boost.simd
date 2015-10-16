//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_LO_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_LO_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/simd/function/bitwise_and.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/bitwise_cast.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/dispatch/meta/scalar_of.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( lo_
                          , (typename A0)
                          , bd::cpu_
                          , bd::generic_< bd::arithmetic_<A0> >
                          )
  {
    using result_t = bd::as_integer_t<A0,unsigned>;
    using s_t = bd::scalar_of_t<result_t>;

    BOOST_FORCEINLINE result_t operator() ( A0 const& a0) const
    {
      static const s_t pattern = (s_t(1) << sizeof(s_t)*(CHAR_BIT/2)) - 1;
      return bitwise_and( splat<result_t>(bitwise_cast<result_t>(pattern)),  a0 );
//      return bitwise_and( integral_constant<result_t, pattern>(), a0 );
    }
  };
} } }


#endif
