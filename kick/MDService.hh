#ifndef KICK_MDSERVICE_HH
#define KICK_MDSERVICE_HH

#include "soil/Config.hh"
#include "json/json.hh"

namespace kick
{

class MDCallback
{
 public:
  virtual ~MDCallback() {
  }

  virtual void msgCallback(const json::Document*) = 0;
};

class MDService
{
 public:
  virtual ~MDService()
  {
  }

  static soil::Options* createOptions();

  static MDService* createService(soil::Options* options, MDCallback* callback);

};

};

#endif
