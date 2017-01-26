//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_GENMASK_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
 /*!
    @ingroup group-bitwise
    This function object returns a mask of bits. All ones if the
    input element is non @ref Zero else all zeros.

    @see genmaskc


   @par Example:

     @snippet genmask.cpp genmask

   @par Possible output:

     @snippet genmask.txt genmask

    @par Alias:
    @c if_allbits_else_zero

    @see if_allbits_else

  **/
  template<typename A>  A genmask(const A& a) {}

  /*!
    @overload
  */
  template<typename T, typename A> T genmask(const A& a) {}
} }
#endif

#include <boost/simd/function/scalar/genmask.hpp>
#include <boost/simd/function/simd/genmask.hpp>

#endif
