//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_ALIGNED_LOAD_HPP_INCLUDED

#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // aligned_load from a pointer
  BOOST_DISPATCH_OVERLOAD ( aligned_load_
                          , (typename Target, typename Pointer)
                          , bs::simd_
                          , bd::pointer_<bd::scalar_<bd::unspecified_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,bs::simd_emulation_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;
    using value_t   = typename storage_t::value_type;

    BOOST_FORCEINLINE target_t operator()(Pointer p, Target const&) const BOOST_NOEXCEPT
    {
      BOOST_ASSERT_MSG( boost::alignment::is_aligned(p, sizeof(storage_t))
                      , "boost::simd::aligned_load was performed on an unaligned pointer"
                      );

      return do_(p, brigand::range<std::size_t,0,std::tuple_size<storage_t>::value>{} );
    }

    // How many elements does each aligned_load loads ?
    template<typename I>
    using offset_t = std::integral_constant<std::size_t,I::value*target_t::traits::element_size>;

    template<typename... N>
    static inline storage_t do_(Pointer p, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      return {{ aligned_load<value_t>(p+offset_t<N>::value)... }};
    }
  };
} } }

#endif
