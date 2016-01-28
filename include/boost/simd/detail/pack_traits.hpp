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
#include <boost/simd/detail/storage_of.hpp>
#include <boost/simd/detail/pack_iterator.hpp>
#include <boost/simd/detail/pack_proxy.hpp>
#include <boost/preprocessor/repetition/enum.hpp>
#include <cstddef>
#include <cstring>
#include <iterator>

namespace boost { namespace simd
{

namespace detail
{
  template < typename T
           , std::size_t N
           , typename Storage = typename detail::storage_of<T, N>::type
           >
  class pack_traits;

  // Needed for const pack_proxy
  template <typename T, std::size_t N, typename Storage>
  class pack_traits<const T, N, const Storage> : public pack_traits<T, N, Storage> {};
}

template < typename T
         , std::size_t N
         , typename Storage
         >
class pack_traits_base
{
  public:
  using storage_type            = Storage;
  using storage_value_type      = Storage;

  using value_type              = T;
  using size_type               = std::size_t;

  enum { static_size = N };

  using reference               = detail::pack_proxy<value_type, static_size, storage_type>;
  using const_reference         = detail::pack_proxy<value_type const, static_size, storage_type const>;

  using storage_kind            = ::boost::simd::native_storage;

  static BOOST_FORCEINLINE
  value_type get(storage_type const& data, std::size_t index) BOOST_NOEXCEPT
  {
    typename std::remove_const<value_type>::type temp[N];
    memcpy(&temp[0], (void*)(&data), sizeof(data));
    return temp[index];
  }

  static BOOST_FORCEINLINE
  void set(storage_type& data, std::size_t index, value_type const& other) BOOST_NOEXCEPT
  {
    value_type temp[N];
    /* read first */
    memcpy(&temp[0], (void*)(&data), sizeof(data));
    /* modify the element */
    temp[index] = other;
    /* now write back the result */
    memcpy((void*)(&data), (void*)&temp[0], sizeof(data));
  }

  static BOOST_FORCEINLINE
  reference at(storage_type& v, std::size_t i) BOOST_NOEXCEPT
  {
    return {&v, i};
  }

  static BOOST_FORCEINLINE
  const_reference at(storage_type const& v, std::size_t i) BOOST_NOEXCEPT
  {
    return {&v, i};
  }

  template <typename F>
  static BOOST_FORCEINLINE
  void apply(storage_type& v, F f)
  {
    f(v);
  }

  template <typename F, typename AnotherStorage>
  static BOOST_FORCEINLINE
  void map(storage_type& in, AnotherStorage& out, F f)
  {
    f(in, out);
  }

  template <typename F, typename DefaultValue>
  static BOOST_FORCEINLINE
  auto fold(storage_type& v, DefaultValue const& d, F f) -> decltype(f(d, v))
  {
    return f(d, v);
  }
};

} }

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M0(z, n, _) value_type BOOST_PP_CAT(e, n)

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M1(z, n, N)\
  BOOST_PP_CAT(e, BOOST_PP_SUB(N, BOOST_PP_ADD(n, 1)))

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M2(z, n, text)\
  BOOST_PP_CAT(text, n) = (b != e ? *(b++) : value_type());

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M3(z, n, _) BOOST_PP_CAT(e, n)

#define BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(TPL, TYPE, N, VTYPE, VFILL, VLOAD, VSPLAT)               \
  template <TPL>                                                                                   \
  class pack_traits<TYPE, N, VTYPE> : public pack_traits_base<TYPE, N, VTYPE> {                    \
    using super = pack_traits_base<TYPE, N, VTYPE>;                                                \
                                                                                                   \
    public:                                                                                        \
    using storage_type              = typename super::storage_type;                                \
    using value_type                = typename super::value_type;                                  \
                                                                                                   \
    BOOST_FORCEINLINE static void fill(                                                            \
        storage_type& v,                                                                           \
        BOOST_PP_ENUM(N, BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M0, BOOST_PP_EMPTY())                   \
        ) BOOST_NOEXCEPT                                                                           \
    {                                                                                              \
      v = VFILL(BOOST_PP_ENUM(N, BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M1, N));                        \
    }                                                                                              \
                                                                                                   \
    static BOOST_FORCEINLINE                                                                       \
    void load(storage_type& v, value_type const* ptr) BOOST_NOEXCEPT                               \
    {                                                                                              \
      v = VLOAD(ptr);                                                                              \
    }                                                                                              \
                                                                                                   \
    template <typename Iterator>                                                                   \
    static BOOST_FORCEINLINE                                                                       \
    void load(storage_type& v, Iterator b, Iterator e) BOOST_NOEXCEPT                              \
    {                                                                                              \
      BOOST_PP_REPEAT(N, BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M2, auto e)                             \
                                                                                                   \
      fill(v, BOOST_PP_ENUM(N, BOOST_SIMD_DEFINE_PACK_TRAITS_TPL_M3, BOOST_PP_EMPTY()));           \
    }                                                                                              \
                                                                                                   \
    static BOOST_FORCEINLINE                                                                       \
    void splat(storage_type& v, value_type a) BOOST_NOEXCEPT                                       \
    {                                                                                              \
      v = VSPLAT(a);                                                                               \
    }                                                                                              \
  };                                                                                               \
  /**/

#define BOOST_SIMD_DEFINE_PACK_TRAITS(TYPE, N, VTYPE, VFILL, VLOAD, VSPLAT)                        \
  BOOST_SIMD_DEFINE_PACK_TRAITS_TPL(BOOST_PP_EMPTY(), TYPE, N, VTYPE, VFILL, VLOAD, VSPLAT)

#endif
