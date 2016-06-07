//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [hello]
#include <iostream>
//! [hello-include-pack]
#include <boost/simd/pack.hpp>
//! [hello-include-pack]

int main()
{
  //! [hello-namespace]
  namespace bs = boost::simd;
  //! [hello-namespace]
  //! [hello-pack]
  using pack_t = bs::pack<float>;
  //! [hello-pack]

  //! [hello-def-ctor]
  pack_t res;
  //! [hello-def-ctor]

  //! [hello-splat-ctor]
  pack_t tens{10};
  //! [hello-splat-ctor]

  //! [hello-splat-explicit]
  pack_t elevens(11);
  //! [hello-splat-explicit]

  //! [hello-ops]
  res = (tens + elevens) * 2.f;
  //! [hello-ops]

  //! [hello-io]
  std::cout << res << std::endl;
  //! [hello-io]

  return 0;
}
//! [hello]
