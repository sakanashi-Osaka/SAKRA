#include "V1730ZLEHeader.hpp"

ClassImp(TV1730ZLEHeader)

TV1730ZLEHeader::TV1730ZLEHeader(){
};

void TV1730ZLEHeader::Clear(){
  event_size=-1;
  board_fail_flag=false;
  //trigger_time_tag=-1;
  //event_counter=-1;
  //channel_mask.set(0);
};
