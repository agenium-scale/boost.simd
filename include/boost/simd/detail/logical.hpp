//==================================================================================================
/*!
  @file

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_LOGICAL_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_LOGICAL_HPP_INCLUDED

#include <boost/config.hpp>

namespace boost { namespace simd { namespace detail
{
  // traits of pack<logical<T>,N> is the one of its underlying type
  template<typename T, std::size_t N, typename Storage>
  class pack_traits<boost::simd::logical<T>, N, Storage>
      : public pack_traits<T, N, Storage>
  {
    public:
    using value_type  = boost::simd::logical<T>;
  };

  // Remove ambiguity with the other pack_traits
  template <typename T, std::size_t N>
  class pack_traits<boost::simd::logical<T>, N, std::array<boost::simd::logical<T>, N> >
  {
    public:
    using storage_type      = std::array<boost::simd::logical<T>, N>;
    using value_type        = boost::simd::logical<T>;
    using size_type         = std::size_t;
    using reference         = value_type&;
    using const_reference   = value_type const&;
    using storage_kind      = ::boost::simd::scalar_storage;

    enum { static_size = N, element_size = 1 };
    enum { alignment = sizeof(T) };

    template<typename Pack>
    BOOST_FORCEINLINE static reference at(Pack& d, std::size_t i)
    {
      return (d.storage())[i];
    }

    template<typename Pack>
    BOOST_FORCEINLINE static const_reference at(Pack const& d, std::size_t i)
    {
      return (d.storage())[i];
    }
  };

  template <typename T, typename SIMD, std::size_t N, std::size_t NumberOfVectors>
  class pack_traits<boost::simd::logical<T>, N, std::array<SIMD, NumberOfVectors> >
  {
    public:

    using storage_type    = std::array<SIMD, NumberOfVectors>;
    using value_type      = boost::simd::logical<T>;
    using size_type       = std::size_t;
    using reference       = typename SIMD::reference;
    using const_reference = typename SIMD::const_reference;
    using storage_kind    = ::boost::simd::aggregate_storage;

    enum  { static_size = N, element_size = N / NumberOfVectors};
    enum  { alignment   = SIMD::alignment };

    public:

    template<typename Pack> BOOST_FORCEINLINE
    static reference at(Pack& d, std::size_t i)
    {
      return (d.storage())[i / element_size][i % element_size];
    }

    template<typename Pack> BOOST_FORCEINLINE
    static const_reference at(Pack const& d, std::size_t i)
    {
      return (d.storage())[i / element_size][i % element_size];
    }
  };
} } }

#endif
