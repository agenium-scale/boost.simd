//==================================================================================================
/*!
  @file

  @copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#ifndef BOOST_SIMD_ALGORITHM_IOTA_HPP_INCLUDED
#define BOOST_SIMD_ALGORITHM_IOTA_HPP_INCLUDED

#include <boost/simd/range/segmented_output_range.hpp>
#include <boost/simd/function/enumerate.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/as.hpp>
#include <boost/simd/pack.hpp>
#include <iterator>
namespace boost { namespace simd
{
  /*!
    @ingroup group-std

    Fills the range [first, last) with sequentially increasing values,
    starting with seed  and repetitively evaluating value += step.

    @param first  Beginning of the range of elements
    @param last   End of the range of elements
    @param seed   initial value to store
    @param step   value to add (default to 1)

    @par Requirement

      - @c first, @c last and @c out must be pointer to Vectorizable type.


    @par Example:

      @snippet iota.cpp iota

    @par Possible output:

      @snippet iota.txt iota

  **/

  template<typename T,  typename T1,  typename T2>
  void iota(T * first, T * last, T1 seed, T2 step)
  {
    struct sg
    {
      sg(T1 seed, T2 step)
        : i_(seed),  step_(step) {}
      T operator()()
      {
        auto z = i_;
        i_+= step_;
        return z;
      }
      T i_;
      T step_;
    };
    struct vg
    {
      using p_t =  pack<T>;
      vg(T1 seed, T2 step)
        : i_(bs::enumerate<p_t>(seed, step)), step_(step) {}
       p_t operator()()
      {
        auto z = i_;
        i_+=step_*p_t::static_size;
        return z;
      }
      p_t i_;
      p_t step_;
    };
    auto pr = segmented_output_range(first,last);

    // prologue
    auto r0 = std::get<0>(pr);
    sg gg0(seed, step);
    std::generate(r0.begin(), r0.end(), [&gg0](){return gg0(); });
    // main SIMD part
    auto r1 = std::get<1>(pr);
    T s = seed+T(std::distance(r0.begin(), r0.end()));
    vg gg1(s, step);
    std::generate(r1.begin(), r1.end(), [&gg1](){return gg1(); });

    // epilogue
    s += T(std::distance(r1.begin(), r1.end())*pack<T>::static_size*step);
    auto r2 = std::get<2>(pr);
    sg gg2(s, step);
    std::generate(r2.begin(), r2.end(), [&gg2](){return gg2(); });

  }
  /* overload */
  template<typename T,  typename T1>
  void iota(T * first, T * last, T1 seed)
  {
    struct sg
    {
      sg(T1 seed)
        : i_(seed) {}
      T operator()()
      {
        return i_++;
      }
      T i_;
    };
    struct vg
    {
      using p_t =  pack<T>;
      vg(T seed)
        : i_(bs::enumerate<p_t>(seed)) {}
       p_t operator()()
      {
        auto z = i_;
        i_+= p_t::static_size;
        return z;
      }
      p_t i_;
    };
    auto pr = segmented_output_range(first,last);

    // prologue
    auto r0 = std::get<0>(pr);
    sg gg0(seed);
    std::generate(r0.begin(), r0.end(), [&gg0](){return gg0(); });
    // main SIMD part
    auto r1 = std::get<1>(pr);
    T s = seed+T(std::distance(r0.begin(), r0.end()));
    vg gg1(s);
    std::generate(r1.begin(), r1.end(), [&gg1](){return gg1(); });

    // epilogue
    s += T(std::distance(r1.begin(), r1.end())*pack<T>::static_size);
    auto r2 = std::get<2>(pr);
    sg gg2(s);
    std::generate(r2.begin(), r2.end(), [&gg2](){return gg2(); });

  }


} }

#endif
