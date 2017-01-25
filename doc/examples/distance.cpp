//! [distance-all]
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <limits>

#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/deinterleave.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>

int main(int argc, char** argv)
{
  using namespace std::chrono;
  namespace bs = boost::simd;
  typedef float T;
  using pack_t = bs::pack<T>;

  //! [distance-declare]
  std::size_t num_points = 1600000;
  std::vector<T, bs::allocator<T>> X(num_points);
  std::vector<T, bs::allocator<T>> Y(num_points);
  std::vector<T, bs::allocator<T>> distance0(num_points);
  std::vector<T, bs::allocator<T>> distance1(num_points);
  std::vector<T, bs::allocator<T>> distance2(num_points);
  std::vector<T, bs::allocator<T>> distance3(num_points);

  std::generate(X.begin(), X.end(),
                []() { return T(std::rand()) / std::numeric_limits<int>::max(); });
  std::generate(Y.begin(), Y.end(),
                []() { return T(std::rand()) / std::numeric_limits<int>::max(); });

  T refX = 0, refY = 0;
  //! [distance-declare]

  auto t0 = high_resolution_clock::now();
  //! [distance-scalar]
  for (int i = 0; i < num_points; ++i) {
    auto x       = refX - X[i];
    auto y       = refY - Y[i];
    distance0[i] = std::sqrt(x * x + y * y);
  }
  //! [distance-scalar]
  auto t1 = high_resolution_clock::now();
  std::cout << " time scalar " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  //! [distance-time]
  t0 = high_resolution_clock::now();
  //! [distance-calc]
  pack_t vrefX = pack_t(refX);
  pack_t vrefY = pack_t(refY);

  for (int i = 0; i < num_points; i += pack_t::static_size) {
    pack_t vX  = bs::aligned_load<pack_t>(&X[i]);
    pack_t vY  = bs::aligned_load<pack_t>(&Y[i]);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::aligned_store(res, &distance1[i]);
  }
  //! [distance-calc]
  t1 = high_resolution_clock::now();
  std::cout << " time SIMD " << duration_cast<microseconds>(t1 - t0).count() << std::endl;
  //! [distance-time]

  //! [distance-interleave]
  // The input vector contains interleaved X and Y data, i.e. x0, y0, x1, y1,
  // ..., xn, yn
  std::vector<T, bs::allocator<T>> interleaved_data(num_points * 2);
  for (int i = 0; i < num_points * 2; i += 2) {
    interleaved_data[i]     = X[i / 2];
    interleaved_data[i + 1] = Y[i / 2];
  }
  t0 = high_resolution_clock::now();
  for (int i = 0; i < num_points * 2; i += pack_t::static_size * 2) {
    pack_t v0 = bs::aligned_load<pack_t>(&interleaved_data[i]);
    pack_t v1 = bs::aligned_load<pack_t>(&interleaved_data[i + pack_t::static_size]);

    auto V     = bs::deinterleave(v0, v1);
    pack_t res = bs::sqrt(bs::sqr(vrefX - V[0]) + bs::sqr(vrefY - V[1]));
    bs::aligned_store(res, &distance2[i / 2]);
  }
  t1 = high_resolution_clock::now();
  //! [distance-interleave]
  std::cout << " time SIMD de-interleave " << duration_cast<microseconds>(t1 - t0).count()
            << std::endl;
}
//! [distance-all]
