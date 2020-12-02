
void Fit_3alpha(){
  int xbin = adc_0_00->GetNbinsX();
  int sum = adc_0_00->Integral(1,xbin);
  int count[xbin];
  for(int i=0; i<xbin; i++) count[i] = adc_0_00->GetBinContent(i+1);
  double x=0;
  for(int i=0; i<xbin; i++) x+=(i+1)*count[i]/sum;

  cout<< "Gd:3.1MeV" << endl;
  int peak_Gd=0;
  int tmp=0;
  for(int i=0;i<x;i++){
    if(tmp<count[i]){
      tmp=count[i];
      peak_Gd=i;
    }
  }
  adc_0_00->Fit("gaus","","",peak_Gd-20,peak_Gd+20);
}
