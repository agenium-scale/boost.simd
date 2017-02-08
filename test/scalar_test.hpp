//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SCALAR_TEST_HPP_INCLUDED
#define SCALAR_TEST_HPP_INCLUDED

#define STF_CUSTOM_DRIVER_FUNCTION scalar_test
#include <stf/stf.hpp>

// -------------------------------------------------------------------------------------------------
// adapt pack for STF testing
namespace stf { namespace ext
{
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
  return scalar_test(argc,argv);
}

#endif
