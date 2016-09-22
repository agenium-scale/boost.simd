//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [hello]
#include <iostream>
#include <list>
#include <numeric>
#include <vector>
//! [hello-include-pack]
#include <boost/simd/pack.hpp>
//! [hello-include-pack]

#include <boost/simd/function/multiplies.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/splat.hpp>
#include <boost/simd/function/store.hpp>

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

  pack_t elevens{11};

  //! [hello-ptr-iota]
  std::vector<float> values(1000);
  std::iota(values.begin(), values.end(), float(0));
  pack_t ptr_pack(values.data());
  //! [hello-ptr-iota]

  //! [hello-iter-con]
  std::list<float> data(pack_t::static_size);
  std::iota(data.begin(), data.begin() + pack_t::static_size, float(0));
  pack_t iter_pack(data.begin(), data.end());
  //! [hello-iter-con]

  //! [hello-enum-con]
  pack_t enum_pack({10, 11, 12, 13, 14, 15, 16, 17});
  //! [hello-enum-con]

  //! [hello-ops]
  res = (tens + elevens) * 2;
  //! [hello-ops]

  //! [hello-store]
  float output[pack_t::static_size];
  bs::store(res, &output[0]);
  //! [hello-store]

  //! [hello-io]
  std::cout << res << std::endl;
  //! [hello-io]

  return 0;
}
//! [hello]
