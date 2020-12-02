#include "V1730ZLE.hpp"
#include <iostream>

ClassImp(TV1730ZLE)

TV1730ZLE::TV1730ZLE(){
};

void TV1730ZLE::Clear(){
  for(int i=0;i<ch.size();++i) ch[i].Clear();
  //for(int i=0;i<16;++i) ch[i].Clear();
  trigger_time_tag=-1;
  event_counter=-1;
  channel_mask.set(0);
};

void TV1730ZLE::Analyze(uint32_t *rawbuff){
  int event_size=(rawbuff[0]&0x0FFFFFFF);
  bool board_fail_flag=(rawbuff[1]&0x04000000)>>26;
  event_counter=(rawbuff[2]&0x00FFFFFF);
  channel_mask=((rawbuff[2]>>16)&0xFF00) | (rawbuff[1]&0xFF);
  trigger_time_tag=((uint64_t)(rawbuff[1]&0x00FFFF00))<<24 | rawbuff[3];
  
  if(ch.size()==0) ch.resize(channel_mask.count());

  int bp=4;
  for(int ich=0;ich<channel_mask.count();++ich){
    int data_index=0;
    ch[ich].baseline=(rawbuff[bp] & 0x3FFF0000) >> 16;
    int ch_size=rawbuff[bp++] & 0x0000FFFF;

    if(ch_size==1) ch[ich].ch_id=1;
    if(ch_size==2){
      ch[ich].ch_id=2;
      bp++;
      continue;
    }

    ch[ich].ch_id=3;
    for(int i=0;i<(ch_size-1);++i){
      if((rawbuff[bp]>>31)  & 0x1){
	int skipped_samples= (rawbuff[bp++] & 0x0FFFFFFF) * 2;
	//DB(printf("skipped events=%d\n",skipped_samples));
	for(int j=0; j<skipped_samples; j++,data_index++) ch[ich].data.push_back(0);
	continue;
      }
      ch[ich].data.push_back(rawbuff[bp] & 0x00003FFF);
      ch[ich].data.push_back((rawbuff[bp++] & 0x3FFF0000)>>16);
    }
    
    ch[ich].Analyze();
  }
};

