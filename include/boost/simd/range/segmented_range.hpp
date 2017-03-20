//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_RANGE_SEGMENTED_RANGE_HPP_INCLUDED
#define BOOST_SIMD_RANGE_SEGMENTED_RANGE_HPP_INCLUDED

#include <boost/simd/range/range.hpp>
#include <boost/simd/range/detail/segment.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/align/align_down.hpp>

namespace boost { namespace simd
{
  namespace tt = nsm::type_traits;

 /*!
    @ingroup group-range
    Splits an unaligned ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack of cardinal equals to @c card::value. The SIMD ranges are
    iterated over using unaligned load and store, which imply that the scalar head may be empty.

    @par Header <boost/simd/range/segmented_range.hpp>

    @par Example
    @snippet segmented_range_card.cpp segmented_range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8) (9, 10, 11, 12, 13, 14, 15, 16) 17 18 19
    @endcode

    @param b    Starting iterator of the ContiguousRange to adapt
    @param e    End iterator of the ContiguousRange to adapt
    @param card Cardinal of boost::simd::pack to be iterated.
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see aligned_segmented_range
  */
  template<typename Iterator, std::size_t N>
  BOOST_FORCEINLINE detail::segment_<Iterator, detail::iterator<Iterator,N>>
  segmented_range(Iterator b, Iterator e, nsm::uint64_t<N> const& card)
  {
    using result_t = detail::segment_<Iterator, detail::iterator<Iterator,N>>;

    /*
      When dealing with unaligned range adaptation, we know there is no head.
      We just need to compute where the original range stops in terms of packs.
    */
    auto alg = pack<typename std::iterator_traits<Iterator>::value_type,N>::static_size;
    std::size_t vz = alignment::align_down(std::distance(b, e),alg);

    return result_t { iterator_range<Iterator>()
                    , range(b,b+vz, card)
                    , iterator_range<Iterator>(b+vz,e)
                    };
  }

 /*!
    @ingroup group-range
    Splits an unaligned ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack. The SIMD ranges are iterated over using unaligned load and
    store, which imply that the scalar head may be empty.

    @par Header <boost/simd/range/segmented_range.hpp>

    @par Example
    @snippet segmented_range.cpp segmented_range
    Possible output:
    @code
    Sum of [1 ... 13] is 91
    @endcode

    @param b    Starting iterator of the ContiguousRange to adapt
    @param e    End iterator of the ContiguousRange to adapt

    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see aligned_segmented_range
  */
  template<typename Iterator>
  BOOST_FORCEINLINE detail::segment_<Iterator, detail::iterator<Iterator>>
  segmented_range(Iterator b, Iterator e)
  {
    using value_t = typename std::iterator_traits<Iterator>::value_type;
    return segmented_range(b,e, nsm::uint64_t<pack<value_t>::static_size>());
  }

 /*!
    @ingroup group-range
    Splits an unaligned ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack of cardinal equals to @c card::value. The SIMD ranges are
    iterated over using unaligned load and store, which imply that the scalar head may be empty.

    @par Header <boost/simd/range/segmented_range.hpp>

    @par Example
    @snippet segmented_range_card_range.cpp segmented_range_card
    Possible output:
    @code
    (1, 2, 3, 4, 5, 6, 7, 8) (9, 10, 11, 12, 13, 14, 15, 16) 17 18 19
    @endcode

    @param r ContiguousContiguousRange to split
    @param card Cardinal of boost::simd::pack to be iterated.
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see aligned_segmented_range
  */
  template<std::size_t N, typename Range>
  BOOST_FORCEINLINE
  detail::segment_< detail::range_iterator<Range>
                  , detail::iterator<detail::range_iterator<Range>, N>
                  >
  segmented_range( Range&& r, nsm::uint64_t<N> const& card )
  {
    return segmented_range( tt::begin(std::forward<Range>(r)), tt::end(std::forward<Range>(r))
                          , card
                          );
  }

 /*!
    @ingroup group-range
    Splits an unaligned ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack. The SIMD ranges are iterated over using unaligned load and
    store, which imply that the scalar head may be empty.

    @par Header <boost/simd/range/segmented_range.hpp>

    @par Example
    @snippet segmented_range_range.cpp segmented_range
    Possible output:
    @code
    Sum of [1 ... 13] is 91
    @endcode

    @param r ContiguousContiguousRange to split
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see aligned_segmented_range
  */
  template<typename Range>
  BOOST_FORCEINLINE
  detail::segment_< detail::range_iterator<Range>
                  , detail::iterator<detail::range_iterator<Range>>
                  >
  segmented_range( Range&& r )
  {
    return segmented_range( tt::begin(std::forward<Range>(r)), tt::end(std::forward<Range>(r)) );
  }
} }

#endif
