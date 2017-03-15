//==================================================================================================
/*!

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef SIMD_BENCH_HPP_INCLUDED
#define SIMD_BENCH_HPP_INCLUDED

#include <boost/config.hpp>
#include <boost/simd/pack.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/algorithm/string/erase.hpp>
#include <ns/bench.hpp>

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

namespace ns { namespace bench { namespace generators {

template <typename T, std::size_t N>
struct rand<boost::simd::pack<T, N>>
{
  using pack_type = boost::simd::pack<T, N>;
  using value_type = typename pack_type::value_type;

  template <typename U>
  rand( U min = static_cast<U>(std::numeric_limits<value_type>::min())
      , U max = static_cast<U>(std::numeric_limits<value_type>::max())
      ) : r(min, max)
  {
  }

  inline pack_type operator()() {
    std::array<value_type, sizeof(pack_type) / sizeof(value_type)> v;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
    return {v.begin(), v.end()};
  }

  std::string description() const {
    return "TODO";
  }

  private :
  rand<value_type> r;
};

} } }

// -------------------------------------------------------------------------------------------------

namespace nsb = ns::bench;
namespace nsbg = nsb::generators;

inline nsb::setup setup()
{
  return nsb::default_setup();
}

inline nsb::results& results()
{
  static nsb::results r;
  return r;
}

inline bool is_quiet()
{
  return nsb::args_map().get<bool>("quiet", false);
}

inline void display()
{
  std::cout << results() << std::endl;
}

inline std::string sanitized_simd()
{
  namespace ba = boost::algorithm;
  auto s = nsb::type_id<BOOST_SIMD_DEFAULT_SITE>();
  ba::ierase_all(s, "boost::simd::");
  ba::ierase_all(s, "_");
  return s;
}

template <typename F>
inline std::string sanitized_function()
{
  namespace ba = boost::algorithm;
  auto s = nsb::type_id<F>();
  ba::ierase_all(s, "boost::dispatch::functor");
  ba::ierase_all(s, "boost::simd::tag::");
  ba::ierase_all(s, "<");
  ba::ierase_all(s, ">");
  ba::ierase_all(s, "_");
  ba::ierase_all(s, " ");
  auto i = s.find(",");
  if (i != std::string::npos) {
    s = s.substr(0, i);
  }
  return "boost::simd::" + s;
}

inline void describe()
{
  if (!is_quiet()) {
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
    std::cout << ":: Compiler: " << BOOST_COMPILER << std::endl;
    std::cout << ":: Platform: " << BOOST_PLATFORM << std::endl;
    std::cout << ":: SIMD:     " << sanitized_simd() << std::endl;
    std::cout << ":: --------------------------------------------------------------------------------------------------------------------------------------------------";
    std::cout << std::endl;
  }
}

// -------------------------------------------------------------------------------------------------

template <typename T> struct experiment_size_of {
  enum { value = 1 };
};

template <typename T, std::size_t N>
struct experiment_size_of<boost::simd::pack<T, N>>  {
  enum { value = N };
};

// -------------------------------------------------------------------------------------------------

template <typename T, typename F, typename... Args>
void run(std::string const& name, F f, Args&&... args)
{
  enum { N = experiment_size_of<T>::value };
  if (!is_quiet()) {
    std::cout << ":: [T = " << nsb::type_id<T>() << "]" << std::endl;
    std::cout << ":: [N = " << N << "]" << std::endl;
  }
  nsb::run(results(), setup(), name, nsb::make_sized_function(N, f), std::forward<Args>(args)...);
}

template <typename T, typename F, typename... Args>
void run(F f, Args&&... args)
{
  run<T>(sanitized_function<F>(), f, std::forward<Args>(args)...);
}

// -------------------------------------------------------------------------------------------------

#define DEFINE_BENCH_MAIN()                                                                        \
  void main2();                                                                                    \
  int main(int argc, char** argv)                                                                  \
  {                                                                                                \
    nsb::parse_args(argc, argv);                                                                   \
    main2();                                                                                       \
    describe();                                                                                    \
    results().add_optional_info("simd", sanitized_simd());                                         \
    display();                                                                               \
    return 0;                                                                                      \
  }                                                                                                \
  void main2()                                                                                     \
/**/

#endif
