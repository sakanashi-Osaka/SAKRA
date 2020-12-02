#ifndef _CHEVENT_HPP_
#define _CHEVENT_HPP_

#include <vector>
#include <TObject.h>

const int RECORD_LENGTH=4096;

class TChEvent : public TObject{
public:
  TChEvent();
  int baseline;
  std::vector<uint16_t> data;
  std::vector<uint16_t> Clk;
  int adc;
  double energy;
  int ch_id;

  void Analyze();
  void Clear();

  int GetData(){return data.size();};
  
  ClassDef(TChEvent,1);
};

#endif
