//==================================================================================================
/*!
  @file

  Convenience header for Boost.SIMD

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==============================================================================
#ifndef BOOST_SIMD_SDK_SIMD_ALGORITHM_HPP_INCLUDED
#define BOOST_SIMD_SDK_SIMD_ALGORITHM_HPP_INCLUDED

#include <boost/simd/pack.hpp>
#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/splat.hpp>

#include <boost/align/align_up.hpp>
#include <boost/align/is_aligned.hpp>

#include <boost/mpl/assert.hpp>
#include <boost/assert.hpp>

#include <algorithm>

//workaround for boost align:
//align_up does not take the pointer as const even though it does not modify it.
namespace boost { namespace alignment {
  inline void* align_up(void const* ptr, std::size_t alignment) BOOST_NOEXCEPT    
  {                                                                               
    BOOST_ASSERT(detail::is_alignment(alignment));                              
    return reinterpret_cast<void*>(align_up(reinterpret_cast<std::              
          size_t>(ptr), alignment));                                              
  }                                                                               
} }

namespace boost { namespace simd
{
  template<class T, class U, class UnOp>
  U* transform(T const* begin, T const* end, U* out, UnOp f)
  {
    typedef boost::simd::pack<T> vT;
    typedef boost::simd::pack<U> vU;

    BOOST_MPL_ASSERT_MSG( vT::static_size == vU::static_size
                        , BOOST_SIMD_TRANSFORM_INPUT_OUTPUT_NOT_SAME_SIZE
                        , (T, U)
                        );

    static const std::size_t N = vU::static_size;

    std::size_t shift = (U*)boost::alignment::align_up(out, N) - out;
    T const* end2 = begin + std::min<size_t>(shift, end-begin);
    T const* end3 = end2 + (end - end2)/N*N;

    // prologue
    for(; begin!=end2; ++begin, ++out){
      *out = f(*begin);
    }

    if(boost::alignment::is_aligned(vT::alignment, begin))
    {
      for(; begin!=end3; begin += N, out += N){
        simd::aligned_store(f(simd::aligned_load<vT>(begin)), out);
      }
    }
    else
    {
      for(; begin!=end3; begin += N, out += N){
        simd::aligned_store(f(simd::load<vT>(begin)), out);
      }
    }

    // epilogue
    for(; begin!=end; ++begin, ++out){
      *out = f(*begin);
    }

    return out;
  }

  template<class T1, class T2, class U, class BinOp>
  U* transform(T1 const* begin1, T1 const* end, T2 const* begin2, U* out, BinOp f)
  {
    typedef boost::simd::pack<T1> vT1;
    typedef boost::simd::pack<T2> vT2;
    typedef boost::simd::pack<U> vU;

    BOOST_MPL_ASSERT_MSG( vT1::static_size == vT2::static_size && vT1::static_size == vU::static_size
                        , BOOST_SIMD_TRANSFORM_INPUT_OUTPUT_NOT_SAME_SIZE
                        , (T1, T2, U)
                        );

    static const std::size_t N = vU::static_size;

    std::size_t shift = (U*)boost::alignment::align_up(out, N) - out;
    T1 const* end2 = begin1 + std::min<size_t>(shift, end-begin1);
    T1 const* end3 = end2 + (end - end2)/N*N;

    // prologue
    for(; begin1!=end2; ++begin1, ++begin2, ++out){
      *out = f(*begin1, *begin2);
    }

    if( boost::alignment::is_aligned(vT1::alignment, begin1)
       && boost::alignment::is_aligned(vT2::alignment, begin2))
    {
      for(; begin1!=end3; begin1 += N, begin2 += N, out += N){
        simd::aligned_store(f(simd::aligned_load<vT1>(begin1), simd::aligned_load<vT2>(begin2)), out);
      }
    }
    else
    {
      for(; begin1!=end3; begin1 += N, begin2 += N, out += N){
        simd::aligned_store(f(simd::load<vT1>(begin1), simd::load<vT2>(begin2)), out);
      }
    }

    // epilogue
    for(; begin1!=end; ++begin1, ++begin2, ++out){
      *out = f(*begin1, *begin2);
    }

    return out;
  }

  template<class T, class U, class F>
  U accumulate(T const* begin, T const* end, U init, F f)
  {
    typedef boost::simd::pack<T> vT;
    typedef boost::simd::pack<U> vU;

    BOOST_MPL_ASSERT_MSG( vT::static_size == vU::static_size
                        , BOOST_SIMD_ACCUMULATE_INPUT_OUTPUT_NOT_SAME_SIZE
                        , (T, U)
                        );

    static const std::size_t N = vT::static_size;
    T const* end2 = std::min( (T const*)boost::alignment::align_up(begin, N * sizeof(T)), end );
    T const* end3 = end2 + (end - end2)/N*N;

    vU cur = simd::splat<vU>(init);

    // prologue
    for(; begin!=end2; ++begin){
      init = f(init, *begin);
    }

    for(; begin!=end3; begin += N){
      cur = f(cur, boost::simd::aligned_load<vT>(begin));
    }
    // reduce cur
    for(typename vU::const_iterator b = cur.cbegin(); b != cur.cend(); ++b){
      init = f(init, *b);
    }

    // epilogue
    for(; begin!=end; ++begin){
     init = f(init, *begin);
    }

    return init;
  }
} }

#endif
