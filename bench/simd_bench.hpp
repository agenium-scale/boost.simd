//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_BENCH_HPP_INCLUDED
#define SIMD_BENCH_HPP_INCLUDED

#include <ns.bench.hpp>
#include <boost/config.hpp>
#include <boost/simd/pack.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>

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
  return nsb::default_setup();
}

ns::bench::results& results()
{
  static ns::bench::results r;
  return r;
}

inline bool is_quiet()
{
  return ns::bench::args_map().get<bool>("quiet", false);
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

namespace nsb = ns::bench;

template <typename Experiment, typename Type, std::size_t ElementSize>
struct bench_experiment : ns::bench::experiment
{
  //using type = typename Experiment::type;
  using type = Type;

  void which_type()
  {
    if (!is_quiet()) {
      std::cout << ":: [T = " << nsb::type_id<type>() << "]" << std::endl;
    }
  }

  template <typename U>
  void operator()(U min0, U max0)
  {
    which_type();
    run_bench<ElementSize>
      ( Experiment::name()
      , Experiment::functor()
      , nsb::generators::rand<type>(min0, max0)
      );
  }

  template <typename U>
  void operator()(U min0, U max0, U min1, U max1)
  {
    which_type();
    run_bench<ElementSize>
      ( Experiment::name()
      , Experiment::functor()
      , nsb::generators::rand<type>(min0, max0)
      , nsb::generators::rand<type>(min1, max1)
      );
  }

  template <typename U>
  void operator()(U min0, U max0, U min1, U max1, U min2, U max2)
  {
    which_type();
    run_bench<ElementSize>
      ( Experiment::name()
      , Experiment::functor()
      , nsb::generators::rand<type>(min0, max0)
      , nsb::generators::rand<type>(min1, max1)
      , nsb::generators::rand<type>(min2, max2)
      );
  }
};

void describe()
{
  if (!is_quiet()) {
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
    std::cout << ":: Compiler: " << BOOST_COMPILER << std::endl;
    std::cout << ":: Platform: " << BOOST_PLATFORM << std::endl;
    std::cout << ":: SIMD:     " << nsb::type_id<BOOST_SIMD_DEFAULT_SITE>() << std::endl;
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
  }
}

template <typename T>                            struct template_of;
template <template <class> class Tp, typename T> struct template_of<Tp<T>> { using type = T; };
template <typename T>
using template_of_t = typename template_of<T>::type;

template <typename Experiment>
using simd_experiment =
  bench_experiment< Experiment
                  , boost::simd::pack<template_of_t<Experiment>>
                  , boost::simd::pack<template_of_t<Experiment>>::static_size
                  >;

template <typename Experiment>
using scalar_experiment =
  bench_experiment< Experiment
                  , template_of_t<Experiment>
                  , 1
                  >;

#define DEFINE_BENCH(name_, f, experiment)                                                         \
  template <typename T>                                                                            \
  struct name_ : experiment<name_<T>>                                                              \
  {                                                                                                \
    static const char* name()    { return BOOST_PP_STRINGIZE(name_); }                             \
    static decltype(f) functor() { return f; }                                                     \
  }                                                                                                \
/**/

#define DEFINE_SIMD_BENCH(name, f)   DEFINE_BENCH(name, f, simd_experiment)
#define DEFINE_SCALAR_BENCH(name, f) DEFINE_BENCH(name, f, scalar_experiment)

#define DEFINE_BENCH_MAIN()                                                                        \
  void main2();                                                                                    \
  int main(int argc, char** argv)                                                                  \
  {                                                                                                \
    nsb::parse_args(argc, argv);                                                                   \
    main2();                                                                                       \
    describe();                                                                                    \
    print_results();                                                                               \
    return 0;                                                                                      \
  }                                                                                                \
  void main2()                                                                                     \
/**/

#endif
