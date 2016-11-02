// -------------------------------------------------------------------------------------------------
/*!
  @file Main header for benchmark components
  @copyright 2016 - NumScale SAS
  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
**/
// -------------------------------------------------------------------------------------------------
#ifndef NS_BENCH_HPP_INCLUDED
#define NS_BENCH_HPP_INCLUDED
namespace ns { namespace bench {
/*!
  @defgroup group-bench Benchmark components
  Benchmark components
 **/
} }
#include <boost/core/demangle.hpp>
#include <type_traits>
namespace ns { namespace bench {
template<typename T> inline std::string type_id()
{
  typedef std::is_const<typename std::remove_reference<T>::type>  const_t;
  typedef std::is_lvalue_reference<T>                             lref_t;
  typedef std::is_rvalue_reference<T>                             rref_t;
  std::string s = boost::core::demangle(typeid(T).name());
  s += const_t::value ? " const"  : "";
  s += lref_t::value   ? "&"      : "";
  s += rref_t::value   ? "&&"     : "";
  return s;
}
template<typename T> inline std::string type_id( const T& )
{
  return type_id<T>();
}
} }
#include <boost/lexical_cast.hpp>
#include <list>
#include <unordered_map>
namespace ns { namespace bench { namespace args {
struct parser;
namespace detail {
  struct option;
  template <typename T> struct typed_option;
}
struct options_map {
  using key_type = std::string;
  using value_type = std::string;
  using options_container = std::unordered_map<std::string, value_type>;
  using anonymous_container = std::list<value_type>;
  bool has(key_type const& opt_name) const {
    return opts_map_.find(opt_name) != opts_map_.end();
  }
  template <typename T>
  T get(key_type const& opt_name) const {
    return boost::lexical_cast<T>(opts_map_.at(opt_name));
  }
  template <typename T>
  T get(key_type const& opt_name, T const& fallback) const {
    return has(opt_name) ? get<T>(opt_name) : fallback;
  }
  anonymous_container const& anonymous() const {
    return anon_map_;
  }
  options_container const& options() const {
    return opts_map_;
  }
  private:
  void add_option(key_type const& name, value_type const& value) {
    opts_map_[name] = value;
  }
  void add_anonymous(value_type const& value) {
    anon_map_.emplace_back(value);
  }
  friend parser;
  friend detail::option;
  template <typename T> friend struct detail::typed_option;
  private:
    options_container opts_map_;
    anonymous_container anon_map_;
};
} } }
#include <stdexcept>
namespace ns { namespace bench { namespace args {
struct parse_error : std::runtime_error {
  parse_error(std::string const& what_)
    : std::runtime_error(what_) {
  }
};
} } }
#include <boost/tokenizer.hpp>
#include <string>
namespace ns { namespace bench { namespace args { namespace detail {
struct option {
  option(std::string const& n, std::string const&  o, bool req)
    : name_(n), opts_(o), required_(req) {
  }
  virtual bool validate(options_map& m, std::string const& arg, std::string const& opt) const {
    if (arg.find(opt) == 0 && opt.length() == arg.length()) {
      m.add_option(name(), "1");
      return true;
    }
    return false;
  }
  virtual bool need_value() const {
    return false;
  }
  bool parse(options_map& m, std::string arg) const {
    std::string l_opts(opts_);
    boost::char_separator<char> sep(",");
    for (auto opt : boost::tokenizer<decltype(sep)>(l_opts, sep)) {
      if (validate(m, arg, opt)) {
        return true;
      }
    }
    return false;
  }
  std::string usage() const {
    std::string u;
    std::string s;
    std::size_t how_many = 0;
    boost::char_separator<char> sep(",");
    for (auto opt : boost::tokenizer<decltype(sep)>(std::string(opts()), sep)) {
      if (how_many) {
        s += " | " + opt;
      } else {
        s += opt;
        how_many += 1;
      }
      if (need_value()) {
        s += "=<value>";
      }
    }
    if (!required()) {
      u += "[";
      u += s;
      u += "]";
    } else if (how_many) {
      u += "(";
      u += s;
      u += ")";
    } else {
      u = s;
    }
    return u;
  }
  std::string const& name() const { return name_; }
  std::string const& opts() const { return opts_; }
  bool required() const { return required_; }
  private:
  std::string name_;
  std::string opts_;
  bool required_;
};
template <typename T>
struct typed_option : option {
  typed_option(std::string n, std::string o, bool r)
    : option(n, o, r) {
  }
  virtual bool validate(options_map& m, std::string const& arg, std::string const& opt) const {
    auto pos = arg.find(opt);
    if (pos == 0) {
      if (arg[opt.length()] == '=') {
        auto rhs = arg.substr(opt.length() + 1, arg.length() - opt.length() - 1);
        try {
          (void)boost::lexical_cast<T>(rhs);
        } catch (boost::bad_lexical_cast) {
          throw parse_error(opts() + " expects a valid value of type: " + ns::bench::type_id<T>());
        }
        m.add_option(name(), rhs);
        return true;
      }
    }
    return false;
  }
  virtual bool need_value() const {
    return true;
  }
};
template <typename T, class Enable = void>
struct auto_option {
  using type = typed_option<T>;
};
template <typename T>
struct auto_option<T, typename std::enable_if<std::is_same<T, bool>::value>::type> {
  using type = option;
};
} } } }
#include <list>
#include <unordered_map>
#include <iostream>
namespace ns { namespace bench { namespace args {
struct parser {
  public:
  parser(std::string const& bin_name = "")
    : bin_name_(bin_name), opts_() {
  }
  template <typename T = void>
  void add_option(std::string const& name, std::string const& opts, bool required = false) {
    opts_.emplace(name, new typename detail::auto_option<T>::type(name, opts, required));
  }
  std::string usage() const {
    std::string u = "usage: ";
    u += bin_name_;
    u += " [-h | --help] ";
    bool first = true;
    for (auto opt_pair : opts_) {
      if (!first) {
        u += " " + opt_pair.second->usage();
      } else {
        u += opt_pair.second->usage();
        first = false;
      }
    }
    u += "\n";
    return u;
  }
  void parse(options_map& m, int argc, char **argv) const {
    try {
      parse_(m, argc, argv);
    } catch (parse_error const& e) {
      std::string s;
      s += usage();
      s += bin_name_;
      s += ": ";
      s += "error: ";
      s += e.what();
      s += "\n";
      throw parse_error(s);
    }
  }
  void parse(options_map& m, int argc, char **argv, std::nothrow_t const&) const {
    try {
      parse(m, argc, argv);
    } catch (parse_error const& e) {
      std::cerr << e.what();
      std::cerr.flush();
      std::exit(1);
    }
  }
  private:
  void parse_(options_map& m, int argc, char **argv) const {
    for (int i = 1; i < argc; ++i) {
      std::string arg(argv[i]);
      if (arg == "-h" || arg == "--help") {
        std::cout << usage();
        std::cout.flush();
        std::exit(0);
      }
      bool parsed = false;
      for (auto opt_pair : opts_) {
        auto opt = opt_pair.second;
        if (opt->parse(m, arg)) {
          parsed = true;
          break;
        }
      }
      if (!parsed) {
        if (arg[0] == '-') {
          throw parse_error(arg + " unknown predicate!");
        }
        m.add_anonymous(arg);
      }
    }
    for (auto opt_pair : opts_) {
      auto opt = opt_pair.second;
      if (opt->required() && !m.has(opt->name())) {
        throw parse_error(opt->usage() + " is required!");
      }
    }
  }
  private:
    const std::string bin_name_;
    std::unordered_map<std::string, detail::option*> opts_;
};
} } }
std::ostream& operator<<(std::ostream& os, ns::bench::args::options_map const& m) {
  os << "anonymous( ";
  for (auto a : m.anonymous()) {
    os << a << ", ";
  }
  os << ")" << std::endl;;
  os << "options{ ";
  for (auto a : m.options()) {
    os << a.first << ":" << a.second << ", ";
  }
  os << "}" << std::endl;;
  return os;
}
std::ostream& operator<<(std::ostream& os, ns::bench::args::parser const& p) {
  os << p.usage();
  os.flush();
  return os;
}
#include <cstdint>
#include <new>
namespace ns { namespace bench {
inline ns::bench::args::options_map& args_map() {
  static ns::bench::args::options_map om;
  return om;
}
inline ns::bench::args::parser& parser() {
  static ns::bench::args::parser p("");
  return p;
}
inline void parse_args(int argc, char **argv) {
  auto& p = parser();
  p.add_option<std::size_t>("frequency", "-f,--frequency");
  p.add_option<std::size_t>("loop",      "-l,--loop");
  p.add_option<double>("during" , "-d,--during" );
  p.add_option<double>("really-during", "--really-during");
  p.add_option<bool>("quiet", "-q,--quiet");
  p.add_option<bool>("time-s",  "--time-s");
  p.add_option<bool>("time-ms", "--time-ms");
  p.add_option<bool>("time-ns", "--time-ns");
  p.add_option<bool>("time-us", "--time-us");
  p.add_option<bool>("op-s",    "--op-s");
  p.add_option<bool>("op-ms",   "--op-ms");
  p.add_option<bool>("op-ns",   "--op-ns");
  p.add_option<bool>("op-us",   "--op-us");
  p.add_option<bool>("cpe-s",   "--cpe");
  p.add_option<bool>("cpe-s",   "--cpe-s");
  p.add_option<bool>("cpe-ms",  "--cpe-ms");
  p.add_option<bool>("cpe-ns",  "--cpe-ns");
  p.add_option<bool>("cpe-us",  "--cpe-us");
  p.add_option<bool>("stddev",   "--stddev");
  p.add_option<bool>("median",   "--median");
  p.add_option<bool>("mean",     "--mean");
  p.add_option<bool>("min",      "--min");
  p.add_option<bool>("max",      "--max");
  p.add_option<bool>("json",     "--json");
  p.parse(args_map(), argc, argv, std::nothrow);
}
} }
#include <chrono>
namespace ns { namespace bench {
using time_clock = std::chrono::high_resolution_clock;
template <typename Duration>
double to_seconds(Duration const& d) {
  return std::chrono::duration_cast<std::chrono::duration<double>>(d).count();
}
} }
#include <boost/config.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/predef/architecture.h>
#include <boost/predef/compiler.h>
#include <ctime>
#include <unistd.h>
#include <ratio>
#include <chrono>
#include <iostream>
#include <cstdint>
#if BOOST_COMP_MSVC
  #include <intrin.h>
