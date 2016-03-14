#include "gtest/gtest.h"

#include "service/KickLog.hh"
#include "kick/MDService.hh"

#include "soil/STimer.hh"

namespace kick
{

class MDServiceTest : public ::testing::Test, public MDCallback
{
 public:
  MDServiceTest()
  {
  }
  
  void SetUp()
  {
    options_.reset( MDService::createOptions() );

    std::unique_ptr<soil::Config> config( soil::Config::create() );
    config->configFile() = "md.cfg";
    config->registerOptions( options_.get() );
    config->loadConfig();

    KICK_LOG_INIT("log.cfg");

    cond_.reset( soil::STimer::create() );

    service_.reset( MDService::createService(options_.get(), this) );

  }

  void TearDown()
  {
  }

  virtual void msgCallback(const json::Document* doc)
  {
    KICK_INFO <<"msg received:\n"
             <<json::toString(*doc);
  }

 protected:
  std::unique_ptr<MDService> service_;
  
  std::unique_ptr<soil::Options> options_;
  
  std::unique_ptr<soil::STimer> cond_;

};

TEST_F(MDServiceTest, mdTest)
{
  do
  {
    cond_->wait( 2000 );
    
  }while( true );
  
  ASSERT_TRUE( true );
}




}; 
