// timing shift for single histogram
void timing_shift(std::string file1, std::string file2){
  const char taget[] = "waveform_0_00";
  const int POS_OFFSET = 1000;
  const int NEG_OFFSET = 15000;

  TFile *f1 = TFile::Open(file1.c_str());
  TTree *tr1 = (TTree*)f1->Get("tree");
  for(int i = 0; i != 10; ++i){
    tr1->GetEntry(i);
    baseline1 += base1[0][0];
  }



  TFile *f2 = TFile::Open(file2.c_str());

  TTree *tr2 = (TTree*)f2->Get("tree");




  TH2D* hist1 = (TH2D*)f1->Get(target);
  TH2D* hist2 = (TH2D*)f2->Get(target);
  hist1->Draw("colz");
  hist2->Draw("colz");
  TCanvas *c = new TCanvas();
  hist1->GetZaxis()->SetRangeUser(100, 1e04);
  TH2D *hist1_gated = (TH2D*)hist1->Clone();
  double baseline1 = 0, baseline2 = 0;
  int *base1 = NULL, *base2 = NULL;
  tr1->SetBranchAddress("baseline",base1);
  tr2->SetBranchAddress("baseline",base2);
  baseline1/=10.;
  baseline2/=10.;

  hist2->GetZaxis()->SetRangeUser(100, 1e04);
  TH2D *hist2_gated = (TH2D*)hist2->Clone();
}
