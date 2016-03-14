#ifndef KICK_MDOPTIONS_HH
#define KICK_MDOPTIONS_HH

#include "soil/Config.hh"

#include <string>

namespace kick
{
namespace po = boost::program_options;

class MDOptions : public soil::Options
{
 public:

  MDOptions();
  
  virtual ~MDOptions();

  virtual po::options_description* configOptions();

  std::string user_name;
  std::string password;

  std::string topic;

 private:

  boost::program_options::options_description options_;
};

}  


#endif 
