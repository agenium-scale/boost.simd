//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_CONSTANT_VALUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SCALAR_CONSTANT_CONSTANT_VALUE_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/as.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace tag { struct constant_; }}}

#ifdef BOOST_MSVC
#pragma warning(push)
#pragma warning(disable: 4310) // Truncation
#pragma warning(disable: 4309) // Truncation
#endif

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;

  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename Constant, typename T)
                                  , boost::dispatch::constant_value_<Constant>
                                  , boost::dispatch::cpu_
                                  , bd::target_<bd::scalar_<bd::unspecified_<T>>>
                                  )
  {
    using value_t = typename detail::constant_traits<Constant,typename T::type>::type;

    BOOST_FORCEINLINE typename value_t::value_type operator()(T const&) const BOOST_NOEXCEPT
    {
      return value_t{};
    }
  };

  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename V)
                                  , boost::dispatch::constant_value_<tag::constant_>
                                  , boost::dispatch::cpu_
                                  , bd::scalar_<bd::unspecified_<V>>
                                  )
  {
    template<typename T, T N>
    static BOOST_FORCEINLINE T impl(std::integral_constant<T,N> const&) BOOST_NOEXCEPT
    {
      return std::integral_constant<T,N>{};
    }

    template<typename R, typename T, T N>
    static BOOST_FORCEINLINE R impl(brigand::real_<R,T,N> const& ) BOOST_NOEXCEPT
    {
      return static_cast<R>(brigand::real_<R,T,N>{});
    }

    template<typename T, std::intmax_t N, std::intmax_t D>
    static BOOST_FORCEINLINE T impl(detail::ratio<T,N,D> const&) BOOST_NOEXCEPT
    {
      return T(double(N)/double(D));
    }

    BOOST_FORCEINLINE auto operator()(V const& v) const BOOST_NOEXCEPT -> decltype(impl(v))
    {
      return impl( v );
    }
  };
} } }

#ifdef BOOST_MSVC
#pragma warning(pop)
#endif

#endif
