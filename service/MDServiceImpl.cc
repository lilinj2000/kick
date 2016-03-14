#include "MDServiceImpl.hh"
#include "MDOptions.hh"
#include "KickLog.hh"
#include "kick/KickDef.hh"
// #include "Message.hh"

#include "soil/NumberToString.hh"

namespace kick
{

MDServiceImpl::MDServiceImpl(soil::Options* options, MDCallback* callback):
    options_(nullptr),
    callback_(callback)
{
  KICK_TRACE <<"MDServiceImpl::MDServiceImpl()";

  try
  {
    options_ = dynamic_cast<MDOptions*>(options);

    kmds_api_.reset( new CKmdsUserApi() );

    if( !kmds_api_.get() )
    {
      throw std::runtime_error("create kmds api failed.");
    }

    initKMDS();

    subscribe();
  }
  catch(std::exception& e )
  {
    KICK_ERROR <<e.what();

    throw;
  }

}

MDServiceImpl::~MDServiceImpl()
{
  KICK_TRACE <<"MDServiceImpl::~MDServiceImpl()";

  if( kmds_api_.get() )
  {
    kmds_api_->UnInit();

    kmds_api_.reset( nullptr );
  }
}


void MDServiceImpl::OnKmdsMsg(void* pmsgdesc, void* pmsgopts,int ncmd, CMsgData* pmsg)
{
  KICK_TRACE <<"MDServiceImpl::OnKmdsMsg()";

  if( !pmsg )
    return ;

  std::string dump_info;

  pmsg->Dump(EM_DUMP_FORMAT_COLDETAIL, dump_info);
  KICK_INFO <<"col detail info:\n"
            <<dump_info;

  dump_info = "";
  pmsg->Dump(EM_DUMP_FORMAT_ROWMODE, dump_info);
  KICK_INFO <<"row mode:\n"
            <<dump_info;

  dump_info = "";
  pmsg->Dump(EM_DUMP_FORMAT_ROWMODE_NOTITLE, dump_info);
  KICK_INFO <<"row mode without titile:\n"
            <<dump_info;

  dump_info = "";
  pmsg->Dump(EM_DUMP_FORMAT_CALLPROGRAM, dump_info);
  KICK_INFO <<"call program:\n"
            <<dump_info;
    
  // std::unique_ptr<Message> msg( Message::create(ncmd, pmsg) );

  // json::Document doc;
  // msg->parse( doc );
  
}

void MDServiceImpl::OnRvFtAction(const char *pgroupname, int enaction)
{
  KICK_TRACE <<"MDServiceImpl::OnRvFtAction()";
  
}

void MDServiceImpl::initKMDS()
{
  KICK_TRACE <<"MDServiceImpl::initKMDS()";

  int ret = kmds_api_->Init();
  if( ret!=0 )
  {
    std::string err_msg = "Init kmds failed.\n";
    err_msg += kmdsError();

    throw std::runtime_error( err_msg );
  }

  ret = kmds_api_->Login(options_->user_name.data(),
                         options_->password.data());
  if( ret!=0 )
  {
    std::string err_msg = "login failed.\n" + kmdsError();

    throw std::runtime_error( err_msg );
  }

  kmds_api_->SetKmdsMsgCB( this );
  
}

std::string MDServiceImpl::kmdsError()
{
  std::string err_msg;
  err_msg = "ErrorCode: " + soil::numToString(kmds_api_->GetErrCode()) + "\n";
  err_msg += "ErrMsg: ";
  err_msg += kmds_api_->GetErrMsg();

  return err_msg;
}

void MDServiceImpl::subscribe()
{
  KICK_TRACE <<"MDServiceImpl::subscribe()";

  KICK_INFO <<"subscribe topic: " <<options_->topic;

  int ret = kmds_api_->Subscribe( options_->topic.data() );
  if( ret!=0 )
  {
    std::string err_msg = "subscribe failed.\n";
    err_msg += kmdsError();

    throw std::runtime_error( err_msg );
  }

}

void MDServiceImpl::unsubscribe()
{
  KICK_TRACE <<"MDServiceImpl::unsubscribe()";

}

soil::Options* MDService::createOptions()
{
  return new MDOptions();
}

MDService* MDService::createService(soil::Options* options, MDCallback* callback)
{
  return new MDServiceImpl(options, callback);
}



};
