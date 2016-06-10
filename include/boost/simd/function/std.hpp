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

    Decorate a function to use the standard compliant implementation.

    @par Semantic

    For a function object @c func,

    @code
    auto std_func = std_(func);
    @endcode

    generates a function object that behaves strictly as the standard compliant version of @c func.
    This implies, for example:

    - for simd vector parameter a map of the standard function is done
      for each vector element: this is never vectorized.

    - std_ is given to be able to shortly compare boost.simd functors
    and stdlibc++ equivalent behaviours.

    @see @ref Decorators

  **/
  const detail::decorator<std_tag> std_ = {};
} }
#endif

namespace boost { namespace simd
{
  struct std_tag : decorator_<std_tag>
  {
    using parent = decorator_<std_tag>;
  };

  const detail::decorator<std_tag> std_ = {};
} }

#endif
