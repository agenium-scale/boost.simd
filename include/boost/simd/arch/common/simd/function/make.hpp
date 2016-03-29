//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>
#include <initializer_list>
#include <algorithm>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::simd_
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,bs::simd_emulation_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    static_assert ( sizeof...(Values) == target_t::static_size
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return do_( vs..., typename target_t::storage_kind{});
    }

    static inline storage_t do_ ( Values const&... vs
                                , ::boost::simd::scalar_storage const&
                                ) BOOST_NOEXCEPT
    {
      storage_t that{{ static_cast<typename target_t::value_type>(vs)... }};
      return that;
    }

    static inline target_t do_( Values const&... vs
                              , ::boost::simd::aggregate_storage const&
                              ) BOOST_NOEXCEPT
    {
      /*
        This version sounds awful but we have no way to either cut
        the parameter pack into sub-packs or to do that without being
        circularly dependent on load, which ends up doing something
        similar anyway.
      */
      target_t that;

      using value_t = typename target_t::value_type;
      std::initializer_list<value_t> lst{static_cast<value_t>(vs)...};
      std::copy(lst.begin(),lst.end(),that.begin());
      return that;
    }
  };
} } }

#endif
