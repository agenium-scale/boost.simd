//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_SELECT_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_SELECT_HPP_INCLUDED

#include <boost/simd/range/segmented_output_range.hpp>
#include <boost/simd/algorithm/transform.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Select elements from first or second range according to  predicate p
    to put in another range starting at out.

    @param first1  Beginning of the first range of elements
    @param last1   End of the first range of elements
    @param first2  Beginning of the second range of elements
    @param out     Beginning of the ouput range
    @param p       binary predicate used to select.

    @par Requirement

      - @c first1 , @c last1 , @c first2 and @c out must be pointer to type which can be used within
        boost::simd::pack.

    @par Example:

       @snippet select.cpp select

    @par possible output:

       @snippet select.txt select
  **/

  template<typename T, typename P>
  void select(T * first1, T * last1, T * first2, T * out , P p)
  {
    struct local
    {
      using p_t = pack<T>;
      local(P const& p) : p_(p){}

      T operator()(T const& x, T const& y) { return p_(x, y) ? x : y; }
      p_t operator()(p_t const& x, p_t const& y) { return if_else(p_(x, y), x, y); }

      P p_;
    };
    local loc(p);
    transform(first1, last1, first2, out, loc);
//  When c++14
//  transform(first1, last1, first2, out, [&p](auto& x, auto& y){return if_else(p(x, y), x, y); });
  }

} }

#endif
