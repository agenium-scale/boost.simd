//==================================================================================================
/*!
  @file

  Defines the masked hint

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_MASK_HPP_INCLUDED
#define BOOST_SIMD_MASK_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/dispatch/adapted/common/pointer.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/config.hpp>

namespace boost { namespace simd
{
  namespace detail
  {
    // Hint-type for masked pointer
    template<typename T, typename Mask> struct masked_pointer
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

    @param ptr Type to mark
    @return ...
  **/
  template<typename T, typename Mask>
  BOOST_FORCEINLINE detail::masked_pointer<T,Mask> mask(T* ptr, T const& v, Mask status) BOOST_NOEXCEPT
  {
    return {ptr,v,status};
  }

  /// @overload
  template<typename T, typename Mask>
  BOOST_FORCEINLINE detail::masked_pointer<T,Mask> mask(T* ptr, Mask status) BOOST_NOEXCEPT
  {
    return {ptr,T{0},status};
  }
} }

//--------------------------------------------------------------------------------------------------
// Hierarchy and dispatch helpers for masked_pointer
namespace boost { namespace dispatch
{
  template<typename T>
  struct masked_pointer_ : masked_pointer_<typename T::parent>
  {
    using parent = masked_pointer_<typename T::parent>;
  };

  template<typename T>
  struct  masked_pointer_<unspecified_<T>> : hierarchy_of_t<typename T::pointer>
  {
    // We lose the notion of masked_pointer in the underlying type
    using parent = hierarchy_of_t<typename T::pointer>;
  };

  namespace ext
  {
    template<typename T, typename Mask> struct model_of<boost::simd::detail::masked_pointer<T,Mask>>
    {
      template<typename X> struct apply
      {
        using type = boost::simd::detail::masked_pointer<X,Mask>;
      };
    };

    template<typename T, typename Mask> struct value_of<boost::simd::detail::masked_pointer<T,Mask>>
    {
      using base = typename boost::simd::detail::masked_pointer<T,Mask>::element_type;
      using type = boost::dispatch::value_of_t<base>;
    };

    template<typename T, typename Mask, typename Origin>
    struct hierarchy_of< boost::simd::detail::masked_pointer<T,Mask>, Origin >
    {
      using base = typename boost::simd::detail::masked_pointer<T,Mask>::element_type;
      using type = masked_pointer_< boost::dispatch::hierarchy_of_t<base,Origin> >;
    };
  }
} }

#endif
