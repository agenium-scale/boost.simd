//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS
  @copyright 2016 J.T. Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_COMPARE_GREATER_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{

 /*!

    @ingroup group-reduction
    Function object implementing compare_greater capabilities

    return a bool that is the result of the lexicographic
    test for > on all elements of the entries

    It is probably not what you wish. Have a look to @ref is_greater

    @par Semantic:

    For every parameters of type T0:

    @code
    as_logical_t<scalar_of_t<T0>> r = compare_greater(x,y);
    @endcode

    is similar to:

    @code
      as_logical_t<scalar_of_t<T0>> r = False;
      for(std::size_t i=0;i<cardinal_of<A0>;++i)
      {
        if (x[i] > y[i])  {r =  True; break;}
        if (y[i] > x[i])  {r = False; break;}
      }
    @endcode

    @par Alias:
    @c compare_gt

    @see is_greater

  **/
  const boost::dispatch::functor<tag::compare_greater_> compare_greater = {};
} }
#endif

#include <boost/simd/function/scalar/compare_greater.hpp>
#include <boost/simd/function/simd/compare_greater.hpp>

#endif
