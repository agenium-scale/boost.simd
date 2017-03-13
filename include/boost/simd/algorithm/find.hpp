//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_FIND_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_FIND_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/fma.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns an iterator to the first element in the range [first,last)
    for which the element equals val.
    If no such element is found, the function returns last.

    @param first  Beginning of the range of elements to find
    @param last   End of the range of elements to find
    @param val    Value to search for in the range.

    @par Requirement

      - @c first, @c last and @c out must be pointer to Vectorizable type.

      - @c val must be a scalar value convertible to the pointee type of first.

    @par Example:

       @snippet find.cpp find

    @par possible output:

       @snippet find.txt find

    @return An iterator to the first element in the range that compares equal to val.
    If no elements match, the function returns last.
.
  **/
  template<typename T, typename U>
  T const* find(T const* first, T const* last, U const & val)
  {
    using p_t =  pack<T>;
    auto pr = segmented_input_range(first,last);
    // prologue
    auto r0 = std::get<0>(pr);
    auto r = std::find(r0.begin(), r0.end(), val);
    if (r != r0.end()) return r;

    // main simd part
    auto r1 = std::get<1>(pr);
    using type_t = typename std::decay<decltype(*r1.begin())>::type;
    const type_t v(val);
    auto rv = std::find_if(r1.begin(), r1.end(), [v](const type_t& x){return any(v == x); });
    if (rv != r1.end())
    {
      auto z =  std::find((*rv).begin(), (*rv).end(), val);
      return std::get<0>(pr).end()
        + std::distance(r1.begin(), rv)*bs::cardinal_of_t<p_t>::value + std::distance((*rv).begin(), z);
    }
    // epilogue
    auto r2 = std::get<2>(pr);
    return std::find(r2.begin(), r2.end(), val);

  }

} }

#endif
