//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ISINCLUDED_C_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
 /*!
    @ingroup group-reduction
    Function object implementing isincluded_c capabilities

    Returns @ref True is only if all bits set in x are not set in y

    @par Semantic:

    For every parameters of types respectively T0, T1 of same bit size:

    @code
    auto r = isincluded_c(x,y);
    @endcode

    is similar to:

    @code
    auto r = all(x&y == zero);
    @endcode
  **/
  template<typename T0, typename T1>
  bool isincluded_c(T0 const& x, T1 const& y);
} }
#endif

#include <boost/simd/function/scalar/isincluded_c.hpp>
#include <boost/simd/function/simd/isincluded_c.hpp>

#endif
