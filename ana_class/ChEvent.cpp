#include "ChEvent.hpp"
#include <iostream>

ClassImp(TChEvent);

TChEvent::TChEvent(){
};

void TChEvent::Analyze(){
  if(data[0]>baseline) return;
  for(int i=0;i<data.size();i++){
    Clk.push_back(i);
    if(data[i]==0) continue;
    //waveform[board][ch]->Fill(i,ch[ich].data[i],1.);
    if(adc<abs(data[i]-baseline)){
      adc=abs(data[i]-baseline);
      //energy=(ADCtoE[0]+ADCtoE[1]*adc);
      energy=adc;
      //PeakClk[board][ch]=i;
    }
  }
  /*
    for(int i=0;i<RECORD_LENGTH;i++){
    if(data[board][ch][i]==0) continue;
    if(0.15*ADC[board][ch]<abs(data[board][ch][i]-baseline[board][ch])){
    RiseEdge[board][ch]=i;
    break;
    }
    }
  */ 
};

void TChEvent::Clear(){
  baseline=-1;
  adc=-1;
  energy=-1;
  data.clear();
  Clk.clear();
  ch_id=-1;
};
