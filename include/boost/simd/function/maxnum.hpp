//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_MAXNUM_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!
    @ingroup group-ieee
    This function object returns the maximum value, ignoring nans.

    @par Decorators

     - std_ for floating entries calls the stdlibc++ function std::fmax.

    @see max, maxnummag,  maxmag

    @par Example:

     @snippet maxnum.cpp maxnum

   @par Possible output:

     @snippet maxnum.txt maxnum

  **/
  Value maxnum(Value const & x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/maxnum.hpp>
#include <boost/simd/function/simd/maxnum.hpp>

#endif
