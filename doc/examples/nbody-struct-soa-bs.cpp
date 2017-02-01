//! [nbody-all]
#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>

#include <boost/simd/function/aligned_load.hpp>
#include <boost/simd/function/aligned_store.hpp>
#include <boost/simd/function/sqrt.hpp>
#include <boost/simd/pack.hpp>

#include <boost/simd/memory/allocator.hpp>

typedef float T;
namespace bs = boost::simd;
using pack_t = bs::pack<T>;

struct particles
{
  std::vector<T, bs::allocator<T>> x, y, z, m, vx, vy, vz;
  std::size_t size_;

  particles(std::size_t size)
    : size_(size)
    , x(size + pack_t::static_size)
    , y(size + pack_t::static_size)
    , z(size + pack_t::static_size)
    , m(size + pack_t::static_size)
    , vx(size + pack_t::static_size)
    , vy(size + pack_t::static_size)
    , vz(size + pack_t::static_size)
  {
  }

  std::size_t size() const
  {
    return size_;
  }
};

//! [nbody-simd]
void nbody_step(particles& ps)
{
  pack_t grav_con{6.67408e-11};
  pack_t epsilon{0.00125f};
  for (std::size_t i = 0; i < ps.size(); i += pack_t::static_size) {
    pack_t ax{0};
    pack_t ay{0};
    pack_t az{0};

    pack_t pix{&ps.x[i]};
    pack_t piy{&ps.y[i]};
    pack_t piz{&ps.z[i]};

    pack_t pim{&ps.m[i]};

    for (std::size_t j = i + 1; j < ps.size(); ++j) {
      auto pjx = bs::load<pack_t>(&ps.x[j]);
      auto pjy = bs::load<pack_t>(&ps.y[j]);
      auto pjz = bs::load<pack_t>(&ps.z[j]);

      auto dx = pjx - pix;
      auto dy = pjy - piy;
      auto dz = pjz - piz;

      auto inorm  = grav_con / bs::sqrt(dx * dx + dy * dy + dz * dz + epsilon);
      auto inorm3 = inorm * inorm * inorm;

      auto fi = bs::load<pack_t>(&ps.m[j]) * inorm3;
      auto fj = pim * inorm3;

      ax += dx * fi;
      ay += dy * fi;
      az += dz * fi;

      auto pjvx = bs::load<pack_t>(&ps.vx[j]);
      pjvx -= dx * fj;
      bs::store(pjvx, &ps.vx[j]);
      auto pjvy = bs::load<pack_t>(&ps.vy[j]);
      pjvy -= dy * fj;
      bs::store(pjvy, &ps.vy[j]);
      auto pjvz = bs::load<pack_t>(&ps.vz[j]);
      pjvz -= dz * fj;
      bs::store(pjvz, &ps.vz[j]);
    }

    pack_t pivx{&ps.vx[i]};
    pack_t pivy{&ps.vy[i]};
    pack_t pivz{&ps.vz[i]};

    pivx += ax;
    pivy += ay;
    pivz += az;

    pix += pivx;
    piy += pivy;
    piz += pivz;

    bs::aligned_store(pivx, &ps.vx[i]);
    bs::aligned_store(pivy, &ps.vy[i]);
    bs::aligned_store(pivz, &ps.vz[i]);

    bs::aligned_store(pix, &ps.x[i]);
    bs::aligned_store(piy, &ps.y[i]);
    bs::aligned_store(piz, &ps.z[i]);
  }
}
//! [nbody-simd]

//! [nbody-scalar]
void nbody_step_scalar(particles& ps)
{
  T epsilon = 0.00125f;
  for (std::size_t i = 0; i < ps.size(); ++i) {
    T ax{0};
    T ay{0};
    T az{0};

    T pix = ps.x[i];
    T piy = ps.y[i];
    T piz = ps.z[i];

    T pim = ps.m[i];

    for (std::size_t j = i + 1; j < ps.size(); ++j) {
      T pjx = ps.x[j];
      T pjy = ps.y[j];
      T pjz = ps.z[j];

      T dx = pjx - pix;
      T dy = pjy - piy;
      T dz = pjz - piz;

      T inorm = 6.667408e-11 / std::sqrt(dx * dx + dy * dy + dz * dz + epsilon);

      T fi = ps.m[j] * inorm * inorm * inorm;
      T fj = pim * inorm * inorm * inorm;

      ax += dx * fi;
      ay += dy * fi;
      az += dz * fi;

      ps.vx[j] -= dx * fj;
      ps.vy[j] -= dy * fj;
      ps.vz[j] -= dz * fj;
    }

    T pivx = ps.vx[i];
    T pivy = ps.vy[i];
    T pivz = ps.vz[i];

    pivx += ax;
    pivy += ay;
    pivz += az;

    pix += pivx;
    piy += pivy;
    piz += pivz;

    ps.vx[i] = pivx;
    ps.vy[i] = pivy;
    ps.vz[i] = pivz;

    ps.x[i] = pix;
    ps.y[i] = piy;
    ps.z[i] = piz;
  }
}
//! [nbody-scalar]

int main(int argc, char* argv[])
{
  std::size_t size = 4096, steps = 10;

  if (argc != 3) {
    std::cerr << "E: Incorrect number of arguments, using " << size << " particles and " << steps
              << " steps." << std::endl;
  } else {
    size  = std::stoll(argv[1], 0, 10);
    steps = std::stoll(argv[2], 0, 10);
  }

  particles ps_scalar(size);
  particles ps_simd(size);

  for (std::size_t i = 0; i < size; ++i) {
    ps_scalar.x[i] = (0.5f + i - size / 2) * 10.0f;
    ps_scalar.y[i] = 0.0f;
    ps_scalar.z[i] = 0.0f;
    ps_scalar.m[i] = 1.0f;
    ps_simd.x[i]   = (0.5f + i - size / 2) * 10.0f;
    ps_simd.y[i]   = 0.0f;
    ps_simd.z[i]   = 0.0f;
    ps_simd.m[i]   = 1.0f;
  }

  auto start = std::chrono::system_clock::now();

  for (std::size_t step = 0; step < steps; ++step) {
    nbody_step_scalar(ps_scalar);
  }

  auto stop = std::chrono::system_clock::now();

  auto duration = stop - start;

  std::cout << " Time scalar: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

  start = std::chrono::system_clock::now();

  for (std::size_t step = 0; step < steps; ++step) {
    nbody_step(ps_simd);
  }

  stop = std::chrono::system_clock::now();

  duration = stop - start;

  std::cout << " Time SIMD: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

  if (size < 64) {
    for (std::size_t i = 0; i < ps_scalar.size(); ++i) {
      std::cout << "(" << ps_scalar.x[i] << ", " << ps_scalar.y[i] << ", " << ps_scalar.z[i] << ")"
                << std::endl;
      std::cout << "(" << ps_simd.x[i] << ", " << ps_simd.y[i] << ", " << ps_simd.z[i] << ")"
                << std::endl;
    }
  }
  return 0;
}
//! [nbody-all]
