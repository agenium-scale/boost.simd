//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [threshold]
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

#include <boost/simd/pack.hpp>

#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/memory/allocator.hpp>

int main()
{
  namespace bs   = boost::simd;
  int image_size = 2560 * 2560;
  std::vector<std::int16_t, bs::allocator<std::int16_t>> image(image_size);
  std::vector<std::int16_t, bs::allocator<std::int16_t>> binary(image_size);
  std::generate(image.begin(), image.end(),
                []() { return std::rand() % std::numeric_limits<std::int16_t>::max(); });
  // select arbitrary threshold
  std::int16_t threshold = 5000;
  //! [scalar-threshold]
  for (int i = 0; i < image.size(); ++i) {
    if (image[i] < threshold) {
      binary[i] = 0;
    } else {
      binary[i] = 1;
    }
  }
  //! [scalar-threshold]

  //! [simd-threshold]
  using pack_t    = bs::pack<std::int16_t>;
  using logical_t = bs::pack<bs::logical<std::int16_t>>;

  pack_t v_threshold{threshold};
  for (int i = 0; i < image.size(); i += pack_t::static_size) {
    pack_t v_image(&image[i]);
    logical_t v_res = bs::is_less(v_image, v_threshold);
    pack_t v_binary = bs::if_zero_else_one(v_res);
    bs::aligned_store(v_binary, &binary[i]);
  }
  //! [simd-threshold]
}
// This code can be compiled using (for instance for gcc)
// g++ thresholding.cpp -msse4.2 -std=c++11 -O3 -DNDEBUG -o thresholding
// -I/path_to/boost_simd/ -I/path_to/boost/

//! [threshold]
