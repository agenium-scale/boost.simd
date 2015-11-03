//==================================================================================================
/*!
  @file

  Defines SIMD storage type generator

  @copyright 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_SIMD_STORAGE_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_SIMD_STORAGE_HPP_INCLUDED

#include <algorithm>
#include <array>

namespace boost { namespace simd { namespace detail
{
  /*!
    @ingroup  group-detail
    @brief    Storage type for SIMD data

    For a given couple @c Type x @c Cardinal, provides type and utility functions to handle data
    block containing @c Cardinal elements of type @c Type in an optimized way.

    @tparam Type      Type of the stored elements
    @tparam Cardinal  Number of element stored
  **/
  template<typename Type, std::size_t Cardinal, typename Enable = void>
  struct simd_storage
  {
    using emulated_storage  = void;
    using type              = std::array<Type,Cardinal>;
    using iterator          = typename type::iterator;
    using const_iterator    = typename type::const_iterator;
    using reference         = typename type::reference;
    using const_reference   = typename type::const_reference;

    template<typename Iterator> BOOST_FORCEINLINE static void load(type& d, Iterator it)
    {
      std::copy(it, it+Cardinal, d.begin());
    }

    template<typename Iterator> BOOST_FORCEINLINE static void load(type& d, Iterator b, Iterator e)
    {
      std::copy(b, e, d.begin());
    }

    template<typename Value> BOOST_FORCEINLINE static void splat(type& d, Value v)
    {
      d.fill(v);
    }

    template<typename... Ts> BOOST_FORCEINLINE static void fill(type& d, Ts const&... v)
    {
      d = type{{ static_cast<Type>(v)... }};
    }

    template<std::size_t I> BOOST_FORCEINLINE static reference at(type& d)
    {
      return at(d,I);
    }

    template<std::size_t I> BOOST_FORCEINLINE static const_reference at(type const& d)
    {
      return at(d,I);
    }

    BOOST_FORCEINLINE static reference at(type& d, std::size_t i)
    {
      return d[i];
    }

    BOOST_FORCEINLINE static const_reference at(type const& d, std::size_t i)
    {
      return d[i];
    }
  };
} } }

#endif
