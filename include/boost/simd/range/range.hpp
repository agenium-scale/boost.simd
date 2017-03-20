//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_RANGE_RANGE_HPP_INCLUDED
#define BOOST_SIMD_RANGE_RANGE_HPP_INCLUDED

#include <boost/simd/range/detail/iterator.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/assert.hpp>
#include <iterator>

namespace boost { namespace simd
{
  namespace tt = nsm::type_traits;

  /*!
    @ingroup group-range
    Builds a ContiguousContiguousRange that iterates over the original <tt>[begin, end[</tt>
    ContiguousContiguousRange by returning boost::simd::pack of cardinal @c card::value
    at every iteration step.

    @par Header <boost/simd/range/range.hpp>

    @par Example
    @snippet range_card.cpp range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8)(9, 10, 11, 12, 13, 14, 15, 16)
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of @c N

    @param begin Starting iterator of the ContiguousContiguousRange to adapt
    @param end   End iterator of the ContiguousContiguousRange to adapt
    @param card  Integral constant representing the cardinal of the pack to use when iterating.
    @return A ContiguousContiguousRange returning boost::simd::pack of cardinal @c card::value

    @see aligned_range
  **/
  template<std::size_t N, class Iterator> inline
  boost::iterator_range<detail::iterator<Iterator, N> >
  range( Iterator begin, Iterator end, nsm::uint64_t<N> const& card)
  {
    BOOST_ASSERT_MSG
    ( boost::simd::detail::is_aligned(std::distance(begin,end), N)
    , "Adapted ContiguousRange does not hold an integral number of SIMD pack."
    );

    boost::ignore_unused(card);
    return boost::make_iterator_range ( detail::begin<N>(begin)
                                      , detail::end<N>(end)
                                      );
  }

  /*!
    @ingroup group-range
    Builds a ContiguousContiguousRange that iterates over the original <tt>[begin, end[</tt>
    ContiguousContiguousRange by returning boost::simd::pack of default cardinal at every iteration step.

    @par Header <boost/simd/range/range.hpp>

    @par Example
    @snippet range.cpp range
    Possible output:
    @code
    Sum of [1 ... 16] is 136
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of current architecture native cardinal

    @param begin Starting iterator of the ContiguousContiguousRange to adapt
    @param end   End iterator of the ContiguousContiguousRange to adapt
    @return A ContiguousContiguousRange returning boost::simd::pack

    @see aligned_range
  **/
  template<class Iterator> inline
  boost::iterator_range< detail::iterator<Iterator> >
  range( Iterator begin, Iterator end )
  {
    BOOST_ASSERT_MSG
    ( boost::simd::detail::is_aligned(std::distance(begin,end),detail::iterator<Iterator>::cardinal)
    , "Adapted ContiguousRange does not hold an integral number of SIMD pack."
    );

    return boost::make_iterator_range( detail::begin(begin), detail::end(end) );
  }

  /*!
    @ingroup group-range
    Builds a ContiguousContiguousRange that iterates over the original ContiguousContiguousRange by
    returning boost::simd::pack of cardinal @c card::value at every iteration step.

    @par Header <boost/simd/range/range.hpp>

    @par Example
    @snippet range_card_range.cpp range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8)(9, 10, 11, 12, 13, 14, 15, 16)
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of @c card::value
    @param r ContiguousContiguousRange to adapt
    @param card  Integral constant representing the cardinal of the pack to use when iterating.
    @return A ContiguousContiguousRange returning boost::simd::pack of cardinal @c card::value

    @see aligned_range
  **/
  template<std::size_t N, class ContiguousRange> inline
  boost::iterator_range<detail::iterator<typename range_iterator<ContiguousRange>::type,N>>
  range( ContiguousRange&& r, nsm::uint64_t<N> const& card )
  {
    return range( tt::begin(std::forward<ContiguousRange>(r))
                , tt::end(std::forward<ContiguousRange>(r))
                , card
                );
  }


  /*!
    @ingroup group-range
    Builds a ContiguousContiguousRange that iterates over the original ContiguousContiguousRange by
    returning boost::simd::pack at every iteration step.

    @par Header <boost/simd/range/range.hpp>

    @par Example
    @snippet range_range.cpp range
    Possible output:
    @code
    Sum of [1 ... 16] is 136
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple  of current architecture native cardinal
    @param r ContiguousContiguousRange to adapt
    @return A ContiguousContiguousRange returning boost::simd::pack of cardinal @c card::value

    @see aligned_range
  **/
  template<class ContiguousRange> inline
  boost::iterator_range<detail::iterator<typename range_iterator<ContiguousRange>::type>>
  range( ContiguousRange&& r )
  {
    return range( tt::begin(std::forward<ContiguousRange>(r))
                , tt::end(std::forward<ContiguousRange>(r))
                );
  }
} }

#endif
