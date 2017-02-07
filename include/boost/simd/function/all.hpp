//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_ALL_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-reduction
   This function object returns @ref True if all elements of the argument are
   non zero.

    @see ant, none, nbtrue

    @par Header <boost/simd/function/all.hpp>

    @par Example:

      @snippet all.cpp all

    @par Possible output:

      @snippet all.txt all

  **/
  bool all(Value const &x);
} }
#endif

#include <boost/simd/function/scalar/all.hpp>
#include <boost/simd/function/simd/all.hpp>

#endif
