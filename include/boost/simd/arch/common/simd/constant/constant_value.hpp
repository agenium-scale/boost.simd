//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_CONSTANT_CONSTANT_VALUE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_CONSTANT_CONSTANT_VALUE_HPP_INCLUDED

#include <boost/simd/config.hpp>
#if defined(BOOST_SIMD_DETECTED)
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/as.hpp>
#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace tag { struct constant_; }}}

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename Constant, typename T, typename X)
                                  , boost::dispatch::constant_value_<Constant>
                                  , bs::simd_
                                  , bd::target_< bs::pack_<bd::unspecified_<T>,X> >
                                  )
  {
    using value_t   = typename T::type::value_type;
    using scalar_t  = decltype(bd::functor<Constant>{}(bd::as_<value_t>()));
    using result_t  = typename T::type::template rebind<scalar_t>;

    BOOST_FORCEINLINE result_t operator()(T const&) const BOOST_NOEXCEPT
    {
      return result_t{ bd::functor<Constant>{}(bd::as_<value_t>()) };
    }
  };

/*  BOOST_DISPATCH_OVERLOAD_FALLBACK( (typename V)
                                  , boost::dispatch::constant_value_<tag::constant_>
                                  , bs::simd_
                                  , bd::scalar_<bd::unspecified_<V>>
                                  )
  {
    using value_t   = typename T::type::value_type;
    using scalar_t  = decltype(bd::functor<tag::constant_>{}(V()));
    using result_t  = typename T::type::template rebind<scalar_t>;

    BOOST_FORCEINLINE result_t operator()(V const& v) const BOOST_NOEXCEPT
    {
      return result_t{ bd::functor<tag::constant_>{}(v) };
    }
  };*/
} } }

#endif

#endif
