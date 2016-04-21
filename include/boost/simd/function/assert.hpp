//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ASSERT_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ASSERT_HPP_INCLUDED

#include <boost/simd/detail/decorator.hpp>

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-decorator

    call the asserting version if it exists.

    @par Semantic

    For scalar parameters,

    @code
    T r = assert_(func)(< func parameters >);
    @endcode

     @see  sqrt,  pow and log10

  **/
  template<typename T> auto assert_(T const& x) {}

} }
#endif

namespace boost { namespace simd
{
  struct assert_tag
  {
    using parent = assert_tag;
    using hierarchy_tag = void;
  };

  const detail::decorator<assert_tag> assert_ = {};
} }

#endif
