//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/function/pack_cast.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>
#include "cast_test_base.hpp"

namespace bs = boost::simd;
using bs::pack;

STF_CASE( "Check cast behavior for double" )
{
  static const std::size_t N = bs::pack<double>::static_size;

  test_val<bs::pack<double, N>>(runtime);
  test_val<bs::pack<double, N/2>>(runtime);
  test_val<bs::pack<double, N*2>>(runtime);
}
