//! [distance-all]
#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/function/fast.hpp>
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
#include <boost/simd/function/shuffle.hpp>

int main(int argc, char **argv){
  using namespace std::chrono;
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;

  using pack_t = bs::pack<float>;

  //! [distance-declare]
  std::size_t num_points = 1024000;
  std::size_t alignment = pack_t::alignment;
  namespace ba = boost::alignment;
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> X(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> Y(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> distance0(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> distance1(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> distance2(num_points);
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> distance3(num_points);

  std::iota(X.begin(), X.end(), float(0));
  std::iota(Y.begin(), Y.end(), float(num_points));

  float refX, refY;
  //! [distance-declare]

  auto t0 = high_resolution_clock::now();
  //! [distance-scalar]
  for(int i = 0; i < num_points; ++i){
    distance0[i] = std::sqrt(std::pow(refX - X[i], 2) + std::pow(refY - Y[i], 2));
  }
  //! [distance-scalar]
  auto t1 = high_resolution_clock::now();
  std::cout<<" time scalar " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  // X and Y are assumed to be filled with the required data

  //! [distance-time]
  t0 = high_resolution_clock::now();
  //! [distance-calc]
  pack_t vrefX = pack_t(refX);
  pack_t vrefY = pack_t(refY);

  for(int i = 0; i < num_points; i += pack_t::static_size){
    pack_t vX = bs::aligned_load<pack_t>(&X[i]);
    pack_t vY = bs::aligned_load<pack_t>(&Y[i]);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
//    pack_t res = bs::fast_(bs::sqrt)(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::aligned_store(res, &distance1[i]);
  }
  //! [distance-calc]
  t1 = high_resolution_clock::now();
  std::cout<<" time SIMD " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [distance-time]

  //! [distance-interleave]
  // The input vector contains interleaved X and Y data, i.e. x0, y0, x1, y1, ..., xn, yn
  std::vector<float, ba::aligned_allocator<float, pack_t::alignment>> interleaved_data(num_points * 2);
  for(int i = 0; i < num_points*2;i += 2){
    interleaved_data[i] = i / 2;
  }
  for(int i = 1; i < num_points*2;i += 2){
    interleaved_data[i] = (i) / 2 + num_points;
  }
  t0 = high_resolution_clock::now();
  for(int i = 0; i < num_points * 2; i += pack_t::static_size * 2){
    pack_t v0 = bs::aligned_load<pack_t>(&interleaved_data[i]);
    pack_t v1 = bs::aligned_load<pack_t>(&interleaved_data[i + pack_t::static_size]);

    auto b0 = bs::bitwise_cast<bd::as_floating_t<pack_t>>(v0);
    auto b1 = bs::bitwise_cast<bd::as_floating_t<pack_t>>(v1);
    auto b2 = _mm256_permute2f128_ps(b0,b1,0x20);
    auto b3 = _mm256_permute2f128_ps(b0,b1,0x31);

    pack_t vX =  _mm256_unpacklo_ps( _mm256_unpacklo_ps(b2,b3) , _mm256_unpackhi_ps(b2,b3));
    pack_t vY =  _mm256_unpackhi_ps( _mm256_unpacklo_ps(b2,b3) , _mm256_unpackhi_ps(b2,b3));
    //pack_t vX = bs::deinterleave_first(v0, v1);
    //pack_t vY = bs::deinterleave_second(v0, v1);
   // std::cout<<" v0 " << vX0 << " vx " << vX << std::endl;
   // std::cout<<" v1 " << vY0 << " vx " << vY << std::endl;
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::aligned_store(res, &distance2[i/2]);
  }
  //! [distance-interleave]
  t1 = high_resolution_clock::now();
  std::cout<<" time SIMD de-interleave " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
}
//! [distance-all]
