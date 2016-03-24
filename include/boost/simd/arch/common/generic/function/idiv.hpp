//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IDIV_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_GENERIC_FUNCTION_IDIV_HPP_INCLUDED

#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/function/definition/trunc.hpp>
#include <boost/simd/function/definition/fix.hpp>
#include <boost/simd/function/div.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/hierarchy.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{

  namespace bd = boost::dispatch;
  namespace bs = boost::simd;
  BOOST_DISPATCH_OVERLOAD ( idiv_
                          , (typename T)
                          , bd::cpu_
                          , bd::generic_<bd::arithmetic_<T>>
                          , bd::generic_<bd::arithmetic_<T>>
                          )
  {
    BOOST_FORCEINLINE  bd::as_integer_t<T>
    operator()(T const& a, T const& b ) const BOOST_NOEXCEPT
    {
      return div(a, b, fix);
    }
  };
//   BOOST_DISPATCH_OVERLOAD ( idiv_
//                           , (typename T)
//                           , bd::cpu_
//                           , bd::generic_<bd::arithmetic_<T>>
//                           , bd::generic_<bd::arithmetic_<T>>
//                           , bs::tag::trunc_
//                           )
//   {
//     BOOST_FORCEINLINE bd::as_integer_t<T>
//     operator()(T const& a, T const& b
//                , bd::functor<bs::tag::trunc_> ) const BOOST_NOEXCEPT
//     {
//       return idiv(a, b, fix);
//     }
//   };

} } }

#endif
