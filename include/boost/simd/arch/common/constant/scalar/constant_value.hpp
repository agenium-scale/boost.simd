//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_CONSTANT_SCALAR_CONSTANT_VALUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_CONSTANT_SCALAR_CONSTANT_VALUE_HPP_INCLUDED

#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename Constant, typename T)
                                  , boost::dispatch::constant_value_<Constant>
                                  , boost::dispatch::cpu_
                                  , bd::target_<bd::scalar_<bd::arithmetic_<T>>>
                                  )
  {
    using value_t = typename detail::constant_traits<Constant,typename T::type>::type;

    BOOST_FORCEINLINE typename value_t::value_type operator()(T const&) const
    {
      return value_t{};
    }
  };
} } }

#endif
