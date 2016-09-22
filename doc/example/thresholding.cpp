//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [threshold]
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

//! [hello-include-pack]
#include <boost/simd/pack.hpp>
//! [hello-include-pack]

#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/group.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/is_less.hpp>

int main()
{
  using namespace std::chrono;
  int image_size = 2560 * 2560;
  std::vector<std::int16_t> image(image_size);
  std::vector<std::int16_t> binary(image_size);
  std::generate(image.begin(), image.end(),
                []() { return std::rand() % std::numeric_limits<std::int16_t>::max(); });
  // select arbitrary threshold
  std::int16_t threshold = 5000;
  auto t0                = high_resolution_clock::now();
  //! [scalar-threshold]
  for (int i = 0; i < image.size(); ++i) {
    if (image[i] < threshold) {
      binary[i] = 0;
    } else {
      binary[i] = 1;
    }
  }
  auto t1 = high_resolution_clock::now();
  std::cout << "scalar       " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [scalar-threshold]

  //! [simd-threshold]
  namespace bs = boost::simd;

  using pack_t    = bs::pack<std::int16_t>;
  using logical_t = bs::pack<bs::logical<std::int16_t>>;

  static const std::size_t cardinal = pack_t::static_size;

  pack_t v_threshold{threshold};
  t0 = high_resolution_clock::now();
  for (int i = 0; i < image.size(); i += cardinal) {
    pack_t v_image(&image[i]);
    logical_t v_res = bs::is_less(v_image, v_threshold);
    pack_t v_binary = bs::if_zero_else_one(v_res);
    bs::aligned_store(v_binary, &binary[i]);
  }
  //! [simd-threshold]
  t1 = high_resolution_clock::now();
  std::cout << "SIMD         " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  //! [simd-threshold-downgrade]
  using pack_8           = bs::pack<std::int8_t>;
  std::size_t cardinal_8 = pack_8::static_size;
  std::vector<std::int8_t> binary_8(image_size);
  t0 = high_resolution_clock::now();
  for (int i = 0; i < image.size(); i += cardinal_8) {
    pack_t v_image0(&image[i]);
    pack_t v_image1(&image[i + cardinal]);
    pack_t v_binary0      = bs::if_zero_else_one(bs::is_less(v_image0, threshold));
    pack_t v_binary1      = bs::if_zero_else_one(bs::is_less(v_image1, threshold));
    pack_8 v_binary_group = bs::group(v_binary0, v_binary1);
    bs::aligned_store(v_binary_group, &binary_8[i]);
  }
  t1 = high_resolution_clock::now();
  std::cout << "downgrade    " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [simd-threshold-downgrade]
}
// This code can be compiled using (for instance for gcc)
// g++ thresholding.cpp -msse4.2 -std=c++11 -O3 -DNDEBUG -o thresholding
// -I/path_to/boost_simd/ -I/path_to/boost/

//! [threshold]