#endif
namespace ns { namespace bench {
using cycle_t = std::uint64_t;
BOOST_FORCEINLINE cycle_t read_cycles();
template <std::size_t Freq>
struct basic_cycle_clock {
  using rep = cycle_t;
  using period = std::ratio<1, Freq>;
  using duration = std::chrono::duration<rep, period>;
  using time_point = std::chrono::time_point<basic_cycle_clock>;
  const bool is_steady = false;
  static time_point now() {
    return time_point(duration(read_cycles()));
  }
};
#ifndef NS_BENCH_FREQUENCY
  #define NS_BENCH_FREQUENCY 1
#endif
using cycle_clock = basic_cycle_clock<NS_BENCH_FREQUENCY>;
template <typename CycleDuration>
double to_cycles(CycleDuration const& c)
{
  return static_cast<double>(c.count());
}
BOOST_FORCEINLINE cycle_t read_cycles() {
  cycle_t c = 0;
#if (BOOST_COMP_GNUC || BOOST_COMP_CLANG || BOOST_COMP_INTEL) && BOOST_ARCH_X86
  std::uint32_t hi = 0, lo = 0;
  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi) : : "memory" );
  c = static_cast<cycle_t>(lo) | (static_cast<cycle_t>(hi) << 32);
#elif BOOST_COMP_MSVC
  #if defined(_M_AMD64)
      __faststorefence();
  #elif defined(_M_IX86)
      long cpu_barrier; __asm xchg cpu_barrier, eax;
  #endif
  ::_ReadWriteBarrier();
  c = ( ::__rdtsc() );
  ::_ReadWriteBarrier();
#elif  (BOOST_COMP_GNUC        && BOOST_ARCH_PPC) \
  || (BOOST_COMP_MWERKS      && BOOST_OS_MACOS) \
  || (defined(__IBM_GCC_ASM) && BOOST_ARCH_PPC)
  std::uint32_t tbl, tbu0, tbu1;
  do
  {
    __asm__ __volatile__ ("mftbu %0" : "=r"(tbu0));
    __asm__ __volatile__ ("mftb %0"  : "=r"(tbl));
    __asm__ __volatile__ ("mftbu %0" : "=r"(tbu1));
  } while (tbu0 != tbu1);
  c = (cycle_t)((((std::uint64_t)tbu0) << 32) | tbl);
#elif BOOST_OS_LINUX && !defined(BOOST_OS_ANDROID_AVAILABLE)
#else
  static_assert(false, "read_cycles not available");
#endif
  return c;
}
} }
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/max.hpp>
#include <boost/accumulators/statistics/min.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/median.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <boost/accumulators/statistics/variance.hpp>
#include <chrono>
namespace ns { namespace bench {
  using accumulators = boost::accumulators::stats< boost::accumulators::tag::mean
                                                 , boost::accumulators::tag::median
                                                 , boost::accumulators::tag::min
                                                 , boost::accumulators::tag::max
                                                 , boost::accumulators::tag::count
                                                 , boost::accumulators::tag::variance
                                                 >;
  using stats_set  = boost::accumulators::accumulator_set<double, accumulators>;
  thread_local stats_set times_set, cycles_set;
} }
namespace ns { namespace bench { namespace stats {
struct basic_stat {
  virtual double eval(stats_set const&) const = 0;
  virtual std::string name() const = 0;
};
} } }
namespace ns { namespace bench {
struct basic_experiment {
  virtual std::size_t size() const {
    return 1u;
  }
  virtual std::size_t element_size() const {
    return 1u;
  }
  virtual std::size_t flops() const {
    return 1u;
  }
  virtual std::size_t frame_count() const {
    return 1u;
  }
  virtual std::size_t transfer() const {
    return 1u;
  }
  virtual std::string description() const {
    return "no description given";
  }
};
template <bool IsMutable>
struct basic_mutable_experiment : basic_experiment {
  enum { is_mutable = IsMutable };
};
using experiment           = basic_mutable_experiment<true>;
using mutable_experiment   = experiment;
using immutable_experiment = basic_mutable_experiment<false>;
} }
#include <string>
namespace ns { namespace bench { namespace units {
struct basic_unit {
  virtual double eval( basic_experiment const& e
                     , stats::basic_stat const& s
                     ) const = 0;
  virtual std::string name() const = 0;
};
} } }
#include <set>
namespace ns { namespace bench {
struct metric {
  metric(stats::basic_stat const& s, units::basic_unit const& u)
    : stat_(&s), unit_(&u) {
  }
  metric(metric&&) = default;
  metric(metric const&) = default;
  double eval(basic_experiment const& e) const {
    return unit_->eval(e, *stat_);
  }
  double result(basic_experiment const& e) const {
    return eval(e) / e.element_size();
  }
  stats::basic_stat const& stat() const {
    return *stat_;
  }
  units::basic_unit const& unit() const {
    return *unit_;
  }
  private:
  friend std::less<metric>;
  bool operator<(metric const& other) const {
    return (stat().name() + unit().name()) < (other.stat().name() + other.unit().name());
  }
  private:
    stats::basic_stat const* stat_;
    units::basic_unit const* unit_;
};
} }
#include <boost/accumulators/accumulators.hpp>
#include <string>
namespace ns { namespace bench { namespace stats {
namespace detail {
  struct min : basic_stat {
    virtual double eval(stats_set const& s) const {
      return boost::accumulators::min(s);
    }
    virtual std::string name() const { return "(min)"; }
  };
}
const detail::min min_{};
metric min(units::basic_unit const& u) {
  return metric(min_, u);
}
} } }
#include <boost/accumulators/accumulators.hpp>
#include <string>
namespace ns { namespace bench { namespace stats {
namespace detail {
  struct max : basic_stat {
    virtual double eval(stats_set const& s) const {
      return boost::accumulators::max(s);
    }
    virtual std::string name() const { return "(max)"; }
  };
}
const detail::max max_{};
metric max(units::basic_unit const& u) {
  return metric(max_, u);
}
} } }
#include <boost/accumulators/accumulators.hpp>
#include <string>
namespace ns { namespace bench { namespace stats {
namespace detail {
  struct mean : basic_stat {
    virtual double eval(stats_set const& s) const {
      return boost::accumulators::mean(s);
    }
    virtual std::string name() const { return "(mean)"; }
  };
}
const detail::mean mean_{};
metric mean(units::basic_unit const& u) {
  return metric(mean_, u);
}
} } }
#include <boost/accumulators/accumulators.hpp>
#include <string>
namespace ns { namespace bench { namespace stats {
namespace detail {
  struct median : basic_stat {
    virtual double eval(stats_set const& s) const {
      if (boost::accumulators::count(times_set) < 3) {
        return boost::accumulators::mean(s);
      } else {
        return boost::accumulators::median(s);
      }
    }
    virtual std::string name() const { return "(median)"; }
  };
}
const detail::median median_{};
metric median(units::basic_unit const& u) {
  return metric(median_, u);
}
} } }
#include <boost/accumulators/accumulators.hpp>
#include <string>
#include <cmath>
namespace ns { namespace bench { namespace stats {
namespace detail {
  struct stddev : basic_stat {
    virtual double eval(stats_set const& s) const {
      return std::sqrt(boost::accumulators::variance(s));
    }
    virtual std::string name() const { return "(stddev)"; }
  };
}
const detail::stddev stddev_{};
metric stddev(units::basic_unit const& u) {
  return metric(stddev_, u);
}
} } }
namespace ns { namespace bench { namespace stats {
} } }
#include <string>
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct seconds {
    static double value() { return 1.; }
    static std::string name() { return "s"; }
  };
  struct milliseconds {
    static double value() { return 1e-3; }
    static std::string name() { return "ms"; }
  };
  struct microseconds {
    static double value() { return 1e-6; }
    static std::string name() { return "us"; }
  };
  struct nanoseconds {
    static double value() { return 1e-9; }
    static std::string name() { return "ns"; }
  };
}
const detail::seconds s_{};
const detail::milliseconds ms_{};
const detail::microseconds us_{};
const detail::nanoseconds ns_{};
} } }
namespace ns { namespace bench { namespace units {
namespace detail {
  template <typename Seconds>
  struct cpe : basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      double freq = ns::bench::args_map().get<double>("frequency", -1);
      return (freq == -1)
        ? (s.eval(cycles_set) / e.size() / Seconds::value())
        : (s.eval(times_set)  / e.size() * freq / Seconds::value());
    }
    virtual std::string name() const { return "(cpe)"; }
  };
}
template <typename Seconds>
const detail::cpe<Seconds> cpe_(Seconds) {
  return {};
}
const detail::cpe<decltype(s_)> cpe_s_ = {};
const detail::cpe<decltype(ms_)> cpe_ms_ = {};
const detail::cpe<decltype(us_)> cpe_us_ = {};
const detail::cpe<decltype(ns_)> cpe_ns_ = {};
} } }
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  template <typename Seconds>
  struct time : basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      return s.eval(times_set) / e.size() / Seconds::value();
    }
    virtual std::string name() const { return std::string(Seconds::name()) + "."; }
  };
}
template <typename Seconds>
const detail::time<Seconds> time_(Seconds) {
  return {};
}
const detail::time<decltype(s_)> time_s_ = {};
const detail::time<decltype(ms_)> time_ms_ = {};
const detail::time<decltype(us_)> time_us_ = {};
const detail::time<decltype(ns_)> time_ns_ = {};
} } }
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct fps : basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      return e.frame_count() / s.eval(times_set) * 1e-6;
    }
    virtual std::string name() const { return "fps"; }
  };
}
const detail::fps fps_{};
} } }
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct gflops : basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      double freq = args_map().get<double>("frequency");
      return e.flops() * freq / s.eval(cycles_set) * 1000000000.;
    }
    virtual std::string name() const { return "GFLOPS"; }
  };
}
const detail::gflops gflops_{};
} } }
#include <string>
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct bytes {
    static double value() { return 1.; }
    static std::string name() { return "b"; }
  };
  struct kilobytes {
    static double value() { return 1024. * bytes::value(); }
    static std::string name() { return "kb"; }
  };
  struct megabytes {
    static double value() { return 1024. * kilobytes::value(); }
    static std::string name() { return "mb"; }
  };
  struct gigabytes {
    static double value() { return 1024. * megabytes::value(); }
    static std::string name() { return "gb"; }
  };
}
const detail::bytes b_{};
const detail::kilobytes kb_{};
const detail::megabytes mb_{};
const detail::gigabytes gb_{};
} } }
namespace ns { namespace bench { namespace units {
namespace detail {
  template < typename Bytes
           , typename Seconds
           >
  struct transfer : units::basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      double res = 0.;
      if (dynamic_cast<stats::detail::min const*>(&s)) {
        res = stats::max_.eval(times_set);
      } else if (dynamic_cast<stats::detail::max const*>(&s)) {
        res = stats::min_.eval(times_set);
      } else {
        res = s.eval(times_set);
      }
      return (e.size() * e.transfer() / Bytes::value()) / (res / Seconds::value());
    }
    virtual std::string name() const { return Bytes::name() + "/" + Seconds::name(); }
  };
}
template <typename Bytes, typename Seconds>
const detail::transfer<Bytes, Seconds> transfer_(Bytes, Seconds) {
  return {};
}
const detail::transfer<decltype(gb_), decltype(s_)> gb_s_ = {};
const detail::transfer<decltype(gb_), decltype(ms_)> gb_ms_ = {};
const detail::transfer<decltype(gb_), decltype(ns_)> gb_ns_ = {};
const detail::transfer<decltype(mb_), decltype(s_)> mb_s_ = {};
const detail::transfer<decltype(mb_), decltype(ms_)> mb_ms_ = {};
const detail::transfer<decltype(mb_), decltype(ns_)> mb_ns_ = {};
const detail::transfer<decltype(kb_), decltype(s_)> kb_s_ = {};
const detail::transfer<decltype(kb_), decltype(ms_)> kb_ms_ = {};
const detail::transfer<decltype(kb_), decltype(ns_)> kb_ns_ = {};
const detail::transfer<decltype(b_), decltype(s_)> b_s_ = {};
const detail::transfer<decltype(b_), decltype(ms_)> b_ms_ = {};
const detail::transfer<decltype(b_), decltype(ns_)> b_ns_ = {};
} } }
namespace ns { namespace bench { namespace units {
} } }
namespace ns { namespace bench { namespace detail {
template <std::size_t... N> struct range {};
template <std::size_t N>    struct make_range {};
template <> struct make_range<0> { using type = range<>; };
template <> struct make_range<1> { using type = range<0>; };
template <> struct make_range<2> { using type = range<0, 1>; };
template <> struct make_range<3> { using type = range<0, 1, 2>; };
template <> struct make_range<4> { using type = range<0, 1, 2, 3>; };
template <> struct make_range<5> { using type = range<0, 1, 2, 3, 4>; };
template <> struct make_range<6> { using type = range<0, 1, 2, 3, 4, 5>; };
template <> struct make_range<7> { using type = range<0, 1, 2, 3, 4, 5, 6>; };
template <> struct make_range<8> { using type = range<0, 1, 2, 3, 4, 5, 6, 7>; };
template <> struct make_range<9> { using type = range<0, 1, 2, 3, 4, 5, 6, 7, 8>; };
template <std::size_t N>
using make_range_t = typename make_range<N>::type;
#define NS_BENCH_STATIC_UNROLL(f, ...)                                                             \
  (void)std::initializer_list<int>{((void)f(__VA_ARGS__), 0)...}                                   \

} } }
#include <boost/predef/architecture.h>
#include <iostream>
#include <iomanip>
#include <unordered_map>
namespace ns { namespace bench {
static const std::size_t unit_maxw = 10;
static const std::size_t stat_maxw = 10;
static const std::size_t size_maxw = 10;
static const std::size_t result_maxw = 15;
static const std::size_t samples_maxw = 15;
static const std::size_t description_maxw = 80;
struct result_info {
  double result;
  std::string unit;
  std::string stat;
  std::string desc;
  std::size_t size;
  std::size_t samples;
};
struct results {
  using container_type = std::vector<std::pair<std::string, std::vector<result_info>>>;
  using contained_type = typename container_type::value_type;
  results() {
    comp_ = BOOST_COMPILER;
    plat_ = BOOST_PLATFORM;
    std::string arch = "(unknown)";
    #if BOOST_ARCH_X86_64
      arch = "x86_64";
    #endif
    #if BOOST_ARCH_X86_32
      arch = "x86";
    #endif
    #if BOOST_ARCH_PPC
      arch = "ppc";
      if (sizeof(void*) == 8) {
        arch += "64";
      }
      #if BOOST_ENDIAN_BIG_BYTE
        arch += "be";
      #else
        arch += "le";
      #endif
    #endif
    #if BOOST_ARCH_ARM
      arch = "arm";
    #endif
    #if defined(__aarch64__)
      arch = "aarch64";
    #endif
    arch_ = arch;
  }
  void update(std::string const& name, result_info const& r) {
    auto found =
      std::find_if(results_.begin(), results_.end(), [&](contained_type const& v) {
        return v.first == name;
      });
    if (found == results_.end()) {
      results_.emplace_back(std::make_pair(name, typename contained_type::second_type()));
      results_.back().second.push_back(r);
    } else {
      found->second.push_back(r);
    }
  }
  container_type::const_iterator begin() const  { return results_.begin(); }
  container_type::const_iterator cbegin() const { return results_.cbegin(); }
  container_type::const_iterator end() const    { return results_.end(); }
  container_type::const_iterator cend() const   { return results_.cend(); }
  std::string const& compiler() const { return comp_; }
  std::string const& platform() const { return plat_; }
  std::string const& architecture() const { return arch_; }
  private:
  std::string comp_;
  std::string plat_;
  std::string arch_;
  container_type results_;
};
template <std::size_t... N, typename... Gs>
std::string make_generators_desc(detail::range<N...> const&, std::tuple<Gs...> const& gs) {
  bool first = true;
  std::string desc;
  auto append = [&](std::string const& d) {
    if (!first) desc += ", ";
    desc += d;
    first = false;
  };
  NS_BENCH_STATIC_UNROLL(append, std::get<N>(gs).description());
  return desc;
}
template <typename Experiment, typename Metric, typename... Gs>
result_info make_result_info(Experiment const& e, Metric const& m, std::tuple<Gs...> const& gs) {
  result_info r;
  r.size    = e.size();
  r.unit    = m.unit().name();
  r.stat    = m.stat().name();
  r.desc    = make_generators_desc(detail::make_range_t<sizeof...(Gs)>(), gs);
  r.result  = m.result(e);
  r.samples = boost::accumulators::count(times_set);
  return r;
}
std::ostream& operator<<(std::ostream& os, result_info const& r);
std::ostream& operator<<(std::ostream& os, results const& r);
std::string as_str(std::string const& what)
{
  return "\"" + what + "\"";
}
std::string as_json(result_info const& r)
{
  std::stringstream ss;
  ss << "{";
  ss << " " << as_str("size") << ": " << r.size << ",";
  ss << " " << as_str("stat") << ": " << as_str(r.stat) << ",";
  ss << " " << as_str("unit") << ": " << as_str(r.unit) << ",";
  ss << " " << as_str("result") << ": " << r.result << ",";
  ss << " " << as_str("samples") << ": " << r.samples << ",";
  ss << " " << as_str("description") << ": " << as_str(r.desc);
  ss << "}";
  return ss.str();
}
std::string as_json(results const& r)
{
  std::stringstream ss;
  ss << "{";
  ss << " " << as_str("compiler") << ": " << as_str(r.compiler()) << ",";
  ss << " " << as_str("platform") << ": " << as_str(r.platform()) << ",";
  ss << " " << as_str("architecture") << ": " << as_str(r.architecture()) << ",";
  ss << " " << as_str("benchmarks") << ": {";
  for (auto const& b : r) {
    auto const& name  = b.first;
    ss << as_str(name) << ": [";
    bool first = true;
    for (auto const& info : b.second) {
      if (!first) ss << ", ";
      ss << as_json(info);
      first = false;
    }
    ss << "]";
  }
  ss << "}";
  ss << "}";
  return ss.str();
}
std::string as_table(result_info const& r)
{
  std::stringstream ss;
  ss
    << std::setw(size_maxw)
    << r.size << ' '
    << std::setw(result_maxw)
    << r.result << ' '
    << std::setw(unit_maxw)
    << r.unit << ' '
    << std::setw(stat_maxw)
    << r.stat << ' '
    << std::setw(samples_maxw)
    << r.samples << ' '
    << std::setw(description_maxw)
    << r.desc
    ;
  return ss.str();
}
std::string as_table(results const& r)
{
  std::stringstream ss;
  std::size_t bar_size = 0;
  bar_size += unit_maxw + 1;
  bar_size += stat_maxw + 1;
  bar_size += size_maxw + 1;
  bar_size += result_maxw + 1;
  bar_size += samples_maxw + 1;
  bar_size += description_maxw + 1;
  auto print_bar = [&](std::size_t size, char what) {
    ss << ":: ";
    for (std::size_t i = 0; i < size; ++i) ss << what;
    ss << std::endl;
  };
  for (auto const& b : r) {
    auto const& name  = b.first;
    auto const& infos = b.second;
    ss << ":: Benchmarking results for: \"" << name  << "\"" << std::endl;
    ss
      << std::setw(size_maxw)
      << "Size" << ' '
      << std::setw(result_maxw)
      << "Result" << ' '
      << std::setw(unit_maxw)
      << "Unit" << ' '
      << std::setw(stat_maxw)
      << "Stat" << ' '
      << std::setw(samples_maxw)
      << "Samples" << ' '
      << std::setw(description_maxw)
      << "Generators" << ' '
      << std::endl
      ;
    for (auto const& info : infos) {
      ss << info << std::endl;
    }
    print_bar(bar_size, '-');
  }
  return ss.str();
}
std::ostream& operator<<(std::ostream& os, result_info const& r)
{
  if (args_map().get<bool>("json", false)) {
    os << as_json(r);
  } else {
    os << as_table(r);
  }
  return os;
}
std::ostream& operator<<(std::ostream& os, results const& r)
{
  if (args_map().get<bool>("json", false)) {
    os << as_json(r);
  } else {
    os << as_table(r);
  }
  return os;
}
} }
#include <iostream>
#include <iomanip>
#include <sstream>
namespace ns { namespace bench {
template <typename T>
T sanitize(T const& v)              { return v; }
inline int sanitize(char v)         { return v; }
inline int sanitize(std::int8_t v)  { return v; }
inline int sanitize(std::uint8_t v) { return v; }
template <typename T>
inline std::string format(T const& v)
{
  std::stringstream ss;
  ss << sanitize(v);
  return ss.str();
}
template <typename T>
struct format_type {
  static std::string to_string() {
    return type_id<T>();
  }
};
} }
#include <boost/optional.hpp>
#include <chrono>
#include <functional>
#include <iostream>
#include <iomanip>
namespace ns { namespace bench {
namespace chrono = std::chrono;
class setup {
  public:
  using duration_type = chrono::nanoseconds;
  public:
  setup() : during_(), iteration_() {
    if (args_map().has("duration")) {
      during(args_map().get<double>("duration"));
    }
    if (args_map().has("iteration")) {
      iteration(args_map().get<std::size_t>("iteration"));
    }
  }
  private:
  duration_type to_duration_type(double d) {
    return
      chrono::duration_cast<duration_type>(
          duration_type(static_cast<duration_type::rep>(d * duration_type::period::den)));
  }
  public:
  setup& during(double d) {
    during_ = to_duration_type(d);
    return *this;
  }
  template <typename Rep, typename Period>
  setup& during(chrono::duration<Rep, Period> const& d) {
    during_ = chrono::duration_cast<duration_type>(d);
    return *this;
  }
  setup& really_during(double d) {
    really_during_ = to_duration_type(d);
    return *this;
  }
  template <typename Rep, typename Period>
  setup& really_during(chrono::duration<Rep, Period> const& d) {
    really_during_ = chrono::duration_cast<duration_type>(d);
    return *this;
  }
  setup& iteration(std::size_t n) {
    iteration_ = n;
    return *this;
  }
  public:
  setup& metric(stats::basic_stat const& s, units::basic_unit const& u) {
    metrics_.emplace(s, u);
    return *this;
  }
  setup& metric(::ns::bench::metric const& m) {
    metrics_.emplace(m);
    return *this;
  }
  setup& metric(::ns::bench::metric&& m) {
    metrics_.emplace(std::move(m));
    return *this;
  }
  setup& min(units::basic_unit const& u) {
    return metric(stats::min_, u);
  }
  setup& max(units::basic_unit const& u) {
    return metric(stats::max_, u);
  }
  setup& mean(units::basic_unit const& u) {
    return metric(stats::mean_, u);
  }
  setup& median(units::basic_unit const& u) {
    return metric(stats::median_, u);
  }
  setup& stddev(units::basic_unit const& u) {
    return metric(stats::stddev_, u);
  }
  std::set<::ns::bench::metric> const& metrics() const {
    return metrics_;
  }
  static std::size_t& internal_loop_size() {
    static std::size_t sz = 1024u;
    return sz;
  }
  bool has_during() const        { return static_cast<bool>(during_); }
  bool has_iteration() const     { return static_cast<bool>(iteration_); }
  bool has_really_during() const { return static_cast<bool>(really_during_); }
  double during() const          { return to_seconds(*during_); }
  std::size_t iteration() const  { return *iteration_; }
  double really_during() const   { return to_seconds(*really_during_); }
  private:
  boost::optional<duration_type> during_;
  boost::optional<duration_type> really_during_;
  boost::optional<std::size_t> iteration_;
  std::set<::ns::bench::metric> metrics_;
};
setup default_setup()
{
  setup s;
  typedef setup& (ns::bench::setup::*met_t)(ns::bench::units::basic_unit const&);
  auto update = [](ns::bench::setup& ss, met_t f) {
    if (args_map().get<bool>("cpe",     false)) ss = (ss.*f)(units::cpe_s_);
    if (args_map().get<bool>("cpe-s",   false)) ss = (ss.*f)(units::cpe_s_);
    if (args_map().get<bool>("cpe-ms",  false)) ss = (ss.*f)(units::cpe_ms_);
    if (args_map().get<bool>("cpe-ns",  false)) ss = (ss.*f)(units::cpe_ns_);
    if (args_map().get<bool>("cpe-us",  false)) ss = (ss.*f)(units::cpe_us_);
    if (args_map().get<bool>("time-ms", false)) ss = (ss.*f)(units::time_ms_);
    if (args_map().get<bool>("time-us", false)) ss = (ss.*f)(units::time_us_);
    if (args_map().get<bool>("time-ns", false)) ss = (ss.*f)(units::time_ns_);
    if (args_map().get<bool>("time-s",  false)) ss = (ss.*f)(units::time_s_);
  };
  if (args_map().get<bool>("stddev", false)) update(s, &ns::bench::setup::stddev);
  if (args_map().get<bool>("median", false)) update(s, &ns::bench::setup::median);
  if (args_map().get<bool>("mean",   false)) update(s, &ns::bench::setup::mean);
  if (args_map().get<bool>("min",    false)) update(s, &ns::bench::setup::min);
  if (args_map().get<bool>("max",    false)) update(s, &ns::bench::setup::max);
  s = s.really_during(args_map().get<double>("really-during", 1.0));
  if (s.metrics().empty()) {
    s = s.median(units::cpe_s_);
  }
  return s;
}
} }
#define NS_BENCH_AUTO_DECLTYPE(...)                                                                \
  -> decltype(__VA_ARGS__) { return (__VA_ARGS__); }                                               \

