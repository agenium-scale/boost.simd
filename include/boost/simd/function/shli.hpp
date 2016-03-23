//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHLI_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHLI_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-operator
    Function object implementing shli capabilities

    return left shift of the first operand by the second
    that must be of integer type and of the same number
    of elements as the first parameter
    Infix notation can be used with operator '<<'

    This is a convenient alias of @ref shift_left
  **/
  const boost::dispatch::functor<tag::shli_> shli = {};
} }
#endif

#include <boost/simd/function/scalar/shift_left.hpp>
#include <boost/simd/function/simd/shli.hpp>

#endif
