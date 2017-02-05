//! [distance-hypot-all]
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <limits>

#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/hypot.hpp>
#include <boost/simd/function/pedantic.hpp>
#include <boost/simd/memory/allocator.hpp>
#include <boost/simd/pack.hpp>

int main(int argc, char** argv)
{
  using namespace std::chrono;
  namespace bs = boost::simd;
  typedef float T;
  using pack_t = bs::pack<T>;

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

  auto t0 = high_resolution_clock::now();
  //! [distance-hypot-scalar]
  for (int i = 0; i < num_points; ++i) {
    auto x       = refX - X[i];
    auto y       = refY - Y[i];
    distance0[i] = std::hypot(refX - X[i], refY - Y[i]);
  }
  //! [distance-hypot-scalar]
  auto t1 = high_resolution_clock::now();
  std::cout << " time scalar " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  //! [distance-hypot-time]
  t0 = high_resolution_clock::now();
  //! [distance-hypot-calc]
  pack_t vrefX = pack_t(refX);
  pack_t vrefY = pack_t(refY);

  for (int i = 0; i < num_points; i += pack_t::static_size) {
    pack_t vX  = bs::aligned_load<pack_t>(&X[i]);
    pack_t vY  = bs::aligned_load<pack_t>(&Y[i]);
    pack_t res = bs::pedantic_(bs::hypot)(vrefX - vX, vrefY - vY);
    bs::aligned_store(res, &distance1[i]);
  }
  //! [distance-hypot-calc]

  t1 = high_resolution_clock::now();
  std::cout << " time SIMD hypot " << duration_cast<microseconds>(t1 - t0).count() << std::endl;

  t0 = high_resolution_clock::now();
  //! [distance-hypot-fast-hypot]
  for (int i = 0; i < num_points; i += pack_t::static_size) {
    pack_t vX  = bs::aligned_load<pack_t>(&X[i]);
    pack_t vY  = bs::aligned_load<pack_t>(&Y[i]);
    pack_t res = bs::hypot(vrefX - vX, vrefY - vY);
    bs::aligned_store(res, &distance2[i]);
  }
  ////! [distance-hypot-fast-hypot]
  t1 = high_resolution_clock::now();
  std::cout << " time SIMD fast hypot " << duration_cast<microseconds>(t1 - t0).count()
            << std::endl;
}
//! [distance-hypot-all]
