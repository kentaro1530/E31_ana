#include "../init.C"
#include "../make_gra.C"

TGraphErrors* setOpt(TGraphErrors* gra);
TGraph* setOpt(TGraph* gra);

void draw_noumi(){
  init();
  const double L1405_pole=1.4177;
  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  
  gStyle-> SetPadTopMargin(0.1);
  gStyle-> SetPadBottomMargin(0.01);
  TCanvas *c1=new TCanvas("c1", "c1", 600, 300);

  c1-> cd(1);
  TFile *f=new TFile("~/spectra.root");
  TGraphErrors* pi0S0_CS=(TGraphErrors*)f->Get("pi0S0_CS");
  TGraphErrors* I0=setOpt(make_data_I0());
  pi0S0_CS-> SetLineWidth(2);
  pi0S0_CS-> GetYaxis()-> SetRangeUser(0, 15);

  I0-> Draw("AP");
  pi0S0_CS-> Draw("P");
  pi0S0_CS-> SetLineColor(kBlue);

  TGraph *calc=(TGraph*)f->Get("specByNoumi_wRes");
  calc-> SetLineColor(kRed);
  calc-> SetLineWidth(3);
  calc-> Draw("L");

  TGraph *calc_wo=(TGraph*)f->Get("specByNoumi_woRes");
  calc_wo-> SetLineColor(kRed);
  calc_wo-> SetLineWidth(2);
  calc_wo-> SetLineStyle(7);
  calc_wo-> Draw("L");

  TGraph *resF=(TGraph*)f->Get("responseFunc");
  resF=scale(resF, 0.2);
  resF-> SetLineWidth(2);
  resF-> SetLineStyle(7);
  resF-> Draw("L");
  line.DrawLine(kMass+NMass, 0, kMass+NMass, 16.5);
  TLegend *leg=new TLegend(0.2, 0.35, 0.5, 0.9);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(I0, "Calc from Charge Spectra", "lep");
  leg-> AddEntry(pi0S0_CS, "#pi^{0}#Sigma^{0} Spectrum", "lep");
  leg-> AddEntry(calc, "Fit result w/ Res", "l");
  leg-> AddEntry(calc_wo, "Fit result w/o Res", "l");
  leg-> AddEntry(resF, "Response Func", "l");
  leg-> Draw();
  c1-> Print("pic/Dron/E31_result_up.png");
  c1-> Print("pic/Dron/E31_result_up.eps");
  
  gStyle-> SetPadTopMargin(0.01);
  gStyle-> SetPadBottomMargin(0.15);
  TCanvas *c2=new TCanvas("c2", "c2", 600, 300);
  TGraph *gra_re=setOpt((TGraph*)f->Get("fit_noumi_KN_KN_re"));
  TGraph *gra_im=setOpt((TGraph*)f->Get("fit_noumi_KN_KN_im"));
  gra_im-> SetLineColor(kRed);
  gra_re-> Draw("AL");
  gra_im-> Draw("L");
  line.DrawLine(kMass+NMass, -1.5, kMass+NMass, 3);
  line.SetLineColor(kBlue);
  line.DrawLine(L1405_pole, -1.5, L1405_pole, 3);

  TLegend *leg2=new TLegend(0.6, 0.7, 0.9, 0.9);
  leg2-> SetBorderSize(0);
  leg2-> SetFillStyle(0);
  leg2-> AddEntry(gra_re, "Real", "l");
  leg2-> AddEntry(gra_im, "Imag", "l");
  leg2-> Draw();
  c2-> Print("pic/Dron/E31_result_down.png");
  c2-> Print("pic/Dron/E31_result_down.eps");
}

TGraphErrors* setOpt(TGraphErrors* gra){
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

TGraph* setOpt(TGraph* gra){
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra-> GetYaxis()-> SetRangeUser(-1.5, 3);
  
  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi#Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("T^{I=0}_{#bar{K}N #rightarrow #bar{K}N} [fm]");

  gra-> SetLineWidth(3);
  gra-> SetTitle("");

  return gra;
}
