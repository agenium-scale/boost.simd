//==================================================================================================
/*!
  @file

  Main header for the unit test system

  @copyright 2015 Joel Falcou


  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef STF_HPP_INCLUDED
#define STF_HPP_INCLUDED




#include <unordered_map>
#include <sstream>
#include <cstdlib>
#include <string>
#include <boost/config.hpp>

namespace stf
{
  namespace detail
  {
    struct args_map
    {
      args_map()
      {
                std::pair<std::string,std::string>
        envvars[] = { {"STF_COMPACT" , "compact"}
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
        return (s.size() > 2) && (s[0] == '-') && (s[1] == '-');
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

#include <iostream>
#include <cstddef>
#include <string>

namespace stf
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

            std::ostream& pass()    const { return os << "[PASS]" << " - "; }

            std::ostream& fail()    const { return os << "[FAIL]" << " - "; }

            std::ostream& invalid() const
      {
        if(compact_mode)
          return os << "I";
        else
          return os << "[IVLD]" << " - ";
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

    e.stream()  << std::string(80,'-') << "\n"
      << "Results: "
      << e.tests()  << " "    << test_txt << " - "
      << e.successes() << " " << pass_txt << " - "
      << e.failures() << "/"  << fails     << " " << fail_txt << " - "
      << e.invalids() << "/"  << invalids  << " " << inv_txt
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
                    << "Scenario: " << t.name << std::endl
                    << hbar << std::endl;
    }
    else
    {
      env.stream()  << "Scenario: " << t.name << " : ";
    }
  }

  inline void process_invalid( unit::env& env, std::ptrdiff_t count)
  {
    if(count == env.tests())
    {
      env.as_invalid();
      if(!env.is_compact())
        env.invalid() << "Empty test case" << std::endl;
      else
        env.stream() << "!";
    }
  }
}



#define STF_STRING__(...) #__VA_ARGS__
#define STF_STRING_(text) STF_STRING__ text

#define STF_STRING(...) STF_STRING_((__VA_ARGS__))


#define STF_UNIQUE3( ID, LINE )  ID ## LINE
#define STF_UNIQUE2( ID, LINE )  STF_UNIQUE3( ID, LINE )

#if defined(DOXYGEN_ONLY)
#define STF_UNIQUE( Identifier )

#define STF_FUNCTION

#define STF_REGISTRATION
#else

#define STF_UNIQUE( Identifier ) STF_UNIQUE2( Identifier, __LINE__ )
#define STF_FUNCTION      STF_UNIQUE(stf_function)
#define STF_REGISTRATION  STF_UNIQUE(stf_registration)

#endif



#include <vector>
#include <functional>

namespace stf { namespace unit
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


namespace stf { namespace detail
{
  struct registrar
  {
    registrar( ::stf::unit::test const& test_case ) { unit::suite().push_back( test_case ); }
  };
} }


#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#define STF_CASE(DESCRIPTION)                                                                       \
void STF_FUNCTION( ::stf::unit::env& );                                                             \
namespace                                                                                           \
{                                                                                                   \
  ::stf::detail::registrar                                                                          \
  STF_REGISTRATION{::stf::unit::test(DESCRIPTION, STF_FUNCTION)};                                   \
}                                                                                                   \
void STF_FUNCTION( ::stf::unit::env& $ )                                                            \

#define STF_RTYPE(z, n, t)                                                                          \
{                                                                                                   \
  using T = BOOST_PP_SEQ_ELEM(n,t);                                                                 \
  $.stream() << std::endl;                                                                          \
  $.stream() <<  "With T = [" << STF_STRING(BOOST_PP_SEQ_ELEM(n,t))                                 \
                        << "] ";                                                                    \
  if(!$.is_compact()) $.stream() << std::endl;                                                      \
  STF_FUNCTION<T>($);                                                                               \
}                                                                                                   \

#define STF_CASE_TPL(DESCRIPTION, TYPES)                                                            \
template<typename T> void STF_FUNCTION( stf::unit::env& );                                          \
namespace                                                                                           \
{                                                                                                   \
  stf::detail::registrar                                                                            \
  STF_REGISTRATION{ stf::unit::test                                                                 \
                      ( DESCRIPTION                                                                 \
                      , [](::stf::unit::env& $) -> void                                             \
                        {                                                                           \
                          BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(TYPES),STF_RTYPE,TYPES)                 \
                        }                                                                           \
                      )                                                                             \
                    };                                                                              \
}                                                                                                   \
template<typename T> void STF_FUNCTION( stf::unit::env& $ )                                         \


#include <cstddef>
#include <cstdint>

#define STF_SIGNED_INTEGRAL_TYPES     (std::int8_t)(std::int16_t)(std::int32_t)(std::int64_t)
#define STF_UNSIGNED_INTEGRAL_TYPES   (std::uint8_t)(std::uint16_t)(std::uint32_t)(std::uint64_t)
#define STF_INTEGRAL_TYPES            (char)STF_SIGNED_INTEGRAL_TYPES STF_UNSIGNED_INTEGRAL_TYPES

#define STF_IEEE_TYPES (float)(double)

#define STF_SIGNED_NUMERIC_TYPES    STF_SIGNED_INTEGRAL_TYPES STF_IEEE_TYPES
#define STF_UNSIGNED_NUMERIC_TYPES  STF_UNSIGNED_INTEGRAL_TYPES
#define STF_NUMERIC_TYPES           STF_SIGNED_NUMERIC_TYPES STF_UNSIGNED_NUMERIC_TYPES

#define STF_ALL_TYPES     (bool) STF_NUMERIC_TYPES



namespace stf
{
  inline bool is_false()  { return false; }

  inline bool is_true()   { return true; }
}

#include <algorithm>
#include <random>

namespace stf
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

    return ::stf::report(environment,setup...);
  }
}



#if !defined(STF_CUSTOM_DRIVER_FUNCTION)
#define STF_CUSTOM_DRIVER_FUNCTION main
#endif

#if defined(DOXYGEN_ONLY)
#define STF_CUSTOM_DRIVER_FUNCTION
#endif

#if !defined(STF_USE_CUSTOM_DRIVER)
int STF_CUSTOM_DRIVER_FUNCTION(int argc, const char** argv)
{
  ::stf::unit::env $env(argc,argv,std::cout);
  return ::stf::run( $env, ::stf::unit::suite(), 0, 0 );
}
#endif







#include <iostream>
#include <string>

namespace stf
{
  struct location
  {
    std::string file;
    std::size_t line;
  };

    std::ostream& operator<<(std::ostream& os, location const& l)
  {
    return os << l.file << ":" << l.line;
  }

    inline location at(std::string const& f, std::size_t l) { return {f,l}; }
}




#include <cstddef>
#include <type_traits>

namespace stf { namespace detail
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

  template<typename T, typename U, typename R>
  using are_not_containers = typename std::enable_if<   !detail::is_container<T>::type::value
                                                    &&  !detail::is_container<U>::type::value
                                                    ,   R
                                                  >::type;


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

namespace stf { namespace detail
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

namespace stf
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


#include <string>

namespace stf { namespace detail
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

#define STF_DUMP(R)                                                                                 \
$.stream()  << "failing because:\n" << R.lhs << R.op << R.rhs << "\n" << "is incorrect.\n";         \

  
namespace stf
{
  namespace ext
  {
    template<typename LHS, typename RHS, typename EnableIf = void>
    struct equal
    {
      inline bool operator()(LHS const& l, RHS const& r) const
      {
        return l == r;
      }
    };

    template<typename LHS, typename RHS, typename EnableIf = void>
    struct less
    {
      inline bool operator()(LHS const& l, RHS const& r) const
      {
        return l < r;
      }
    };
  }

  namespace detail
  {
    template<typename LHS, typename RHS> inline bool eq(LHS const& l, RHS const& r)
    {
      return ::stf::ext::equal<LHS,RHS>()(l, r);
    }

    template<typename LHS, typename RHS> inline bool neq(LHS const& l, RHS const& r)
    {
      return !eq(l, r);
    }

    template<typename LHS, typename RHS> inline bool lt(LHS const& l, RHS const& r)
    {
      return ::stf::ext::less<LHS,RHS>()(l, r);
    }

    template<typename LHS, typename RHS> inline bool ge(LHS const& l, RHS const& r)
    {
      return !lt(l, r);
    }

    template<typename LHS, typename RHS> inline bool gt(LHS const& l, RHS const& r)
    {
      return !lt(l, r) || !neq(l, r);
    }

    template<typename LHS, typename RHS> inline bool le(LHS const& l, RHS const& r)
    {
      return lt(l, r) || eq(l, r);
    }
  }
}


namespace stf { namespace detail
{
    template<typename Expression> struct lhs_expr
  {
    Expression lhs;

    lhs_expr( Expression x ) : lhs( x ) {}

    lhs_expr(lhs_expr const&)             = delete;
    lhs_expr& operator=(lhs_expr const&)  = delete;

    operator result()
    {
      return result { bool(lhs)
                    , stf::to_string( bool(lhs) )
                    , stf::to_string("")
                    , stf::to_string("")
                    };
    }

    #define STF_BINARY_DECOMPOSE(OP,SB,FN)                                                          \
    template<typename R> result operator OP( R const & rhs )                                        \
    {                                                                                               \
      return  { stf::detail::FN(lhs, rhs)                                                           \
              , stf::to_string( lhs ), stf::split_line(lhs,rhs,SB), stf::to_string(rhs)             \
              };                                                                                    \
    }                                                                                               \
    
    STF_BINARY_DECOMPOSE( ==, "==", eq  )
    STF_BINARY_DECOMPOSE( !=, "!=", neq )
    STF_BINARY_DECOMPOSE( < , "<" , lt  )
    STF_BINARY_DECOMPOSE( > , ">" , gt  )
    STF_BINARY_DECOMPOSE( >=, ">=", ge  )
    STF_BINARY_DECOMPOSE( <=, "<=", le  )

    #undef STF_BINARY_DECOMPOSE
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

#define STF_DECOMPOSE( XPR ) ( stf::detail::decomposer()->* XPR )


#define STF_DISPLAY( INDICATOR, MESSAGE )                                                           \
do                                                                                                  \
{                                                                                                   \
  if(!$.is_compact()) $.stream() << INDICATOR << MESSAGE << std::endl;                              \
} while( ::stf::is_false() )                                                                        \

#define STF_INFO( MESSAGE ) STF_DISPLAY("[INFO] ", MESSAGE)

#define STF_WARNING( MESSAGE ) STF_DISPLAY("[WARNING] ", MESSAGE)

#define STF_ERROR( MESSAGE ) STF_DISPLAY("[ERROR] ", MESSAGE)

#define STF_PASS( MESSAGE )                                                                         \
do                                                                                                  \
{                                                                                                   \
  $.as_success();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.pass() << MESSAGE << " in: " << ::stf::at(__FILE__,__LINE__) << std::endl;                    \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << "+";                                                                              \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                        \

#define STF_FAIL( MESSAGE )                                                                         \
do                                                                                                  \
{                                                                                                   \
  $.as_failure();                                                                                   \
  if(!$.is_compact())                                                                               \
  {                                                                                                 \
    $.fail() << MESSAGE << " in: " << ::stf::at(__FILE__,__LINE__) << std::endl;                    \
  }                                                                                                 \
  else                                                                                              \
  {                                                                                                 \
    $.stream() << "-";                                                                              \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                        \


#define STF_EXPECT( EXPR )                                                                          \
do                                                                                                  \
{                                                                                                   \
  if( ::stf::detail::result stf_local_r = STF_DECOMPOSE(EXPR) )                                     \
    STF_PASS( "Expecting: " << STF_STRING(EXPR));                                                   \
  else                                                                                              \
  {                                                                                                 \
    STF_FAIL( "Expecting: " << STF_STRING(EXPR));                                                   \
    if(!$.is_compact()) STF_DUMP( stf_local_r );                                                    \
  }                                                                                                 \
} while( ::stf::is_false() )                                                                        \

#define STF_EXPECT_NOT( EXPR )                                                                      \
do                                                                                                  \
{                                                                                                   \
  if( ::stf::detail::result stf_local_r = STF_DECOMPOSE(EXPR) )                                     \
  {                                                                                                 \
    STF_FAIL( "Not expecting: " << STF_STRING(EXPR));                                               \
    if(!$.is_compact()) STF_DUMP( stf_local_r );                                                    \
  }                                                                                                 \
  else                                                                                              \
    STF_PASS( "Not expecting: " << STF_STRING(EXPR));                                               \
} while( ::stf::is_false() )                                                                        \



#if defined(__GNUC__) || defined(DOXYGEN_ONLY)
#define STF_UNUSED(X) (void) X
#else
#define STF_UNUSED(X) X
#endif

#include <boost/preprocessor/punctuation/remove_parens.hpp>

#define STF_THROW( X, T )                                                                           \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try                                 { STF_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                    \
  catch( BOOST_PP_REMOVE_PARENS(T)& ) { caught = true; }                                            \
                                                                                                    \
  if(caught)                                                                                        \
    STF_PASS( STF_STRING(X) <<  " throws " <<  STF_STRING(T) );                                     \
  else                                                                                              \
    STF_FAIL( STF_STRING(X) <<  " does not throw " <<  STF_STRING(T) );                             \
} while( ::stf::is_false() )                                                                        \

#define STF_NO_THROW( X )                                                                           \
do                                                                                                  \
{                                                                                                   \
  bool caught = false;                                                                              \
  try          { STF_UNUSED(BOOST_PP_REMOVE_PARENS(X)); }                                           \
  catch( ... ) { caught = true; }                                                                   \
                                                                                                    \
  if(caught)                                                                                        \
    STF_FAIL( STF_STRING(X) << " throws while not expected to" );                                   \
  else                                                                                              \
    STF_PASS( STF_STRING(X) << " doesn't throw" );                                                  \
} while( ::stf::is_false() )                                                                        \




#include <vector>
#include <string>

namespace stf
{
    template<typename Measure, typename Reference> struct approx_
  {
    approx_(Reference const& r, double u) : ref(r), diff(u), size_mismatch(false), max_diff(u) {}

    template<typename U> inline bool compare(U const& data) const
    {
      Measure m;
      size_mismatch = detail::size(ref) != detail::size(data);
      if(size_mismatch) return false;

      auto br = detail::begin(data);
      auto er = detail::end(data);
      auto bi = detail::begin(ref);

      std::vector<double> dist;
      while(br != er)
        dist.push_back( m(*br++,*bi++) );

      bi = detail::begin(ref);
      br = detail::begin(data);
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
      using stf::to_string;

      if( u  > diff )
      {
        errors.push_back( {u, to_string(x),to_string(y), idx} );
        max_diff = std::max<double>(max_diff,u);
      }
    }

    Reference                   ref;
    double                      diff;
    mutable bool                size_mismatch;
    mutable double              max_diff;
    mutable std::vector<error>  errors;
  };

    template<typename Measure, typename Reference>
  std::ostream& operator<<( std::ostream& os, approx_<Measure,Reference> const& u )
  {
    using stf::to_string;

    if(u.mismatched()) return os << "arguments with mismatched size.";

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

    return os << "{\n"  + ls.str() + "}\n with a maximal error of " + s.str();
  }

  namespace ext
  {
    template<typename T, typename Measure, typename Reference, typename EnableIf>
    struct equal<T,stf::approx_<Measure, Reference>,EnableIf>
    {
      inline bool operator()(T const& l, stf::approx_<Measure, Reference> const& r) const
      {
        return r.compare(l);
      }
    };
  }
}



#include <type_traits>

namespace stf { namespace detail
{
  template<typename T, typename R>
  using if_integral = typename std::enable_if<std::is_integral<T>::value, R>::type;

  template<typename T, typename R>
  using if_real = typename std::enable_if<std::is_floating_point<T>::value, R>::type;

    template<typename T, typename U>
  using common_t = typename std::common_type<T,U>::type;
} }

#include <type_traits>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace stf
{
  namespace ext
  {
    template< typename T1, typename T2 = T1
            , typename EnableIF = void
            >
    struct ulpdist
    {
      inline double operator()(T1 a, T2 b) const
      {
        using common_t = detail::common_t<T1,T2>;
        return ext::ulpdist<common_t>() ( static_cast<common_t>(a)
                                        , static_cast<common_t>(b)
                                        );
      }
    };

        template< typename T>
    struct ulpdist<T,T,typename std::enable_if<std::is_same<T,bool>::value>::type>
    {
      inline double operator()(T a, T b) const
      {
        return a == b ? 0. : 1.;
      }
    };

        template<typename T>
    struct ulpdist< T, T
                  , typename std::enable_if<std::is_floating_point<T>::value>::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        if( (a==b) || ((a!=a) && (b!=b)) )  return 0.;
        if( (a!=a) || (b!=b) )              return std::numeric_limits<T>::infinity();

        int e1 = 0,e2 = 0;
        T   m1,m2;
        m1 = std::frexp(a, &e1);
        m2 = std::frexp(b, &e2);

        int expo = -std::max(e1, e2);

        T e = (e1 == e2)  ? std::abs(m1-m2)
                          : std::abs(std::ldexp(a, expo)- std::ldexp(b, expo));

        return double(e/std::numeric_limits<T>::epsilon());
      }
    };

        template<typename T>
    struct ulpdist< T, T
                  , typename std::enable_if <   std::is_integral<T>::value
                                            &&  !std::is_same<T,bool>::value
                                            >::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        using u_t = typename std::make_unsigned<T>::type;
        return static_cast<double>( (a<b) ? u_t(b-a) : u_t(a-b) );
      }
    };
  }

  template<typename T, typename U> inline double ulpdist(T a0, U a1)
  {
    return ext::ulpdist<T,U>()(a0,a1);
  }

#if 0

#endif
}

#include <string>

namespace stf
{
  namespace detail
  {
    struct ulp_measure
    {
      template<typename T, typename U>
      double operator()(T const& data, U const& ref) const
      {
        return stf::ulpdist(data,ref);
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



#include <type_traits>
#include <algorithm>
#include <iterator>
#include <cmath>

namespace stf
{
  namespace ext
  {
    template< typename T1, typename T2 = T1
            , typename EnableIF = void
            >
    struct reldist
    {
      inline double operator()(T1 a, T2 b) const
      {
        using common_t = detail::common_t<T1,T2>;
        return ext::reldist<common_t>() ( static_cast<common_t>(a)
                                        , static_cast<common_t>(b)
                                        );
      }
    };

        template< typename T>
    struct reldist<T,T,typename std::enable_if<std::is_same<T,bool>::value>::type>
    {
      inline double operator()(T a, T b) const
      {
        return a == b ? 0. : 1.;
      }
    };

        template<typename T>
    struct reldist< T, T
                  , typename std::enable_if<std::is_floating_point<T>::value>::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        auto inf_ = std::numeric_limits<T>::infinity();
        auto aa   = std::abs(a);
        auto ab   = std::abs(b);

        if( (a == b  ) || ((a != a) && (b!=b)) )  return 0.;
        if( (a != a  ) || (b  != b) )             return inf_;
        if( (aa==inf_) || (ab == inf_) )          return inf_;

        return std::abs(a-b) / std::max(T(1), std::max(aa,ab));
      }
    };

        template<typename T>
    struct reldist< T, T
                  , typename std::enable_if <   std::is_integral<T>::value
                                            &&  !std::is_same<T,bool>::value
                                            >::type
                  >
    {
      inline double operator()(T a, T b) const
      {
        auto d0 = static_cast<double>(a), d1 = static_cast<double>(b);
        return reldist<double>()(d0,d1);
      }
    };
  }

  template<typename T, typename U> inline double reldist(T a0, U a1)
  {
    return ext::reldist<T,U>()(a0,a1);
  }
}

#include <string>

namespace stf
{
  namespace detail
  {
    struct relative_measure
    {
      template<typename T, typename U>
      double operator()(T const& data, U const& ref) const
      {
        return ::stf::reldist(data,ref);
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


#define STF_ULP_EQUAL(A,B,X)                                                                        \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = ::stf::ulpdist((A),(B));                                                       \
  if( stf_local_r <= (X) )                                                                          \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " ULPs." ); \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                             << " within " << X << " ULPs " << "but found:\n" << stf_local_r        \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \

#define STF_IEEE_EQUAL(A,B)  STF_ULP_EQUAL(A,B,0.)


#define STF_ALL_ULP_EQUAL(A,B,X)                                                                    \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::ulp(B,X));                                         \
  if( stf_local_r )                                                                                 \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " ULPs." ); \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                             << " within " << X << " ULPs " << "but found:\n" << stf_local_r.rhs    \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \

#define STF_ALL_IEEE_EQUAL(A,B)  STF_ALL_ULP_EQUAL(A,B,0.)

#define STF_RELATIVE_EQUAL(A,B,X)                                                                   \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = ::stf::reldist((A),(B));                                                       \
  if( stf_local_r <= (X/100.))                                                                      \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " %.");     \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                            << " within " << X << " % "                                             \
                            << "but found:\n" << stf_local_r                                        \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \

#define STF_ALL_RELATIVE_EQUAL(A,B,X)                                                               \
do                                                                                                  \
{                                                                                                   \
  auto stf_local_r = STF_DECOMPOSE((A) == ::stf::relative(B,X));                                    \
  if( stf_local_r )                                                                                 \
    STF_PASS( "Expecting: " << STF_STRING(A) " == " STF_STRING(B) << " within " << X << " %.");     \
  else                                                                                              \
    STF_FAIL( "Expecting: " << STF_STRING(A) " == " STF_STRING(B)                                   \
                            << " within " << X << " % "                                             \
                            << "but found:\n" << stf_local_r.rhs                                    \
            );                                                                                      \
} while( ::stf::is_false() )                                                                        \



#define STF_EQUAL( A, B )      STF_EXPECT( (A) == (B) )

#define STF_NOT_EQUAL( A, B )  STF_EXPECT( (A) != (B) )

#define STF_LESS(A,B)        STF_EXPECT( (A) < (B) )

#define STF_GREATER(A,B)       STF_EXPECT( (A) > (B) )

#define STF_LESS_EQUAL(A,B)  STF_EXPECT( (A) <= (B) )

#define STF_GREATER_EQUAL(A,B) STF_EXPECT( (A) >= (B) )


#include <type_traits>

#include <boost/core/demangle.hpp>
#include <type_traits>
#include <typeinfo>
#include <string>

namespace stf
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

#define STF_TYPE_IS(T, Type)                                                                        \
do                                                                                                  \
{                                                                                                   \
  volatile bool stf_local_b = std::is_same< BOOST_PP_REMOVE_PARENS(Type)                            \
                                          , BOOST_PP_REMOVE_PARENS(T)                               \
                                          >::value;                                                 \
  if( stf_local_b )                                                                                 \
    STF_PASS (   "Expecting " << STF_STRING(BOOST_PP_REMOVE_PARENS(T))                              \
                <<  " == " << stf::type_id<BOOST_PP_REMOVE_PARENS(Type)>()                          \
                );                                                                                  \
  else                                                                                              \
    STF_FAIL (   "Expecting " << STF_STRING(BOOST_PP_REMOVE_PARENS(T))                              \
                <<  " == " << stf::type_id<BOOST_PP_REMOVE_PARENS(Type)>()                          \
                <<  " found " << stf::type_id<BOOST_PP_REMOVE_PARENS(T)>()                          \
                <<  " instead"                                                                      \
                );                                                                                  \
} while( ::stf::is_false() )                                                                        \

#define STF_EXPR_IS(Expression, Type)                                                               \
STF_TYPE_IS(decltype( BOOST_PP_REMOVE_PARENS(Expression)), Type)                                    \

#define STF_EXPR_TYPE(Expression, Lambda, Type)                                                     \
do                                                                                                  \
{                                                                                                   \
  using other = boost::mpl::apply < BOOST_PP_REMOVE_PARENS(Lambda)                                  \
                                  , decltype(BOOST_PP_REMOVE_PARENS(Expression))                    \
                                  >::type;                                                          \
                                                                                                    \
  volatile bool stf_local_b = std::is_same<BOOST_PP_REMOVE_PARENS(Type), other>::value;             \
  if( stf_local_b )                                                                                 \
    STF_PASS (   "Expecting "                                                                       \
                << STF_STRING(BOOST_PP_REMOVE_PARENS(Lambda))                                       \
                << " applied on "                                                                   \
                << stf::type_id(BOOST_PP_REMOVE_PARENS(Expression))                                 \
                <<  " to be "                                                                       \
                << stf::type_id<BOOST_PP_REMOVE_PARENS(Type)>()                                     \
                );                                                                                  \
  else                                                                                              \
    STF_FAIL(   "Expecting "                                                                        \
                << STF_STRING(BOOST_PP_REMOVE_PARENS(Lambda))                                       \
                << " applied on "                                                                   \
                << stf::type_id(BOOST_PP_REMOVE_PARENS(Expression))                                 \
                <<  " to be "                                                                       \
                << stf::type_id<BOOST_PP_REMOVE_PARENS(Type)>()                                     \
                << " but found " << stf::type_id<other>() << " instead"                             \
                );                                                                                  \
} while( ::stf::is_false() )                                                                        \



namespace stf
{
  namespace unit
  {




#if defined(DOXYGEN_ONLY)
#define STF_USE_CUSTOM_DRIVER
#endif
  }

   namespace detail
  {
  }
}

#endif
