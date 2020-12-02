#define LENGTH 4096

TGraph* wave_ave[2][16];
int side=0;
int ch=0;

int wave_ave(){ 
  for(side=0; side<1; side++){
    for(ch=0; ch<1; ch++){
      if(side==1 && ch>7) continue;
      cout << endl;
      cout << "SIDE: " << side << ", CH: " << ch << endl;
      tree->Draw(">>elist",Form("ADC[%d][%d]>0",side,ch));
      TEventList *elist= (TEventList*)gROOT->FindObject("elist");
  
      int N=elist->GetN();
      cout << "all event :" << N << endl;
  
      int baseline[2][16]={};
      int ADC[2][16]={};
      UShort_t data[2][16][4096]={};
      tree->SetBranchAddress("baseline",baseline);
      tree->SetBranchAddress("ADC",ADC);
      tree->SetBranchAddress("data",data);

      char hnum[100];
      double baseline_col[20000]={};
      double ADC_col[20000]={};
      
      for(int i=0;i<N;i++){

	if(i % 100 == 0){
	  cout << "\rEvent:" << i;
	  fflush(stdout);
	}

	double wave_ave[LENGTH];
	for(int j=0; j<LENGTH; j++) wave[j]=0;
      	{
	  baseline_col[i]=0;
	  ADC_col[i]=0;
	}
		
	tree->GetEntry(elist->GetEntry(i));

	for(int j=450;j<550;j++){
	  baseline_col[i]+=data[side][ch][j]/100;
	}

	//move_ave(data[side][ch],LENGTH,5);
	//trapezoidal(data[side][ch],LENGTH,100,50);

	for(int j=400;j<3000;j++){
	  if(ADC_col[i]<abs(data[side][ch][j]-baseline_col[i])){
	    ADC_col[i]=abs(data[side][ch][j]-baseline_col[i]);
	  }
	}      

	count++;
      }
      
    }
  }
  
  return 0;
}

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
