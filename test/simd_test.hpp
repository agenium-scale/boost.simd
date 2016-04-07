//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_TEST_HPP_INCLUDED
#define SIMD_TEST_HPP_INCLUDED

#define STF_CUSTOM_DRIVER_FUNCTION simd_test
#include <stf.hpp>

#include <boost/simd/pack.hpp>

// -------------------------------------------------------------------------------------------------
// adapt pack for STF testing
namespace stf { namespace ext
{
  // -----------------------------------------------------------------------------------------------
  // equal for pack
  template<typename T, std::size_t N, typename A>
  struct equal<boost::simd::pack<T,N,A>,boost::simd::pack<T,N,A>>
  {
    using type_t = boost::simd::pack<T,N,A>;
    inline bool operator()(type_t const& l, type_t const& r) const
    {
      for(std::size_t i = 0; i < N; ++i)
        if(l[i] != r[i]) return false;
      return true;
    }
  };

  // -----------------------------------------------------------------------------------------------
  // ulpdist for pack
  template<typename T, std::size_t N, typename A>
  struct ulpdist<boost::simd::pack<T,N,A>,boost::simd::pack<T,N,A>>
  {
    using type_t = boost::simd::pack<T,N,A>;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      double max_ulp = 0;
      for(std::size_t i = 0; i < N; ++i)
        max_ulp = std::max( max_ulp, stf::ulpdist(T(l[i]),T(r[i])) );

      return max_ulp;
    }
  };

  // -----------------------------------------------------------------------------------------------
  // reldist for pack
  template<typename T, std::size_t N, typename A>
  struct reldist<boost::simd::pack<T,N,A>,boost::simd::pack<T,N,A>>
  {
    using type_t = boost::simd::pack<T,N,A>;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      double max_rel = 0;
      for(std::size_t i = 0; i < N; ++i)
        max_rel = std::max( max_rel, stf::reldist(T(l[i]),T(r[i])) );

      return max_rel;
    }
  };

  template<typename S>
  struct reldist<boost::simd::detail::pack_proxy<S>,boost::simd::detail::pack_proxy<S>>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::value_type;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::reldist(value_t(l),value_t(r));
    }
  };

  template<typename S>
  struct ulpdist<boost::simd::detail::pack_proxy<S>,boost::simd::detail::pack_proxy<S>>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::value_type;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::ulpdist(value_t(l),value_t(r));
    }
  };
} }

// -------------------------------------------------------------------------------------------------
// Test driver entry point
int main(int argc, const char** argv)
{
  std::cout << "CTEST_FULL_OUTPUT\n";
  std::cout << "Compiled for: "
            << stf::type_id<BOOST_DISPATCH_DEFAULT_SITE>()
            << "\n";
  return simd_test(argc,argv);
}

#endif
