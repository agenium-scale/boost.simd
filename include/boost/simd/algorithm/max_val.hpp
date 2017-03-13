//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_MAX_VAL_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_MAX_VAL_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/function/if_else.hpp>
#include <boost/simd/function/max.hpp>
#include <boost/simd/function/maximum.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/is_aligned.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns the value of the element with the smallest value in the range [first,last),
    The largest possible value for the order if the range is empty.

    @param first  Beginning of the range of elements to max_val
    @param last   End of the range of elements to max_val
    @param comp   comparison function object that will be applied.

    @par Requirement

      - @c first and @c last must be pointer to Vectorizable type.

      - @c comp must be a polymorphic unary function object, i.e callable on generic types.
      - if @c comp is not present the function test is done with operator <

    @par Example

    The following code uses simd::max_val to find the greatest and smallest element
    @c std::vector.
    @snippet max_val.cpp max_val
    @snippet max_val.txt max_val

    @return the maximum value of the range elements.
  **/
  template<typename T, typename Comp>
  T max_val(T const* first, T const* last, Comp comp)
  {
    if (first == last) return comp(T(0), T(1)) ? Inf<T>() : Minf<T>();
    auto pr = segmented_input_range(first,last);
    T m =  *first;
    // prologue
    for( auto const & e : std::get<0>(pr) ){
      if (comp(m, e))  m = e;
    }

    // main SIMD part
    using p_t =  pack<T>;
    p_t mm(m);
    for( auto const & e : std::get<1>(pr) )
    {
      mm =  if_else(comp(m, e), e, m);
    }
    m =  mm[0];
    for (  size_t i =  1; i < p_t::static_size;  ++i){
      if (comp(m, mm[i])) m = mm[i];
    }

    // epilogue
    for( auto const & e : std::get<2>(pr) ){
      if(comp(m, e))  m = e;
    }

    return m;
  }

  template<typename T>
  T max_val(T const* first, T const* last)
  {

    if (first == last) return Minf<T>();
    auto pr = segmented_input_range(first,last);
    T m = *first;
    // prologue
    for( auto const & e : std::get<0>(pr) ){
      m = max(e, m);
    }

    // main SIMD part
    using p_t =  pack<T>;
    p_t mm(m);
    for( auto const & e : std::get<1>(pr) )
    {
      mm = max(e, mm);
    }
    m =  maximum(mm);
    // epilogue
    for( auto const & e : std::get<2>(pr) ){
      m = max(e, m);
    }

    return m;
  }

} }

#endif
