//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_RANGE_SEGMENTED_ALIGNED_RANGE_HPP_INCLUDED
#define BOOST_SIMD_RANGE_SEGMENTED_ALIGNED_RANGE_HPP_INCLUDED

#include <boost/simd/range/aligned_range.hpp>
#include <boost/simd/range/detail/segment.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/align/align_up.hpp>

namespace boost { namespace simd
{
  namespace tt = nsm::type_traits;

 /*!
    @ingroup group-range
    Splits an arbitrary ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack of cardinal equals to @c card::value. The SIMD data are iterated
    over using aligned load and store.

    @par Header <boost/simd/range/segmented_aligned_range.hpp>

    @par Example
    @snippet segmented_aligned_range_card.cpp segmented_range_card
    Possible output:
    @code
    1 2 (3, 4, 5, 6, 7, 8, 9, 10) (11, 12, 13, 14, 15, 16, 17, 18) 19
    @endcode

    @param b    Starting iterator of the ContiguousRange to adapt
    @param e    End iterator of the ContiguousRange to adapt
    @param card Cardinal of boost::simd::pack to be iterated.
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see segmented_range
  */
  template<typename Iterator, std::size_t N>
  BOOST_FORCEINLINE detail::segment_<Iterator, detail::aligned_iterator<Iterator,N>>
  segmented_aligned_range(Iterator b, Iterator e, nsm::uint64_t<N> const& card)
  {
    using result_t = detail::segment_<Iterator, detail::aligned_iterator<Iterator,N>>;
    auto alg = pack<typename std::iterator_traits<Iterator>::value_type,N>::alignment;

    // How many data in the range
    std::size_t sz = std::distance(b, e);

    // Compute the pointer to the beginning of the aligned zone inside r
    auto p = &(*b);
    auto a = reinterpret_cast<decltype(p)>( alignment::align_up( reinterpret_cast<std::uintptr_t>(p)
                                                               , alg
                                                               )
                                          );

    // Next aligned address may be out of range, so make sure psz is not bigger than sz
    std::size_t psz = std::min<std::size_t>(sz,std::distance(p, a));

    // How many data are inside the SIMD body
    //std::size_t msz = (sz >= psz) ? (N * ((sz - psz) / N)) : (0u);
    std::size_t msz = (sz >= psz) ? (N * ((sz - psz) / N)) : (0u);

    // Head/Body/Tail frontiers
    auto has_body = (msz != 0u);
    auto he = has_body ? b  + psz : e;
    auto be = has_body ? he + msz : e;
    auto te = has_body ? be       : e;

    return result_t { iterator_range<Iterator>(b,he)
                    , aligned_range(he,be,card)
                    , iterator_range<Iterator>(te,e)
                    };
  }

 /*!
    @ingroup group-range
    Splits an arbitrary ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack. The SIMD data are iterated over using aligned load and
    store.

    @par Header <boost/simd/range/segmented_aligned_range.hpp>

    @par Example
    @snippet segmented_aligned_range.cpp segmented_range
    Possible output:
    @code
    Sum of [1 ... 13] is 91
    @endcode

    @param b    Starting iterator of the ContiguousRange to adapt
    @param e    End iterator of the ContiguousRange to adapt

    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see segmented_range
  */
  template<typename Iterator>
  BOOST_FORCEINLINE detail::segment_<Iterator, detail::aligned_iterator<Iterator>>
  segmented_aligned_range(Iterator b, Iterator e)
  {
    using value_t = typename std::iterator_traits<Iterator>::value_type;
    return segmented_aligned_range(b,e, nsm::uint64_t<pack<value_t>::static_size>());
  }

 /*!
    @ingroup group-range
    Splits an arbitrary ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack of cardinal equals to @c card::value. The SIMD data are iterated
    over using aligned load and store.

    @par Header <boost/simd/range/segmented_aligned_range.hpp>

    @par Example
    @snippet segmented_aligned_range_card_range.cpp segmented_range_card
    Possible output:
    @code
    1 2 (3, 4, 5, 6, 7, 8, 9, 10) (11, 12, 13, 14, 15, 16, 17, 18) 19
    @endcode

    @param r ContiguousContiguousRange to split
    @param card Cardinal of boost::simd::pack to be iterated.
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see segmented_range
  */
  template<std::size_t N, typename Range>
  BOOST_FORCEINLINE
  detail::segment_< detail::range_iterator<Range>
                  , detail::aligned_iterator<detail::range_iterator<Range>, N>
                  >
  segmented_aligned_range( Range&& r, nsm::uint64_t<N> const& card )
  {
    return segmented_aligned_range( tt::begin(std::forward<Range>(r))
                                  , tt::end(std::forward<Range>(r))
                                  , card
                                  );
  }

 /*!
    @ingroup group-range
    Splits an arbitrary ContiguousRange into a triplet of ranges covering the head, body and tail
    of the range so that iteration over each Ranges is performed with the proper scalar and SIMD
    operations on boost::simd::pack. The SIMD data are iterated over using aligned load and
    store.

    @par Header <boost/simd/range/segmented_aligned_range.hpp>

    @par Example
    @snippet segmented_aligned_range_range.cpp segmented_range
    Possible output:
    @code
    Sum of [1 ... 13] is 91
    @endcode

    @param r ContiguousContiguousRange to split
    @return   A triplet of Ranges covering the scalar head, the SIMD body and the scalar
              tail covering the same data than the original Range.

    @see segmented_range
  */
  template<typename Range>
  BOOST_FORCEINLINE
  detail::segment_< detail::range_iterator<Range>
                  , detail::aligned_iterator<detail::range_iterator<Range>>
                  >
  segmented_aligned_range( Range&& r )
  {
    return segmented_aligned_range( tt::begin(std::forward<Range>(r))
                                  , tt::end(std::forward<Range>(r))
                                  );
  }
} }

#endif
