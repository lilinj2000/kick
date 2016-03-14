#ifndef KICK_MESSAGE_HH
#define KICK_MESSAGE_HH

#include "kmdsapidef.h"
#include "json/json.hh"

namespace kick
{

class Message
{
 public:

  Message(CMsgData* pmsg);
  
  virtual void parse(json::Document& doc) = 0;

  int parseTotRecord();

  int parseMktTPCode();
  
  virtual ~Message() {
  }

  static Message* create(int ncmd, CMsgData* pmsg);
  
 private:
  
  CMsgData* msg_;
  
};

class StockSnapshot : public Message
{
 public:
  StockSnapshot(CMsgData* pmsg);

  virtual void parse(json::Document& doc);

  virtual ~StockSnapshot() {
  }
 
};


};

#endif
