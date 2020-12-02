{
  tree->Draw("ADC[2][15]>>h(300,1000,4000)","ADC[2][15]>0");
  TF1 fit("fit","gaus(0)+gaus(3)+gaus(6)",1000,4000);
  fit.SetParLimits(0, 0, 1000);
  fit.SetParLimits(3, 0, 1000);
  fit.SetParLimits(6, 0, 1000);  
  fit.SetParLimits(1,1800,2500);
  fit.SetParLimits(4,2500,3500);
  fit.SetParLimits(7,2500,3500);
  fit.SetParLimits(2, 1, 100);
  fit.SetParLimits(5, 1, 100);
  fit.SetParLimits(8, 1, 100);
  h->Fit(&fit,"","",1000,4000);
  std::vector<std::vector<double>> v = {{fit.GetParameter(1), fit.GetParameter(2)}, {fit.GetParameter(4), fit.GetParameter(5)}, {fit.GetParameter(7), fit.GetParameter(8)}};
  std::sort(v.begin(),v.end(),[](const vector<double> &alpha, const vector<double> &beta){return alpha[0] < beta[0];});
  std::cout << std::endl << v[0][0] << " " << v[1][0] << " " <<v[2][0] << std::endl;std::cout << v[0][1] << " " << v[1][1] << " " << v[2][1] << std::endl;
}
