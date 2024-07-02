#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_decomposed(){
  init();

  TFile *f=new TFile(infileroot);
  TGraph *gra_pimSp_A=(TGraph*)f->Get("pimSp_modelA");
  TGraph *gra_pimSp_A_conv=(TGraph*)f->Get("pimSp_modelA_conv");
  TGraph *gra_pimSp_B=(TGraph*)f->Get("pimSp_modelB");
  TGraph *gra_pimSp_B_conv=(TGraph*)f->Get("pimSp_modelB_conv");
  TGraph *interfer_A=(TGraph*)f->Get("interfer_A");
  TGraph *interfer_B=(TGraph*)f->Get("interfer_B");
  TGraphErrors *gra_pimSp_data=(TGraphErrors*)f->Get("pimSp_CS2");

  TGraph *gra_pipSm_A=(TGraph*)f->Get("pipSm_modelA");
  TGraph *gra_pipSm_A_conv=(TGraph*)f->Get("pipSm_modelA_conv");
  TGraph *gra_pipSm_B=(TGraph*)f->Get("pipSm_modelB");
  TGraph *gra_pipSm_B_conv=(TGraph*)f->Get("pipSm_modelB_conv");
  TGraphErrors *gra_pipSm_data=(TGraphErrors*)f->Get("pipSm_CS2");

  TGraph *gra_pimS0_A=(TGraph*)f->Get("pimS0_modelA");
  TGraph *gra_pimS0_A_conv=(TGraph*)f->Get("pimS0_modelA_conv");
  TGraph *gra_pimS0_B=(TGraph*)f->Get("pimS0_modelB");
  TGraph *gra_pimS0_B_conv=(TGraph*)f->Get("pimS0_modelB_conv");
  TGraphErrors *gra_pimS0_data=(TGraphErrors*)f->Get("pimS0_CS1");

  gra_pimSp_A-> SetLineStyle(9);
  gra_pimSp_A-> SetLineColor(kRed);
  gra_pimSp_A_conv-> SetLineColor(kRed);
  gra_pimSp_B-> SetLineStyle(9);
  gra_pimSp_B-> SetLineColor(kRed);
  gra_pimSp_B_conv-> SetLineColor(kRed);
  gra_pimSp_data-> SetLineColor(kRed);
  gra_pimSp_A-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimSp_A-> Draw("AL");
  gra_pimSp_A_conv-> Draw("L");
  gra_pimSp_data-> Draw("P");
  c1-> Print("pic/discussion/pimSp_A.png");
  c1-> Print("pic/discussion/pimSp_A.eps");

  gra_pimSp_B-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimSp_B-> Draw("AL");
  gra_pimSp_B_conv-> Draw("L");
  gra_pimSp_data-> Draw("P");
  c1-> Print("pic/discussion/pimSp_B.png");
  c1-> Print("pic/discussion/pimSp_B.eps");

  gra_pipSm_A-> SetLineStyle(9);
  gra_pipSm_A-> SetLineColor(kBlue);
  gra_pipSm_A_conv-> SetLineColor(kBlue);
  gra_pipSm_B-> SetLineStyle(9);
  gra_pipSm_B-> SetLineColor(kBlue);
  gra_pipSm_B_conv-> SetLineColor(kBlue);
  gra_pipSm_data-> SetLineColor(kBlue);
  gra_pipSm_A-> GetYaxis()-> SetRangeUser(0., 15.);
  gra_pipSm_A-> Draw("AL");
  gra_pipSm_A_conv-> Draw("L");
  gra_pipSm_data-> Draw("P");
  c1-> Print("pic/discussion/pipSm_A.png");
  c1-> Print("pic/discussion/pipSm_A.eps");

  gra_pipSm_B-> GetYaxis()-> SetRangeUser(0., 15.);
  gra_pipSm_B-> Draw("AL");
  gra_pipSm_B_conv-> Draw("L");
  gra_pipSm_data-> Draw("P");
  c1-> Print("pic/discussion/pipSm_B.png");
  c1-> Print("pic/discussion/pipSm_B.eps");

  gra_pimS0_A-> SetLineStyle(9);
  gra_pimS0_A-> SetLineColor(3);
  gra_pimS0_A_conv-> SetLineColor(3);
  gra_pimS0_B-> SetLineStyle(9);
  gra_pimS0_B-> SetLineColor(3);
  gra_pimS0_B_conv-> SetLineColor(3);
  gra_pimS0_data-> SetLineColor(3);
  gra_pimS0_A-> GetYaxis()-> SetRangeUser(0., 10.);
  gra_pimS0_A-> Draw("AL");
  gra_pimS0_A_conv-> Draw("L");
  gra_pimS0_data-> Draw("P");
  c1-> Print("pic/discussion/pimS0_A.png");
  c1-> Print("pic/discussion/pimS0_A.eps");

  gra_pimS0_B-> GetYaxis()-> SetRangeUser(0., 10.);
  gra_pimS0_B-> Draw("AL");
  gra_pimS0_B_conv-> Draw("L");
  gra_pimS0_data-> Draw("P");
  c1-> Print("pic/discussion/pimS0_B.png");
  c1-> Print("pic/discussion/pimS0_B.eps");
}
