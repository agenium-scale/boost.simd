//==============================================================================
//         Copyright 2009 - 2013 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//         Copyright 2013        MetaScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/function/scalar/log.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmax.hpp>

#include <exhaustive.hpp>

// #define NT2_ASSERTS_AS_TRAP
// #include <nt2/sdk/error/assert_as_trap.hpp>

#include <cmath>
#include <cstdlib>

struct raw_log
{
  float operator()(float x) const
  {
    return std::log(double(x));
  }
};

int main(int argc, char* argv[])
{
  float mini = bs::Zero<float>();
  float maxi = bs::Valmax<float>();
  if(argc >= 2) mini = std::atof(argv[1]);
  if(argc >= 3) maxi = std::atof(argv[2]);
  bs::exhaustive_test<float> ( mini
                              , maxi
                             , bs::log
                              , raw_log()
                              );

  return 0;
}
