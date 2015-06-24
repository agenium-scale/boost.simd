//==================================================================================================
/*!
  @file

  Defines functions to retrieve options through command line or environment variables

  @copyright 2009 - 2015 LRI UMR 8623 CNRS/Univ Paris Sud XI
  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_COMMON_ARGS_HPP_INCLUDED
#define NSTEST_COMMON_ARGS_HPP_INCLUDED

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
        // List of environment variable to map onto options
        std::pair<std::string,std::string> envvars[] = { {"NSTEST_COLOR", "color"} };

        // fill map with environment variable
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
          // look for --name value pattern
          std::string cur{argv[i]};

          if(is_option(cur))
          {
            found = true;
            id    = std::string{cur.begin()+2,cur.end()}; // Remove the '--'
          }
          else
          {
            // if an option was found and we're looking at another impromptu option, update the map
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

      // warning-free getenv on MSVC
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

  /*!
    @ingroup group-common

    Centralized options provider

    Provides a global access to all the command line and environment options.
  **/
  const detail::args_map args;
}

#endif
