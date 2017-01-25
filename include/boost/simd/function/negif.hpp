//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGIF_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean
    This function object returns  -x if c is @ref True and x otherwise.

   @par Example:

     @snippet negif.cpp negif

   @par Possible output:

     @snippet negif.txt negif

  **/
  Value negif(LogicalValue const& cond, Value const & x);

  /*!
    @overload
  */
  Value negif(Value const& c, Value const & x);
} }
#endif

#include <boost/simd/function/scalar/negif.hpp>
#include <boost/simd/function/simd/negif.hpp>

#endif
