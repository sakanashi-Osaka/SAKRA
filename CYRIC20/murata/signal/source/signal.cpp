#include <iostream>
#include <cmath>
#include <TTree.h>
#include <TFile.h>
#include <TF1.h>
#include <TH1.h>
#include <TGraph.h>

class  PreAmpSignalModel {
public:

  int GetNumberOfParameters()const{return 4;}
  //par0 baseline
  //par1 input height
  //par2 t_0 (input begin) > 0
  //par3 T (duration of input) > 0
  double operator() (double *x, double *p) {
    double baseline = p[0];
    double inputHeight = p[1];
    double t0 = p[2];
    double T = p[3];

    double t = x[0];
    if(t < t0)
      return baseline;
    else{
      double t_tmp = t0;
      double signal = baseline;
      while(t_tmp < t){
	double input = 0;
	if(t_tmp < t0 + T){
	  input = inputHeight;
	}
	signal += input;
	signal = (signal - baseline) * std::exp(-1/fDecayTime) + baseline;
	t_tmp += 1.;
      }
      return signal;
    }
  }
  void SetDecayTime(double _fDecayTime){fDecayTime = _fDecayTime;  };
  double GetDecayTime() const{ return fDecayTime;  };

private:
  double fDecayTime;
};





int main(){
  TFile fOut("test.root", "recreate");

  PreAmpSignalModel amp;
  amp.SetDecayTime(10000);
  TF1 signal_model("signal_model", amp, 0, 4096, amp.GetNumberOfParameters());
  signal_model.SetParameters(15000, -2000, 500, 10);

  TGraph g(4096);
  for(int i = 0; i < 4096; ++i){
    g.SetPoint(i, i, signal_model.Eval(i));
  }
  g.SetName("g");
  g.Write();
  

  
  // double baseline = 100;
  // int pulse_begin = 10;
  // int pulse_end = 50;
  // int pulse_height = 10;

  // double signal = baseline;
  // double decay_time = 1000;

  // double input = baseline;
  // for(int i = 0; i < 100; ++i){

  //   if(pulse_begin < i && i < pulse_end){
  //     input = pulse_height;
  //   }
  //   else{
  //     input = 0;
  //   }
  //   signal += input;
  //   signal = (signal - baseline) * std::exp(-1/decay_time) + baseline;
  //   std::cout << i << " " << input << " " << signal << std::endl;;
    
  // }

  return 0;
}
