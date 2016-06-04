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

namespace ns {
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
}
#include <boost/lexical_cast.hpp>
#include <list>
#include <unordered_map>
namespace ns { namespace args {
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
  T get_or(key_type const& opt_name, T const& fallback) const {
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
} }
#include <stdexcept>
namespace ns { namespace args {
struct parse_error : std::runtime_error {
  parse_error(std::string const& what)
    : std::runtime_error(what) {
  }
};
} }
#include <boost/tokenizer.hpp>
#include <string>
namespace ns { namespace args { namespace detail {
struct option {
  option(std::string name, std::string opts, bool required)
    : name_(name), opts_(opts), required_(required) {
  }
  virtual bool validate(options_map& m, std::string const& arg, std::string const& opt) const {
    if (arg.find(opt) == 0 && opt.length() == arg.length()) {
      m.add_option(name(), "");
      return true;
    }
    return false;
  }
  virtual bool need_value() const {
    return false;
  }
  bool parse(options_map& m, std::string arg) const {
    std::string opts(opts_);
    boost::char_separator<char> sep(",");
    for (auto opt : boost::tokenizer<decltype(sep)>(opts, sep)) {
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
  typed_option(std::string name, std::string opts, bool required)
    : option(name, opts, required) {
  }
  virtual bool validate(options_map& m, std::string const& arg, std::string const& opt) const {
    auto pos = arg.find(opt);
    if (pos == 0) {
      if (arg[opt.length()] == '=') {
        auto rhs = arg.substr(opt.length() + 1, arg.length() - opt.length() - 1);
        try {
          (void)boost::lexical_cast<T>(rhs);
        } catch (boost::bad_lexical_cast) {
          throw parse_error(opts() + " expects a valid value of type: " + ns::type_id<T>());
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
struct auto_option<T, typename std::enable_if<std::is_same<T, void>::value>::type> {
  using type = option;
};
} } }
#include <list>
#include <unordered_map>
#include <iostream>
namespace ns { namespace args {
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
} }
std::ostream& operator<<(std::ostream& os, ns::args::options_map const& m) {
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
std::ostream& operator<<(std::ostream& os, ns::args::parser const& p) {
  os << p.usage();
  os.flush();
  return os;
}
#include <cstdint>
#include <new>
namespace ns { namespace bench {
ns::args::options_map args_map;
inline void parse_args(int argc, char **argv) {
  ns::args::parser p(argv[0]);
  p.add_option<uint64_t>("frequency", "-f,--frequency");
  p.add_option<uint64_t>("duration" , "-d,--duration" );
  p.add_option<uint64_t>("iteration", "-i,--iteration");
  p.parse(args_map, argc, argv, std::nothrow);
}
} }
#include <boost/config.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/predef/architecture.h>
#include <boost/predef/compiler.h>
#include <cstdint>
#if BOOST_COMP_MSVC
  #include <intrin.h>
#endif
namespace ns { namespace bench {
  using cycle_t = std::uint64_t;
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
#include <cstdint>
#include <ctime>
#include <unistd.h>
#include <ratio>
#include <chrono>
#include <iostream>
namespace ns { namespace bench {
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
} }
#include <boost/accumulators/accumulators.hpp>
#include <boost/accumulators/statistics/stats.hpp>
#include <boost/accumulators/statistics/max.hpp>
#include <boost/accumulators/statistics/min.hpp>
#include <boost/accumulators/statistics/mean.hpp>
#include <boost/accumulators/statistics/median.hpp>
#include <boost/accumulators/statistics/count.hpp>
#include <chrono>
namespace ns { namespace bench {
  using accumulators = boost::accumulators::stats< boost::accumulators::tag::mean
                                                 , boost::accumulators::tag::median
                                                 , boost::accumulators::tag::min
                                                 , boost::accumulators::tag::max
                                                 , boost::accumulators::tag::count
                                                 >;
  using stats_set  = boost::accumulators::accumulator_set<double, accumulators>;
  thread_local stats_set times_set, cycles_set;
} }
namespace ns { namespace bench { namespace stats {
struct basic_stat {
  virtual double eval(stats_set const&) const = 0;
  virtual std::string unit() const = 0;
};
} } }
#include <iostream>
#include <iomanip>
namespace ns { namespace bench { namespace format {
static const int unit_maxw = 10;
static const int stat_maxw = 10;
static const int size_maxw = 10;
static const int result_maxw = 15;
static const int samples_maxw = 15;
static const int parameters_maxw = 80;
static std::reference_wrapper<std::ostream> global_ostream = std::ref(std::cout);
inline std::ostream& get_os() {
  return global_ostream.get();
}
inline void set_os(std::ostream& os) {
  global_ostream = std::ref(os);
}
inline std::string format_line(std::string const& what) {
  return what.empty() ? what : std::string(":: ") + what + "\n";
}
inline void print_line(std::string const& what) {
  get_os() << format_line(what);
}
inline std::size_t print_bar(std::size_t size, char what) {
  auto& os = get_os();
  for (std::size_t i = 0; i < size; ++i) {
    os << what;
  }
  os << std::endl;
  return size;
}
inline std::size_t print_header() {
  std::stringstream ss;
  ss
    << std::setw(format::size_maxw)
    << "Size"
    << ' '
    << std::setw(format::result_maxw)
    << "Result"
    << ' '
    << std::setw(format::unit_maxw)
    << "Unit"
    << ' '
    << std::setw(format::stat_maxw)
    << "Stat"
    << ' '
    << std::setw(format::samples_maxw)
    << "Samples"
    << ' '
    << std::setw(format::parameters_maxw)
    << "Parameters"
    << ' '
    << std::endl;
    ;
  get_os() << ss.str();
  return ss.str().size();
}
inline std::size_t print_experiment(std::string const& benchmark) {
  get_os() << format_line(std::string("Benchmarking: \"") + benchmark +"\"");
  return print_bar(print_header(), '-');
}
template <typename Experiment, typename Metric>
inline void print_results(Experiment const& e, Metric const& m, double res) {
  std::size_t number_of_samples = boost::accumulators::count(times_set);
  auto& os = get_os();
  std::ios::fmtflags saved_fmt(os.flags());
  os
    << std::setw(format::size_maxw)
    << e.size()
    << ' '
    << std::setw(format::result_maxw)
    << res
    << ' '
    << std::setw(format::unit_maxw)
    << m.unit().unit()
    << ' '
    << std::setw(format::stat_maxw)
    << m.stat().unit()
    << ' '
    << std::setw(format::samples_maxw)
    << number_of_samples
    << ' '
    << std::setw(format::parameters_maxw)
    << e.description()
    << std::endl
    ;
  os.flags(saved_fmt);
}
struct scoped_printer {
  scoped_printer(std::string const& name)
    : bar_size_(0)
  {
    bar_size_ = print_experiment(name);
  }
  ~scoped_printer()
  {
    print_bar(bar_size_, '=');
  }
  private:
  std::size_t bar_size_;
};
template <typename T>
T sanitize(T const& v)              { return v; }
inline int sanitize(char v)         { return v; }
inline int sanitize(std::int8_t v)  { return v; }
inline int sanitize(std::uint8_t v) { return v; }
} } }
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
namespace ns { namespace bench {
struct basic_experiment {
  virtual void before_run() {
  }
  virtual void after_run() {
  }
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
} }
#include <string>
namespace ns { namespace bench { namespace units {
struct basic_unit {
  virtual double eval( basic_experiment const& e
                     , stats::basic_stat const& s
                     ) const = 0;
  virtual std::string unit() const = 0;
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
  stats::basic_stat const& stat() const {
    return *stat_;
  }
  units::basic_unit const& unit() const {
    return *unit_;
  }
  private:
  friend std::less<metric>;
  bool operator<(metric const& other) const {
    return (stat().unit() + unit().unit()) < (other.stat().unit() + other.unit().unit());
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
    virtual std::string unit() const { return "(min)"; }
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
    virtual std::string unit() const { return "(max)"; }
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
    virtual std::string unit() const { return "(mean)"; }
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
    virtual std::string unit() const { return "(median)"; }
  };
}
const detail::median median_{};
metric median(units::basic_unit const& u) {
  return metric(median_, u);
}
} } }
namespace ns { namespace bench { namespace stats {
} } }
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct cpe : basic_unit {
    virtual double eval( basic_experiment const& e
                       , stats::basic_stat const& s
                       ) const
    {
      double freq = ns::bench::args_map.get_or<double>("frequency", -1);
      return (freq == -1)
        ? (s.eval(cycles_set) / e.size())
        : (s.eval(times_set) * freq) / (e.size() * 1e6);
    }
    virtual std::string unit() const { return "(cpe)"; }
  };
}
const detail::cpe cpe_{};
} } }
#include <string>
#include <string>
namespace ns { namespace bench { namespace units {
namespace detail {
  struct seconds {
    static double value() { return 1.; }
    static std::string unit() { return "s"; }
  };
  struct milliseconds {
    static double value() { return 1e-3; }
    static std::string unit() { return "ms"; }
  };
  struct nanoseconds {
    static double value() { return 1e-6; }
    static std::string unit() { return "ns"; }
  };
}
const detail::seconds s_{};
const detail::milliseconds ms_{};
const detail::nanoseconds ns_{};
} } }
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
    virtual std::string unit() const { return std::string(Seconds::unit()) + "."; }
  };
}
template <typename Seconds>
const detail::time<Seconds> time_(Seconds) {
  return {};
}
const detail::time<decltype(s_)> time_s_ = {};
const detail::time<decltype(ms_)> time_ms_ = {};
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
    virtual std::string unit() const { return "fps"; }
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
      double freq = args_map.get<double>("frequency");
      return e.flops() * freq / s.eval(cycles_set) * 1000000000.;
    }
    virtual std::string unit() const { return "GFLOPS"; }
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
    static std::string unit() { return "b"; }
  };
  struct kilobytes {
    static double value() { return 1024. * bytes::value(); }
    static std::string unit() { return "kb"; }
  };
  struct megabytes {
    static double value() { return 1024. * kilobytes::value(); }
    static std::string unit() { return "mb"; }
  };
  struct gigabytes {
    static double value() { return 1024. * megabytes::value(); }
    static std::string unit() { return "gb"; }
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
    virtual std::string unit() const { return Bytes::unit() + "/" + Seconds::unit(); }
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
const detail::transfer<decltype(mb_), decltype(s_)> mb_ms_ = {};
const detail::transfer<decltype(mb_), decltype(s_)> mb_ns_ = {};
const detail::transfer<decltype(kb_), decltype(s_)> kb_s_ = {};
const detail::transfer<decltype(kb_), decltype(s_)> kb_ms_ = {};
const detail::transfer<decltype(kb_), decltype(s_)> kb_ns_ = {};
const detail::transfer<decltype(b_), decltype(s_)> b_s_ = {};
const detail::transfer<decltype(b_), decltype(s_)> b_ms_ = {};
const detail::transfer<decltype(b_), decltype(s_)> b_ns_ = {};
} } }
namespace ns { namespace bench { namespace units {
} } }
#include <boost/optional.hpp>
#include <chrono>
#include <functional>
#include <iostream>
#include <iomanip>
namespace ns { namespace bench {
namespace detail {
  template <typename Experiment, typename Enable = void>
  struct experiment_copy {
    using type = Experiment;
  };
  template <typename Experiment>
  struct experiment_copy<Experiment, typename std::enable_if<!Experiment::is_mutable>::type> {
    using type = Experiment&;
  };
  template <typename Experiments>
  struct run_experiments {
    template <typename Benchmark, typename... Args>
    run_experiments(Benchmark&, Args&&...) {
    }
  };
  template <template <class...> class Seq, typename E0>
  struct run_experiments<Seq<E0>> {
    template <typename Benchmark, typename... Args>
    run_experiments(Benchmark& b, Args&&... args) {
      b.template run_experiment<E0>(std::forward<Args>(args)...);
    }
  };
  template <template <class...> class Seq, typename E0, typename E1>
  struct run_experiments<Seq<E0, E1>> {
    template <typename Benchmark, typename... Args>
    run_experiments(Benchmark& b, Args&&... args) {
      b.template run_experiment<E0>(std::forward<Args>(args)...);
      b.template run_experiment<E1>(std::forward<Args>(args)...);
    }
  };
  template <template <class...> class Seq, typename E0, typename E1, typename E2, typename... En>
  struct run_experiments<Seq<E0, E1, E2, En...>> {
    template <typename Benchmark, typename... Args>
    run_experiments(Benchmark& b, Args&&... args) {
      b.template run_experiment<E0>(std::forward<Args>(args)...);
      b.template run_experiment<E1>(std::forward<Args>(args)...);
      b.template run_experiment<E2>(std::forward<Args>(args)...);
      run_experiments<Seq<En...>>(b, std::forward<Args>(args)...);
    }
  };
  template <typename... L>
  struct meta_seq;
  template <typename L>
  struct make_meta_seq {
    using type = meta_seq<L>;
  };
  template <typename... L>
  struct make_meta_seq<meta_seq<L...>> {
    using type = meta_seq<L...>;
  };
  template <typename T>
  using make_meta_seq_t = typename make_meta_seq<T>::type;
}
namespace chrono = std::chrono;
using metrics_t = std::set<::ns::bench::metric>;
inline const char* no_description();
template <typename Experiments>
class benchmark {
  public:
  using duration_type = chrono::milliseconds;
  public:
  benchmark(std::string const& name = "") : name_(boost::none), during_(), iteration_() {
    if (name != no_description()) {
      name_ = name;
    }
    if (args_map.has("duration")) {
      during(args_map.get<double>("duration"));
    }
    if (args_map.has("iteration")) {
      iteration(args_map.get<std::size_t>("iteration"));
    }
  }
  benchmark& during(double d) {
    during_ =
      chrono::duration_cast<duration_type>(
          chrono::milliseconds(static_cast<chrono::milliseconds::rep>(d * 1000.))
          );
    return *this;
  }
  template <typename Rep, typename Period>
  benchmark& during(chrono::duration<Rep, Period> const& d) {
    during_ = chrono::duration_cast<duration_type>(d);
    return *this;
  }
  benchmark& really_during(double d) {
    really_during_ =
      chrono::duration_cast<duration_type>(
          chrono::milliseconds(static_cast<chrono::milliseconds::rep>(d * 1000.))
          );
    return *this;
  }
  template <typename Rep, typename Period>
  benchmark& really_during(chrono::duration<Rep, Period> const& d) {
    really_during_ = chrono::duration_cast<duration_type>(d);
    return *this;
  }
  benchmark& iteration(std::size_t n) {
    iteration_ = n;
    return *this;
  }
  private:
  template <typename Experiment, typename... Args>
  benchmark& run_experiment(Args&&... args) {
    using time_clock = chrono::high_resolution_clock;
    Experiment e(std::forward<Args>(args)...);
    double time = 0.;
    double max_time = time;
    double max_real_time = time;
    std::size_t iter = 0;
    std::size_t max_iter = iter;
    auto real_starting_time = time_clock::now();
    if (during_) {
      max_time = to_seconds(*during_);
    }
    if (really_during_) {
      max_real_time = to_seconds(*really_during_);
    }
    if (iteration_) {
      max_iter = *iteration_;
    }
    auto do_continue =
      [this, &iter, &max_iter, &time, &max_time, &real_starting_time, &max_real_time]()
      {
        auto elapsed_real_time = to_seconds(time_clock::now() - real_starting_time);
        if (this->really_during_ && elapsed_real_time >= max_real_time) {
          return false;
        }
        if (this->iteration_ && iter > max_iter) {
          return false;
        }
        if (this->during_ && time > max_time) {
          return false;
        }
        if (!this->during_ && !this->iteration_ && !this->really_during_) {
          return false;
        }
        return true;
      }
    ;
    auto do_step = [this, &iter, &time](double elapsed_time) {
      iter += 1;
      time += elapsed_time;
    };
    times_set = stats_set();
    cycles_set = stats_set();
    while (do_continue()) {
      typename detail::experiment_copy<Experiment>::type local(e);
      local.before_run();
      auto t0 = time_clock::now();
      auto c0 = cycle_clock::now();
      local.run();
      auto c1 = cycle_clock::now();
      auto t1 = time_clock::now();
      local.after_run();
      auto elapsed_time = to_seconds(t1 - t0);
      times_set(elapsed_time);
      cycles_set(static_cast<double>((c1 - c0).count()));
      do_step(elapsed_time);
    }
    for (auto m : metrics_) {
      format::print_results(e, m, m.eval(e) / static_cast<double>(e.element_size()));
    }
    return *this;
  }
  public:
  template <typename... Args>
  benchmark& run(Args&&... args) {
    using experiments = detail::make_meta_seq_t<Experiments>;
    if (name_) {
      format::scoped_printer _(*name_);
      detail::run_experiments<experiments>(*this, std::forward<Args>(args)...);
    } else {
      detail::run_experiments<experiments>(*this, std::forward<Args>(args)...);
    }
    return *this;
  }
  benchmark& metric(stats::basic_stat const& s, units::basic_unit const& u) {
    metrics_.emplace(s, u);
    return *this;
  }
  benchmark& metric(::ns::bench::metric const& m) {
    metrics_.emplace(m);
    return *this;
  }
  benchmark& metric(::ns::bench::metric&& m) {
    metrics_.emplace(std::move(m));
    return *this;
  }
  benchmark& min(units::basic_unit const& u) {
    return metric(stats::min_, u);
  }
  benchmark& max(units::basic_unit const& u) {
    return metric(stats::max_, u);
  }
  benchmark& mean(units::basic_unit const& u) {
    return metric(stats::mean_, u);
  }
  benchmark& median(units::basic_unit const& u) {
    return metric(stats::median_, u);
  }
  private:
  template <typename Duration>
  static double to_seconds(Duration const& d) {
    return chrono::duration_cast<chrono::duration<double>>(d).count();
  }
  template <typename> friend struct detail::run_experiments;
  private:
    boost::optional<std::string> name_;
    boost::optional<duration_type> during_;
    boost::optional<duration_type> really_during_;
    boost::optional<std::size_t> iteration_;
    metrics_t metrics_;
};
template <template <class> class Experiment, typename... Types>
benchmark<detail::meta_seq<Experiment<Types>...>> make_benchmark(std::string const& name = "") {
  return benchmark<detail::meta_seq<Experiment<Types>...>>(name);
}
template <typename... Experiments>
benchmark<detail::meta_seq<Experiments...>> make_benchmark(std::string const& name = "") {
  return benchmark<detail::meta_seq<Experiments...>>(name);
}
inline const char* no_description()
{
  return "";
}
} }
namespace ns { namespace bench {
} }
namespace ns { namespace bench {
namespace detail {
  template <bool IsMutable>
  struct basic_mutable_experiment : basic_experiment {
    enum {
      is_mutable = IsMutable
    };
  };
}
using experiment           = detail::basic_mutable_experiment<true>;
using mutable_experiment   = experiment;
using immutable_experiment = detail::basic_mutable_experiment<false>;
} }
#include <memory>
#include <chrono>
namespace ns { namespace bench {
namespace detail {
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_common_function_experiment : mutable_experiment {
    enum {
      result_array_size = 32,
      experiment_size = 1024
    };
    using return_t       = decltype(std::declval<F>()(std::declval<Args>()()...));
    using return_array_t = std::array<return_t, result_array_size>;
    static_assert( !std::is_same<void, return_t>::value
                 , "Functions passed to function_experiment must not return void"
                 );
    public:
    basic_common_function_experiment(F f,  Args&&... args)
      : f_(f), args_gen_(std::forward<Args>(args)...), results_(std::make_shared<return_array_t>()) {
    }
    virtual std::size_t size() const {
      return experiment_size;
    }
    virtual std::size_t element_size() const {
      return ExpSize;
    }
    protected:
    template <std::size_t N>
    std::string description_of() const {
      return std::get<N>(this->args_gen_).description();
    }
    public:
    F f_;
    std::tuple<decltype(std::declval<Args>()())...> args_;
    std::tuple<Args...> args_gen_;
    std::shared_ptr<return_array_t> results_;
  };
  template <std::size_t N, std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment;
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment<0, ExpSize, F, Args...>
    : basic_common_function_experiment<ExpSize, F, Args...>
  {
    using super = basic_common_function_experiment<ExpSize, F, Args...>;
    using super::super;
    virtual void before_run() {
    }
    void run() {
      for (std::size_t i = 0; i < super::experiment_size; ++i) {
        (*this->results_)[i % super::result_array_size] =
          this->f_();
      }
    }
    virtual std::string description() const {
      return "()";
    }
  };
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment<1, ExpSize, F, Args...>
    : basic_common_function_experiment<ExpSize, F, Args...>
  {
    using super = basic_common_function_experiment<ExpSize, F, Args...>;
    using super::super;
    virtual void before_run() {
      std::get<0>(this->args_) = std::get<0>(this->args_gen_)();
    }
    void run() {
      for (std::size_t i = 0; i < super::experiment_size; ++i) {
        (*this->results_)[i % super::result_array_size] =
          this->f_(std::get<0>(this->args_));
      }
    }
    virtual std::string description() const {
      return "(" + super::template description_of<0>() + ")";
    }
  };
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment<2, ExpSize, F, Args...>
    : basic_common_function_experiment<ExpSize, F, Args...>
  {
    using super = basic_common_function_experiment<ExpSize, F, Args...>;
    using super::super;
    virtual void before_run() {
      std::get<0>(this->args_) = std::get<0>(this->args_gen_)();
      std::get<1>(this->args_) = std::get<1>(this->args_gen_)();
    }
    void run() {
      for (std::size_t i = 0; i < super::experiment_size; ++i) {
        (*this->results_)[i % super::result_array_size] =
          this->f_( std::get<0>(this->args_)
                  , std::get<1>(this->args_)
                  );
      }
    }
    virtual std::string description() const {
      return
          "("  + super::template description_of<0>()
        + ", " + super::template description_of<1>()
        + ")"
        ;
    }
  };
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment<3, ExpSize, F, Args...>
    : basic_common_function_experiment<ExpSize, F, Args...>
  {
    using super = basic_common_function_experiment<ExpSize, F, Args...>;
    using super::super;
    virtual void before_run() {
      std::get<0>(this->args_) = std::get<0>(this->args_gen_)();
      std::get<1>(this->args_) = std::get<1>(this->args_gen_)();
      std::get<2>(this->args_) = std::get<2>(this->args_gen_)();
    }
    void run() {
      for (std::size_t i = 0; i < super::experiment_size; ++i) {
        (*this->results_)[i % super::result_array_size] =
          this->f_( std::get<0>(this->args_)
                  , std::get<1>(this->args_)
                  , std::get<2>(this->args_)
                  );
      }
    }
    virtual std::string description() const {
      return
          "("  + super::template description_of<0>()
        + ", " + super::template description_of<1>()
        + ", " + super::template description_of<2>()
        + ")"
        ;
    }
  };
  template <std::size_t ExpSize, typename F, typename... Args>
  struct basic_function_experiment<4, ExpSize, F, Args...>
    : basic_common_function_experiment<ExpSize, F, Args...>
  {
    using super = basic_common_function_experiment<ExpSize, F, Args...>;
    using super::super;
    virtual void before_run() {
      std::get<0>(this->args_) = std::get<0>(this->args_gen_)();
      std::get<1>(this->args_) = std::get<1>(this->args_gen_)();
      std::get<2>(this->args_) = std::get<2>(this->args_gen_)();
      std::get<3>(this->args_) = std::get<3>(this->args_gen_)();
    }
    void run() {
      for (std::size_t i = 0; i < super::experiment_size; ++i) {
        (*this->results_)[i % super::result_array_size] =
          this->f_( std::get<0>(this->args_)
                  , std::get<1>(this->args_)
                  , std::get<2>(this->args_)
                  , std::get<3>(this->args_)
                  );
      }
    }
    virtual std::string description() const {
      return
          "("  + super::template description_of<0>()
        + ", " + super::template description_of<1>()
        + ", " + super::template description_of<2>()
        + ", " + super::template description_of<3>()
        + ")"
        ;
    }
  };
  template <template <typename> class Functor, typename... Types>
  struct make_for_each;
  template <template <typename> class Functor>
  struct make_for_each<Functor> {
    template <typename ...Args>
    make_for_each(Args&&...)
    {
    }
  };
  template <template <typename> class Functor, typename Type, typename... Types>
  struct make_for_each<Functor, Type, Types...>  {
    template <typename ...Args>
    make_for_each(Args&&... args)
    {
      Functor<Type> f;
      f(std::forward<Args>(args)...);
      make_for_each<Functor, Types...>(std::forward<Args>(args)...);
    }
  };
}
template <std::size_t ExpSize, typename F, typename... Args>
struct function_experiment
  : detail::basic_function_experiment<sizeof...(Args), ExpSize, F, Args...>
{
  using super = detail::basic_function_experiment<sizeof...(Args), ExpSize, F, Args...>;
  using super::super;
};
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_sized(std::string const& name, metrics_t const& ms, F f, Args&&... args) {
  auto b = make_benchmark<function_experiment<ExpSize, F, Args...>>(name);
  b.really_during(std::chrono::seconds(5));
  for (metric const& m : ms) {
    b.metric(m);
  }
  b.run(f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment(std::string const& name, metrics_t const& ms, F f, Args&&... args) {
  make_function_experiment_sized<1>(name, ms, f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment(std::string const& name, F f, Args&&... args) {
  auto ms = metrics_t{
    stats::median(units::cpe_),
    stats::median(units::time_ns_)
  };
  make_function_experiment(name, ms, f, std::forward<Args>(args)...);
}
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_sized(std::string const& name, F f, Args&&... args) {
  auto ms = metrics_t{
    stats::median(units::cpe_),
    stats::median(units::time_ns_)
  };
  make_function_experiment_sized<ExpSize>(name, ms, f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment_cpe(std::string const& name, F f, Args&&... args) {
  auto ms = metrics_t{
    stats::median(units::cpe_),
  };
  make_function_experiment(name, ms, f, std::forward<Args>(args)...);
}
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_cpe_sized(std::string const& name, F f, Args&&... args) {
  auto ms = metrics_t{
    stats::median(units::cpe_),
  };
  make_function_experiment_sized<ExpSize>(name, ms, f, std::forward<Args>(args)...);
}
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_sized_(metrics_t const& ms, F f, Args&&... args) {
  make_function_experiment_sized(no_description(), ms, f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment_(metrics_t const& ms, F f, Args&&... args) {
  make_function_experiment(no_description(), ms, f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment_(F f, Args&&... args) {
  make_function_experiment(no_description(), f, std::forward<Args>(args)...);
}
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_sized_(F f, Args&&... args) {
  make_function_experiment_sized<ExpSize>(no_description(), f, std::forward<Args>(args)...);
}
template <typename F, typename... Args>
void make_function_experiment_cpe_(F f, Args&&... args) {
  make_function_experiment_cpe(no_description(), f, std::forward<Args>(args)...);
}
template <std::size_t ExpSize, typename F, typename... Args>
void make_function_experiment_cpe_sized_(F f, Args&&... args) {
  make_function_experiment_cpe_sized<ExpSize>(no_description(), f, std::forward<Args>(args)...);
}
template <template <typename> class Functor, typename... Types>
struct make_for_each {
  template <typename ...Args>
  make_for_each(Args&&... args)
  {
    std::string name = "";
    name = ns::type_id<Functor<void>>();
    name = name.substr(0, name.find('<'));
    do_(name, std::forward<Args>(args)...);
  }
  template <typename ...Args>
  make_for_each(std::string const& name, Args&&... args)
  {
    do_(name, std::forward<Args>(args)...);
  }
  template <typename ...Args>
  void do_(std::string const& name, Args&&... args)
  {
    format::scoped_printer _(name);
    detail::make_for_each<Functor, Types...>(std::forward<Args>(args)...);
  }
};
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
#include <ctime>

namespace ns { namespace bench { namespace generators {

template <typename U, typename IS = typename std::is_scalar<U>::type>
struct rand {};
template <typename T>
struct rand<T, std::true_type>
{
  template <typename U>
  rand( U min = std::numeric_limits<T>::min()
      , U max = std::numeric_limits<T>::max()
      )
  {
    if (std::is_unsigned<T>::value) {
      min = std::abs(min);
      max = std::abs(max);
    }
    if (min > max) std::swap(min, max);
    if (min == max) min = T(0);
    min_ = min;
    max_ = max;
    f = (max_ - min_);
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
    ss << ns::type_id<T>() << " [" << ns::bench::format::sanitize(min_) << ", " << ns::bench::format::sanitize(max_) << "]";
    return ss.str();
  }
  private:
  T min_, max_;
  double f;
};
template <typename T>
struct rand<T, std::false_type>
{
  using value_type = typename T::value_type;
  template <typename U>
  rand( U min = std::numeric_limits<value_type>::min()
      , U max = std::numeric_limits<value_type>::max()
      ) : r(min, max)
  {
  }
  inline T operator()() {
    std::array<value_type, sizeof(T) / sizeof(value_type)> v;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random(); });
    return {v.begin(), v.end()};
  }
  std::string description() const {
    return r.description();
  }
  private :
   rand<typename T::value_type> r;
};

template <typename T>
struct randlg
{
  using value_type = typename T::value_type;
  using under_t = typename value_type::value_type;
  randlg() : r(0.0, 1.0)
  {
  }
  inline T operator()() {
    std::array<value_type, sizeof(T) / sizeof(value_type)> v;
    std::transform(v.begin(), v.end(), v.begin(), [this](value_type const&) { return r.random() < 0.5; });
    return {v.begin(), v.end()};
  }
  std::string description() const {
    std::stringstream ss;
    ss << ns::type_id<T>();
    return ss.str();
  }
  private :
  rand<double> r;
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
