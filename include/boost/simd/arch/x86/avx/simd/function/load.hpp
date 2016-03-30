//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of double
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::avx_
                          , bd::pointer_<bd::scalar_<bd::double_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::double_<Target>,bs::avx_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_pd(p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a pointer of single
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::avx_
                          , bd::pointer_<bd::scalar_<bd::single_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::avx_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return _mm256_loadu_ps(p);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a range of floating point value
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End)
                          , bs::avx_
                          , bd::input_iterator_<bd::scalar_<bd::floating_<Begin>>>
                          , bd::input_iterator_<bd::scalar_<bd::floating_<End>>>
                          , bd::target_<bs::pack_<bd::floating_<Target>,bs::avx_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, brigand::range<std::size_t,0,target_t::static_size>{} );
    }

    template<typename I, typename T>
    static BOOST_FORCEINLINE T const& make(T const& v) BOOST_NOEXCEPT { return v; }

    template<typename... N>
    static inline target_t do_(Begin const& b, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      Begin p = b;
      typename target_t::value_type data[target_t::static_size] = { make<N>(*p++)...};
      return load<target_t>( &data[0] );
    }
  };
} } }

#endif
