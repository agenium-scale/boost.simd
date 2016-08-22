//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <boost/simd/iterator/segmented_input_range.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/pack.hpp>
#include <boost/align/is_aligned.hpp>

namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Applies the given function @c f to the Contiguous Range  @c[first, last[ and stores the result
    in another Contiguous Range, beginning at @c out.

    @param first  Beginning of the range of elements to transform
    @param last   End of the range of elements to transform
    @param out    Beginning of the range of the destination range
    @param f      unary operation function object that will be applied.

    @par Requirement

      - @c first , @c last and @c out must be pointer to type which can be used within
        boost::simd::pack.
      - f must be a polymorphic function object, i.e callable on generic types.
      - @c boost::simd::pack<T>::static_size @c == @c boost::simd::pack<U>::static_size

    @par Example

      The following code uses simd::transform to compute the square of the values stored in a
      std::vector. Note the generic lambda function used to fulfill requirements on the
      user-defined function object.

      @code
      #include <boost/simd/algorithm.hpp>
      #include <vector>

      int main()
      {
        std::vector<float> d{1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f};

        boost::simd::transform( s.data(), s.data()+7, s.data()
                              , [](auto const& e) { return e*e; }
                              );
      }
      @endcode

    @return Pointer to the element past the last element transformed.
  **/
  template<typename T, typename U, typename UnOp>
  U* transform(T const* first, T const* last, U* out, UnOp f)
  {
    using vU = pack<U>;

    static_assert ( pack<T>::static_size == vU::static_size
                  , "SIMD cardinal mismatch between T and U"
                  );

    auto pr = segmented_input_range(first,last);

    // prologue
    for( auto const & e : std::get<0>(pr) ) *out++ = f(e);

    // main SIMD part - checks if we can store efficiently or not
    if(boost::alignment::is_aligned(out, vU::alignment))
    {
      for( auto const& e : std::get<1>(pr) )
      {
        aligned_store( f(e) ,out);
        out += vU::static_size;
      }
    }
    else
    {
      for( auto const& e : std::get<1>(pr) )
      {
        store( f(e) ,out);
        out += vU::static_size;
      }
    }

    // epilogue
    for( auto const & e : std::get<2>(pr) ) *out++ = f(e);

    return out;
  }

  template<typename T1, typename T2, typename U, typename BinOp>
  U* transform(T1 const* first1, T1 const* last1, T2 const* first2, U* out, BinOp f)
  {
    using vT2 = boost::simd::pack<T2>;
    using vU = pack<U>;

    static_assert ( pack<T1>::static_size == vT2::static_size
                  , "SIMD cardinal mismatch between T1 and T2"
                  );

    static_assert ( pack<T1>::static_size == vU::static_size
                  , "SIMD cardinal mismatch between T1 and U"
                  );

    static_assert ( vT2::static_size == vU::static_size
                  , "SIMD cardinal mismatch between T2 and U"
                  );

    auto pr = segmented_input_range(first1,last1);

    // prologue
    for( auto const & e : std::get<0>(pr) ) *out++ = f(e, *first2++);

    // main SIMD part - Everybody is aligned
    if(   boost::alignment::is_aligned(out    , vU::alignment )
      &&  boost::alignment::is_aligned(first2 , vT2::alignment)
      )
    {
      for( auto const& e : std::get<1>(pr) )
      {
        aligned_store( f(e, aligned_load<vT2>(first2) ) ,out);
        out     += vU::static_size;
        first2  += vT2::static_size;
      }
    }
    // main SIMD part - input1 and output is aligned
    else if( boost::alignment::is_aligned(out, vU::alignment ) )
    {
      for( auto const& e : std::get<1>(pr) )
      {
        aligned_store( f(e,load<vT2>(first2)) ,out);
        out     += vU::static_size;
        first2  += vT2::static_size;
      }
    }
    // main SIMD part - Both inputs is aligned
    else if( boost::alignment::is_aligned(first2, vT2::alignment ) )
    {
      for( auto const& e : std::get<1>(pr) )
      {
        store( f(e,aligned_load<vT2>(first2)) ,out);
        out     += vU::static_size;
        first2  += vT2::static_size;
      }
    }
    // main SIMD part - input1 is aligned
    else
    {
      for( auto const& e : std::get<1>(pr) )
      {
        store( f(e,load<vT2>(first2)) ,out);
        out     += vU::static_size;
        first2  += vT2::static_size;
      }
    }

    // epilogue
    for( auto const & e : std::get<2>(pr) ) *out++ = f(e, *first2++);
    return out;
  }
} }

#endif
