//==================================================================================================
/*!
  @file

  Defines traits for pack.

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_TRAITS_HPP_INCLUDED

#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/detail/pack_iterator.hpp>
#include <iterator>
#include <cstddef>
#include <cstring>

namespace boost { namespace simd
{
  template<typename T> struct logical;
} }

namespace boost { namespace simd { namespace detail
{
  template < typename T
           , std::size_t N
           , typename Storage
           >
  class pack_traits;

  // Needed for const pack_proxy
  template <typename T, std::size_t N, typename Storage>
  class pack_traits<const T, N, const Storage> : public pack_traits<T, N, Storage> {};

  // WIP logical
  template <typename T, std::size_t N, typename Storage>
  class pack_traits<boost::simd::logical<T>, N, Storage> {

    public:
    using storage_type              = Storage;
    using substorage_type           = T; // T or logical<T> ?

    using value_type                = boost::simd::logical<T>;
    using size_type                 = std::size_t;

    enum { static_size = N };
    enum { alignment = sizeof(Storage) };

    using reference               = value_type&;
    using const_reference         = value_type const&;

    using static_range = brigand::range<std::size_t, 0, N>;

    using storage_kind = ::boost::simd::native_storage;
  };
} } }

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(TPL, TYPE, N, VTYPE)                                     \
  template <TPL>                                                                                   \
  class pack_traits<TYPE, N, VTYPE> {                                                              \
                                                                                                   \
    public:                                                                                        \
    using storage_type              = VTYPE;                                                       \
    using substorage_type           = VTYPE;                                                       \
                                                                                                   \
    using value_type                = TYPE;                                                        \
    using size_type                 = std::size_t;                                                 \
                                                                                                   \
    enum { static_size = N, element_size = 1 };                                                    \
    enum { alignment = sizeof(VTYPE) };                                                            \
                                                                                                   \
    using reference               = value_type&;                                                   \
    using const_reference         = value_type const&;                                             \
                                                                                                   \
    using static_range = brigand::range<std::size_t, 0, N>;                                        \
                                                                                                   \
    using storage_kind = ::boost::simd::native_storage;                                            \
  };                                                                                               \
  /**/

#define BOOST_SIMD_DEFINE_PACK_TRAITS(TYPE, N, VTYPE)                                              \
BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(BOOST_PP_EMPTY(), TYPE, N, VTYPE)                                \
/**/

#endif
