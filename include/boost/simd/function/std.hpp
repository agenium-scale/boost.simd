//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_STD_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_STD_HPP_INCLUDED

#include <boost/simd/detail/decorator.hpp>

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
  @ingroup group-decorator

    call the corresponding standard libc++ function.

    @par Semantic

    For scalar parameters,

    @code
    T r = std_(func)(< func parameters >);
    @endcode

    is equivalent to:

    @code
    T r = std::func(< func parameters >);
    @endcode

    @par Note:

    - for simd vector parameter a map of the standard function is done
      for each vector element: this is never vectorized.


    - std_ is given to be able to shortly compare boost.simd functors
    and stdlibc++ equivalent behaviours.

    @see  fast_,  raw_

  **/
  template<typename T> auto std_(T const& x) {}

} }
#endif

namespace boost { namespace simd
{
  struct std_tag : boost::dispatch::unspecified_<std_tag>
  {
    using parent = boost::dispatch::unspecified_<std_tag>;
  };

  const detail::decorator<std_tag> std_ = {};
} }

#endif
