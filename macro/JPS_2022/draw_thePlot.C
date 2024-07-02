#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_thePlot(){
  init();
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);

  TFile *f=new TFile(infileroot);
  TGraph *pimSp_modelA=(TGraph*)f->Get("pimSp_modelA");
  TGraph *pimSp_modelB=(TGraph*)f->Get("pimSp_modelB");
  pimSp_modelA-> GetYaxis()-> SetRangeUser(0, 35);
  pimSp_modelA-> SetLineColor(kRed);
  pimSp_modelB-> SetLineColor(kRed);
  pimSp_modelA-> SetLineWidth(3);
  pimSp_modelB-> SetLineWidth(3);
  pimSp_modelA-> Draw("APL");
  pimSp_modelB-> Draw("PL");
  line.DrawLine(kpThre, 0., kpThre, 35);
  TLegend *leg=new TLegend(0.2, 0.6, 0.5, 0.8);
  leg-> SetFillStyle(0);
  leg-> SetBorderSize(0);
  leg-> AddEntry(pimSp_modelA, "Model.A", "lp");
  leg-> AddEntry(pimSp_modelB, "Model.B", "lp");
  leg-> Draw();

  TGraph *pipSm_modelA=(TGraph*)f->Get("pipSm_modelA");
  TGraph *pipSm_modelB=(TGraph*)f->Get("pipSm_modelB");
  pipSm_modelA-> GetYaxis()-> SetRangeUser(0, 35);
  pipSm_modelA-> SetLineColor(kBlue);
  pipSm_modelB-> SetLineColor(kBlue);
  pipSm_modelA-> SetLineWidth(3);
  pipSm_modelB-> SetLineWidth(3);
  pipSm_modelA-> Draw("APL");
  pipSm_modelB-> Draw("PL");
  line.DrawLine(kpThre, 0., kpThre, 35);
  leg-> Draw();

  TGraph *pimS0_modelA=(TGraph*)f->Get("pi0S0_modelA");
  TGraph *pimS0_modelB=(TGraph*)f->Get("pi0S0_modelB");
  pimS0_modelA-> GetYaxis()-> SetRangeUser(0, 35);
  pimS0_modelA-> SetLineColor(3);
  pimS0_modelB-> SetLineColor(3);
  pimS0_modelA-> SetLineWidth(3);
  pimS0_modelB-> SetLineWidth(3);
  pimS0_modelA-> Draw("APL");
  pimS0_modelB-> Draw("PL");
  line.DrawLine(kpThre, 0., kpThre, 35);
  leg-> Draw();

  pimS0_modelA-> SetLineColor(3);
  pimS0_modelA-> GetXaxis()-> SetRangeUser(0, 35);
  pimSp_modelA-> Draw("APL");
  pipSm_modelA-> Draw("PL");
  pimS0_modelA-> Draw("PL");
  TLegend *leg =new TLegend(0.18, 0.6, 0.5, 0.8);
  TLatex latex;
  latex.SetTextSize(0.12);
  leg-> AddEntry(pimSp_modelA, "#pi^{-}#Sigma^{+}", "lp");
  leg-> AddEntry(pipSm_modelA, "#pi^{+}#Sigma^{-}", "lp");
  leg-> AddEntry(pimS0_modelA, "#pi^{0}#Sigma^{0}", "lp");
  leg-> SetBorderSize(0);
  leg-> Draw();
  latex.DrawLatex(1.36, 30, "Model.A");
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_thePlotA.eps");

  pimS0_modelB-> SetLineColor(3);
  pimS0_modelB-> GetXaxis()-> SetRangeUser(0, 35);
  pimSp_modelB-> Draw("APL");
  pipSm_modelB-> Draw("PL");
  pi0S0_modelB-> Draw("PL");
  leg-> Draw();
  latex.DrawLatex(1.36, 30, "Model.B");
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_thePlotB.eps");


}

