//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_COUNT_IF_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_COUNT_IF_HPP_INCLUDED

#include <boost/simd/range/segmented_input_range.hpp>
#include <boost/simd/function/nbtrue.hpp>
#include <boost/simd/pack.hpp>
#include <algorithm>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Returns he number of elements in the range [first,last)
    for which pred returns true.

    @param first  Beginning of the range of elements
    @param last   End of the range of elements
    @param pred  predicate to apply to each element.

    @par Requirement

      - @c first , @c last and @c out must be pointers to type which can be used within
        boost::simd::pack.

    @par Example:

      @snippet count_if.cpp count_if

    @par Possible output:

      @snippet count_if.txt count_if

  **/

  template<typename T, typename Pred>
  typename std::iterator_traits<const T*>::difference_type
  count_if(T const* first, T const* last, Pred const & pred)
  {
     struct count_if_sum
    {
      using p_t =  pack<T>;
      using itype_t = typename std::iterator_traits<const T*>::difference_type;
      count_if_sum(const itype_t & c, const Pred & f): s_(c), f_(f){ }
      void operator()(const p_t& x) { s_ += nbtrue(f_(x)); }
      itype_t  s_;
      const Pred & f_;
    };
    auto pr = segmented_input_range(first,last);
    // prologue
    auto r0 = std::get<0>(pr);
    auto c = std::count_if(r0.begin(), r0.end(), pred);

    // main simd part
    auto r1 = std::get<1>(pr);
    c = std::for_each(r1.begin(), r1.end(), count_if_sum(c, pred)).s_;

    // epilogue
    auto r2 = std::get<2>(pr);
    c += std::count_if(r2.begin(), r2.end(), pred);

    return c;
  }

} }

#endif
