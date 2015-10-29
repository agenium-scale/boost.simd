//==================================================================================================
/*!
  @file

  @copyright 2009-2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012-2015 NumScale SAS
  @copyright 2015 J.T.Lapreste

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED
#define BOOST_SIMD_FUNCTION_SHUFFLE_HPP_INCLUDED

#if defined(DOXYGEN_ONLY)
namespace boost { namespace simd
{
  /*!

    @ingroup group-swar

    SIMD register shuffling

    Shuffle the elements of two SIMD registers following a compile-time
    permutation pattern passed as a @metafunction.

    @par Semantic:

    Let's @c T be a SIMD register type of cardinal @c N, @c Perm be a
    binary @metafunction. For any SIMD register @c x and  @c y of type @c T,
    the following code:

    @code
    T r = shuffle<Perm>(x,y);
    @endcode

    is equivalent to

    @code
    T r = shuffle< mpl::apply<Perm, int_<0>, int_<N> >::type::value
                 , ...
                 , mpl::apply<Perm, int_<C-1>, int_<N> >::type::value
                 >(x,y);
    @endcode

    @usage{shuffle_perm1.cpp}

    @tparam Perm Permutation pattern @metafunction

    @return A SIMD register shuffled as per the permutation pattern

**/
  template<typename Perm, typename T> auto shuffle(T const& x, T const& y) {}

  namespace functional
  {
    /*!
      @ingroup group-callable-swar

      SIMD register shuffling


      Function object tied to simd::shuffle

      @see simd::shuffle
    **/
    const boost::dispatch::functor<tag::shuffle_> shuffle = {};
  }
} }
#endif

#include <boost/simd/function/definition/shuffle.hpp>
#include <boost/simd/arch/common/scalar/function/shuffle.hpp>
#include <boost/simd/function/simd/shuffle.hpp>

#endif
