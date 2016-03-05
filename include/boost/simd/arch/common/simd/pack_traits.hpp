//==================================================================================================
/*!
  @file

  Defines generic functions and traits for SIMD storage used by pack

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_COMMON_SIMD_PACK_TRAITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_COMMON_SIMD_PACK_TRAITS_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/arch/common/tags.hpp>
#include <boost/simd/arch/spec.hpp>
#include <array>

namespace boost { namespace simd { namespace detail
{
  // emulated_storage: *
  //-----------------------------------------------------------------------------------------------
  template <typename T, std::size_t N>
  class pack_traits<T, N, std::array<T, N> > {
    public:
    using storage_type              = std::array<T, N>;

    using value_type                = T;
    using size_type                 = std::size_t;

    using reference                 = value_type&;
    using const_reference           = value_type const&;

    using storage_kind = ::boost::simd::scalar_storage;

    enum { static_size = N };

    template <typename... Ts>
    BOOST_FORCEINLINE static void fill(storage_type& d, Ts const&... v)
    {
      d = std::array<T, N>{{ static_cast<T>(v)... }};
    }

    BOOST_FORCEINLINE static reference at(storage_type& d, std::size_t i) BOOST_NOEXCEPT
    {
      return d[i];
    }

    BOOST_FORCEINLINE static const_reference at(storage_type const& d, std::size_t i) BOOST_NOEXCEPT
    {
      return d[i];
    }

    template <typename Iterator>
    BOOST_FORCEINLINE static void load(storage_type& d, Iterator it)
    {
      std::copy(it, it+N, d.begin());
    }

    template <typename Iterator>
    BOOST_FORCEINLINE static void load(storage_type& d, Iterator b, Iterator e)
    {
      std::copy(b, e, d.begin());
    }

    template <typename Value>
    BOOST_FORCEINLINE static void splat(storage_type& d, Value v)
    {
      d.fill(v);
    }
  };

  // aggregated_storage: *
  //-----------------------------------------------------------------------------------------------

  // Static unroll of call to `pack_traits::fill` for aggregated storage.

  // static_unrolled_fill: base case
  template < typename T
           , std::size_t Index
           , std::size_t NumberOfVectors
           , typename SIMD
           , std::size_t Card
           , bool Stop = Index == NumberOfVectors // Needed to avoid ambiguity
           >
  struct static_unrolled_fill {
    template <typename... Ts>
    BOOST_FORCEINLINE static void fill(std::array<SIMD, NumberOfVectors>&, Ts const&...) {
    }
  };

  // static_unrolled_fill: Cardinal == 2

#define BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL_M0(z, n, text)\
  T const& BOOST_PP_CAT(text, n)

#define BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL_M1(z, n, text)\
  BOOST_PP_CAT(text, n)

#define BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(N)                                             \
  template < typename T                                                                            \
           , std::size_t Index                                                                     \
           , std::size_t NumberOfVectors                                                           \
           , typename SIMD                                                                         \
           >                                                                                       \
  struct static_unrolled_fill<T, Index, NumberOfVectors, SIMD, N, false> {                         \
    template <typename... Ts>                                                                      \
    BOOST_FORCEINLINE static void fill(                                                            \
        std::array<SIMD, NumberOfVectors>& storage                                                 \
        , BOOST_PP_ENUM(N, BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL_M0, e)                      \
        , Ts const&... en                                                                          \
        )                                                                                          \
    {                                                                                              \
      pack_traits<T, N, SIMD>::fill(                                                               \
          storage[Index],                                                                          \
          BOOST_PP_ENUM(N, BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL_M1, e));                    \
                                                                                                   \
      static_unrolled_fill<T, Index + 1, NumberOfVectors, SIMD, N>::fill(storage, static_cast<T>(en)...);          \
    }                                                                                              \
  };                                                                                               \
  /**/

  BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(2);
  BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(4);
  BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(8);
  BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(16);
  BOOST_SIMD_PACK_TRAITS_STATIC_UNROLLED_FILL(32);

  template <typename T, typename SIMD, std::size_t N, std::size_t NumberOfVectors>
  class pack_traits<T, N, std::array<SIMD, NumberOfVectors> > {
    public:
    enum {
      static_size = N,
      cardinal = N / NumberOfVectors
    };

    using storage_type              = std::array<SIMD, NumberOfVectors>;
    using internal_pack_traits      = pack_traits<T, cardinal, SIMD>;

    using value_type                = T;
    using size_type                 = std::size_t;

    using reference                 = typename internal_pack_traits::reference;
    using const_reference           = typename internal_pack_traits::const_reference;

    using storage_kind = ::boost::simd::aggregate_storage;

    public:
    template <typename... Ts>
    BOOST_FORCEINLINE static void fill(storage_type& d, Ts const&... v)
    {
      // We do need to statically unroll `pack_traits::fill` as `v` is variadic.
      // We decompose `v` in `cardinal` arguments (`NumberOfVectors` times).
      static_unrolled_fill<T, 0, NumberOfVectors, SIMD, cardinal>::fill(d, v...);
    }

    BOOST_FORCEINLINE static reference at(storage_type& d, std::size_t i)
    {
      return internal_pack_traits::at(d[i / cardinal], i % cardinal);
    }

    BOOST_FORCEINLINE static const_reference at(storage_type const& d, std::size_t i)
    {
      return internal_pack_traits::at(d[i / cardinal], i % cardinal);
    }

    BOOST_FORCEINLINE static void load(storage_type& d, value_type const* ptr)
    {
      for (auto& a : d) {
        internal_pack_traits::load(a, ptr);
        ptr += cardinal;
      }
    }

    template <typename Iterator>
    BOOST_FORCEINLINE static void load(storage_type& d, Iterator b, Iterator e)
    {
      auto it = b;
      for (std::size_t i = 0; i < NumberOfVectors && it != e; ++i) {
        // Do not use `internal_pack_traits::load(d[i], it)` here as `b` could be
        // a forward iterator, which mean that we can only use `++` operator.
        //
        // Calling `internal_pack_traits::load(d[i], it)` will move
        // the iterator inside the function and we won't be able to move the
        // iterator using the following: `b += N` as `b` can be a forward iterator.
        //
        // Instead, we doing it by hand using `internal_pack_traits::at`!
        for (std::size_t j = 0; j < cardinal && it != e; ++j, ++it) {
          internal_pack_traits::at(d[i], j) = *it;
        }
      }
    }

    template <typename Value>
    BOOST_FORCEINLINE static void splat(storage_type& d, Value v)
    {
      for (auto& a : d) {
        internal_pack_traits::splat(a, v);
      }
    }
  };

} } }

#endif
