//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_EQUAL_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_EQUAL_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/compare_equal.hpp>
#include <boost/simd/function/all.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <boost/core/demangle.hpp>
#include <type_traits>


namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns true if the range [first1, last1) is equal
    to the range [first2, first2 + (last1 - first1)), and false otherwise

    @param first1, last1  -   the first range of the elements to compare
    @param first2         -   the beginning of the second range of the elements to compare

    @par Requirement

      - @c first, @c last and @c out must be pointer to Vectorizable type.


    @par Example:

      @snippet equalrange.cpp equalrange

    @par Possible output:

      @snippet equalrange.txt equalrange

  **/

  template<typename T>
  bool equal(T const* first, T const* last, const T* first2)
  {
    using vT = pack<T>;

    auto pr = segmented_input_range(first,last);

    // prologue
    for( auto const & e : std::get<0>(pr) ) if (!(e == *first2++)) return false;

    // main SIMD part - checks if we can store efficiently or not
    if(boost::simd::detail::is_aligned(first2, vT::alignment))
    {
      for( auto const& e : std::get<1>(pr) )
      {
        if(!compare_equal( aligned_load<vT>(first2), e)) return false;
        first2 += vT::static_size;
      }
    }
    else
    {
      for( auto const& e : std::get<1>(pr) )
      {
        if(!compare_equal(load<vT>(first2), e)) return false;
        first2 += vT::static_size;
      }
    }

    // epilogue
    for( auto const & e : std::get<2>(pr) ) if(!(e == *first2++)) return false;

    return true;
  }


  /*!
    @ingroup group-std

    Returns true if all the pairs in the range [first1, last1) and the range [first2, first2 + (last1 - first1)),
    satisfy f and false otherwise

    @param first1, last1  -   the first range of the elements to compare
    @param first2         -   the beginning of the second range of the elements to compare
    @param f       binary predicate operation function object that will be applied.

    @par Requirement

      - @c first, @c last and @c out must be pointer to Vectorizable type.

      - @c f must be a polymorphic binary function object, i.e callable on generic types.
      - @c boost::simd::pack<T1>::static_size @c == @c boost::simd::pack<T2>::static_size @c

    @par Example:

      @snippet equal.binary.cpp equal-binary

    @par Possible output:

      @snippet equal.binary.txt equal-binary

  **/
  template<typename T, typename Pred>
  bool equal(T const* first1, T const* last1, T const* first2, Pred f)
  {
    using vT = boost::simd::pack<T>;

     auto pr = segmented_input_range(first1,last1);

    // prologue
    for( auto const & e : std::get<0>(pr) ) if (!f(e, *first2++)) return false;

    // main SIMD part - Everybody is aligned
    if(  boost::simd::detail::is_aligned(first2 , vT::alignment))
    {
      for( auto const& e : std::get<1>(pr) )
      {
        if (!all(f(e, aligned_load<vT>(first2)))) return false;
        first2  += vT::static_size;
      }
    }
    else
    {
      for( auto const& e : std::get<1>(pr) )
      {
        if (!all(f(e, load<vT>(first2)))) return false;
        first2  += vT::static_size;
      }
    }

    // epilogue
    for( auto const & e : std::get<2>(pr) )  if (!f(e, *first2++)) return false;
    return true;
  }
} }

#endif
