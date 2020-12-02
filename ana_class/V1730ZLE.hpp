#ifndef _V1730ZLE_HPP_
#define _V1730ZLE_HPP_

#include <vector>
#include <TObject.h>
#include "ChEvent.hpp"
#include "V1730ZLEHeader.hpp"

class TV1730ZLE : public TObject{
private:
public:
  TV1730ZLE();
  uint64_t trigger_time_tag;
  int event_counter;
  std::bitset<16> channel_mask;
  
  TV1730ZLEHeader header;
  std::vector<TChEvent> ch;
  //TChEvent ch[16];

  void Clear();
  void Analyze(uint32_t *rawbuff);
  
  ClassDef(TV1730ZLE,1);
};

#endif
