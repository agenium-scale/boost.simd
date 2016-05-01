//==================================================================================================
/**
  Copyright 2016 Numscale SAS
  Copyright 2016 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_SLIDE_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSSE3_SIMD_FUNCTION_SLIDE_HPP_INCLUDED

#include <boost/simd/meta/as_arithmetic.hpp>
#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = boost::dispatch;
  namespace bs = boost::simd;

  BOOST_DISPATCH_OVERLOAD ( slide_
                          , (typename T, typename Offset)
                          , bs::ssse3_
                          , bs::pack_< bd::fundamental_<T>, bs::sse_ >
                          , bs::pack_< bd::fundamental_<T>, bs::sse_ >
                          , bd::constant_<bd::integer_<Offset>>
                          )
  {
    using storage_t = typename T::storage_type;

    BOOST_FORCEINLINE T operator()(T const& a0, T const& a1, Offset const&) const BOOST_NOEXCEPT
    {
      // Compute relative offsets
      using bitcount = std::integral_constant < std::size_t
                                              , sizeof(as_arithmetic_t<typename T::value_type>)
                                              * Offset::value
                                              >;

      // Shift everything in place
      return (storage_t)( _mm_alignr_epi8 ( (__m128i)(a1.storage()), (__m128i)(a0.storage())
                                          , bitcount::value
                                          )
                        );
    }
  };
} } }

#endif
