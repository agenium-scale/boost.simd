//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_IFNOT_NEG_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_IFNOT_NEG_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-boolean

    This function object conditionally returns -x if cond is @ref False and x otherwise.

   @par Example:

     @snippet negifnot.cpp negifnot

   @par Possible output:

     @snippet negifnot.txt negifnot

  **/
  Value ifnot_neg(LogicalValue const& cond, Value const & x);

  //@overload
  Value ifnot_neg(Value const& cond, Value const & x);

} }
#endif

#include <boost/simd/function/scalar/ifnot_neg.hpp>
#include <boost/simd/function/simd/ifnot_neg.hpp>

#endif
