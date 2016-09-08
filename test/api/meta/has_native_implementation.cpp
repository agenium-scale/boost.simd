//==================================================================================================
/**
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
//==================================================================================================
#include <boost/simd/meta/has_native_implementation.hpp>
#include <boost/simd/function/divides.hpp>
#include <boost/simd/pack.hpp>
#include <simd_test.hpp>

namespace bs= boost::simd;

STF_CASE( "Check has_native_implementation" )
{
  using gd = bs::detail::get_dispatcher<bs::tag::divides_,bs::pack<float>, bs::pack<float>>::type;
  using gi = bs::detail::get_implementation<gd>::template apply<bs::pack<float>, bs::pack<float>>::type;
  std::cout << stf::type_id<gd>() << "\n";
  std::cout << stf::type_id<gi>() << "\n";
  std::cout << stf::type_id<typename gi::is_emulated_tag>() << "\n";
}
