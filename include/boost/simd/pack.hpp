//==================================================================================================
/*!
  @file

  Defines the abstraction for SIMD registers

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_PACK_HPP_INCLUDED
#define BOOST_SIMD_PACK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/pack_traits.hpp>
#include <boost/simd/sdk/is_power_of_2.hpp>
#include <boost/simd/sdk/hierarchy/simd.hpp>
#include <boost/align/is_aligned.hpp>
#include <boost/config.hpp>
#include <iterator>
#include <iostream>
#include <cstddef>

namespace boost { namespace simd
{
  /*!
    @ingroup  group-api
    @brief    High-level interface for manipulating SIMD data

    For a given couple @c T and @c N, provides an interface to manipulate SIMD
    data with the best storage possible depending on your hardware.

    @pre @c N must be a power of two.

    @tparam T   Type of the stored elements
    @tparam N   Number of element stored
    @tparam ABI Binary flag to prevent ABI issue
   **/
  template< typename T
          , std::size_t N
          , typename ABI
          >
  class pack {

    static_assert( boost::simd::is_power_of_2_<N>::value
                 , "Cardinal must be a power of 2"
                 );

    public:
    using traits                    = detail::pack_traits<T, N>;

    using storage_type              = typename traits::storage_type;
    using value_type                = typename traits::value_type;
    using size_type                 = typename traits::size_type;

    using reference                 = typename traits::reference;
    using const_reference           = typename traits::const_reference;

    using iterator                  = detail::pack_iterator<pack>;
    using const_iterator            = detail::pack_iterator<pack const>;
    using reverse_iterator          = std::reverse_iterator<iterator>;
    using const_reverse_iterator    = std::reverse_iterator<const_iterator>;

    enum { static_size = N };

    public:

    /*!
      @brief Default constructor

      Constructs a pack without initializing any of its elements.
    **/
    BOOST_FORCEINLINE pack() BOOST_NOEXCEPT {}

    /// @brief Copy constructor
    BOOST_FORCEINLINE pack(pack const& rhs) BOOST_NOEXCEPT : data_(rhs.data_) {}

    /*!
      @brief Construct a pack from aligned, contiguous memory

      Construct a pack by loading @c N value from the pointer @c ptr which references
      an block of contiguous, aligned memory.

      @pre @c ptr is aligned and reference at least @c N contiguous elements.

      @param ptr Pointer to load from
    **/
    BOOST_FORCEINLINE explicit pack(T const* ptr)
    {
      BOOST_ASSERT_MSG( (boost::alignment::is_aligned(sizeof(storage_type), ptr))
                      , "pack(ctor) pointer must be aligned"
                      );
      traits::load(data_, ptr);
    }

    /*!
      @brief Construct a pack from a range of element

      Construct a pack by loading, in a piecewise way, every element contained inside the range
      @c [b,e[ . Contrary to the constructor using aligned contiguous memory, this range can
      be unaligned and non-contiguous.

      @pre <tt>std::distance(e,b) >= N</tt>

      @param b Beginning of the range to load from
      @param e End of the range to load from
    **/
    template < typename Iterator
             , typename = typename std::enable_if<!std::is_fundamental<Iterator>::value>::type
             >
    BOOST_FORCEINLINE pack(Iterator b, Iterator e)
    {
      traits::load(data_, b, e);
    }

    /*!
      @brief Construct a pack from a set of scalar values

      Construct a pack by inserting, in a piecewise way, the exactly @c N scalar values passed
      as parameters.

      @note The number of scalar values must be equal to the cardinal @c N of the pack.

      @param v0 First scalar value to insert
      @param v1 Second scalar value to insert
      @param vn Remaining scalar values to insert
    **/
    template <typename T0, typename T1, typename... Ts>
    BOOST_FORCEINLINE pack(T0 const& v0, T1 const& v1, Ts const&... vn) BOOST_NOEXCEPT
    {
      static_assert( 2 + sizeof...(vn) == static_size
                   , "number of parameters must be the exact same size of N"
                   );
      traits::fill(data_, static_cast<T>(v0), static_cast<T>(v1), static_cast<T>(vn)...);
    }

    /*!
      @brief Construct a pack by replicating a scalar value

      @param value The value to replicate
    **/
    BOOST_FORCEINLINE explicit pack(T const& value) BOOST_NOEXCEPT
    {
      traits::splat(data_, value);
    }

    /// @brief Pack assignment operator
    BOOST_FORCEINLINE pack& operator=(pack const& rhs) BOOST_NOEXCEPT
    {
      data_ = rhs.data_;
      return *this;
    }

    /// @brief Conversion from underlying storage data
    BOOST_FORCEINLINE pack(storage_type const& reg) BOOST_NOEXCEPT : data_(reg) {}

    /// @brief Assignment from underlying storage data
    BOOST_FORCEINLINE pack& operator=( storage_type const& reg ) BOOST_NOEXCEPT
    {
      data_ = reg;
      return *this;
    }

    /// @brief Conversion to underlying storage data
    BOOST_FORCEINLINE operator storage_type() const BOOST_NOEXCEPT { return data_; }

    /// @brief Get reference to internal storage
    BOOST_FORCEINLINE storage_type& storage() BOOST_NOEXCEPT { return data_; }

    /// @overload
    BOOST_FORCEINLINE storage_type const& storage() const BOOST_NOEXCEPT { return data_; }

    /*!
      @brief Random-access to the pack elements

      Return a reference to the @c i th element of the current pack.

      @note This operation may involves proxy reference and is, in general, costly.

      @param i Index to the element to retrieved
    **/
    BOOST_FORCEINLINE reference operator[](std::size_t i)
    {
      return traits::at(data_, i);
    }

    /// @overload
    BOOST_FORCEINLINE const_reference operator[](std::size_t i) const
    {
      return traits::at(data_, i);
    }

    public:

    /// @brief Returns an iterator to the beginning of the pack
    BOOST_FORCEINLINE iterator begin() BOOST_NOEXCEPT
    {
      return iterator(this);
    }

    /// @overload
    BOOST_FORCEINLINE const_iterator begin() const BOOST_NOEXCEPT
    {
      return const_iterator(this);
    }

    /// @brief  Returns an iterator to the end of the pack
    BOOST_FORCEINLINE iterator end() BOOST_NOEXCEPT
    {
      return iterator(this, size());
    }

    /// @overload
    BOOST_FORCEINLINE const_iterator end() const BOOST_NOEXCEPT
    {
      return const_iterator(this, size());
    }

    /// @brief  Returns a constant iterator to the beginning of the pack
    BOOST_FORCEINLINE const_iterator cbegin() const BOOST_NOEXCEPT
    {
      return const_iterator(this);
    }

    /// @brief  Returns a constant iterator to the end of the pack
    BOOST_FORCEINLINE const_iterator cend() const BOOST_NOEXCEPT
    {
      return const_iterator(this, size());
    }

    /// @brief Returns a reverse iterator to the beginning of the pack
    BOOST_FORCEINLINE reverse_iterator rbegin() BOOST_NOEXCEPT
    {
      return reverse_iterator(end());
    }

    /// @overload
    BOOST_FORCEINLINE const_reverse_iterator rbegin() const BOOST_NOEXCEPT
    {
      return reverse_iterator(end());
    }

    /// @brief Returns a reverse iterator to the end of the pack
    BOOST_FORCEINLINE reverse_iterator rend() BOOST_NOEXCEPT
    {
      return reverse_iterator(begin());
    }

    /// @overload
    BOOST_FORCEINLINE const_reverse_iterator rend() const BOOST_NOEXCEPT
    {
      return reverse_iterator(begin());
    }

    /// @brief Returns a constant reverse iterator to the beginning of the pack
    BOOST_FORCEINLINE const_reverse_iterator crbegin() const BOOST_NOEXCEPT
    {
      return const_reverse_iterator(cend());
    }

    /// @brief Returns a constant reverse iterator to the end of the pack
    BOOST_FORCEINLINE const_reverse_iterator crend() const BOOST_NOEXCEPT
    {
      return const_reverse_iterator(cbegin());
    }

    public:
    /// @brief Retrieve the pack's cardinal, i.e the number of element in the pack.
    static BOOST_FORCEINLINE size_type size()     BOOST_NOEXCEPT { return static_size; }

    /// @brief Retrieve the pack's maximum size, i.e the number of element in the pack.
    static BOOST_FORCEINLINE size_type max_size() BOOST_NOEXCEPT { return static_size; }

    /// @brief Empty status for pack
    BOOST_FORCEINLINE bool empty() const BOOST_NOEXCEPT { return false; }

    /// @brief Swap data between two packs
    BOOST_FORCEINLINE void swap(pack& rhs) BOOST_NOEXCEPT
    {
      using std::swap;
      swap(data_, rhs.data_);
    }

    private:
    storage_type data_;
  };

  /// @brief Swap two packs of same type and cardinal
  template <typename T, std::size_t N>
  void swap(pack<T, N>& lhs, pack<T, N>& rhs) BOOST_NOEXCEPT
  {
    lhs.swap(rhs);
  }

  /// @brief Stream insertion for pack
  template <typename T, std::size_t N>
  std::ostream& operator<<(std::ostream& os, pack<T, N> const& p)
  {
    os << '(';
    auto it = p.cbegin();
    os << T(*it);
    // This is safe to increment without checking because pack has always at least 1 element
    ++it;
    for (; it != p.cend(); ++it) {
      os << ", ";
      os << T(*it);
    }
    os << ')';
    return os;
  }
} }

#include <boost/simd/detail/pack_info.hpp>

#endif
