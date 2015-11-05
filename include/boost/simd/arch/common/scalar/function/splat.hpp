//==================================================================================================
/*!
  @file
  @copyright 2015 NumScale SAS
  @copyright 2015 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/as.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  BOOST_DISPATCH_OVERLOAD ( splat_
                          , (typename A0, typename T)
                          , bd::cpu_
                          , bd::scalar_< bd::fundamental_<A0> >
                          , bd::target_< bd::scalar_< bd::fundamental_<T> > >
                          )
  {
    using result_t = typename T::type;

    BOOST_FORCEINLINE result_t operator()( A0 a0, T const &) const BOOST_NOEXCEPT
    {
      return static_cast<typename T::type>(a0);
    }
  };
} } }


#endif
