#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

//! [substract]
#include <boost/simd/pack.hpp>
#include <boost/simd/meta/cardinal_of.hpp>

//! [substract-include]
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
//! [substract-include]
#include <boost/simd/function/minus.hpp>

int main() {
 //! [substract-simd-types]
  namespace bs = boost::simd;
  size_t size = 128;
  std::vector<int32_t> array(size);
  std::vector<int32_t> out(size);
  // Initialize input array
  std::iota(array.begin(), array.end(), 0);
  int32_t scalar = 42;
  //! [substract-simd-types]

  //! [substract-cardinal]
  using pack_t = bs::pack<int32_t>;
  size_t pack_card = bs::cardinal_of<pack_t>();
  //! [substract-cardinal]


  //! [substract-scalar]
  // Scalar version
  for ( size_t i = 0; i < size; ++i ){
    out[i] = array[i] - scalar;
  }
  //! [substract-scalar]

  {
  //! [substract-loop-con]
  for ( size_t i = 0; i < size; i += pack_card ) {

  }
  //! [substract-loop-con]

  //! [substract-fortytwo]
  pack_t p_out, fortytwo(scalar);
  //! [substract-fortytwo]

  //! [substract-pointer]
  for ( size_t i = 0; i < size; i += pack_card ) {
    pack_t p_arr(array.data() + i);
    p_out = p_arr - fortytwo;
    bs::store(p_out, out.data() + i);
  }
  //! [substract-pointer]
  }

  {
  //! [substract-load]
  // Using explicit load/store
  pack_t p_out, p_arr, fortytwo{scalar};
  for ( size_t i = 0; i < size; i += pack_card ) {
    p_arr = bs::load<pack_t>(array.data() + i);
    p_out = p_arr - fortytwo;
    bs::store(p_out, out.data() + i);
  }
  //! [substract-load]
  }

  {
  //! [substract-remainder]
  // Using explicit load/store
  // set size to an arbitrary value
  size = 133;
  pack_t p_out, p_arr, fortytwo{42};
  array.resize(size);
  out.resize(size);
  size_t i = 0;
  for (; i + pack_card <= size; i += pack_card ) {
    p_arr = bs::load<pack_t>(array.data() + i);
    p_out = p_arr - fortytwo;
    bs::store(p_out, out.data() + i);
  }

  for (; i < size; ++i ){
    out[i] = array[i] - scalar;
  }
  //! [substract-remainder]
  }
  return 0;
}
//! [substract]
