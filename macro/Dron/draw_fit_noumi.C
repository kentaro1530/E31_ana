#include "macro/init.C"

void draw_fit_noumi(){
  init();

  const double kpThre=(kpMass+pMass);
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);
  TCanvas *c1=new TCanvas("c1", "c1");
  c1-> Divide(1, 2, 0);

  c1-> cd(1);
  TFile *f=new TFile("~/spectra.root");
  TGraphErrors *gra_I0=(TGraphErrors*)f-> Get("I0_CS");
  TGraphErrors *gra_pi0S0=(TGraphErrors*)f-> Get("pi0S0_CS");
  TGraph* fit=(TGraph*)f-> Get("specByNoumi_woRes");
  TGraph* fit_wReso=(TGraph*)f-> Get("specByNoumi_wRes");
  set(gra_pi0S0, kBlue);
  set(gra_I0);
  set(fit, kRed);
  set(fit_wReso, kRed);
  fit-> SetLineStyle(9);

  gra_I0-> Draw("AP");
  gra_pi0S0-> Draw("P");
  fit-> Draw("L");
  fit_wReso-> Draw("L");
  line.DrawLine(kMass+NMass, 0, kMass+NMass, 20);

  c1-> cd(2);
  TFile *f2=new TFile("scat_test.root");
  TGraph *KN_KN_re=set((TGraph*)f2->Get("KN_KN_re"));
  TGraph *KN_KN_im=set((TGraph*)f2->Get("KN_KN_im"), kRed);
  KN_KN_re-> GetYaxis()-> SetRangeUser(-3, 3);
  KN_KN_re->GetYaxis()->SetTitle("T^{I=0}_{#bar{K}N #rightarrow #bar{K}N} [GeV/c^{2}]");
  KN_KN_re->Draw("AL");
  KN_KN_im->Draw("L");

  gPad-> SetGrid();
  line.SetLineWidth(3);
  line.DrawLine(kMass+NMass, -3, kMass+NMass, 3);

  line.SetLineColor(kBlue);
  line.DrawLine(1.4177, -3, 1.4177, 3);

  double re=-0.323*1.9733;
  double re_err=-0.074*1.9733;

  double im=0.407*1.9733;
  double im_err=-0.308*1.9733;
  TBox box;
  line.SetLineColor(kBlack);
  line.DrawLine(kpMass+pMass, re, k0Mass+nMass, re);
  line.SetLineColor(kRed);
  line.DrawLine(kpMass+pMass, im, k0Mass+nMass, im);
  box.SetLineWidth(3);
  box.SetFillStyle(0);
  box.DrawBox(kpMass+pMass, re-re_err, k0Mass+nMass, re+re_err);
  box.SetLineColor(kRed);
  box.DrawBox(kpMass+pMass, im-im_err, k0Mass+nMass, im+im_err);

  c1-> Print("pic/Dron/fit_noumi.eps");
  c1-> Print("pic/Dron/fit_noumi.png");
}

TGraph* set(TGraph* gra, int colorID=kBlack){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1.350, 1.500);
  gra-> GetYaxis()-> SetRangeUser(0, 20.);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();

  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
  return gra;
}

TGraphErrors* set(TGraphErrors* gra, int colorID=kBlack){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1.350, 1.500);
  gra-> GetYaxis()-> SetRangeUser(0, 20.);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();

  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
  return gra;
}
