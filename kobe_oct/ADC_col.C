#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include <TCanvas.h>
#include <TEventList.h>
#include <TH1F.h>
#include <TROOT.h>
#include <TTree.h>
#include <TFile.h>

#define LENGTH 4096
#define noise_flag 1
#define baseline_flag 0
#define rise_flag 1
#define adc_flag 1

int side=0;
int ch=0;
//int move_ave(UShort_t wave[],int length,int ave_n);
//int trapezoidal(UShort_t wave[],int length,int L,int G);

int ADC_col(){ 
  for(side=0; side<2; side++){
    for(ch=0; ch<16; ch++){
      if(side==1 && ch>7) continue;
      cout << endl;
      cout << "SIDE: " << side << ", CH: " << ch << endl;
      auto tree = (TTree*)gROOT->FindObject("tree");
      tree->Draw(">>elist",Form("ADC[%d][%d]>0",side,ch));
      TEventList *elist= (TEventList*)gROOT->FindObject("elist");
      TH1F* h_adc[2][16];
      TH1F* h_rise[2][16];
  
      int N=elist->GetN();
      cout << "all event :" << N << endl;
  
      int baseline[2][16]={};
      int ADC[2][16]={};
      UShort_t data[2][16][4096]={};
      tree->SetBranchAddress("baseline",baseline);
      tree->SetBranchAddress("ADC",ADC);
      tree->SetBranchAddress("data",data);

      char hnum[100];
      int count=0;
      double baseline_col[100000]={};
      double ADC_col[100000]={};
      double rise_i[100000]={};
      double rise_f[100000]={};
      double risetime[100000]={};

      
      for(int i=0;i<N;i++){
	if(i % 100 == 0){
	  cout << "\rEvent:" << i;
	  fflush(stdout);
	}
      	{
	  baseline_col[i]=-1;
	  ADC_col[i]=-1;
	  rise_i[i]=-1;
	  rise_f[i]=-1;
	  risetime[i]=-1;
	}
	tree->GetEntry(elist->GetEntry(i));

	//baseline_col[i]=baseline[side][ch];
	for(int j=450;j<550;j++){
	  baseline_col[i]+=data[side][ch][j]/100;
	}

	//move_ave(data[side][ch],LENGTH,3);
	//trapezoidal(data[side][ch],LENGTH,100,50);

	for(int j=400;j<1100;j++){
	  if(ADC_col[i]<abs(data[side][ch][j]-baseline_col[i])){
	    ADC_col[i]=abs(data[side][ch][j]-baseline_col[i]);
	  }
	}

	for(int j=400;j<1100;j++){
	  if(ADC_col[i]*0.05 > abs(data[side][ch][j]-baseline_col[i])){
	    rise_i[i]=j;
	  }
	  if(ADC_col[i]*0.80 < abs(data[side][ch][j]-baseline_col[i])){
	    rise_f[i]=j;
	    break;
	  }
	}
	if(ADC_col[i]>7000) continue;
	if(ADC_col[i]<3000) continue;
	risetime[i]=rise_f[i]-rise_i[i];
      }
	
	

      
      //---------------adc_col plot---------------------// 
      if(adc_flag==1){
	sprintf(hnum,"adc_%d_%02d",side,ch);
	h_adc[side][ch] = new TH1F(hnum,hnum,400,-1000,9000);
	for(int i=0;i<N;i++){
	  h_adc[side][ch]->Fill(ADC_col[i]);
	}
	//h_adc->Draw();
      }

      //---------------risetime plot---------------------// 
      if(rise_flag==1){
	sprintf(hnum,"rise_%d_%02d",side,ch);
	h_rise[side][ch] = new TH1F(hnum,hnum,160,0,160);
	for(int i=0;i<N;i++){
	  h_rise[side][ch]->Fill(risetime[i]);
	}
	//h_adc->Draw();
      }
    }
  }
  
  return 0;
}

/*
//-------------------filter-----------------------//
int move_ave(UShort_t wave[],int length,int ave_n){
  for(int j=0; j<LENGTH-ave_n; j++){
	  int tmp=0;
	  for(int k=0; k<ave_n; k++){
	    tmp+=wave[j+k]/(ave_n);
	  }
	  wave[j]=tmp;
  }
  return 0;
}

int trapezoidal(UShort_t wave[],int length,int L,int G){
  for(int j=0; j<LENGTH-(2*L+G); j++){
    int tmp=0;
    for(int k=0;k<L;k++){
      tmp+=wave[j+k]*(-1/L);
    }
    for(int k=0;k<G;k++){
      tmp+=wave[j+k]*0;
    }
    for(int k=0;k<L;k++){
      tmp+=wave[j+k]*(1/L);
    }
  }
  return 0;
}
*/
