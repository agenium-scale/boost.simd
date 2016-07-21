//==============================================================================
//         Copyright 2016        Numscale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/simd/expm1.hpp>
#include <boost/simd/detail/constant/minlog.hpp>
#include <boost/simd/detail/constant/maxlog.hpp>
#include <boost/simd/pack.hpp>
#include <exhaustive.hpp>

#include <cmath>
#include <cstdlib>

struct raw_expm1
{
  float operator()(float x) const
  {
    return ::expm1(double(x));
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Minlog<float>();// expm1 is -1 under
  float maxi = bs::Maxlog<float>();// expm1 is inf above
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<bs::pack<float>> ( mini
                                       , maxi
                                       , bs::expm1
                                       , raw_expm1()
                                       );

  return 0;
}
