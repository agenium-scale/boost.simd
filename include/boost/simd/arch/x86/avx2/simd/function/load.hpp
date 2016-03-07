//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX2_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of integers
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::avx2_
                          , bd::pointer_<bd::scalar_<bd::integer_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::integer_<Target>,bs::avx_>>
                          )
  {
    using target = typename Target::type;
    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_si256((__m256i*)(p));
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a range of integers
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End)
                          , bs::avx2_
                          , bd::input_iterator_<bd::scalar_<bd::integer_<Begin>>>
                          , bd::input_iterator_<bd::scalar_<bd::integer_<End>>>
                          , bd::target_<bs::pack_<bd::arithmetic_<Target>,bs::avx_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, brigand::range<std::size_t,0,target_t::static_size>{} );
    }

    template<typename I, typename T>
    static BOOST_FORCEINLINE T make(T const& v) BOOST_NOEXCEPT { return v; }

    template<typename... N>
    static inline storage_t do_(Begin const& b, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      Begin p = b;
      typename target_t::value_type data[target_t::static_size] = { make<N>(*p++)...};
      return _mm256_loadu_si256( (__m256i*)(&data[0]) );
    }
  };
} } }

#endif