#define NS_BENCH_ASM_MARKER() __asm__ __volatile__ ("cpuid")
namespace ns { namespace bench {
#if defined(__GNUC__)
template <typename T>
BOOST_FORCEINLINE void dnopt(T const& v)
{
  asm volatile("" : "+m" (const_cast<T&>(v)));
}
#else
void dnopt_reinterpreted(char const volatile*)
{
}
template <typename T>
BOOST_FORCEINLINE void dnopt(T const& v) {
  dnopt_reinterpreted(&reinterpret_cast<char const volatile&>(v));
}
#endif
} }
#include <functional>
#include <limits>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <random>
namespace ns { namespace bench { namespace generators {
template <typename T>
struct fixed
{
  fixed(T const& val) : val_(val)
  {
  }
  inline T const& operator()() {
    return val_;
  }
  std::string description() const {
    return "";
  }
  private:
  T val_;
};
} } }
#include <boost/align/aligned_allocator.hpp>
#include <boost/optional.hpp>
#include <functional>
namespace ns { namespace bench {
namespace detail {
template <typename T, typename A, typename G>
void prepare_parameter(std::vector<T, A>& val, G& g, std::size_t sz)
{
  val.resize(sz);
  val.clear();
  for (std::size_t i = 0; i < sz; ++i) {
    val[i] = g();
  }
}
template <typename T>
void prepare_parameter(generators::fixed<T>*& val, generators::fixed<T>& g, std::size_t)
{
  val = &g;
}
template <std::size_t... N, typename... Ts, typename... Gs>
void prepare_parameters( range<N...> const&
                       , std::tuple<Ts...>& ps
                       , std::tuple<Gs...>& gs
                       , std::size_t sz
                       )
{
  NS_BENCH_STATIC_UNROLL(prepare_parameter, std::get<N>(ps), std::get<N>(gs), sz);
}
template <typename... Ts, typename... Gs>
void prepare_parameters( std::tuple<Ts...>& ps
                       , std::tuple<Gs...>& gs
                       , std::size_t sz
                       )
{
  prepare_parameters(make_range_t<sizeof...(Ts)>(), ps, gs, sz);
}
template <typename T, typename A>
T container_at(std::vector<T, A> const& v, std::size_t i)
{
  return v[i];
}
template <typename T>
T const& container_at(generators::fixed<T>* const& g, std::size_t)
{
  return (*g)();
}
template <typename F, std::size_t... N, typename... Args>
BOOST_FORCEINLINE auto call(range<N...> const&, F f, std::tuple<Args...> const& args, std::size_t i)
NS_BENCH_AUTO_DECLTYPE(f(container_at(std::get<N>(args), i)...))
template <typename F, typename... Args>
BOOST_FORCEINLINE auto call(F f, std::tuple<Args...> const& args, std::size_t i)
NS_BENCH_AUTO_DECLTYPE(call(make_range_t<sizeof...(Args)>(), f, args, i))
template <typename F>
BOOST_FORCEINLINE auto call(F f, std::tuple<> const&, std::size_t)
NS_BENCH_AUTO_DECLTYPE(f())
template <typename Experiment, typename Enable = void>
struct experiment_maybe_copy {
  using type = Experiment;
};
template <typename Experiment>
struct experiment_maybe_copy<Experiment, typename std::enable_if<!Experiment::is_mutable>::type> {
  using type = Experiment&;
};
template <typename Experiment>
using experiment_maybe_copy_t = typename experiment_maybe_copy<Experiment>::type;
template <typename T, typename Enable = void>
struct parameter_alignment
: boost::alignment::alignment_of<T>
{};
template <typename T>
struct parameter_alignment<T, typename std::enable_if<T::alignment == T::alignment>::type>
: std::integral_constant<std::size_t, T::alignment>
{};
template <typename G, typename T>
struct make_parameters_container {
  using type =
    std::vector<T, boost::alignment::aligned_allocator<T, parameter_alignment<T>::value>>;
};
template <typename T>
struct make_parameters_container<generators::fixed<T>, T const&> {
  using type = generators::fixed<T>*;
};
template <typename G, typename T>
using make_parameters_container_t =
  typename make_parameters_container<typename std::decay<G>::type, T>::type;
}
template <typename Experiment, typename... Gs>
void run(results& r, setup const& s, std::string const& name, Experiment&& e, Gs&&... g) {
  static_assert( std::is_base_of<basic_experiment, typename std::decay<Experiment>::type>::value
               , "Experiment must inherits from experiment base class!"
               );
  double time = 0.;
  double max_time = time;
  double max_real_time = time;
  std::size_t iter = 0;
  std::size_t max_iter = iter;
  auto real_starting_time = time_clock::now();
  auto dot_time           = time_clock::now();
  if (s.has_during())        max_time = s.during();
  if (s.has_iteration())     max_iter = s.iteration();
  if (s.has_really_during()) max_real_time = s.really_during();
  bool is_quiet = args_map().get<bool>("quiet", false);
  auto do_continue = [&]() {
    auto elapsed_real_time = to_seconds(time_clock::now() - real_starting_time);
    auto elapsed_dot_time  = to_seconds(time_clock::now() - dot_time);
    if (!is_quiet && elapsed_dot_time >= 1.) {
      dot_time = time_clock::now();
      std::cerr << ".";
    }
    if (s.has_really_during() && elapsed_real_time >= max_real_time) {
      return false;
    }
    if (s.has_iteration() && iter >= max_iter) {
      return false;
    }
    if (s.has_during() && time >= max_time) {
      return false;
    }
    if (!s.has_during() && !s.has_iteration() && !s.has_really_during()) {
      return false;
    }
    return true;
  };
  auto do_step = [&](double elapsed_time) {
    iter += 1;
    time += elapsed_time;
  };
  times_set  = stats_set();
  cycles_set = stats_set();
  auto ps = std::tuple<detail::make_parameters_container_t<decltype(g), decltype(g())>...>();
  auto gs = std::make_tuple(std::forward<Gs>(g)...);
  auto sz  = args_map().get<std::size_t>("loop", ::ns::bench::setup::internal_loop_size());
  if (!is_quiet) std::cerr << ":: Benchmarking: \"" << name << "\" ";
  while (do_continue()) {
    detail::experiment_maybe_copy_t<Experiment> local(e);
    detail::prepare_parameters(ps, gs, sz);
    auto t0 = time_clock::now();
    auto c0 = cycle_clock::now();
    for (std::size_t i = 0; i < sz; ++i) {
      dnopt(detail::call(local, ps, i));
    }
    auto c1 = cycle_clock::now();
    auto t1 = time_clock::now();
    auto elapsed_time   = to_seconds(t1 - t0) / sz;
    auto elapsed_cycles = to_cycles(c1 - c0)  / sz;
    times_set(elapsed_time);
    cycles_set(elapsed_cycles);
    do_step(elapsed_time);
  }
  if (!is_quiet) std::cerr << std::endl;
  for (auto const& m : s.metrics()) {
    r.update(name, make_result_info(e, m, gs));
  }
}
template <typename Experiment, typename... Gs>
results run(setup const& s, std::string const& name, Experiment&& e, Gs&&... g) {
  results r;
  run(r, s, name, std::forward<Experiment>(e), std::forward<Gs>(g)...);
  return r;
}
} }
namespace ns { namespace bench { namespace generators {
} } }
#include <functional>
#include <limits>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <random>
namespace ns { namespace bench { namespace generators {
template <typename U, typename IS = typename std::is_scalar<U>::type>
struct rand {};
template <typename T>
struct rand<T, std::true_type>
{
  template <typename U>
  rand( U pmin = static_cast<U>(std::numeric_limits<T>::min())
      , U pmax = static_cast<U>(std::numeric_limits<T>::max())
      )
  {
    if (std::is_unsigned<T>::value) {
      pmin = std::abs(pmin);
      pmax = std::abs(pmax);
    }
    if (pmin > pmax) std::swap(pmin, pmax);
    if (pmin == pmax) pmin = T(0);
    min_ = pmin;
    max_ = pmax;
  }
  T random() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dist(0.0, 1.0);
    double f = (max_ - min_);
    return min_ + f * dist(gen);
  }
  inline T operator()() {
    return random();
  }
  std::string description() const {
    std::stringstream ss;
    ss << "rand<" << format_type<T>::to_string() << ">[" << format(min()) << ", " << format(max()) << "]";
    return ss.str();
  }
  T const& min() const { return min_; }
  T const& max() const { return max_; }
  private:
  T min_, max_;
};
template <typename T>
struct rand<T, std::false_type>
{
  using value_type = typename T::value_type;
  template <typename U>
  rand( U min = static_cast<U>(std::numeric_limits<value_type>::min())
      , U max = static_cast<U>(std::numeric_limits<value_type>::max())
      ) : r(min, max)
  {
  }
  inline T operator()() {
    std::array<value_type, sizeof(T) / sizeof(value_type)> v;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
    return {v.begin(), v.end()};
  }
  std::string description() const {
    std::stringstream ss;
    ss << "rand<" << format_type<T>::to_string() << ">[" << format(r.min()) << ", " << format(r.max()) << "]";
    return ss.str();
  }
  private :
  rand<typename T::value_type> r;
};
} } }
#include <functional>
#include <cassert>
#include <sstream>
namespace ns { namespace bench { namespace generators {
template <typename T, template <class> class Comp = std::greater>
struct range {
  range( T from
       , T to
       , T step = 1
       ) : from_(from), to_(to), step_(step), counter_(from), comp_()
  {
    assert(from_ < to_ && "`from` must be lower than `to`!");
  }
  T operator()() {
    if (comp_(counter_, to_)) {
      counter_ = from_;
    }
    T current = counter_;
    counter_ += step_;
    return current;
  }
  std::string description() const {
    std::stringstream ss;
    ss << "value from [" << from_ << ", " << to_ << "] (step = " << step_ << ")";
    return ss.str();
  }
  private:
    T from_, to_, step_, counter_;
    Comp<T> comp_;
};
template <typename T>
using exrange = range<T, std::greater_equal>;
} } }
namespace ns { namespace bench {
} }
namespace ns { namespace bench {
template <typename F>
struct function_experiment : experiment {
  private:
  F f_;
  public:
  function_experiment(F f) : f_(f) {}
  template <typename... Args>
  auto operator()(Args&&... args) const
  NS_BENCH_AUTO_DECLTYPE(this->f_(std::forward<Args>(args)...))
};
template <typename F>
struct sized_function_experiment : function_experiment<F> {
  sized_function_experiment(std::size_t esz, F f) : function_experiment<F>(f), esz_(esz) {}
  virtual std::size_t element_size() const {
    return esz_;
  }
  private:
  std::size_t esz_;
};
template <typename F>
function_experiment<F> make_function(F f) {
  return function_experiment<F>(f);
}
template <typename F>
sized_function_experiment<F> make_sized_function(std::size_t esz, F f) {
  return sized_function_experiment<F>(esz, f);
}
} }
namespace ns { namespace bench {
namespace detail {
template <typename... Types> struct list {};
template <typename F, typename... Types, std::size_t... N, typename... Args>
void for_each(F f, range<N...> const&, std::tuple<Args...> const& args)
{
  f(std::get<N>(args)...);
}
}
template <template <class> class F, typename... Types, typename... Args>
void for_each(Args&&... args)
{
  auto targs = std::make_tuple(std::forward<Args>(args)...);
  NS_BENCH_STATIC_UNROLL(detail::for_each, F<Types>(), detail::make_range_t<sizeof...(Args)>(), targs);
}
} }
#define NS_BENCH_SIGNED_INTEGRAL_TYPES     std::int8_t, std::int16_t, std::int32_t, std::int64_t
#define NS_BENCH_UNSIGNED_INTEGRAL_TYPES   std::uint8_t, std::uint16_t, std::uint32_t, std::uint64_t
#define NS_BENCH_INTEGRAL_TYPES            NS_BENCH_SIGNED_INTEGRAL_TYPES, NS_BENCH_UNSIGNED_INTEGRAL_TYPES
#define NS_BENCH_IEEE_TYPES                float, double
#define NS_BENCH_SIGNED_NUMERIC_TYPES      NS_BENCH_SIGNED_INTEGRAL_TYPES, NS_BENCH_IEEE_TYPES
#define NS_BENCH_UNSIGNED_NUMERIC_TYPES    NS_BENCH_UNSIGNED_INTEGRAL_TYPES
#define NS_BENCH_NUMERIC_TYPES             NS_BENCH_UNSIGNED_NUMERIC_TYPES, NS_BENCH_SIGNED_NUMERIC_TYPES
#define NS_BENCH_TYPES_8                   std::int8_t, std::uint8_t
#define NS_BENCH_TYPES_16                  std::int16_t, std::uint16_t
#define NS_BENCH_TYPES_32                  std::int32_t, std::uint32_t, float
#define NS_BENCH_TYPES_64                  std::int64_t, std::uint64_t, double
#define NS_BENCH_ALL_TYPES                 bool, NS_BENCH_NUMERIC_TYPES
#endif
