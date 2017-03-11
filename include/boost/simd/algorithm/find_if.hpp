//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_FIND_IF_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_FIND_IF_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/any.hpp>
#include <boost/simd/function/is_nez.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <type_traits>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns an iterator to the first element in the range [first,last)
    for which pred returns true.
    If no such element is found, the function returns last.

    @param first  Beginning of the range of elements
    @param last   End of the range of elements
    @param pred   Predicate to apply to each element in the range.

    @par Requirement

      - @c first, @c last and @c out must be pointers to Vectorizable type.


    @par Example:

      @snippet find_if.cpp find_if

    @par possible output:

      @snippet find_if.txt find_if

  **/
  template<typename T, typename Pred>
  T const* find_if(T const* first, T const* last, Pred pred)
  {
    using p_t =  pack<T>;
    auto pr = segmented_input_range(first,last);
    // prologue
    auto r0 = std::get<0>(pr);
    auto r = std::find_if(r0.begin(), r0.end(), pred);
    if (r != r0.end()) return r;

    // main simd part
    auto r1 = std::get<1>(pr);
    using type_t = typename std::decay<decltype(*r1.begin())>::type;
    auto rv = std::find_if(r1.begin(), r1.end(), [pred](const type_t& x){return any(pred(x)); });
    if (rv != r1.end())
    {
      auto z =  std::find_if((*rv).begin(), (*rv).end(), pred);
      return std::get<0>(pr).end()
        + std::distance(r1.begin(), rv)*bs::cardinal_of_t<p_t>::value + std::distance((*rv).begin(), z);
    }
    // epilogue
    auto r2 = std::get<2>(pr);
    return std::find_if(r2.begin(), r2.end(), pred);
  }

} }

#endif
