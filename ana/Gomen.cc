void Gomen(){
  TCanvas *c = new TCanvas();
  TText *text[3];
  text[0] = new TText(0.2,0.5,"amari");
  text[1] = new TText(0.2,0.5,"susumanakutegomenne");
  text[2] = new TText(0.2,0.5,"gomenne");
  //  for(int i = 0; i != 3; ++i){
  //  }
  TImage *img = TImage::Open("/home/quser/Desktop/pien.jpg");
  img->Draw();
  
  while(true){
    double x = gRandom->Uniform();
    double y = gRandom->Uniform();
    int col = gRandom->Uniform() * 256;
    text[0]->SetTextColor(col);
    text[0]->DrawTextNDC(x, y, "Gomennne!!!!");

    c->Update();
    gSystem->Sleep(1000000);
  }

}
