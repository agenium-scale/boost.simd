//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_NEGATE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-ieee
    Function object implementing negate capabilities

    Retuns the first element multiplied by the @ref sign of the second.

    @par Semantic:

    @code
    T r = negate(x,y);
    @endcode

    is similar to:

    @code
    T r =  x*sign(y);
    @endcode

    @par Note
    If y is @ref Zero the result is zero. If you want to avoid that use
    @ref negatenz or @ref copysign.

    @see sign, negatenz, copysign,  Mzero,  is_positive, is_negative

  **/
  Value negate(Value const & x, Value const& y);
} }
#endif

#include <boost/simd/function/scalar/negate.hpp>
#include <boost/simd/function/simd/negate.hpp>

#endif
