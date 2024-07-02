#include "macro/init.C"

void draw_fit_scat_amp_I1(){
  init();
  TFile *f=new TFile("~/spectra_fit_scat_amp_I1.root");

  TGraphErrors *data=(TGraphErrors*)f->Get("pimS0_CS0");
  TGraph *fit=(TGraph*)f-> Get("fit_pimS0");
  TGraph *fit_wReso=(TGraph*)f-> Get("fit_pimS0_wReso");
  TGraph *gra_T2=scale((TGraph*)f-> Get("gra_I1_KN_piS_abs2"), 0.1);
  TGraph *responseFunc=scale((TGraph*)f-> Get("responseFunc"), 0.05);
  data-> GetYaxis()-> SetRangeUser(0, 8);
  setColor(data, 5);
  fit-> SetLineColor(kBlue);
  fit_wReso-> SetLineColor(kBlue);
  data-> SetLineWidth(3);
  fit-> SetLineStyle(9);
  fit-> SetLineWidth(2);
  fit_wReso-> SetLineWidth(2);
  gra_T2-> SetLineWidth(2);
  gra_T2-> SetLineColor(kRed);
  responseFunc-> SetLineWidth(2);
  responseFunc-> SetLineStyle(9);

  data-> Draw("AP");
  fit-> Draw("L");
  fit_wReso-> Draw("L");
  gra_T2-> Draw("L");
  responseFunc-> Draw("L");
  data-> Draw("P");

  c1-> Print("pic/Dron/fit_scat_amp_I1.eps");
  c1-> Print("pic/Dron/fit_scat_amp_I1.png");
}

void setColor(TGraphErrors *gra, int colorID){
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
}

TGraph* scale(TGraph* gra){
  std::vector<double> x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra->GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(tmpy);
  }
  return new TGraph(x.size(), &x[0], &y0);
}
