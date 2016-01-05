//==================================================================================================
/*!
  @file

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_EMULATION_HPP_INCLUDED
#define BOOST_SIMD_SDK_EMULATION_HPP_INCLUDED

namespace boost { namespace simd
{
  /*!
    @ingroup  group-api
    @brief    Checks if a wide register is emulated

    For a given type @c Type representing a wide register, returns a types indicating if the storage
    o said wide register is using a native wide register type, an aggregate of scalar value or an
    aggregate of smaller wide registers.

    @tparam Type Type to check

    @see native_storage
    @see scalar_storage
    @see aggregate_storage
  **/
  template<typename T> struct emulation
  {
    using type = typename T::traits::storage_kind;
  };

  /// @brief Eager short-cut to emulation metafunction
  template<typename T> using emulation_t = typename emulation<T>::type;
} }

#endif
