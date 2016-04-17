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

#include <boost/simd/function/make.hpp>
#include <boost/simd/meta/hierarchy/simd.hpp>
#include <boost/dispatch/function/overload.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/dispatch/adapted/std/iterator.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/assert.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of whatever in a pack
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer, typename Ext)
                          , bs::simd_
                          , bd::pointer_<bd::scalar_<bd::unspecified_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,Ext>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    BOOST_FORCEINLINE target_t operator()(Pointer p, Target const&) const BOOST_NOEXCEPT
    {
      return do_(p, typename target_t::storage_kind(), typename target_t::traits::static_range{} );
    }

    // How many elements does each load loads ?
    template<typename I>
    using offset_t = std::integral_constant<std::size_t,I::value*target_t::traits::element_size>;

    /*
      Emulation case: fill in the storage by calling load on the underlying data over successive
      jump in the pointer.
    */
    template<typename... N>
    static inline storage_t do_(Pointer p, aggregate_storage const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      return {{ load<typename storage_t::value_type>(p+offset_t<N>::value)... }};
    }

    /*
      Native case: We doesn't know what we're storing but we know we fill a pack.
      So we prepare data then call make on the proper target type.
    */
    template<typename K, typename... N> static inline
    target_t do_(Pointer const& b, K const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      using value_t   = typename target_t::value_type;
      std::initializer_list<value_t> lst{ static_cast<value_t>(b[N::value])... };

      auto p = lst.begin();
      return make<target_t>(p[N::value]...);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a range into emulated vector
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End, typename Ext)
                          , bs::simd_
                          , bd::input_iterator_<bd::scalar_<bd::unspecified_<Begin>>>
                          , bd::input_iterator_<bd::scalar_<bd::unspecified_<End>>>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>, Ext>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, typename target_t::storage_kind(), typename target_t::traits::static_range{});
    }

    // template<typename I>
    // using offset_t = std::integral_constant<std::size_t,target_t::traits::element_size>;

    /*
      Emulation case: fill in the storage by calling load on the underlying data
      We use advance as we're dealing with InputIterator and the dances with lb/le is
      there so we don't call advance from the beginning each time, thus doing ++ exactly N times
      and note N.(N-1)/2 times.
    */
    template<typename... N>
    static inline storage_t do_(Begin b, aggregate_storage const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      Begin b0 = b;

      Begin b1 = b0;
      std::advance(b1,target_t::traits::element_size);

      Begin b2 = b1;
      std::advance(b2,target_t::traits::element_size);

      return  {{  load<typename target_t::substorage_type>(b0,b1)
                , load<typename target_t::substorage_type>(b1,b2)
              }};
    }

    template<typename N> static inline
    typename target_t::value_type value(Begin& b) BOOST_NOEXCEPT { return *b++; }

    /*
      Native case: We doesn't know what we're storing but we know we fill a pack.
      So we just prepare data then call make on the proper target type.
    */
    template<typename K, typename... N> static inline
    target_t do_(Begin b, K const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      using value_t   = typename target_t::value_type;
      std::initializer_list<value_t> lst{ value<N>(b)... };

      auto p = lst.begin();
      return make<target_t>(p[N::value]...);
    }
  };

  //------------------------------------------------------------------------------------------------
  // load from a random access range <---
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Begin, typename End, typename Ext)
                          , bs::simd_
                          , bd::random_access_iterator_<bd::scalar_<bd::unspecified_<Begin>>>
                          , bd::random_access_iterator_<bd::scalar_<bd::unspecified_<End>>>
                          , bd::target_<bs::pack_<bd::unspecified_<Target>,Ext>>
                          )
  {
    using target_t  = typename Target::type;
    using storage_t = typename target_t::storage_type;

    BOOST_FORCEINLINE target_t operator()(Begin const& b, End const&, Target const&) const BOOST_NOEXCEPT
    {
      return do_(b, typename target_t::storage_kind(), typename target_t::traits::static_range{});
    }

    /*
      Emulation case: fill in the storage by calling load on the underlying data
      while jumping inside the RandomAccessRange.
    */
    template<typename... N> static inline
    storage_t do_(Begin b, aggregate_storage const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      Begin   b1 = b  + target_t::traits::element_size
            , b2 = b1 + target_t::traits::element_size;

      return  {{  load<typename target_t::substorage_type>(b, b1)
                , load<typename target_t::substorage_type>(b1,b2)
              }};
    }

    /*
      Native case: We doesn't know what we're storing but we know we fill a pack.
      So we just call make on the proper target type with every randomly accessed
      values.
    */
    template<typename K, typename... N> static inline
    target_t do_(Begin b, K const&, brigand::list<N...> const&) BOOST_NOEXCEPT
    {
      return make<target_t>(b[N::value]...);
    }
  };
} } }

#endif
