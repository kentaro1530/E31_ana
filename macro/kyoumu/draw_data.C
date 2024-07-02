#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_data(){
  init();

  TFile *f=new TFile(infileroot);
  TGraphErrors *gra_pimSp_data=(TGraphErrors*)f->Get("pimSp_CS0");
  TGraphErrors *gra_pipSm_data=(TGraphErrors*)f->Get("pipSm_CS0");
  TGraphErrors *gra_pimS0_data=(TGraphErrors*)f->Get("pimS0_CS0");
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);
  TArrow arr;
  TLatex latex;
  arr.SetLineWidth(2);
  gra_pimSp_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pimSp_data-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimSp_data-> SetLineColor(kRed);
  gra_pimSp_data-> Draw("AP");
  line.DrawLine(kpThre, 0., kpThre, 30);
  c1-> Print("kyoumu/pic/pimSp_data2.png");
  c1-> Print("kyoumu/pic/pimSp_data2.eps");

  gra_pipSm_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pipSm_data-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pipSm_data-> SetLineColor(kBlue);
  gra_pipSm_data-> Draw("AP");
  line.DrawLine(kpThre, 0., kpThre, 30);
  c1-> Print("kyoumu/pic/pipSm_data2.png");
  c1-> Print("kyoumu/pic/pipSm_data2.eps");

  gra_pimS0_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pimS0_data-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimS0_data-> SetLineColor(3);
  gra_pimS0_data-> Draw("AP");
  line.DrawLine(kpThre, 0., kpThre, 30);
  c1-> Print("kyoumu/pic/pimS0_data2.png");
  c1-> Print("kyoumu/pic/pimS0_data2.eps");

}
