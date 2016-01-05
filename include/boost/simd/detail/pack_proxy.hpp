//==================================================================================================
/*!
  @file

  Defines SSE2 functions for SIMD storage used by pack

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================

#ifndef BOOST_SIMD_DETAIL_PACK_PROXY_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_PROXY_HPP_INCLUDED

#include <boost/config.hpp>
#include <type_traits>

namespace boost { namespace simd { namespace detail
{
  template < typename T
           , std::size_t N
           , typename Storage
           >
  class pack_traits;

  template <typename T, std::size_t N, typename Storage>
  class pack_proxy {

    using traits = pack_traits<T, N, Storage>;

    public:
    BOOST_FORCEINLINE pack_proxy(Storage* data, std::size_t index) : data_(data), index_(index) {}

    BOOST_FORCEINLINE T get() const BOOST_NOEXCEPT
    {
      return traits::get(*data_, index_);
    }

    BOOST_FORCEINLINE void set(T const& other) BOOST_NOEXCEPT
    {
      return traits::set(*data_, index_, other);
    }

    BOOST_FORCEINLINE pack_proxy& operator=(T const& other) BOOST_NOEXCEPT
    {
      set(other);
      return *this;
    }

    BOOST_FORCEINLINE pack_proxy& operator=(pack_proxy const& other) BOOST_NOEXCEPT
    {
      set(other.get());
      return *this;
    }

    // We do need to take `operator...` as parameter because pasting `operator` and `+` leads to
    // an invalid preprocessing token
#define M0(OP_TOKEN, OP)                                                                           \
    template <typename U>                                                                          \
    BOOST_FORCEINLINE                                                                              \
    pack_proxy& OP_TOKEN(U const& other) BOOST_NOEXCEPT                                            \
    {                                                                                              \
      set(get() OP static_cast<T>(other));                                                         \
      return *this;                                                                                \
    }                                                                                              \
    BOOST_FORCEINLINE                                                                              \
    pack_proxy& OP_TOKEN(pack_proxy const& other) BOOST_NOEXCEPT                                   \
    {                                                                                              \
      set(get() OP other.get());                                                                   \
      return *this;                                                                                \
    }                                                                                              \
    /**/

    M0(operator+=, +)
    M0(operator-=, -)
    M0(operator*=, *)
    M0(operator/=, /)
    M0(operator%=, %)
#undef  M0

    // operator: (cast)
    operator T() const BOOST_NOEXCEPT
    {
      return get();
    }

    private:
    Storage*    data_;
    std::size_t index_;
  };

#define M0(OP_TOKEN, OP)                                                                           \
  template <typename T, std::size_t N, typename Storage, typename U>                               \
  BOOST_FORCEINLINE                                                                                \
  T OP_TOKEN(pack_proxy<T, N, Storage> const& lhs, U const& rhs) BOOST_NOEXCEPT                    \
  {                                                                                                \
    return T(lhs.get() OP rhs);                                                                    \
  }                                                                                                \
  template <typename T, std::size_t N, typename Storage, typename U>                               \
  BOOST_FORCEINLINE                                                                                \
  T OP_TOKEN(U const& lhs, pack_proxy<T, N, Storage> const& rhs) BOOST_NOEXCEPT                    \
  {                                                                                                \
    return T(lhs OP rhs.get());                                                                    \
  }                                                                                                \
  template <typename T, std::size_t N, typename Storage>                                           \
  BOOST_FORCEINLINE                                                                                \
  T OP_TOKEN                                                                                       \
      ( pack_proxy<T, N, Storage> const& lhs                                                       \
      , pack_proxy<T, N, Storage> const& rhs                                                       \
      ) BOOST_NOEXCEPT                                                                             \
  {                                                                                                \
    return T(lhs.get() OP rhs.get());                                                              \
  }                                                                                                \
  /**/

  M0(operator+, +)
  M0(operator-, -)
  M0(operator/, /)
  M0(operator*, *)
  M0(operator%, %)
#undef  M0

#define M0(OP_TOKEN, OP)                                                                           \
  template < typename T, std::size_t N, typename Storage, typename U                               \
           , typename Enable = typename std::enable_if<std::is_arithmetic<U>::value>::type         \
           >                                                                                       \
  BOOST_FORCEINLINE                                                                                \
  bool OP_TOKEN(pack_proxy<T, N, Storage> const& lhs, T const& rhs) BOOST_NOEXCEPT                 \
  {                                                                                                \
    return lhs.get() OP rhs;                                                                       \
  }                                                                                                \
  template < typename T, std::size_t N, typename Storage, typename U                               \
           , typename Enable = typename std::enable_if<std::is_arithmetic<U>::value>::type         \
           >                                                                                       \
  BOOST_FORCEINLINE                                                                                \
  bool OP_TOKEN(U const& lhs, pack_proxy<T, N, Storage> const& rhs) BOOST_NOEXCEPT                 \
  {                                                                                                \
    return lhs OP rhs.get();                                                                       \
  }                                                                                                \
  template <typename T, std::size_t N, typename Storage, typename U>                               \
  BOOST_FORCEINLINE                                                                                \
  bool OP_TOKEN                                                                                    \
      ( pack_proxy<T, N, Storage> const& lhs                                                       \
      , pack_proxy<T, N, Storage> const& rhs                                                       \
      ) BOOST_NOEXCEPT                                                                             \
  {                                                                                                \
    return lhs.get() OP rhs.get();                                                                 \
  }                                                                                                \
  /**/

  M0(operator==, ==)
  M0(operator!=, !=)
#undef  M0

  // operator: !
  template <typename T, std::size_t N, typename Storage>
  BOOST_FORCEINLINE
  bool operator!(pack_proxy<T, N, Storage> const& p) BOOST_NOEXCEPT
  {
    return !p.get();
  }
} } }

#endif
