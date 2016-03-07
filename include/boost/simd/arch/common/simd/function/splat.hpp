//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLAT_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_SPLAT_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/simd/detail/brigand.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <tuple>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // splat from a scalar
  BOOST_DISPATCH_OVERLOAD ( splat_
                          , (typename Target, typename V)
                          , bs::simd_
                          , bd::scalar_<bd::unspecified_<V>>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,bs::simd_emulation_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;
    using value_t   = typename storage_t::value_type;

    BOOST_FORCEINLINE target_t operator()(V const& v, Target const&) const BOOST_NOEXCEPT
    {
      return do_(v, brigand::range<std::size_t,0,std::tuple_size<storage_t>::value>{} );
    }

    template<typename N, typename T>
    static BOOST_FORCEINLINE T&& make(T&& t) BOOST_NOEXCEPT { return std::forward<T>(t); }

    template<typename... N>
    static inline storage_t do_(V const& v, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      value_t s(v);
      return {{ make<N>(s)... }};
    }
  };
} } }

#endif
