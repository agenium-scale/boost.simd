//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_RANGE_ALIGNED_RANGE_HPP_INCLUDED
#define BOOST_SIMD_RANGE_ALIGNED_RANGE_HPP_INCLUDED

#include <boost/simd/range/detail/aligned_iterator.hpp>
#include <boost/simd/detail/is_aligned.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/assert.hpp>
#include <iterator>

namespace boost { namespace simd
{
  namespace tt = nsm::type_traits;

  /*!
    @ingroup group-range
    Builds a ContiguousRange that iterates over the original <tt>[begin, end[</tt>
    aligned ContiguousRange by returning boost::simd::pack of cardinal @c card::value at
    every iteration step.

    @par Header <boost/simd/range/aligned_range.hpp>

    @par Example
    @snippet aligned_range_card.cpp aligned_range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8)(9, 10, 11, 12, 13, 14, 15, 16)
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of @c card::value
    @pre @c std::addressof(*begin) is aligned on @c pack<Iterator::value_type,N>::alignment

    @param begin Starting iterator of the ContiguousRange to adapt
    @param end   End iterator of the ContiguousRange to adapt
    @param card  Integral constant representing the cardinal of the pack to use when iterating.

    @return A ContiguousRange returning boost::simd::pack of cardinal @c card::value
  **/
  template<std::size_t C, typename Iterator> inline
  boost::iterator_range<detail::aligned_iterator<Iterator, C> >
  aligned_range( Iterator begin, Iterator end, nsm::uint64_t<C> const& card )
  {
    BOOST_ASSERT_MSG
    ( boost::simd::detail::is_aligned(std::distance(begin,end), C)
    , "ContiguousRange being adapted holds a non integral number of SIMD pack."
    );

    boost::ignore_unused(card);
    return boost::make_iterator_range ( detail::aligned_begin<C>(begin)
                                      , detail::aligned_end<C>(end)
                                      );
  }

  /*!
    @ingroup group-range
    Builds a ContiguousRange that iterates over the original <tt>[begin, end[</tt>
    aligned ContiguousRange by returning boost::simd::pack at every iteration step.

    @par Header <boost/simd/range/aligned_range.hpp>

    @par Example
    @snippet aligned_range.cpp aligned_range
    Possible output:
    @code
    Sum of [1 ... 16] is 136
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of current architecture native cardinal
    @pre @c std::addressof(*begin) is aligned on @c pack<Iterator::value_type>::alignment

    @param begin Starting iterator of the ContiguousRange to adapt
    @param end   End iterator of the ContiguousRange to adapt

    @return A ContiguousRange returning boost::simd::pack
  **/
  template<typename Iterator> inline
  boost::iterator_range< detail::aligned_iterator<Iterator> >
  aligned_range( Iterator begin, Iterator end )
  {
    BOOST_ASSERT_MSG
    ( boost::simd::detail::is_aligned ( std::distance(begin,end)
                                      , detail::aligned_iterator<Iterator>::cardinal
                                      )
    , "ContiguousRange being adapted holds a non integral number of SIMD pack."
    );

    return boost::make_iterator_range ( detail::aligned_begin(begin)
                                      , detail::aligned_end(end)
                                      );
  }

  /*!
    @ingroup group-range
    Builds a ContiguousRange that iterates over the original aligned ContiguousRange by
    returning boost::simd::pack of cardinal @c card::value at every iteration step.

    @par Header <boost/simd/range/aligned_range.hpp>

    @par Example
    @snippet aligned_range_card_range.cpp aligned_range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8)(9, 10, 11, 12, 13, 14, 15, 16)
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of @c card::value
    @pre @c &(*begin) is aligned on @c pack<ContiguousRange::value_type,card::value>::alignment

    @param r ContiguousRange to adapt
    @param card  Integral constant representing the cardinal of the pack to use when iterating.
    @return A ContiguousRange returning boost::simd::pack of cardinal @c card::value
  **/
  template<std::size_t C, typename ContiguousRange> inline
  boost::iterator_range<detail::aligned_iterator<typename range_iterator<ContiguousRange>::type,C>>
  aligned_range( ContiguousRange&& r, nsm::uint64_t<C> const& card )
  {
    return aligned_range( tt::begin(std::forward<ContiguousRange>(r))
                        , tt::end(std::forward<ContiguousRange>(r))
                        , card
                        );
  }

  /*!
    @ingroup group-range
    Builds a ContiguousRange that iterates over the original aligned ContiguousRange by
    returning boost::simd::pack at every iteration step.

    @par Header <boost/simd/range/aligned_range.hpp>

    @par Example
    @snippet aligned_range_range.cpp aligned_range
    Possible output:
    @code
    Sum of [1 ... 16] is 136
    @endcode

    @pre @c std::distance(begin,end) is an exact multiple of current architecture native cardinal
    @pre @c &(*begin) is aligned on @c pack<ContiguousRange::value_type>::alignment

    @param r ContiguousRange to adapt
    @return A ContiguousRange returning boost::simd::pack
  **/
  template<typename ContiguousRange> inline
  boost::iterator_range<detail::aligned_iterator<typename range_iterator<ContiguousRange>::type>>
  aligned_range( ContiguousRange&& r )
  {
    return aligned_range( tt::begin(std::forward<ContiguousRange>(r))
                        , tt::end(std::forward<ContiguousRange>(r))
                        );
  }
} }

#endif
