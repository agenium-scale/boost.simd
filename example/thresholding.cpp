//==================================================================================================
/*
  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================

//! [threshold]
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <limits>

//! [hello-include-pack]
#include <boost/simd/pack.hpp>
//! [hello-include-pack]

#include <boost/simd/function/store.hpp>
#include <boost/simd/function/if_zero_else_one.hpp>
#include <boost/simd/function/is_less.hpp>
#include <boost/simd/function/group.hpp>

int main()
{
  int image_size = 256 * 256;
  std::vector<std::uint16_t> image(image_size);
  std::vector<std::uint16_t> binary(image_size);
  std::generate( image.begin(), image.end(),
                []()
                {
                  return std::rand() % std::numeric_limits<std::uint16_t>::max();
                }
                );
  //select arbitrary threshold
  std::uint16_t threshold = 50;
  //! [scalar-threshold]
  for(int i = 0; i < image.size(); ++i){
    if(image[i] < threshold){
      binary[i] = 0;
    } else {
      binary[i] = 1;
    }
  }
  //! [scalar-threshold]

  //! [simd-threshold]
  namespace bs = boost::simd;
  using pack_t = bs::pack<std::uint16_t>;
  using logical_t = bs::pack<bs::logical<std::uint16_t>>;
  std::size_t cardinal = pack_t::static_size;

  pack_t v_threshold{threshold};
  for( int i = 0; i < image.size(); i += cardinal){
    pack_t v_image(&image[i]);
    auto v_res = bs::is_less(v_image, threshold);
    pack_t v_binary = bs::if_zero_else_one(v_res);
    bs::store(v_binary, &binary[i]);
  }
  //! [simd-threshold]

  //! [simd-threshold-downgrade]
  using pack_8 = bs::pack<std::uint8_t>;
  std::size_t cardinal_8 = pack_8::static_size;

  std::vector<std::uint8_t> binary_8(image_size);
  for( int i = 0; i < image.size(); i += cardinal_8){
    pack_t v_image0(&image[i]);
    pack_t v_image1(&image[i + cardinal]);
    pack_t v_binary0 = bs::if_zero_else_one(bs::is_less(v_image0, threshold));
    pack_t v_binary1 = bs::if_zero_else_one(bs::is_less(v_image1, threshold));
    pack_8 v_binary_group = bs::group(v_binary0, v_binary1);
    bs::store(v_binary_group, &binary_8[i]);
  }
  //! [simd-threshold-downgrade]
}
//! [threshold]
