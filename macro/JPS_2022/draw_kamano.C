#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_kamano(){
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
  pimSp_modelB-> SetLineColor(kBlue);
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
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_pimSp.eps");

  TGraph *pipSm_modelA=(TGraph*)f->Get("pipSm_modelA");
  TGraph *pipSm_modelB=(TGraph*)f->Get("pipSm_modelB");
  pipSm_modelA-> GetYaxis()-> SetRangeUser(0, 35);
  pipSm_modelA-> SetLineColor(kRed);
  pipSm_modelB-> SetLineColor(kBlue);
  pipSm_modelA-> SetLineWidth(3);
  pipSm_modelB-> SetLineWidth(3);
  pipSm_modelA-> Draw("APL");
  pipSm_modelB-> Draw("PL");
  line.DrawLine(kpThre, 0., kpThre, 35);
  leg-> Draw();
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_pipSm.eps");

  TGraph *pimS0_modelA=(TGraph*)f->Get("pimS0_modelA");
  TGraph *pimS0_modelB=(TGraph*)f->Get("pimS0_modelB");
  pimS0_modelA-> GetYaxis()-> SetRangeUser(0, 35);
  pimS0_modelA-> SetLineColor(kRed);
  pimS0_modelB-> SetLineColor(kBlue);
  pimS0_modelA-> SetLineWidth(3);
  pimS0_modelB-> SetLineWidth(3);
  pimS0_modelA-> Draw("APL");
  pimS0_modelB-> Draw("PL");
  line.DrawLine(kpThre, 0., kpThre, 35);
  leg-> Draw();
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_pimS0.eps");

  pimSp-> Draw("APL");
}

