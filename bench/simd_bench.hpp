//==================================================================================================
/*!

  Copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_BENCH_HPP_INCLUDED
#define SIMD_BENCH_HPP_INCLUDED

#include <ns.bench.v2.hpp>
#include <boost/simd/pack.hpp>

namespace ns { namespace bench {

template <typename T, std::size_t N>
struct format_type<boost::simd::pack<T, N>>
{
  static std::string to_string()
  {
    std::stringstream ss;

    ss << "pack<" << format_type<T>::to_string() << ", " << N << ">";
    return ss.str();
  }
};

} }

ns::bench::setup setup()
{
  namespace nsb = ns::bench;
  return nsb::setup()
    .median(nsb::units::cpe_)
    .really_during(1.)
    ;
}

ns::bench::results& results()
{
  static ns::bench::results r;
  return r;
}

void print_results()
{
  std::cout << results() << std::endl;
}

template <std::size_t N, typename F, typename... Args>
void run_bench(std::string const& name, F f, Args&&... args)
{
  namespace nsb = ns::bench;
  nsb::run(results(), setup(), name, nsb::make_sized_function(N, f), std::forward<Args>(args)...);
}

template <std::size_t N, typename F, typename... Args>
void run_bench(const char* name, F f, Args&&... args)
{
  run_bench<N>(std::string(name), f, std::forward<Args>(args)...);
}

template <std::size_t N, typename F, typename... Args>
void run_bench(F f, Args&&... args)
{
  namespace nsb = ns::bench;
  run_bench<N>(nsb::type_id<F>(), f, std::forward<Args>(args)...);
}

#endif
