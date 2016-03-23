//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_LESS_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_less capabilities

    Returns a logical scalar that is the result of the lexicographic
    test for < on all elements of the entries

    It is probably not what you wish. Have a look to @ref is_less

    @par Semantic:

    For every parameters of type T0:

    @code
    as_logical_t<scalar_of_t<T0>> r = compare_less(x,y);
    @endcode

    is similar to:

    @code
     as_logical_t<scalar_of_t<T0>> r = False;
      for(std::size_t i=0;i<cardinal_of<A0>;++i)
      {
        if (x[i] <  y[i])  {r =  True; break;}
        if (y[i] <  x[i])  {r = False; break;}
      }
    @endcode

    @see is_less
    @par Alias:
    @c compare_lt

  **/
  const boost::dispatch::functor<tag::compare_less_> compare_less = {};
} }
#endif

#include <boost/simd/function/scalar/compare_less.hpp>
#include <boost/simd/function/simd/compare_less.hpp>

#endif
