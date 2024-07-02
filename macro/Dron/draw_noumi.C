#include "macro/init.C"
#include "macro/make_gra.C"

void draw_noumi(){
  init();

  TFile *f=new TFile("~/spectra.root");
  TGraphErrors* pi0S0=(TGraphErrors*)f->Get("pi0S0_CS");
  TGraphErrors* I0=set(make_data_I0());
  pi0S0_CS-> GetYaxis()-> SetRangeUser(0, 15);

  I0-> Draw("AP");
  pi0S0_CS-> Draw("P");
  pi0S0_CS-> SetLineColor(kBlue);

  TGraph *calc=(TGraph*)f->Get("specByNoumi_wRes");
  calc-> SetLineColor(kRed);
  calc-> SetLineWidth(3);
  calc-> Draw("L");

  TGraph *resF=(TGraph*)f->Get("responseFunc");
  resF=scale(resF, 0.2);
  resF-> SetLineWidth(2);
  resF-> SetLineColor(kRed);
  resF-> SetLineStyle(7);
  resF-> Draw("L");

  c1-> Print("pic/Dron/E31_result.png");
  c1-> Print("pic/Dron/E31_result.eps");
}

TGraphErrors* set(TGraphErrors* gra){
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);

  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");

  gra-> SetLineWidth(3);
  gra-> SetTitle("");

  return gra;
}
