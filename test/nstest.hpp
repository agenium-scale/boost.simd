//==================================================================================================
/*!
  @file

  Main header for the unit test system

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_HPP_INCLUDED
#define NSTEST_UNIT_HPP_INCLUDED





#include <boost/algorithm/string/predicate.hpp>
#include <unordered_map>
#include <sstream>
#include <cstdlib>
#include <string>

namespace nstest
{
  namespace detail
  {
    struct args_map
    {
      args_map()
      {
                std::pair<std::string,std::string>
        envvars[] = { {"NSTEST_COLOR"   , "color"}
                    , {"NSTEST_COMPACT" , "compact"}
                    };

                for(auto const& id : envvars)
        {
          auto p = get_env(id.first);
          if(!p.empty()) data_[id.second] = p;
        }
      }

      void update(int argc, const char** argv) const
      {
        bool found = false;
        std::string id;

        for(int i=1;i<argc;++i)
        {
                    std::string cur{argv[i]};

          if(is_option(cur))
          {
            found = true;
            id    = std::string{cur.begin()+2,cur.end()};           }
          else
          {
                        if(found && !is_option(cur))
            {
              data_[id] = cur;
              found = false;
            }
          }
        }
      }

      template<typename R> R operator()(std::string const& id, R def = R{} ) const
      {
        auto opt = data_.find(id);
        if(opt != data_.cend())
        {
          std::istringstream s(opt->second);
          s >> def;
        }

        return def;
      }

      static bool is_option(std::string const& s)
      {
        return boost::starts_with(s, "--") && s != "--";
      }

            static std::string get_env(std::string const& name)
      {
  #if defined(BOOST_MSVC)
        char* buf = 0;
        std::size_t sz = 0;

        _dupenv_s(&buf, &sz, name.c_str());

        std::string that = buf ? buf : " ";
        free(buf);
  #else
        auto p = std::getenv(name.c_str());
        std::string that = p ? p : "";
  #endif

        return that;
      }

      private:
      mutable std::unordered_map<std::string,std::string> data_;
    };
  }

  const detail::args_map args;
}



#include <cstddef>
#include <type_traits>

namespace nstest { namespace detail
{
  template<typename T> struct is_container
  {
    template<typename U>
    static auto test( int ) -> decltype ( std::declval<U>().begin()
                                        , std::declval<U>().end()
                                        , std::declval<U>().size()
                                        , std::true_type()
                                        );

    template<typename>
    static auto test( ... ) -> std::false_type;

    typedef std::is_same<decltype(test<T>(0)),std::true_type> type;
  };

  template <typename T, typename R>
  using if_container = typename std::enable_if<is_container<T>::type::value,R>::type;


  template <typename T, typename R>
  using if_not_container = typename std::enable_if<!is_container<T>::type::value,R>::type;

#if defined(DOXYGEN_ONLY)

  template<typename C> inline std::size_t size(C const& v);

  template<typename C> inline auto begin(C const& v);

  template<typename C> inline auto end(C const& v);

#else

  template<typename C>
  inline detail::if_container<C,std::size_t> size(C const& c)   { return c.size(); }

  template<typename C>
  inline detail::if_not_container<C,std::size_t> size(C const&) { return 1ull; }

  template<typename C>
  inline detail::if_container<C,typename C::const_iterator> begin(C const& c) { return c.begin(); }

  template<typename C>
  inline detail::if_not_container<C,C const*> begin(C const& t) { return &t; }

  template<typename C>
  inline detail::if_container<C,typename C::const_iterator> end(C const& c) { return c.end(); }

  template<typename C>
  inline detail::if_not_container<C,C const*> end(C const& t) { return (&t)+1; }

#endif
} }


#include <cstddef>
#include <iostream>
#include <type_traits>

namespace nstest { namespace detail
{
  template<typename T> struct is_streamable
  {
    template<typename U>
    static auto test( int ) -> decltype ( std::cout << std::declval<U>()
                                        , std::true_type()
                                        );

    template<typename>
    static auto test( ... ) -> std::false_type;

    typedef std::is_same<decltype(test<T>(0)),std::true_type> type;
  };

  template <typename T, typename R>
  using if_streamable = typename std::enable_if<is_streamable<T>::type::value,R>::type;


  template <typename T, typename R>
  using if_not_streamable = typename std::enable_if<!is_streamable<T>::type::value,R>::type;
} }

#include <boost/core/demangle.hpp>
#include <sstream>
#include <cstddef>
#include <string>
#include <iomanip>

namespace nstest
{
  inline std::string to_string( std::nullptr_t )        { return "nullptr";             }
  inline std::string to_string( bool v )                { return v ? "true" : "false";  }
  inline std::string to_string( std::string const& v )  { return v;                     }
  inline std::string to_string( char const* v )         { return std::string(v);        }
  inline std::string to_string( char v )                { return std::string(1, v);     }

  template <typename T>
  inline detail::if_streamable<T,std::string> to_string( T const& value)
  {
    std::ostringstream os;
    os << std::setprecision(20) << value;
    return os.str();
  }

  template <typename T>
  inline detail::if_container<T,std::string> make_string( T const& value)
  {
    auto b = value.begin(), e = value.end();
    std::ostringstream os;

    os << "{ ";
    if(b!=e)      os << to_string(*b++);
    while(b != e) os << ", " << to_string(*b++);
    os << " }";

    return os.str();
  }

  template <typename T>
  inline detail::if_not_container<T,std::string> make_string( T const& value)
  {
    std::ostringstream os;

    os << "[ ";
    os << boost::core::demangle(typeid(T).name());
    os << " ] @" << (void*)(&value);

    return os.str();
  }

  template <typename T>
  inline detail::if_not_streamable<T,std::string> to_string( T const& value)
  {
    return make_string(value);
  }

  template<typename LHS, typename RHS>
  inline std::string split_line(LHS const&, RHS const&, std::string const& op)
  {
    auto lb = detail::is_container<LHS>::type::value;
    auto rb = detail::is_container<RHS>::type::value;

    return (lb?"\n":"") + op + (rb?"\n":"");
  }
}

#include <boost/predef.h>
#include <iostream>
#include <iomanip>

#if defined(BOOST_OS_WINDOWS_AVAILABLE) && !defined(BOOST_OS_CYGWIN_AVAILABLE)
#include <windows.h>
#define NSTEST_USE_CONSOLE_ATTRIBUTES
#endif

namespace nstest
{
    #if defined(NSTEST_USE_CONSOLE_ATTRIBUTES)
  enum Color { GRAY = 7, DARKGRAY = 8, GREEN = 10, RED = 12, YELLOW = 14, WHITE = 15, DEFAULT = 7 };
#else
  enum Color { GRAY = 37, DARKGRAY = 90, GREEN = 32, RED = 31, YELLOW = 33, WHITE = 97, DEFAULT = 39 };
#endif

  template<typename Color> struct colored_data
  {
    std::string data;
    Color       color;
  };

  template<int Code> struct color_markup
  {
    template<typename T> inline std::basic_ostream<T>& setup(std::basic_ostream<T>& os) const
    {
      if(&os == &std::cout && args("color",true))
      {
#if defined(NSTEST_USE_CONSOLE_ATTRIBUTES)
        auto h = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(h, Code);
#else
        os << "\033[" << Code << "m";
#endif
      }

      return os;
    }

    template<typename T> colored_data<color_markup<Code>> operator()(T const& t) const
    {
      return {to_string(t),*this};
    }
  };

  template<int Code> inline std::ostream& operator<<(std::ostream& os, const color_markup<Code>& cm)
  {
    return cm.setup(os);
  }

  const color_markup<Color::RED>       red_{};
  const color_markup<Color::GREEN>     green_{};
  const color_markup<Color::WHITE>     white_{};
  const color_markup<Color::GRAY>      gray_{};
  const color_markup<Color::YELLOW>    yellow_{};
  const color_markup<Color::DEFAULT>   default_{};
  const color_markup<Color::DARKGRAY>  darkgray_{};

  template<typename C>
  inline std::ostream& operator<<(std::ostream& os, const colored_data<C>& cd)
  {
    os << cd.color << cd.data << default_;
    return os;
  }
}

#include <iostream>
#include <cstddef>
#include <string>

namespace nstest
{
  namespace unit
  {
    struct env
    {
      public:

      env(int argc, const char** argv, std::ostream& s = std::cout)
        : test_count{0}, success_count{0}, invalid_count{0}, os(s)
      {
        args.update(argc,argv);
      }

            void compact(bool m) { compact_mode = m; }

            bool is_compact() const { return compact_mode; }

            void as_success() { test_count++; success_count++; }

      void as_invalid() { test_count++; invalid_count++; }

            void as_failure() { test_count++; }

            bool passed() const { return tests() != successes(); }

            std::ptrdiff_t tests() const { return test_count; }

            std::ptrdiff_t successes() const { return success_count; }

            std::ptrdiff_t invalids() const { return invalid_count; }

            std::ptrdiff_t failures() const { return tests() - successes() - invalids(); }

            std::ostream& stream() const { return os; }

            std::ostream& pass()    const { return os << green_("[PASS]") << " - "; }

            std::ostream& fail()    const { return os << red_("[FAIL]") << " - "; }

            std::ostream& invalid() const
      {
        if(compact_mode)
          return os << yellow_("I");
        else
          return os << yellow_("[IVLD]") << " - ";
      }

            env(env const&)             = delete;
      env& operator=(env const&)  = delete;

      private:
      std::ptrdiff_t  test_count;
      std::ptrdiff_t  success_count;
      std::ptrdiff_t  invalid_count;
      bool            compact_mode;
      std::ostream&   os;
    };
  }
  inline bool report(unit::env const& e, std::ptrdiff_t fails, std::ptrdiff_t invalids)
  {
    auto test_txt = e.tests()     > 1 ? "tests"     : "test";
    auto pass_txt = e.successes() > 1 ? "successes" : "success";
    auto fail_txt = e.failures()  > 1 ? "failures"  : "failure";
    auto inv_txt  = e.invalids()  > 1 ? "invalids"  : "invalid";

    e.stream()  << default_ << std::string(80,'-') << "\n"
      << white_("Results: ")
      << white_(e.tests())  << " "    << white_(test_txt) << " - "
      << white_(e.successes()) << " " << green_(pass_txt) << " - "
      << white_(e.failures()) << "/"  << fails     << " " << red_(fail_txt) << " - "
      << white_(e.invalids()) << "/"  << invalids  << " " << yellow_(inv_txt)
      << std::endl;

    if(!fails && !invalids)
      return e.passed();
    else
      return e.failures() != fails || e.invalids() != invalids;
  }

  template<typename Test>
  inline void scenario_header( unit::env& env, Test const& t)
  {
    if(!env.is_compact())
    {
      auto hbar = std::string(80,'-');
      env.stream()  << hbar << std::endl
                    << "Scenario: " << ::nstest::white_(t.name) << std::endl
                    << hbar << std::endl;
    }
    else
    {
      env.stream()  << "Scenario: " << ::nstest::white_(t.name) << " : ";
    }
  }

  inline void process_invalid( unit::env& env, std::ptrdiff_t count)
  {
    if(count == env.tests())
    {
      env.as_invalid();
      if(!env.is_compact())
        env.invalid() << ::nstest::white_("Empty test case") << std::endl;
      else
        env.stream() << ::nstest::yellow_("!");
    }
  }
}



#define NSTEST_STRING__(...) #__VA_ARGS__
#define NSTEST_STRING_(text) NSTEST_STRING__ text

#define NSTEST_STRING(...) NSTEST_STRING_((__VA_ARGS__))


#define NSTEST_UNIQUE3( ID, LINE )  ID ## LINE
#define NSTEST_UNIQUE2( ID, LINE )  NSTEST_UNIQUE3( ID, LINE )

#if defined(DOXYGEN_ONLY)
#define NSTEST_UNIQUE( Identifier )

#define NTEST_FUNCTION

#define NTEST_REGISTRATION
#else

#define NSTEST_UNIQUE( Identifier ) NSTEST_UNIQUE2( Identifier, __LINE__ )
#define NTEST_FUNCTION      NSTEST_UNIQUE(nstest_function)
#define NTEST_REGISTRATION  NSTEST_UNIQUE(nstest_registration)

#endif



#include <vector>
#include <functional>

namespace nstest { namespace unit
{
  struct test
  {
    using behavior_t = std::function<void( env& )>;

    std::string name;
    behavior_t  behaviour;

    test( std::string const& n, behavior_t const& b ) : name( n ), behaviour( b ) {}

        void operator()(env& e) { behaviour(e); }
  };

  using test_suite = std::vector<test>;

  static inline test_suite& suite()
  {
    static test_suite tests;
    return tests;
  }
} }


namespace nstest { namespace detail
{
  struct registrar
  {
    registrar( ::nstest::unit::test const& test_case ) { unit::suite().push_back( test_case ); }
  };
} }


#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#define NSTEST_CASE(DESCRIPTION)                                                                    \
void NTEST_FUNCTION( ::nstest::unit::env& );                                                        \
namespace                                                                                           \
{                                                                                                   \
  ::nstest::detail::registrar                                                                       \
  NTEST_REGISTRATION{::nstest::unit::test(DESCRIPTION, NTEST_FUNCTION)};                            \
}                                                                                                   \
void NTEST_FUNCTION( ::nstest::unit::env& $ )                                                       \

#define NTEST_RTYPE(z, n, t)                                                                        \
{                                                                                                   \
  using T = BOOST_PP_SEQ_ELEM(n,t);                                                                 \
  $.stream() << std::endl;                                                                          \
  $.stream() <<  "With T = [" << ::nstest::white_(NSTEST_STRING(BOOST_PP_SEQ_ELEM(n,t)))            \
                        << "] ";                                                                    \
  if(!$.is_compact()) $.stream() << std::endl;                                                      \
  NTEST_FUNCTION<T>($);                                                                             \
}                                                                                                   \

#define NSTEST_CASE_TPL(DESCRIPTION, TYPES)                                                         \
template<typename T> void NTEST_FUNCTION( nstest::unit::env& );                                     \
namespace                                                                                           \
{                                                                                                   \
  nstest::detail::registrar                                                                         \
  NTEST_REGISTRATION{ nstest::unit::test                                                            \
                      ( DESCRIPTION                                                                 \
                      , [](::nstest::unit::env& $) -> void                                          \
                        {                                                                           \
                          BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(TYPES),NTEST_RTYPE,TYPES)               \
                        }                                                                           \
                      )                                                                             \
                    };                                                                              \
}                                                                                                   \
template<typename T> void NTEST_FUNCTION( nstest::unit::env& $ )                                    \



namespace nstest
{
  inline bool is_false()  { return false; }

  inline bool is_true()   { return true; }
}

#include <algorithm>
#include <random>

namespace nstest
{
  template<typename Environment, typename Suite, typename... Setup>
  inline bool run(Environment& environment, Suite& tests, Setup const&... setup)
  {
        auto is_compact = args("compact",false);
    environment.compact(is_compact);

        if(auto seed = args("random",0u))
    {
      std::shuffle( tests.begin(), tests.end(), std::mt19937{seed} );
    }

    for(auto& t : tests )
    {
      scenario_header(environment,t);
      auto count = environment.tests();

      t(environment);

      process_invalid(environment, count);

      environment.stream() << std::endl;
    }

    return ::nstest::report(environment,setup...);
  }
}


#if !defined(NSTEST_USE_CUSTOM_DRIVER)

#if !defined(NSTEST_CUSTOM_DRIVER_FUNCTION)
#define NSTEST_CUSTOM_DRIVER_FUNCTION main
#endif

#if defined(DOXYGEN_ONLY)
#define NSTEST_CUSTOM_DRIVER_FUNCTION
#endif

int NSTEST_CUSTOM_DRIVER_FUNCTION(int argc, const char** argv)
{
  ::nstest::unit::env $env(argc,argv,std::cout);
  return ::nstest::run( $env, ::nstest::unit::suite(), 0, 0 );
}

#endif





#include <iostream>
#include <string>

namespace nstest
{
  struct location
  {
    std::string file;
    std::size_t line;
  };

    std::ostream& operator<<(std::ostream& os, location const& l)
  {
    return os << darkgray_(l.file) << ":" << darkgray_(l.line);
  }

    inline location at(std::string const& f, std::size_t l) { return {f,l}; }
}



#include <string>

namespace nstest { namespace detail
{
    struct result
  {
    bool        status;
    std::string lhs;
    std::string op;
    std::string rhs;

    explicit operator bool() { return status; }
  };
} }

#define NSTEST_DUMP(R)                                                                              \
$.stream()  << "failing because:\n"                                                                 \
            << ::nstest::white_(R.lhs) << R.op << ::nstest::white_(R.rhs) << "\n"                   \
            << "is incorrect.\n";                                                                   \


namespace nstest { namespace detail
{
  template<typename LHS, typename RHS>
  inline bool compare_equal(LHS const& l, RHS const& r)         { return l == r; }

  template<typename LHS, typename RHS>
  inline bool compare_less(LHS const& l, RHS const& r)          { return l < r; }

  template<typename LHS, typename RHS>
  inline bool compare_not_equal(LHS const& l, RHS const& r)     { return l != r; }

  template<typename LHS, typename RHS>
  inline bool compare_less_equal(LHS const& l, RHS const& r)    { return l <= r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater(LHS const& l, RHS const& r)       { return l > r; }

  template<typename LHS, typename RHS>
  inline bool compare_greater_equal(LHS const& l, RHS const& r) { return l >= r; }
} }


namespace nstest { namespace detail
{
    template<typename Expression> struct lhs_expr
  {
    Expression lhs;

    lhs_expr( Expression x ) : lhs( x ) {}

    lhs_expr(lhs_expr const&)             = delete;
    lhs_expr& operator=(lhs_expr const&)  = delete;

    #define NSTEST_BINARY_DECOMPOSE(OP,SB,FN)                                                       \
    template<typename R> result operator OP( R const & rhs )                                        \
    {                                                                                               \
      using nstest::detail::FN;                                                                     \
      return  { FN(lhs, rhs)                                                                        \
              , nstest::to_string( lhs ), nstest::split_line(lhs,rhs,SB), nstest::to_string(rhs)    \
              };                                                                                    \
    }                                                                                               \

    NSTEST_BINARY_DECOMPOSE( ==,  "==", compare_equal         )
    NSTEST_BINARY_DECOMPOSE( !=,  "!=", compare_not_equal     )
    NSTEST_BINARY_DECOMPOSE( < ,  "<" , compare_less          )
    NSTEST_BINARY_DECOMPOSE( <=,  "<=", compare_less_equal    )
    NSTEST_BINARY_DECOMPOSE( > ,  ">" , compare_greater       )
    NSTEST_BINARY_DECOMPOSE( >=,  ">=", compare_greater_equal )

    #undef NSTEST_BINARY_DECOMPOSE
  };

  struct decomposer
  {
    template <typename Expression>
    lhs_expr<Expression const &> operator->* ( Expression const& expr )
    {
      return { expr };
    }
  };
} }

#define NSTEST_DECOMPOSE( XPR ) ( nstest::detail::decomposer()->* XPR )


#define NSTEST_PASS( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_success();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.pass() << MESSAGE << " in: " << ::nstest::at(__FILE__,__LINE__) << std::endl;                 \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << ::nstest::green_("+");                                                            \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_FAIL( MESSAGE )                                                                      \
do                                                                                                  \
{                                                                                                   \
  $.as_failure();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.fail() << MESSAGE << " in: " << ::nstest::at(__FILE__,__LINE__) << std::endl;                 \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << ::nstest::red_("-");                                                              \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_EXPECT( EXPR )                                                                       \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE(EXPR);                                                                  \
  if( r )                                                                                           \
    NSTEST_PASS( "Expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                          \
  else                                                                                              \
  {                                                                                                 \
    NSTEST_FAIL( "Expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                          \
    if(!$.is_compact()) NSTEST_DUMP( r );                                                           \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_EXPECT_NOT( EXPR )                                                                   \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE(EXPR);                                                                  \
  if( !r )                                                                                          \
    NSTEST_PASS( "Not expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                      \
  else                                                                                              \
  {                                                                                                 \
    NSTEST_FAIL( "Not expecting: " << ::nstest::white_(NSTEST_STRING(EXPR)) );                      \
    if(!$.is_compact()) NSTEST_DUMP( r );                                                           \
  }                                                                                                 \
} while( ::nstest::is_false() )                                                                     \



#if defined(__GNUC__) || defined(DOXYGEN_ONLY)
#define NSTEST_UNUSED(X) (void) X
#else
#define NSTEST_UNUSED(X) X
#endif


#if !defined(BOOST_ENABLE_ASSERT_HANDLER)
#error BOOST_ENABLE_ASSERT_HANDLER must be defined to use NSTEST_ASSERT() macro
#endif

#include <boost/config.hpp>
#if defined(BOOST_NO_EXCEPTIONS)
#error Exceptions must be enabled to  use NSTEST_ASSERT() macro
#endif

#include <boost/core/ignore_unused.hpp>
#include <boost/throw_exception.hpp>
#include <boost/exception/all.hpp>
#include <boost/assert.hpp>

namespace nstest { namespace detail
{
  struct BOOST_SYMBOL_VISIBLE assertion_failure : virtual boost::exception, std::runtime_error
  {
        inline assertion_failure(std::string const& msg) : boost::exception() , std::runtime_error(msg)
    {}
  };

    using throw_message = boost::error_info<struct tag_throw_msg,char const*>;

  inline std::ostream& operator<<(std::ostream& os, assertion_failure const& e)
  {
    auto fn   = boost::get_error_info< ::boost::throw_function >(e);
    auto f    = boost::get_error_info< ::boost::throw_file >(e);
    auto l    = boost::get_error_info< ::boost::throw_line >(e);
    auto msg  = boost::get_error_info< ::nstest::detail::throw_message >(e);

    os  << "Assertion    '"  << ::nstest::white_(e.what()) << "' failed\n"
        << " in function '"  << ::nstest::white_(*fn) << "'\n"
        << " from         "  << ::nstest::at(*f,*l)    << " \n";

    if(msg)  os << " because     '"  << ::nstest::white_(*msg) << "'";

    return os;
  }
} }

namespace boost
{
    inline void assertion_failed( char const* expr, char const* fn, char const* f, long l )
  {
    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception
    (     ::boost::enable_error_info( ::nstest::detail::assertion_failure(expr) )
      <<  ::boost::throw_function(fn)
      <<  ::boost::throw_file(f)
      <<  ::boost::throw_line(int(l))
    );
    #else
    ::boost::ignore_unused(fn,f,l);
    ::boost::throw_exception( ::nstest::detail::assertion_failure(expr) );
    #endif
  }

    inline void assertion_failed_msg( char const* expr, char const* msg
                                  , char const* fn, char const* f, long l
                                  )
  {
    #ifndef BOOST_EXCEPTION_DISABLE
    ::boost::throw_exception
    (     ::boost::enable_error_info( ::nstest::detail::assertion_failure(expr) )
      <<  ::boost::throw_function(fn)
      <<  ::boost::throw_file(f)
      <<  ::boost::throw_line(int(l))
      <<  ::nstest::detail::throw_message(msg)
    );
    #else
    ::boost::ignore_unused(expr,fn,f,l);
    ::boost::throw_exception( ::nstest::detail::assertion_failure(msg) );
    #endif
  }
}

#include <boost/preprocessor/punctuation/remove_parens.hpp>

#define NSTEST_THROW( X, T )                                                                        \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try                                 { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                 \
  catch( BOOST_PP_REMOVE_PARENS(T)& ) { caught = true; }                                            \
                                                                                                    \
  if(caught)                                                                                        \
    NSTEST_PASS (   ::nstest::white_(NSTEST_STRING(X))                                              \
                <<  " throws "                                                                      \
                <<  ::nstest::white_(NSTEST_STRING(T))                                              \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL(   ::nstest::white_(NSTEST_STRING(X))                                               \
                <<  " does not throw "                                                              \
                <<  ::nstest::white_(NSTEST_STRING(T))                                              \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_NO_THROW( X )                                                                        \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try          { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                        \
  catch( ... ) { caught = true; }                                                                   \
                                                                                                    \
  if(caught)                                                                                        \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " throws while not expected to" );           \
  else                                                                                              \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " doesn't throw" );                          \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_ASSERT(X)                                                                            \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try  { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                                \
  catch( ::nstest::detail::assertion_failure& e)                                                    \
  {                                                                                                 \
    caught = true;                                                                                  \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " triggered: \n" << e << "\n" );             \
  }                                                                                                 \
                                                                                                    \
  if(!caught)                                                                                       \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " didn't trigger any assertion." );          \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_NO_ASSERT(X)                                                                         \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try  { NSTEST_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                                \
  catch( ::nstest::detail::assertion_failure& e)                                                    \
  {                                                                                                 \
    caught = true;                                                                                  \
    NSTEST_FAIL( ::nstest::white_(NSTEST_STRING(X)) << " triggered: \n" << e << "\n" );             \
  }                                                                                                 \
                                                                                                    \
  if(!caught)                                                                                       \
    NSTEST_PASS( ::nstest::white_(NSTEST_STRING(X)) << " didn't trigger any assertion." );          \
} while( ::nstest::is_false() )                                                                     \




#include <vector>
#include <string>

namespace nstest
{
    template<typename Measure, typename Reference> struct approx_
  {
    approx_(Reference const& r, double u) : ref(r), diff(u), size_mismatch(false), max_diff(u) {}

    template<typename U> inline bool compare(U const& data) const
    {
      Measure m;
      size_mismatch = detail::size(ref) != detail::size(data);
      if(size_mismatch) return false;

      auto dist = m(data,ref);

      auto br = detail::begin(data);
      auto bi = detail::begin(ref);
      auto bd = detail::begin(dist);
      auto sz = detail::size(data);

      for(std::size_t idx=0;idx < sz; ++idx)
        check( *bd++, *br++, *bi++, (sz>1 ? idx : -1) );

      return errors.size() == 0;
    }

    struct error
    {
      double          value;
      std::string     ref,data;
      std::ptrdiff_t  idx;
    };

    bool                      mismatched()  const { return size_mismatch; }
    double                    max()         const { return max_diff;      }
    std::vector<error> const& report()      const { return errors;        }

    private:

    template<typename U, typename X, typename Y>
    inline void check(U const&  u, X const& x, Y const& y, std::ptrdiff_t idx) const
    {
      using nstest::to_string;

      if( u  > diff )
      {
        errors.push_back( {u, to_string(x),to_string(y), idx} );
        max_diff = std::max(max_diff,u);
      }
    }

    Reference                   ref;
    double                      diff;
    mutable bool                size_mismatch;
    mutable double              max_diff;
    mutable std::vector<error>  errors;
  };

    template<typename Measure, typename Reference>
  std::string to_string( approx_<Measure,Reference> const& u )
  {
    using nstest::to_string;

    if(u.mismatched()) return "arguments with mismatched size.";

    std::ostringstream s,ls;

        ls.precision(20);

    for(auto const& e : u.report())
    {
      (e.idx >= 0) ? ls << "  [" << e.idx << "]: " : ls << "  ";
      ls << to_string(e.ref) << " vs " << to_string(e.data);
      Measure::to_stream(ls,e.value);
    }

        s.precision(20);
    Measure::to_stream(s,u.max());

    return "{\n"  + ls.str() + "}\n with a maximal error of " + s.str();
  }

    template<typename Measure, typename Reference, typename U>
  inline bool compare_equal(U const& l, approx_<Measure, Reference> const& r)
  {
    return r.compare(l);
  }
}



#include <type_traits>

namespace nstest { namespace detail
{
  template<typename T, typename R>
  using if_integral = typename std::enable_if<std::is_integral<T>::value, R>::type;

  template<typename T, typename R>
  using if_real = typename std::enable_if<std::is_floating_point<T>::value, R>::type;

    template<typename T, typename U>
  using common_t = typename std::common_type<T,U>::type;
} }

#include <algorithm>
#include <iterator>
#include <cmath>

namespace nstest
{
#if defined(DOXYGEN_ONLY)
  template<typename T, typename U> inline auto ulpdist(T a0, U a1);
#else

#endif

  inline double ulpdist(bool a0, bool a1) { return a0 == a1 ? 0. : 1.; }

  template<typename T>
  inline detail::if_integral<T,double> ulpdist(T const& a0, T const& a1)
  {
    using u_t = typename std::make_unsigned<T>::type;
    return static_cast<double>( (a0<a1) ? u_t(a1-a0) : u_t(a0-a1) );
  }

  template<typename T>
  inline detail::if_real<T,double> ulpdist(T const& a0, T const& a1)
  {
    if( (a0 == a1) || ((a0!=a0) && (a1!=a1)) )  return 0.;
    if( (a0!=a0) || (a1!=a1) )                  return std::numeric_limits<T>::infinity();

    int e1,e2;
    T   m1,m2;
    m1 = std::frexp(a0, &e1);
    m2 = std::frexp(a1, &e2);

    int expo = -std::max(e1, e2);

    T e = (e1 == e2)  ? std::abs(m1-m2)
                      : std::abs(std::ldexp(a0, expo)- std::ldexp(a1, expo));

    return double(e/std::numeric_limits<T>::epsilon());
  }

  template<typename T>
  inline detail::if_container<T,std::vector<double>> ulpdist(T const& a0, T const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end(), a1.begin()
                  , std::back_inserter(ulps)
                  , [](type const& a,type const& b) { using ::nstest::ulpdist; return ulpdist(a,b); }
                  );

    return ulps;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  ulpdist(T const& a0, U const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(ulps)
                  , [&a1](type const& a) { using ::nstest::ulpdist; return ulpdist(a,a1); }
                  );

    return ulps;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  ulpdist(U const& a1,T const& a0)
  {
    using type = decltype(*a0.begin());
    std::vector<double> ulps;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(ulps)
                  , [&a1](type const& a) { using ::nstest::ulpdist; return ulpdist(a1,a); }
                  );

    return ulps;
  }

  template<typename T, typename U, typename R>
  using are_not_containers = typename std::enable_if<   !detail::is_container<T>::type::value
                                                    &&  !detail::is_container<U>::type::value
                                                    ,   R
                                                  >::type;

  template<typename T, typename U>
  inline are_not_containers<T,U,double> ulpdist(T const& a0, U const& a1)
  {
    return ulpdist(static_cast<detail::common_t<T,U>>(a0), static_cast<detail::common_t<T,U>>(a1));
  }
}

#include <string>

namespace nstest
{
  namespace detail
  {
    struct ulp_measure
    {
      template<typename T, typename U>
      auto operator()(T const& data, U const& ref) const -> decltype(ulpdist(data,ref))
      {
        using nstest::ulpdist;
        return ulpdist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s << " (" << v << " ULPs)\n";
      }
    };
  }
    template<typename R> using ulp_ = approx_<detail::ulp_measure, R>;

    template<typename R> inline ulp_<R> ulp(R const& t, double n) { return {t,n}; }
}



#include <algorithm>
#include <iterator>
#include <cmath>

namespace nstest
{
#if defined(DOXYGEN_ONLY)
  template<typename T, typename U> inline auto reldist(T a0, U a1);
#else

#endif

  inline double reldist(bool a0, bool a1) { return a0 == a1 ? 0. : 1.; }

  template<typename T,typename U> using dependent = U;

  template<typename T>
  inline detail::if_integral<T,double> reldist(T const& a0, T const& a1)
  {
    dependent<T,double> d0 = static_cast<double>(a0), d1 = static_cast<double>(a1);
    return reldist(d0,d1);
  }

  template<typename T>
  inline detail::if_real<T,double> reldist(T const& a0, T const& a1)
  {
    if( (a0 == a1) || ((a0!=a0) && (a1!=a1)) )  return 0.;
    if( (a0!=a0) || (a1!=a1) )                  return std::numeric_limits<T>::infinity();

    return std::abs(a0-a1) / std::max(T(1), std::max(std::abs(a0),std::abs(a1)));
  }

  template<typename T>
  inline detail::if_container<T,std::vector<double>> reldist(T const& a0, T const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end(), a1.begin()
                  , std::back_inserter(rels)
                  , [](type const& a,type const& b) { using ::nstest::reldist; return reldist(a,b); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  reldist(U const& a1,T const& a0)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(rels)
                  , [&a1](type const& a) { using ::nstest::reldist; return reldist(a1,a); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline detail::if_container<T,std::vector<double>>
  reldist(T const& a0,U const& a1)
  {
    using type = decltype(*a0.begin());
    std::vector<double> rels;

    std::transform( a0.begin(), a0.end()
                  , std::back_inserter(rels)
                  , [&a1](type const& a) { using ::nstest::reldist; return reldist(a,a1); }
                  );

    return rels;
  }

  template<typename T, typename U>
  inline auto reldist(T const& a0, U const& a1)
              -> decltype ( reldist ( static_cast<detail::common_t<T,U>>(a0)
                                    , static_cast<detail::common_t<T,U>>(a1)
                                    )
                          )
  {
    return reldist(static_cast<detail::common_t<T,U>>(a0), static_cast<detail::common_t<T,U>>(a1));
  }
}

#include <string>

namespace nstest
{
  namespace detail
  {
    struct relative_measure
    {
      template<typename T, typename U>
      auto operator()(T const& data, U const& ref) const -> decltype(reldist(data,ref))
      {
        using nstest::reldist;
        return reldist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s.precision(2);
        s << " (" << std::fixed << v*100. << " %)\n";
      }
    };
  }

    template<typename R> using relative_ = approx_<detail::relative_measure, R>;

    template<typename R> inline relative_<R> relative(R const& t, double n) { return {t,n/100.}; }
}


#define NSTEST_ULP_EQUAL(A,B,X)                                                                     \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE((A) == ::nstest::ulp(B,X));                                             \
  if( r )                                                                                           \
    NSTEST_PASS ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " ULPs."                    \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " ULPs "                    \
                                << "but found:\n" << ::nstest::white_(r.rhs)                        \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \


#define NSTEST_RELATIVE_EQUAL(A,B,X)                                                                \
do                                                                                                  \
{                                                                                                   \
  auto r = NSTEST_DECOMPOSE((A) == ::nstest::relative(B,X));                                        \
  if( r )                                                                                           \
    NSTEST_PASS ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " %."                       \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL ( "Expecting: " << ::nstest::white_(NSTEST_STRING(A) " == " NSTEST_STRING(B))       \
                                << " within " << ::nstest::white_(X) << " % "                       \
                                << "but found:\n" << ::nstest::white_(r.rhs)                        \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \



#define NSTEST_EQUAL( A, B )      NSTEST_EXPECT( (A) == (B) )

#define NSTEST_NOT_EQUAL( A, B )  NSTEST_EXPECT( (A) != (B) )

#define NSTEST_LESS(A,B)        NSTEST_EXPECT( (A) < (B) )

#define NSTEST_GREATER(A,B)       NSTEST_EXPECT( (A) > (B) )

#define NSTEST_LESS_EQUAL(A,B)  NSTEST_EXPECT( (A) <= (B) )

#define NSTEST_GREATER_EQUAL(A,B) NSTEST_EXPECT( (A) >= (B) )


#include <type_traits>

#include <boost/core/demangle.hpp>
#include <type_traits>
#include <typeinfo>
#include <string>

namespace nstest
{
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

#include <boost/preprocessor/punctuation/remove_parens.hpp>
#include <boost/core/ignore_unused.hpp>
#include <boost/mpl/apply.hpp>

#define NSTEST_TYPE_IS(T, Type)                                                                     \
do                                                                                                  \
{                                                                                                   \
  volatile bool b = std::is_same<BOOST_PP_REMOVE_PARENS(Type), BOOST_PP_REMOVE_PARENS(T)>::value;   \
  if( b )                                                                                           \
    NSTEST_PASS (   "Expecting " << ::nstest::white_ << NSTEST_STRING(BOOST_PP_REMOVE_PARENS(T))    \
                <<  " == " << nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>() << ::nstest::default_ \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL (   "Expecting " << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(T)))      \
                <<  " == " << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())     \
                <<  " found " << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(T)>())     \
                <<  " instead"                                                                      \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \

#define NSTEST_EXPR_IS(Expression, Type)                                                            \
NSTEST_TYPE_IS(decltype( BOOST_PP_REMOVE_PARENS(Expression)), Type)                                 \

#define NSTEST_EXPR_TYPE(Expression, Lambda, Type)                                                  \
do                                                                                                  \
{                                                                                                   \
  using other = boost::mpl::apply < BOOST_PP_REMOVE_PARENS(Lambda)                                  \
                                  , decltype(BOOST_PP_REMOVE_PARENS(Expression))                    \
                                  >::type;                                                          \
                                                                                                    \
  volatile bool b = std::is_same<BOOST_PP_REMOVE_PARENS(Type), other>::value;                       \
  if( b )                                                                                           \
    NSTEST_PASS (   "Expecting "                                                                    \
                << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(Lambda)))                  \
                << " applied on "                                                                   \
                << ::nstest::white_(nstest::type_id(BOOST_PP_REMOVE_PARENS(Expression)))            \
                <<  " to be "                                                                       \
                << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())                \
                );                                                                                  \
  else                                                                                              \
    NSTEST_FAIL(   "Expecting "                                                                     \
                << ::nstest::white_(NSTEST_STRING(BOOST_PP_REMOVE_PARENS(Lambda)))                  \
                << " applied on "                                                                   \
                << ::nstest::white_(nstest::type_id(BOOST_PP_REMOVE_PARENS(Expression)))            \
                <<  " to be "                                                                       \
                << ::nstest::white_(nstest::type_id<BOOST_PP_REMOVE_PARENS(Type)>())                \
                << " but found " << ::nstest::white_(nstest::type_id<other>()) << " instead"        \
                );                                                                                  \
} while( ::nstest::is_false() )                                                                     \



namespace nstest
{
  namespace unit
  {




#if defined(DOXYGEN_ONLY)
#define NSTEST_USE_CUSTOM_DRIVER
#endif
  }

   namespace detail
  {
  }
}

#endif
