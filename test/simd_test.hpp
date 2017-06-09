//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_TEST_HPP_INCLUDED
#define SIMD_TEST_HPP_INCLUDED

#define STF_CUSTOM_DRIVER_FUNCTION simd_test
#include <stf/stf.hpp>

#include <boost/simd/pack.hpp>

// -------------------------------------------------------------------------------------------------
// adapt pack for STF testing
namespace stf { namespace ext
{
  // -----------------------------------------------------------------------------------------------
  // STF conformance for pack
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

  // -----------------------------------------------------------------------------------------------
  // STF conformance for pack_proxy
  template<typename S, typename T>
  struct equal<boost::simd::detail::pack_proxy<S>,T>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::base_type;
    inline double operator()(type_t const& l, T const& r) const
    {
      return value_t(l) == r;
    }
  };

  template<typename S, typename T>
  struct equal<T,boost::simd::detail::pack_proxy<S>>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::base_type;
    inline double operator()(T const& l, type_t const& r) const
    {
      return l == value_t(r);
    }
  };

  template<typename S>
  struct reldist<boost::simd::detail::pack_proxy<S>,boost::simd::detail::pack_proxy<S>>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::base_type;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::reldist(value_t(l),value_t(r));
    }
  };

  template<typename S>
  struct ulpdist<boost::simd::detail::pack_proxy<S>,boost::simd::detail::pack_proxy<S>>
  {
    using type_t  = boost::simd::detail::pack_proxy<S>;
    using value_t = typename type_t::base_type;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::ulpdist(value_t(l),value_t(r));
    }
  };

  // -----------------------------------------------------------------------------------------------
  // STF conformance for logical
  template<typename T>
  struct reldist<boost::simd::logical<T>,boost::simd::logical<T>>
  {
    using type_t  = boost::simd::logical<T>;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::reldist(bool(l),bool(r));
    }
  };

  template<typename T>
  struct ulpdist<boost::simd::logical<T>,boost::simd::logical<T>>
  {
    using type_t  = boost::simd::logical<T>;
    inline double operator()(type_t const& l, type_t const& r) const
    {
      return stf::ulpdist(bool(l),bool(r));
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
