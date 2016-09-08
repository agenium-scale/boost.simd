#include <iostream>
#include <vector>

#include <boost/align/aligned_allocator.hpp>
#include <boost/align/aligned_delete.hpp>

#include <boost/simd/pack.hpp>
#include <boost/simd/function/load.hpp>
#include <boost/simd/function/store.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/function/sqr.hpp>
#include <boost/simd/function/plus.hpp>
#include <boost/simd/function/minus.hpp>
#include <boost/simd/function/deinterleave_first.hpp>
#include <boost/simd/function/deinterleave_second.hpp>

int main(int argc, char **argv){
  namespace bs = boost::simd;
  namespace ba = boost::alignment;

  using pack_t = bs::pack<int>;

  //! [distance-declare]
  std::size_t num_points = 1024;
  std::size_t alignment = pack_t::alignment;
  std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> X(num_points);
  std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> Y(num_points);
  std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> distance(num_points);
  int refX, refY;
  //! [distance-declare]

  // X and Y are assumed to be filled with the required data

  //! [distance-calc]
  pack_t vrefX = pack_t(refX);
  pack_t vrefY = pack_t(refY);

  for(int i = 0; i < num_points; i += pack_t::static_size){
    pack_t vX = bs::load<pack_t>(&X[i]);
    pack_t vY = bs::load<pack_t>(&Y[i]);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::store(res, &distance[i]);
  }
  //! [distance-calc]

  //! [distance-interleave]
  // The input vector contains interleaved X and Y data, i.e. x0, y0, x1, y1, ..., xn, yn
  std::vector<int, ba::aligned_allocator<int, pack_t::alignment>> interleaved_data(num_points * 2);
  for(int i = 0; i < num_points; i += pack_t::static_size * 2){
    pack_t v0 = bs::load<pack_t>(&X[i]);
    pack_t v1 = bs::load<pack_t>(&X[i + pack_t::static_size]);
    pack_t vX = bs::deinterleave_first(v0, v1);
    pack_t vY = bs::deinterleave_second(v0, v1);
    pack_t res = bs::sqrt(bs::sqr(vrefX - vX) + bs::sqr(vrefY - vY));
    bs::store(res, &distance[i]);
  }
  //! [distance-interleave]
}
