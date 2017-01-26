//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_MINUS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object conditionally returns @c x-y (respectively @c x)  if @c c is @ref True
    (respectively  @ref False)

   @par Example:

     @snippet if_minus.cpp if_minus

   @par Possible output:

     @snippet if_minus.txt if_minus

  **/
  Value if_minus(Value const& c, Value const& x, Value const&  y);

  /*!
    @overload
  */
  Value if_minus(LogicalValue const& c, Value const& x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/if_minus.hpp>
#include <boost/simd/function/simd/if_minus.hpp>

#endif
