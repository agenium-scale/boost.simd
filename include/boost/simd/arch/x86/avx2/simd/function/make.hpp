//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_MAKE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_MAKE_HPP_INCLUDED

#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // make a pack of int64
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename V0, typename V1, typename V2, typename V3)
                          , bs::avx2_
                          , bd::target_<bs::pack_<bd::ints64_<Target>,bs::avx_>>
                          , bd::scalar_<bd::unspecified_<V0>>
                          , bd::scalar_<bd::unspecified_<V1>>
                          , bd::scalar_<bd::unspecified_<V2>>
                          , bd::scalar_<bd::unspecified_<V3>>
                          )
  {
    using target_t  = typename Target::type;

    BOOST_FORCEINLINE target_t
    operator()(Target const&, V0 const& v0, V1 const& v1
                            , V2 const& v2, V3 const& v3) const BOOST_NOEXCEPT
    {
      using value_t = typename target_t::value_type;
      return _mm256_set_epi64x( static_cast<value_t>(v3), static_cast<value_t>(v2)
                              , static_cast<value_t>(v1), static_cast<value_t>(v0)
                              );
    }
  };

  //------------------------------------------------------------------------------------------------
  // make a pack of int32
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::avx2_
                          , bd::target_<bs::pack_<bd::ints32_<Target>,bs::avx_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;

    static_assert ( sizeof...(Values) == 8
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return _mm256_setr_epi32(static_cast<typename target_t::value_type>(vs)...);
    }
  };

  //------------------------------------------------------------------------------------------------
  // make a pack of int16
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::avx2_
                          , bd::target_<bs::pack_<bd::ints16_<Target>,bs::avx_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;

    static_assert ( sizeof...(Values) == 16
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return _mm256_setr_epi16(static_cast<typename target_t::value_type>(vs)...);
    }
  };

  //------------------------------------------------------------------------------------------------
  // make a pack of int8
  BOOST_DISPATCH_OVERLOAD ( make_
                          , (typename Target, typename... Values)
                          , bs::avx2_
                          , bd::target_<bs::pack_<bd::ints8_<Target>,bs::avx_>>
                          , bd::scalar_<bd::unspecified_<Values>>...
                          )
  {
    using target_t  = typename Target::type;

    static_assert ( sizeof...(Values) == 32
                  , "boost::simd::make - Invalid number of parameters"
                  );

    BOOST_FORCEINLINE target_t operator()(Target const&, Values const&... vs) const BOOST_NOEXCEPT
    {
      return _mm256_setr_epi8(static_cast<typename target_t::value_type>(vs)...);
    }
  };
} } }

#endif
