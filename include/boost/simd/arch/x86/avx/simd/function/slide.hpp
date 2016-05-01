//==================================================================================================
/**
  Copyright 2016 Numscale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_SLIDE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_SLIDE_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/function/combine.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::avx_
                          , bs::pack_< bd::fundamental_<T>, bs::avx_ >
                          , bs::pack_< bd::fundamental_<T>, bs::avx_ >
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    using storage_t     = typename T::storage_type;
    using hcard         = std::integral_constant<std::size_t,T::static_size/2>;
    using sub_t         = typename T::template resize<hcard::value>;
    using sub_storage_t = typename sub_t::storage_type;

    // slide under half the cardinal
    static BOOST_FORCEINLINE T do_(__m256i v0, __m256i v1, std::true_type const&) BOOST_NOEXCEPT
    {
      sub_t s0h((sub_storage_t)(_mm256_extractf128_si256(v0, 0)));
      sub_t s1h((sub_storage_t)(_mm256_extractf128_si256(v1, 0)));
      sub_t s1l((sub_storage_t)(_mm256_extractf128_si256(v1, 1)));

      return combine( slide<Offset::value%hcard::value>(s1h, s1l)
                    , slide<Offset::value%hcard::value>(s1l, s0h)
                    );
    }

    static BOOST_FORCEINLINE T do_(__m256i v0, __m256i v1, std::false_type const&) BOOST_NOEXCEPT
    {
      sub_t s1l((sub_storage_t)(_mm256_extractf128_si256(v1, 1)));
      sub_t s0h((sub_storage_t)(_mm256_extractf128_si256(v0, 0)));
      sub_t s0l((sub_storage_t)(_mm256_extractf128_si256(v0, 1)));

      return combine( slide<Offset::value%hcard::value>(s1l, s0h)
                    , slide<Offset::value%hcard::value>(s0h, s0l)
                    );
    }

    BOOST_FORCEINLINE T operator()(T const& a0, T const& a1, Offset const&) const BOOST_NOEXCEPT
    {
      return do_( (__m256i)(a1.storage()), (__m256i)(a0.storage())
                , brigand::bool_<(Offset::value < hcard::value)>{}
                );
    }
  };
} } }

#endif
