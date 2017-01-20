//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IF_ELSE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object returns the If @c c is @ref True returns @c t else returns @c f
    If vectors, the types involved in the call must share the same number of elements.

   @par Note

      For every parameters @c c of type @c C, @c t and @c f of type @c T : `T r = if_else(c, t, f)` is similar to: `T r = c ? t : f`


   @par Example:

     @snippet if_else.cpp if_else

   @par Possible output:

     @snippet if_else.txt if_else

  **/
  Value if_else(Value const& c, Value const& t, Value const& f);

  //@overload
  Value if_else(LogicalValue const& c, Value const& t, Value const& f);
} }
#endif

#include <boost/simd/function/scalar/if_else.hpp>
#include <boost/simd/function/simd/if_else.hpp>

#endif
