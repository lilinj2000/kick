#ifndef KICK_MDSERVICE_IMPL_HH
#define KICK_MDSERVICE_IMPL_HH

#include "kick/MDService.hh"
#include "kmdsapidef.h"
#include "kmdsuserapi.h"

namespace kick
{

class MDOptions;

class MDServiceImpl : public MDService, public CKmdsMsgCB
{
 public:
  MDServiceImpl(soil::Options* options, MDCallback* callback);

  virtual ~MDServiceImpl();

  virtual void OnKmdsMsg(void* pmsgdesc, void* pmsgopts,int ncmd ,CMsgData* pmsg);

  virtual void OnRvFtAction(const char *pgroupname, int enaction);
  
 protected:

  void initKMDS();

  std::string kmdsError();
  
  void subscribe();

  void unsubscribe();

 private:

  MDOptions* options_;

  MDCallback* callback_;

  std::unique_ptr<CKmdsUserApi> kmds_api_;
};


};

#endif
