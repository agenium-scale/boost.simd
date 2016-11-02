//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_RANGE_SEGMENTED_INPUT_RANGE_HPP_INCLUDED
#define BOOST_SIMD_RANGE_SEGMENTED_INPUT_RANGE_HPP_INCLUDED

#include <boost/simd/range/detail/segmented_range.hpp>
#include <boost/simd/range/aligned_input_range.hpp>
#include <boost/align/align_up.hpp>
#include <boost/range/iterator_range.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std
    Splits a ContiguousRange in three Contiguous Input Ranges able to support mixed scalar and SIMD
    traversal.

    The three sub-ranges are stored into a std::tuple and covers:
    - the scalar prologue range, i.e the range defined between the original begin and the first
      location to be properly aligned to be read as a boost::simd::pack
    - the main SIMD range, i.e the range defined between the first location to be properly aligned
      to be read as a boost::simd::pack and the location after the last readable pack.
    - the scalar epilogue range, i.e the range defined between the location after the last readable
      pack and the original end.

    @par Example
    @snippet segmented_input_range.cpp segmented_input_range
    Possible output:
    @code
    Sum of [1 ... 16] is 136
    @endcode

    @param b  Starting iterator of the ContiguousRange to adapt
    @param e  End iterator of the ContiguousRange to adapt
    @return   A triplet of Input Range covering the scalar prologue, the SIMD main range and the scalar
              epilogue covering the same data than the original Range.
  **/
  template<std::size_t C, typename Iterator>
  std::tuple< iterator_range<Iterator>
            , iterator_range<detail::aligned_input_iterator<Iterator>>
            , iterator_range<Iterator>
            >
  inline segmented_input_range( Iterator b, Iterator e )
  {
    return detail::segmented_range<C, detail::aligned_input_iterator<Iterator>>
      ( b
      , e
      , [](Iterator bb, Iterator ee) { return aligned_input_range(bb, ee); }
      );
  }

  template<class Iterator> inline
  auto    segmented_input_range( Iterator begin, Iterator end )
      ->  decltype( segmented_input_range< pack< typename std::iterator_traits<Iterator>
                                                              ::value_type
                                                  >::static_size
                                            >( begin, end )
                  )
  {
    return  segmented_input_range< pack< typename std::iterator_traits<Iterator>
                                                    ::value_type
                                        >::static_size
                                  >( begin, end );
  }

  template<std::size_t C, class Range> inline
  auto    segmented_input_range( Range const& r )
      ->  decltype( segmented_input_range<C>( boost::begin(r), boost::end(r) ) )
  {
    return segmented_input_range<C>( boost::begin(r), boost::end(r) );
  }

  template<class Range> inline
  auto    segmented_input_range( Range const& r )
      ->  decltype( segmented_input_range( boost::begin(r), boost::end(r) ) )
  {
    return segmented_input_range( boost::begin(r), boost::end(r) );
  }
} }

#endif
