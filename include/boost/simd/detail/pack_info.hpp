//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_DETAIL_PACK_INFO_HPP_INCLUDED
#define BOOST_SIMD_DETAIL_PACK_INFO_HPP_INCLUDED

#include <boost/simd/cardinal_of.hpp>
#include <boost/dispatch/meta/downgrade.hpp>

namespace boost { namespace simd
{
  // Overload for cardinal_of
  template<typename T, std::size_t N, typename ABI>
  struct cardinal_of<pack<T,N,ABI>> : std::integral_constant<std::size_t,N>
  {};
} }

namespace boost { namespace dispatch { namespace detail
{
  // Overload for downgrade
  template<typename T, std::size_t N, typename ABI,typename Sign>
  struct downgrade<boost::simd::pack<T,N,ABI>,Sign>
  {
    using type = boost::simd::pack<downgrade_t<T,Sign>, N*2>;

    static_assert ( sizeof(downgrade_t<T,Sign>) != sizeof(T)
                  , "boost::dispatch::downgrade can't compute a valid type"
                  );
  };
} } }

#endif
