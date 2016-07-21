//==============================================================================
//         Copyright 2016        Numscale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/simd/exp10.hpp>
#include <boost/simd/detail/constant/minlog10.hpp>
#include <boost/simd/detail/constant/maxlog10.hpp>
#include <boost/simd/pack.hpp>
#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_exp10
{
  float operator()(float x) const
  {
    return ::exp10(double(x));
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Minlog10<float>(); // exp10 is 0 under
  float maxi = bs::Maxlog10<float>(); // exp10 is inf above
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<bs::pack<float>> ( mini
                                       , maxi
                                       , bs::exp10
                                       , raw_exp10()
                                       );

  return 0;
}
