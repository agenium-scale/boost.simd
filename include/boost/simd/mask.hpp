//==================================================================================================
/*!
  @file

  Defines the mask adapter for pointer

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_MASK_HPP_INCLUDED
#define BOOST_SIMD_MASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/detail/dispatch/hierarchy/unspecified.hpp>
#include <boost/simd/detail/dispatch/hierarchy_of.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    // Hint-type for masked pointer
    template<typename T, typename Mask, bool isZero = false> struct masked_pointer
    {
      using pointer       = T*;
      using element_type  = T;
      using mask_type     = Mask;

      BOOST_FORCEINLINE operator      pointer() const BOOST_NOEXCEPT { return ptr;      }
      BOOST_FORCEINLINE pointer       get()     const BOOST_NOEXCEPT { return ptr;      }
      BOOST_FORCEINLINE Mask          mask()    const BOOST_NOEXCEPT { return status;   }
      BOOST_FORCEINLINE element_type  value()   const BOOST_NOEXCEPT { return fallback; }

      pointer       ptr;
      element_type  fallback;
      Mask          status;
    };
  }

  /*!
    @ingroup group-api
    @brief Marks a pointer as being masked

    @param ptr Type to mask
    @return ...
  **/
  template<typename T, typename U, typename Mask> BOOST_FORCEINLINE
  detail::masked_pointer<T,Mask> mask(T* ptr, U const& v, Mask const& status)
  {
    return {ptr,T(v),status};
  }

  /// @overload
  template<typename T, typename Mask>
  BOOST_FORCEINLINE detail::masked_pointer<T,Mask, true> mask(T* ptr, Mask const& status)
  {
    return {ptr,T{0},status};
  }
} }

//--------------------------------------------------------------------------------------------------
// Hierarchy and dispatch helpers for masked_pointer
namespace boost { namespace dispatch
{
  template<typename T, typename Zero>
  struct masked_pointer_ : masked_pointer_<typename T::parent, Zero>
  {
    using parent = masked_pointer_<typename T::parent, Zero>;
  };

  template<typename T, typename Zero>
  struct  masked_pointer_<unspecified_<T>,Zero> : unspecified_<T>
  {
    using parent = unspecified_<T>;
  };

  namespace ext
  {
    template<typename T, typename Mask, bool Zero, typename Origin>
    struct hierarchy_of< boost::simd::detail::masked_pointer<T,Mask,Zero>, Origin >
    {
      using base = typename boost::simd::detail::masked_pointer<T,Mask,Zero>::element_type;
      using type = masked_pointer_< boost::dispatch::hierarchy_of_t<base,Origin>, brigand::bool_<Zero> >;
    };
  }
} }

#endif
