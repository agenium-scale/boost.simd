//==================================================================================================
/*!
  @file

    @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_DIV_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!
    @ingroup group-oerator
    This function object computes the quotient of the two parameters of the
    same type with or without option.

    @par Header <boost/simd/function/div.hpp>

    @par Notes

    For any value @c a and @c b of same type `div({option, }a, b)`
    returns the quotient of @c a by @c b respecting to the option specified.

   With no option this function is equivalent to @ref divides(a, b).

   Options may be c@ref ceil, @ref floor, @ref fix, @ref round, @ref nearbyint (in the namespace booost::simd)
   and provides the same result as if the function object whose option is the name was applied to the floating
   division of the parameters.

    @see divides, rec

    @par Example:

      @snippet div.cpp div

    @par Possible output:

      @snippet div.txt div

  **/

  //@{
  Value div(Option const&, Value const& a, Value const& b);
  Value div(Value const& a, Value const& b);
  //@}

} }
#endif

#include <boost/simd/function/scalar/div.hpp>
#include <boost/simd/function/simd/div.hpp>


#endif
