#define CH 7
TGraph *g_alpha[3];

int alpha_ave(){
  tree->Draw(">>elist",Form("ADC[0][%d]>0",CH));
  TEventList *elist= (TEventList*)gROOT->FindObject("elist");
  
  int N=elist->GetN();
  cout << "all event :" << N << endl;
  
  int baseline[2][16]={};
  int ADC[2][16]={};
  UShort_t data[2][16][4096]={};
  tree->SetBranchAddress("baseline",baseline);
  tree->SetBranchAddress("ADC",ADC);
  tree->SetBranchAddress("data",data);
  
  int count[3]={};
  double sum[3][4096]={};
  double ave[3][4096]={};

  for(int i=0;i<N;i++){
    tree->GetEntry(elist->GetEntry(i));
    int temp[3]={};
    if(4000<ADC[0][CH] && ADC[0][CH]<5000){
      temp[0]=1;
    }
    else if(7800<ADC[0][CH] && ADC[0][CH]<8200){
      temp[1]=1;
    }
    else if(8200<ADC[0][CH] && ADC[0][CH]<8800){
      temp[2]=1;
    }
    for(int k=0;k<3;k++){
      if(temp[k]==1){
	count[k]++;
	for(int j=0;j<4096;j++){
	  sum[k][j]+=((int)data[0][CH][j]-baseline[0][CH]);
	  //sum[k][j]+=((int)data[0][CH][j]-baseline[0][CH])/(double)ADC[0][CH];
	}
      }
    }
  }

  double Clk[4096]={};
  for(int i=0;i<3;i++){
    cout << "count " << i << ":" << count[i] << endl;
    if(count[i]==0) count[i]=1;
    for(int j=0;j<4096;j++){
      Clk[j]=j;
      ave[i][j]=(double)sum[i][j]/count[i];
    }
    g_alpha[i]=new TGraph(4096,Clk,ave[i]);
    g_alpha[i]->SetMarkerStyle(1);
    g_alpha[i]->SetMarkerColor(2);
    g_alpha[i]->GetYaxis()->SetRangeUser(0,9000);
    //g_alpha[i]->GetYaxis()->SetRangeUser(0,1);
    g_alpha[i]->GetXaxis()->SetRangeUser(400,1000);
  }

  g_alpha[0]->SetTitle("3-alpha Gd");
  g_alpha[1]->SetTitle("3-alpha Am");
  g_alpha[2]->SetTitle("3-alpha Cm");

  g_alpha[0]->Draw("AP");
  g_alpha[1]->Draw("P");
  g_alpha[2]->Draw("P");

  return 0;
}
