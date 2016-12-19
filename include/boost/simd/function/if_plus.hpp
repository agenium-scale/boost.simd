//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_PLUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_PLUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-boolean
    Function object implementing if_plus capabilities

    The function returns either the second parameter or the sum of the second
    and third parameters, depending on whether the first parameter is
	@ref False or @ref True .

    @par Semantic:

    For every parameter @c c of type @c C and @c x, @c y of type @c T :

    @code
    T r = if_plus(c, x, y);
    @endcode

    is similar to:

    @code
    T r = c ? x + y : x;
    @endcode
  **/
  Value if_plus(Value const& c, Value const& x, Value const& y);

  //@overload
  Value if_plus(LogicalValue const& c, Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/if_plus.hpp>
#include <boost/simd/function/simd/if_plus.hpp>

#endif
