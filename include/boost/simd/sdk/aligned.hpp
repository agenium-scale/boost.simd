//==================================================================================================
/*!
  @file

  Defines the aligned hint

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_ALIGNED_HPP_INCLUDED
#define BOOST_SIMD_SDK_ALIGNED_HPP_INCLUDED

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
    // Hint-type for aligned pointer
    template<typename T> struct aligned_pointer
    {
      using pointer = T*;
      using element_type = T;

      BOOST_FORCEINLINE operator  pointer() const BOOST_NOEXCEPT { return ptr; }
      BOOST_FORCEINLINE pointer   get()     const BOOST_NOEXCEPT { return ptr; }

      pointer ptr;
    };
  }

  /*!
    @ingroup group-api
    @brief Marks a pointer as being aligned

    @param ptr Type to mark
    @return ...
  **/
  template<typename T> detail::aligned_pointer<T> aligned(T* ptr)
  {
    return {ptr};
  }
} }

//--------------------------------------------------------------------------------------------------
// Hierarchy and dispatch helpers for aligned_pointer
namespace boost { namespace dispatch
{
  template<typename T>
  struct aligned_pointer_ : aligned_pointer_<typename T::parent>
  {
    using parent = aligned_pointer_<typename T::parent>;
  };

  template<typename T>
  struct  aligned_pointer_<unspecified_<T>> : hierarchy_of_t<typename T::pointer>
  {
    // We lose the notion of aligned_pointer in the underlying type
    using parent = hierarchy_of_t<typename T::pointer>;
  };

  namespace ext
  {
    template<typename T> struct model_of<boost::simd::detail::aligned_pointer<T>>
    {
      template<typename X> struct apply { using type = boost::simd::detail::aligned_pointer<X>; };
    };

    template<typename T> struct value_of<boost::simd::detail::aligned_pointer<T>>
    {
      using type = T;
    };

    template<typename T, typename Origin>
    struct hierarchy_of< boost::simd::detail::aligned_pointer<T>, Origin >
    {
      using type = aligned_pointer_< boost::dispatch::hierarchy_of_t<T,Origin> >;
    };
  }
} }
#endif
