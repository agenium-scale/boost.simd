//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ITERATOR_SEGMENTED_OUTPUT_RANGE_HPP_INCLUDED
#define BOOST_SIMD_ITERATOR_SEGMENTED_OUTPUT_RANGE_HPP_INCLUDED

#include <boost/simd/iterator/aligned_output_range.hpp>
#include <boost/align/align_up.hpp>
#include <boost/range/iterator_range.hpp>

namespace boost { namespace simd
{
  /*!
    @brief Clamped adapter for SIMD read-only range

    Convert a range represented as a pair of iterators into a read-only SIMD
    aware range. This range's extrema are modified so that:

    * the beginning of the range is referencing the first aligned element of the
      original range
    * the end of the range is referencing past the last valid SIMD pack accessible
      in the original range.

    Such clamped range is then safe to be iterated using aligned_iterator while
    the remaining elements of the original range can be processed using regular
    scalar iterators.

    @tparam C Width of the SIMD register to use as iteration value.
    @param begin A Range addressing a contiguous memory block
    @param end

    @return An instance of realigned_output_range
  **/
  template<std::size_t C, typename Iterator>
  std::tuple< iterator_range<Iterator>
            , iterator_range<detail::aligned_output_iterator<Iterator>>
            , iterator_range<Iterator>
            >
  inline segmented_output_range( Iterator b, Iterator e )
  {
    // Compute the pointer to the beginning of the aligned zone inside r
    auto const* ptr     = &(*b);
    auto const* new_ptr = reinterpret_cast<decltype(ptr)>
                          ( alignment::align_up ( reinterpret_cast<std::size_t>(ptr)
                                                , C*sizeof(*ptr)
                                                )
                          );

    // Deduces the offset to there
    std::size_t db = std::distance(ptr,new_ptr);

    // Find how many elements are in the SIMD zone
    std::size_t sz = C*((std::distance(b,e)-db)/C);

    // Build the segmented stuff
    return std::make_tuple( make_iterator_range (b      , b+db    )
                          , aligned_output_range(b+db   , b+db+sz )
                          , make_iterator_range (b+db+sz, e       )
                          );
  }

  /// @overload
  template<class Iterator> inline
  auto    segmented_output_range( Iterator begin, Iterator end )
      ->  decltype( segmented_output_range< pack< typename std::iterator_traits<Iterator>
                                                              ::value_type
                                                  >::static_size
                                            >( begin, end )
                  )
  {
    return  segmented_output_range< pack< typename std::iterator_traits<Iterator>
                                                    ::value_type
                                        >::static_size
                                  >( begin, end );
  }

  template<std::size_t C, class Range> inline
  auto    segmented_output_range( Range& r )
      ->  decltype( segmented_output_range<C>( boost::begin(r), boost::end(r) ) )
  {
    return segmented_output_range<C>( boost::begin(r), boost::end(r) );
  }

  template<class Range> inline
  auto    segmented_output_range( Range& r )
      ->  decltype( segmented_output_range( boost::begin(r), boost::end(r) ) )
  {
    return segmented_output_range( boost::begin(r), boost::end(r) );
  }
} }

#endif
