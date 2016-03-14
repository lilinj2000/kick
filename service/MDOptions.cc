#include "MDOptions.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace kick
{

MDOptions::MDOptions():
    options_("MDOptions")
{
  namespace po = boost::program_options;

  options_.add_options()
      ("md.user_name", po::value<std::string>(&user_name), 
       "user name")
      ("md.password", po::value<std::string>(&password), 
       "password")
      
      ("md.topic", po::value<std::string>(&topic), 
       "topic")
      
      ;

  return;
  
}

MDOptions::~MDOptions()
{
}

po::options_description* MDOptions::configOptions()
{
  return &options_;
}

};  
