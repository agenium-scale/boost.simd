#include <iostream>
#include <vector>
#include <chrono>

#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>

int main(int argc, char **argv){
  using namespace std::chrono;
  namespace bs = boost::simd;

  using pack_t = bs::pack<float>;

  //! [distance-declare]
  std::size_t num_points = 1024000;
  std::size_t alignment = pack_t::alignment;
  namespace ba = boost::alignment;
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> X(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> Y(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> distance(num_points);
  float refX, refY;
  //! [distance-declare]

  auto t0 = high_resolution_clock::now();
  //! [distance-scalar]
  for(int i = 0; i < num_points; ++i){
    distance[i] = std::sqrt(std::pow(refX - X[i], 2) + std::pow(refY - Y[i], 2));
  }
  //! [distance-scalar]
  auto t1 = high_resolution_clock::now();
  std::cout<<" time scalar " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  // X and Y are assumed to be filled with the required data

  //! [distance-calc]
  t0 = high_resolution_clock::now();
  pack_t vrefX = pack_t(refX);
  pack_t vrefY = pack_t(refY);

  std::cout<<" card " << pack_t::static_size << std::endl;
  for(int i = 0; i < num_points; i += pack_t::static_size){
    pack_t vX = bs::aligned_load<pack_t>(&X[i]);
    pack_t vY = bs::aligned_load<pack_t>(&Y[i]);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::aligned_store(res, &distance[i]);
  }
  //! [distance-calc]
  t1 = high_resolution_clock::now();
  std::cout<<" time SIMD " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  //! [distance-time]
  //! [distance-interleave]
  // The input vector contains interleaved X and Y data, i.e. x0, y0, x1, y1, ..., xn, yn
  std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> interleaved_data(num_points * 2);
  t0 = high_resolution_clock::now();
  for(int i = 0; i < num_points * 2; i += pack_t::static_size * 2){
    pack_t v0 = bs::aligned_load<pack_t>(&interleaved_data[i]);
    pack_t v1 = bs::aligned_load<pack_t>(&interleaved_data[i + pack_t::static_size]);
    pack_t vX = bs::deinterleave_first(v0, v1);
    pack_t vY = bs::deinterleave_second(v0, v1);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::aligned_store(res, &distance[i]);
  }
  //! [distance-interleave]
  t1 = high_resolution_clock::now();
  std::cout<<" time SIMD de-interleave " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [distance-time]
}
