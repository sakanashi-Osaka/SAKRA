#include <stdio.h>
#include <string>

#define CH 1

TGraph *g_proton;
TGraph *g_deuteron;
TGraph *g_alpha_Gd;

int wave_ave(){

  TFile *f1 = new TFile("./root/beam_0002.root");
  TTree *tr1 = (TTree*)f1->Get("tree");
   
  tr1->Draw(">>elist",Form("ADC[0][%d]>0",CH));
  TEventList *elist= (TEventList*)gROOT->FindObject("elist");

  int N=elist->GetN();
  cout << "all event :" << N << endl;

  int baseline[2][16]={};
  int ADC[2][16]={};
  UShort_t data[2][16][4096]={};
  tr1->SetBranchAddress("baseline",baseline);
  tr1->SetBranchAddress("ADC",ADC);
  tr1->SetBranchAddress("data",data);

  int count=0;
  double sum[4096]={};
  double ave[4096]={};

  for(int i=0;i<N;i++){
    tr1->GetEntry(elist->GetEntry(i));
    int temp=0;
    if(3000<ADC[0][CH] && ADC[0][CH]<5000){
      count++;
      for(int j=0;j<4096;j++){
	//sum[j]+=((int)data[0][CH][j]-baseline[0][CH]);
	sum[j]+=((int)data[0][CH][j]-baseline[0][CH])/(double)ADC[0][CH];
      }
    }
  }

  double Clk[4096]={};
  cout << "count " << ":" << count << endl;
  for(int j=0;j<4096;j++){
    Clk[j]=j;
    ave[j]=(double)sum[j]/count;
  }
  g_proton=new TGraph(4096,Clk,ave);
  g_proton->SetMarkerStyle(1);
  g_proton->SetMarkerColor(4);
  g_proton->GetYaxis()->SetRangeUser(0,1);
  g_proton->GetXaxis()->SetRangeUser(400,2000);

  g_proton->Draw("AP");


  TFile *f2 = new TFile("./root/beam_0075.root");
  TTree *tr2 = (TTree*)f2->Get("tree");
   
  tr2->Draw(">>elist2",Form("ADC[0][%d]>0",CH));
  TEventList *elist2= (TEventList*)gROOT->FindObject("elist2");

  int N2=elist2->GetN();
  cout << "all event :" << N2 << endl;

  tr1->SetBranchAddress("baseline",baseline);
  tr1->SetBranchAddress("ADC",ADC);
  tr1->SetBranchAddress("data",data);

  count=0;
  for(int j=0;j<4096;j++){
    sum[j]=0;
    ave[j]=0;
    Clk[j]=0;
  }
  
  for(int i=0;i<N2;i++){
    tr2->GetEntry(elist->GetEntry(i));
    int temp=0;
    if(3000<ADC[0][CH] && ADC[0][CH]<5000){
      count++;
      for(int j=0;j<4096;j++){
	sum[j]+=((int)data[0][CH][j]-baseline[0][CH])/(double)ADC[0][CH];
      }
    }
  }

  cout << "count " << ":" << count << endl;
  for(int j=0;j<4096;j++){
    Clk[j]=j;
    ave[j]=(double)sum[j]/count;
  }
  g_deuteron=new TGraph(4096,Clk,ave);
  g_deuteron->SetMarkerStyle(1);
  g_deuteron->SetMarkerColor(4);
  g_deuteron->GetYaxis()->SetRangeUser(0,1);
  g_deuteron->GetXaxis()->SetRangeUser(400,1000);

  g_deuteron->Draw("same");

  return 0;
}
