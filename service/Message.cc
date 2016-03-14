#include "Message.hh"
#include "KickLog.hh"

#include "kick/KickDef.hh"

namespace kick
{

Message::Message(CMsgData* pmsg):
    msg_(pmsg)
{
}

int Message::parseTotRecord()
{
  int tot_record = 0;
  
  msg_->GetData_Int32(TOT_RECORD, &tot_record);

  return tot_record;
}

int Message::parseMktTPCode()
{
  int mkt_code = 0;

  msg_->GetData_Int32(MKT_TP_CODE, &mkt_code);

  return mkt_code;
}

Message* Message::create(int ncmd, CMsgData* pmsg)
{
  switch( ncmd )
  {
    case CMD_HQSERVER_HQ_STK_SNAPSHOT:
      return new StockSnapshot( pmsg );
  };

  return nullptr;
}

StockSnapshot::StockSnapshot(CMsgData* pmsg):
    Message(pmsg)
{
}

void StockSnapshot::parse(json::Document& doc)
{
  KICK_TRACE <<"StockSnapshot::parse()";

  json::Value o( json::kObjectType );
  json::addMember(o, TOT_RECORD, parseTotRecord(), doc);
  json::addMember(o, MKT_TP_CODE, parseMktTPCode(), doc);

  CTableData * ptable = nullptr;
  msg_->GetData_TableData(SEQ_HQ_SNAPSHOT, &ptable);

  if( ptable )
  {
    int row_count = 0;
    ptable->GetCount(&row_count);
    
    for(int i=0; i<row_count; ++i)
    {
      CMsgData* prow = nullptr;
      
      ptable->GetRow(i, &prow);
      
      if(prow)
      {
        // prow->GetData_String("SCR_CODE", (unsigned char *)&szstkcode, sizeof(szstkcode));
      }
    }
    ptable->Release();
    ptable = nullptr;

  }
  
}

};
