//==============================================================================
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2013        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/pow.hpp>
#include <nt2/include/constants/one.hpp>

#include <nt2/sdk/exhaustive/exhaustive.hpp>

#define NT2_ASSERTS_AS_TRAP
#include <nt2/sdk/error/assert_as_trap.hpp>

#include <cmath>
#include <cstdlib>

struct raw_pow
{
  float operator()(float x) const
  {
    return std::pow(double(x), double(0.5f*x-0.25f));
  }
};
struct pow0
{
  float operator()(float x) const
  {
    return nt2::pow(x, 0.5f*x-0.25f);
  }
};

int main(int argc, char* argv[])
{
  float mini = nt2::One<float>();
  float maxi = 40.0f;
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  nt2::exhaustive_test<float> ( mini
                              , maxi
                              , pow0()
                              , raw_pow()
                              );

  return 0;
}
