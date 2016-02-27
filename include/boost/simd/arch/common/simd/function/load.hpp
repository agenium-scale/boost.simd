//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/pack.hpp>
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
  // load from a pointer
  BOOST_DISPATCH_OVERLOAD ( load_
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
      return do_(p, brigand::range<std::size_t,0,std::tuple_size<storage_t>::value>{} );
    }

    // How many elements does each load loads ?
    template<typename I>
    using offset_t = std::integral_constant<std::size_t,I::value*target_t::traits::cardinal>;

    template<typename... N>
    static inline storage_t do_(Pointer p, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      return { load<value_t>(p+offset_t<N>::value)... };
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a range
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End)
                          , bs::simd_
                          , bd::input_iterator_<bd::scalar_<bd::unspecified_<Begin>>>
                          , bd::input_iterator_<bd::scalar_<bd::unspecified_<End>>>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,bs::simd_emulation_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;
    using value_t   = typename storage_t::value_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, brigand::range<std::size_t,0,std::tuple_size<storage_t>::value>{} );
    }

    template<typename I>
    using offset_t = std::integral_constant<std::size_t,target_t::traits::cardinal>;

    template<typename... N>
    static inline storage_t do_(Begin const& b, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      Begin lb, le = b;

      // This code is built so every unpacking generates the least amount of calls to std::advance
      return {  ( lb = le
                , std::advance(le,offset_t<N>::value)
                , load<value_t>(lb,le)
                )...
              };
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a random access range <---
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End)
                          , bs::simd_
                          , bd::random_access_iterator_<bd::scalar_<bd::unspecified_<Begin>>>
                          , bd::random_access_iterator_<bd::scalar_<bd::unspecified_<End>>>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,bs::simd_emulation_>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;
    using value_t   = typename storage_t::value_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, brigand::range<std::size_t,0,std::tuple_size<storage_t>::value>{} );
    }

    // How many elements does each load loads ?
    template<typename I>
    using begin_t = std::integral_constant<std::size_t,I::value*target_t::traits::cardinal>;

    template<typename I>
    using end_t = std::integral_constant<std::size_t,(1+I::value)*target_t::traits::cardinal>;

    template<typename... N>
    static inline storage_t do_(Begin const& b, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      // For RandomAccessIterator, we just offset to the proper place
      return { load<value_t>(b+begin_t<N>::value, b+end_t<N>::value)... };
    }
  };
} } }

#endif
