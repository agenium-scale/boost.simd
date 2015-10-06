//==================================================================================================
/*
  Copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [hello]
#include <boost/simd/pack.hpp>
#include <boost/simd/io.hpp>
#include <boost/simd/functions/splat.hpp>
#include <boost/simd/functions/plus.hpp>
#include <boost/simd/functions/multiplies.hpp>
#include <iostream>

int main()
{
  using p_t = boost::simd::pack<float>;

  //! [hello-def-ctor]
  p_t res;
  //! [hello-def-ctor]

  //! [hello-splat-ctor]
  p_t u{10};
  //! [hello-splat-ctor]

  //! [hello-enum-ctor]
  p_t r{11,11,11,11};
  //! [hello-enum-ctor]

  //! [hello-ops]
  res = (u + r) * 2.f;
  //! [hello-ops]

  //! [hello-io]
  std::cout << res << std::endl;
  //! [hello-io]

  return 0;
}
//! [hello]
