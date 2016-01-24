//==================================================================================================
/*!
  @file

  Defines the pack_ hierarchy

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_SDK_HIERARCHY_SIMD_HPP_INCLUDED
#define BOOST_SIMD_SDK_HIERARCHY_SIMD_HPP_INCLUDED

#include <boost/simd/config.hpp>
#include <boost/simd/sdk/abi_of.hpp>
#include <boost/simd/sdk/extension_of.hpp>
#include <boost/simd/sdk/native_cardinal.hpp>
#include <boost/dispatch/hierarchy/generic.hpp>
#include <boost/dispatch/hierarchy/unspecified.hpp>
#include <boost/dispatch/meta/value_of.hpp>
#include <boost/dispatch/meta/model_of.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/dispatch/property_of.hpp>

namespace boost { namespace simd
{
  // Forward declaration of pack
  template< typename T
          , std::size_t N = native_cardinal<T>::value
          , typename ABI  = abi_of_t<T,N>
          >
  class pack;

  /*!
    @ingroup group-sdk
    @brief SIMD register type hierarchy tag

    Types classified as pack_ behaves as wide registers

    @tparam T Base hierarchy
    @tparam X SIMD hardware family tag
  **/
  template<typename T, typename X>
  struct  pack_ : pack_<typename T::parent, X>
  {
    using parent = pack_<typename T::parent, X>;
  };

  template<typename T,typename X>
  struct  pack_< boost::dispatch::unspecified_<T>, X >
        : boost::dispatch::generic_<boost::dispatch::property_of_t<T>>
  {
    using parent = boost::dispatch::generic_<boost::dispatch::property_of_t<T>>;
  };

  namespace ext
  {
    // Short-cut for extension_of
    template<typename T, std::size_t N>
    struct  extension_of<pack<T,N>>
          : boost::simd::extension_of< boost::simd::storage_of_t<T,N> >
    {};
  }
} }

namespace boost { namespace dispatch
{
  namespace ext
  {
    template<typename T,std::size_t N> struct model_of<boost::simd::pack<T,N>>
    {
      template<typename X> struct apply { using type = boost::simd::pack<X,N>; };
    };

    template<typename T,std::size_t N> struct value_of<boost::simd::pack<T,N>>
    {
      using type = T;
    };

    template<typename T, std::size_t N, typename Origin>
    struct hierarchy_of<boost::simd::pack<T,N>,Origin>
    {
      using type = boost::simd::pack_ < boost::dispatch::property_of_t<T,Origin>
                                      , boost::simd::extension_of_t<boost::simd::pack<T,N>>
                                      >;
    };
  }
} }

#endif
