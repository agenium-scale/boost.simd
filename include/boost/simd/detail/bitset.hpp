//==================================================================================================
/**
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_BITSET_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_BITSET_HPP_INCLUDED

#include <boost/simd/detail/dispatch/meta/make_integer.hpp>
#include <boost/simd/function/scalar/popcnt.hpp>
#include <type_traits>
#include <cstddef>
#include <cstdint>
#include <bitset>

namespace boost { namespace simd
{
  namespace detail
  {
    // Roudn to newt power of 2
    template<std::size_t N> struct nextpow2
    {
      static constexpr std::size_t v0 = N-1;
      static constexpr std::size_t v1 = v0 | v0 >> 1;
      static constexpr std::size_t v2 = v1 | v1 >> 2;
      static constexpr std::size_t v3 = v2 | v2 >> 4;
      static constexpr std::size_t v4 = v3 | v3 >> 8;
      static constexpr std::size_t v5 = v4 | v4 >> 16;
      static constexpr std::size_t value = v0 ? v5+1 : 1;
    };

    // Compute how many bytes is N bits
    template<std::size_t N> struct bitset_size
    {
      static constexpr std::size_t base = (N < 8) ? 1 : (N/8 + (N%8 ? 1 : 0));
      static constexpr std::size_t value = nextpow2<base>::value;
    };

    // Small N optimized bitset implementation
    template<std::size_t N> struct bitset
    {
      static constexpr std::size_t bitmask      = (1<<N) - 1;
      using bits_type = bd::make_integer_t<bitset_size<N>::value,unsigned>;

      constexpr bitset()                noexcept : bits_{} {}
      constexpr bitset(bitset const& v) noexcept : bits_{v.bits_} {}
      constexpr bitset(std::size_t n)   noexcept : bits_{static_cast<bits_type>(n & bitmask)} {}

      bitset& reset()               noexcept { bits_ = 0U;                    return *this; }
      bitset& reset(std::size_t p)  noexcept { bits_ = bits_ & ~((1ULL<<p));  return *this; }

      bitset& set() noexcept { bits_ = ~0ULL; return *this; }
      bitset& set(std::size_t p, bool v = true) noexcept
      {
        reset(p);
        bits_ |= (v<<p);
        return *this;
      }

      bitset& flip()                { bits_ = ~bits_;     return *this; }
      bitset& flip(std::size_t p)   { bits_ ^= (1ULL<<p); return *this; }

      constexpr bool operator[]( std::size_t p ) const noexcept { return bits_ & (1<<p); }

      bool test( std::size_t p ) const
      {
        if(p>N) throw std::out_of_range{"Bit index is out of range"};
        return this->operator[](p);
      }

      static constexpr std::size_t size() noexcept { return N; }

                std::size_t count() const noexcept { return boost::simd::popcnt(bits_); }
      constexpr bool        all()   const noexcept { return bits_ == bitmask;           }
      constexpr bool        any()   const noexcept { return bits_ != 0;                 }
      constexpr bool        none()  const noexcept { return bits_ == 0;                 }

      constexpr bool operator==(bitset const& other) const noexcept { return bits_ == other.bits_; }
      constexpr bool operator!=(bitset const& other) const noexcept { return bits_ != other.bits_; }

      bitset  operator>> (std::size_t pos) const { return bitset{bits_ >> pos}; }
      bitset  operator<< (std::size_t pos) const { return bitset{bits_ << pos}; }

      bitset& operator<<=(std::size_t pos) { bits_ <<= pos; return *this; }
      bitset& operator>>=(std::size_t pos) { bits_ >>= pos; return *this; }

      bitset& operator&=( const bitset<N>& other ) noexcept { bits_ &= other.bits_; return *this; }
      bitset& operator|=( const bitset<N>& other ) noexcept { bits_ |= other.bits_; return *this; }
      bitset& operator^=( const bitset<N>& other ) noexcept { bits_ ^= other.bits_; return *this; }

      bitset  operator~() const noexcept { return bitset( ~bits_ ); }

      operator std::bitset<N>() noexcept { return std::bitset<N>{bits_}; }

      constexpr unsigned long      to_ulong()  const noexcept { return bits_; }
      constexpr unsigned long long to_ullong() const noexcept { return bits_; }

      private:
      bits_type bits_;
    };

    template<std::size_t N>
    std::ostream& operator<<( std::ostream& os, bitset<N> const& b)
    {
      os << b.to_ullong();
      return os;
    }

    template<std::size_t N>
    struct select_bitset : std::conditional<(N>64),std::bitset<N>,bitset<N>>
    {};
  }

  // Optimize small bitset if N <= 64bits - els euse std::bitset
  template<std::size_t N> using bitset = typename detail::select_bitset<N>::type;
} }

#endif
