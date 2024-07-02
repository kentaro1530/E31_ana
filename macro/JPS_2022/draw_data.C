#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_data(){
  init();
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);

  TFile *f=new TFile(infileroot);
  TGraphErrors *gra_pimSp_data=GevToMev((TGraphErrors*)f->Get("pimSp_CS0"), kRed);
  // TGraphErrors *gra_pimSp_data=(TGraphErrors*)f->Get("pimSp_CS0");
  TGraphErrors *gra_pipSm_data=GevToMev((TGraphErrors*)f->Get("pipSm_CS0"), kBlue);
  TGraphErrors *gra_pimS0_data=GevToMev((TGraphErrors*)f->Get("pimS0_CS0"), 3);
  const double kpThre=1000.*(kpMass+pMass);
  const double knThre=1000.*(k0Mass+nMass);
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);
  TLine line2;
  line2.SetLineColor(3);
  line2.SetLineWidth(3);

  TArrow arr;
  TLatex latex;
  latex.SetTextSize(0.07);
  arr.SetLineWidth(3);
  // gra_pimSp_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  // gra_pimSp_data-> GetYaxis()-> SetRangeUser(0., 30.);
  // gra_pimSp_data-> SetLineColor(kRed);
  // gra_pipSm_data-> SetLineColor(kBlue);
  // gra_pimSp_data-> SetMarkerColor(kRed);
  // gra_pipSm_data-> SetMarkerColor(kBlue);

  // gra_pimSp_data-> SetMarkerStyle(8);
  // gra_pipSm_data-> SetMarkerStyle(8);
  // gra_pimSp_data-> SetLineWidth(3);
  // gra_pipSm_data-> SetLineWidth(3);
  // gra_pimSp_data-> SetMarkerSize(1.2);
  // gra_pipSm_data-> SetMarkerSize(1.2);
  gra_pimSp_data-> Draw("AP");
  gra_pipSm_data-> Draw("P");
  line.DrawLine(kpThre, 0., kpThre, 30);
  TLegend *leg=new TLegend(0.2, 0.4, 0.5, 0.8);
  leg-> SetFillStyle(0);
  leg-> SetBorderSize(0);
  leg-> AddEntry(gra_pimSp_data, "#pi^{-}#Sigma^{+}", "lep");
  leg-> AddEntry(gra_pipSm_data, "#pi^{+}#Sigma^{-}", "lep");
  leg-> Draw();
  arr.DrawArrow(1.385, 8.5, 1.385, 4.0, 0.05, "-|>");
  latex.DrawLatex(1.36, 9.2, "#Sigma(1385)");

  arr.DrawArrow(1.52, 10., 1.52, 6, 0.05, "-|>");
  latex.DrawLatex(1.5, 11, "#Lambda(1520)");
  c1-> Print("~/ag_Run78/pic/JPS_2022/ChargeCS.eps");
  //  return;

  gra_pimS0_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pimS0_data-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimS0_data-> SetLineColor(3);
  gra_pimS0_data-> SetMarkerStyle(8);
  gra_pimS0_data-> SetMarkerSize(1.2);
  gra_pimS0_data-> SetMarkerColor(3);
  gra_pimS0_data-> SetLineWidth(3);
  gra_pimS0_data-> Draw("AP");
  line.DrawLine(kpThre, 0., kpThre, 30);
  line.DrawLine(knThre, 0., knThre, 30);

  arr.DrawArrow(1.385, 5.5, 1.385, 1.0, 0.05, "-|>");
  latex.DrawLatex(1.36, 6.2, "#Sigma(1385)");
  c1-> Print("~/ag_Run78/pic/JPS_2022/pimS0_CS.eps");
  gra_pimSp_data-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  gra_pimSp_data-> GetXaxis()-> SetTitle("#pi #Sigma mass [MeV/c^{2}]");

  gra_pimSp_data-> Draw("AP");
  gra_pipSm_data-> Draw("P");
  gra_pimS0_data-> Draw("P");
  line.DrawLine(kpThre, 0., kpThre, 30);
  //  line2.DrawLine(knThre, 0., knThre, 30);
  leg-> AddEntry(gra_pimS0_data, "#pi^{-}#Sigma^{0}", "lep");
  leg-> Draw();
  c1-> Print("~/ag_Run78/pic/JPS_2022/All_CS.eps");
}


