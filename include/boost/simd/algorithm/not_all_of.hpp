//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_NOT_ALL_OF_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_NOT_ALL_OF_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/identity.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns true if pred returns false on any element in the range [first,last),
    and false otherwise (in particular when the range is empty).

    @param first  Beginning of the range of elements to test
    @param last   End of the range of elements
    @param pred   predicate function object that will be applied.

    @par Requirement

      - @c first and @c last must be pointers to Vectorizable type.

      - @c pred must be a polymorphic unary function object, i.e cnot_allable on generic types.
      - if @c pred is not present the function test if any  element is zero

    @par Example;:

      @snippet not_all_of.cpp not_all_of

    @par Possible output:

      @snippet not_all_of.txt not_all_of

  **/
  template<typename T, typename Pred>
  bool not_all_of(T const* first, T const* last, Pred f)
  {

    auto pr = segmented_input_range(first,last);

    // prologue
    auto r0 = std::get<0>(pr);
    if (!std::all_of(r0.begin(),  r0.end(), f)) return true;

    // main SIMD part
    auto r1 = std::get<1>(pr);
    using type_t = typename std::decay<decltype(*r1.begin())>::type;
    if (!std::all_of(r1.begin(),  r1.end(),  [&f](const type_t&  x){ return all(f(x)); }))
    {
      return true;
    }

    // epilogue
    auto r2 = std::get<2>(pr);
    if (!std::all_of(r2.begin(),  r2.end(), f)) return true;

    return false;
  }

  template<typename T>
  bool not_all_of(T const* first, T const* last)
  {
    return not_all_of(first, last, detail::identity());
  }

} }

#endif
