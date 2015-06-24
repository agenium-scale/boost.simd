//==================================================================================================
/*!
  @file

  Defines color handling in console display

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_COLOR_HPP_INCLUDED
#define NSTEST_COMMON_COLOR_HPP_INCLUDED

#include <nstest/common/args.hpp>
#include <nstest/common/to_string.hpp>
#include <boost/predef.h>
#include <iostream>
#include <iomanip>

#if defined(BOOST_OS_WINDOWS_AVAILABLE) && !defined(BOOST_OS_CYGWIN_AVAILABLE)
#include <windows.h>
#define NSTEST_USE_CONSOLE_ATTRIBUTES
#endif

namespace nstest
{
  // enum Color { DARKBLUE = 1, DARKGREEN, DARKTEAL, DARKRED, DARKPINK
  // , DARKYELLOW, GRAY, DARKGRAY, BLUE, GREEN, TEAL, RED, PINK, YELLOW, WHITE };
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

#endif
