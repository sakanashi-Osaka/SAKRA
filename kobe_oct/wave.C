#define CH 10
#define SIDE 0
#define RUN_NUMBER 10
#define LENGTH 4096


#define noise_flag 0
#define baseline_flag 0
#define rise_flag 0
#define adc_flag 1

int ADC_col(){

  tree->Draw(">>elist",Form("ADC[%d][%d]>0",SIDE,CH));
  TEventList *elist= (TEventList*)gROOT->FindObject("elist");

  int N=elist->GetN();
  cout << "all event :" << N << endl;

  int baseline[2][16]={};
  int ADC[2][16]={};
  UShort_t data[2][16][4096]={};
  tree->SetBranchAddress("baseline",baseline);
  tree->SetBranchAddress("ADC",ADC);
  tree->SetBranchAddress("data",data);

  int count=0;
  double rise_time[20000]={};
  double rise_i[20000]={};
  double rise_f[20000]={};
  double base[20000]={};
  double baseline_col[20000]={};
  double adc[20000]={};
  double max[20000]={};
  double ADC_col[20000]={};
  
  for(int i=0;i<N;i++){

    {
    rise_time[i]=0;
    rise_i[i]=0;
    rise_f[i]=0;
    baseline_col[i]=0;
    max[i]=0;
    ADC_col[i]=0;
    }
    
    tree->GetEntry(elist->GetEntry(i));

    int ave_n=30;
    for(int j=0; j<LENGTH-ave_n; j++){
      int tmp=0;
      for(int k=0; k<ave_n; k++){
	tmp+=data[SIDE][CH][j+k]/ave_n;
      }
      data[SIDE][CH][j]=tmp;
    }
    

    if(4000<ADC[SIDE][CH] && ADC[SIDE][CH]<10000){      
      base[i]=baseline[SIDE][CH];
      for(int j=450;j<550;j++){
	baseline_col[i]+=data[SIDE][CH][j]/100;
      }

      int tmp=0;
      for(int j=400;j<3000;j++){
        if(max[i]<abs(data[SIDE][CH][j]-baseline_col[i])){
	  max[i]=abs(data[SIDE][CH][j]-baseline_col[i]);
	  tmp=j;
	}
      }      
      for(int j=0;j<30;j++){
	ADC_col[i]+=abs(data[SIDE][CH][tmp+j-15]-baseline_col[i])/30;
      }
      
      adc[i]=ADC[SIDE][CH];
      for(int j=400;j<1000;j++){
	if(abs((double)data[SIDE][CH][j]-baseline_col[i]) < 0.05*abs(ADC_col[i])){
          rise_i[i]=j;
	}
      }
      for(int j=400;j<1000;j++){
        if(abs((double)data[SIDE][CH][j]-baseline_col[i]) < 0.70*abs(ADC_col[i])){
          rise_f[i]=j;
	}
      }

      rise_time[i]=rise_f[i]-rise_i[i];

      //cout << "max:"<< max[i] <<endl;
      //cout << "baseline_col:"<< baseline_col[i] <<endl;
      //cout << "rise_i:"<< rise_i[i] <<endl;
      //cout << "rise_f:"<< rise_f[i] <<endl;
      //cout << abs((double)data[SIDE][CH][1000]-baseline_col[i]) << endl;
      //cout << "" << abs((double)ADC_col[i]-baseline_col[i]) << endl;
      
      if(rise_i[i]>10){
	count++;
      }
    }
  }
  
  double Clk[10000]={};
  cout << "count " << ":" << count << endl;
  for(int j=0;j<10000;j++){
    Clk[j]=j;
  }


  
  if(noise_flag==1){
    TH1F *h1 = new TH1F("h1","h1",200,-200,200);
    for(int i=0;i<N;i++){
      if(rise_time[i]>10){
	for(int j=450;j<500;j++){
	  int tmp=0;
	  tmp=data[SIDE][CH][j]-baseline_col[i];
	  h1->Fill(tmp);
	}
      }
    }
    //h1->Draw();
  }

  
  //---------------baseline plot---------------------// 
  if(baseline_flag==1){
    TH1F *h_base = new TH1F("h_base","h_base",50,14000,16500);
    for(int i=0;i<N;i++){
      h_base->Fill(baseline_col[i]);
    }
    h_base->Draw();
  }
  //---------------rise_time plot---------------------// 
  if(rise_flag==1){
    TH1F *h1 = new TH1F("h1","h1",90,10,100);
    for(int i=0;i<N;i++){
      h1->Fill(rise_time[i]);
    }
    h1->Draw();
  }

  //---------------adc_col plot---------------------// 
  if(adc_flag==1){
    TH1F *h_adc[CH] = new TH1F("h_adc","h_adc",400,1000,9000);
    for(int i=0;i<N;i++){
      h_adc[CH]->Fill(ADC_col[i]);
    }
    h_adc[CH]->Draw();
  }
  
  
  return 0;
}
