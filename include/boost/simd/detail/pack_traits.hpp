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
#include <boost/simd/detail/pack_proxy.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <cstddef>
#include <cstring>
#include <iterator>

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

  template<typename T> using rconst = typename std::remove_const<T>::type;
} } }

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(TPL, TYPE, N, VTYPE)                                     \
  template <TPL>                                                                                   \
  class pack_traits<TYPE, N, VTYPE> {                                                              \
                                                                                                   \
    public:                                                                                        \
    using storage_type              = VTYPE;                                                       \
                                                                                                   \
    using value_type                = TYPE;                                                        \
    using size_type                 = std::size_t;                                                 \
                                                                                                   \
    enum { static_size = N };                                                                      \
                                                                                                   \
    using reference               = pack_proxy<value_type, static_size, storage_type>;             \
    using const_reference         = pack_proxy<value_type const, static_size, storage_type const>; \
                                                                                                   \
    using storage_kind = ::boost::simd::native_storage;                                            \
                                                                                                   \
    BOOST_FORCEINLINE static value_type get(storage_type const& data, std::size_t index)           \
    BOOST_NOEXCEPT                                                                                 \
    {                                                                                              \
      rconst<value_type> temp[N];                                                                  \
      memcpy(&temp[0], (void*)(&data), sizeof(data));                                              \
      return temp[index];                                                                          \
    }                                                                                              \
                                                                                                   \
    BOOST_FORCEINLINE static                                                                       \
    void set(storage_type& data, std::size_t index, value_type const& other) BOOST_NOEXCEPT        \
    {                                                                                              \
      value_type temp[N];                                                                          \
      /* read first */                                                                             \
      memcpy(&temp[0], (void*)(&data), sizeof(data));                                              \
      /* modify the element */                                                                     \
      temp[index] = other;                                                                         \
      /* now write back the result */                                                              \
      memcpy((void*)(&data), (void*)&temp[0], sizeof(data));                                       \
    }                                                                                              \
                                                                                                   \
    static BOOST_FORCEINLINE reference at(storage_type& v, std::size_t i) BOOST_NOEXCEPT           \
    {                                                                                              \
      return {&v, i};                                                                              \
    }                                                                                              \
                                                                                                   \
    static BOOST_FORCEINLINE const_reference at(storage_type const& v, std::size_t i) BOOST_NOEXCEPT\
    {                                                                                              \
      return {&v, i};                                                                              \
    }                                                                                              \
  };                                                                                               \
  /**/

#define BOOST_SIMD_DEFINE_PACK_TRAITS(TYPE, N, VTYPE)                                              \
BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(BOOST_PP_EMPTY(), TYPE, N, VTYPE)                                \
/**/

#endif
