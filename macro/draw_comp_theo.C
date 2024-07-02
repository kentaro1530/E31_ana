#include "macro/init.C"

const TString infileroot="~/spectra.root";

void draw_comp_theo(){
  init();
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);

  TFile *f=new TFile(infileroot);
  TGraphErrors *gra_pimSp_data=(TGraphErrors*)f->Get("pimSp_CS0");
  TGraph *gra_pimSp_blue=(TGraph*)f->Get("pimSp_miyagawa_blue_conv");
  TGraph *gra_pimSp_red=(TGraph*)f->Get("pimSp_miyagawa_red_conv");
  TGraph *gra_pimSp_green=(TGraph*)f->Get("pimSp_miyagawa_green_conv");
  TGraph *gra_pimSpA=(TGraph*)f->Get("pimSp_modelA_conv");
  TGraph *gra_pimSpB=(TGraph*)f->Get("pimSp_modelB_conv");
  gra_pimSp_blue-> SetLineStyle(9);
  gra_pimSp_red-> SetLineStyle(9);
  gra_pimSp_green-> SetLineStyle(9);
  gra_pimSp_data-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimSp_data-> GetYaxis()-> SetRangeUser(0., 35.);
  gra_pimSp_data-> SetLineColor(kRed);
  gra_pimSp_data-> SetMarkerColor(kRed);
  gra_pimSpA-> SetLineColor(kRed);
  gra_pimSpB-> SetLineColor(kRed);
  gra_pimSp_blue-> SetLineColor(kRed);
  gra_pimSp_red-> SetLineColor(kRed);
  gra_pimSp_green-> SetLineColor(kRed);

  gra_pimSp_blue-> SetLineStyle(2);
  gra_pimSp_red-> SetLineStyle(4);
  gra_pimSp_green-> SetLineStyle(5);

  gra_pimSpA-> SetLineWidth(2);
  gra_pimSpB-> SetLineWidth(3);

  gra_pimSp_data-> Draw("AP");
  gra_pimSp_blue-> Draw("L");
  gra_pimSp_red-> Draw("L");
  gra_pimSp_green-> Draw("L");
  gra_pimSpA-> Draw("L");
  gra_pimSpB-> Draw("L");
  TLegend *leg=new TLegend(0.2, 0.5, 0.5, 0.95);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_pimSp_data, "Data", "lpe");
  leg-> AddEntry(gra_pimSp_red, "Cieply and Smejkal", "lp");
  leg-> AddEntry(gra_pimSp_blue, "Ohnishi", "lp");
  leg-> AddEntry(gra_pimSp_green, "ORB", "lp");
  leg-> AddEntry(gra_pimSpA, "DCC model.A", "lp");
  leg-> AddEntry(gra_pimSpB, "DCC model,B", "lp");
  leg-> Draw();

  c1-> Print("pic/kyoumu/comp_theo_pimSp.eps");
  c1-> Print("pic/kyoumu/comp_theo_pimSp.png");

  TGraphErrors *gra_pipSm_data=(TGraphErrors*)f->Get("pipSm_CS0");
  TGraph *gra_pipSm_blue=(TGraph*)f->Get("pipSm_miyagawa_blue_conv");
  TGraph *gra_pipSm_red=(TGraph*)f->Get("pipSm_miyagawa_red_conv");
  TGraph *gra_pipSm_green=(TGraph*)f->Get("pipSm_miyagawa_green_conv");
  TGraph *gra_pipSmA=(TGraph*)f->Get("pipSm_modelA_conv");
  TGraph *gra_pipSmB=(TGraph*)f->Get("pipSm_modelB_conv");
  gra_pipSm_blue-> SetLineStyle(9);
  gra_pipSm_red-> SetLineStyle(9);
  gra_pipSm_green-> SetLineStyle(9);
  gra_pipSm_data-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pipSm_data-> GetYaxis()-> SetRangeUser(0., 35.);
  gra_pipSm_data-> SetLineColor(kBlue);
  gra_pipSm_data-> SetMarkerColor(kBlue);
  gra_pipSmA-> SetLineColor(kBlue);
  gra_pipSmB-> SetLineColor(kBlue);
  gra_pipSm_blue-> SetLineColor(kBlue);
  gra_pipSm_red-> SetLineColor(kBlue);
  gra_pipSm_green-> SetLineColor(kBlue);

  gra_pipSm_blue-> SetLineStyle(2);
  gra_pipSm_red-> SetLineStyle(4);
  gra_pipSm_green-> SetLineStyle(5);

  gra_pipSmA-> SetLineWidth(2);
  gra_pipSmB-> SetLineWidth(3);

  gra_pipSm_data-> Draw("AP");
  gra_pipSm_blue-> Draw("L");
  gra_pipSm_red-> Draw("L");
  gra_pipSm_green-> Draw("L");
  gra_pipSmA-> Draw("L");
  gra_pipSmB-> Draw("L");

  TLegend *leg=new TLegend(0.2, 0.5, 0.5, 0.95);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_pipSm_data, "Data", "lpe");
  leg-> AddEntry(gra_pipSm_red, "Cieply and Smejkal", "lp");
  leg-> AddEntry(gra_pipSm_blue, "Ohnishi", "lp");
  leg-> AddEntry(gra_pipSm_green, "ORB", "lp");
  leg-> AddEntry(gra_pipSmA, "DCC model.A", "lp");
  leg-> AddEntry(gra_pipSmB, "DCC model,B", "lp");
  leg-> Draw();

  c1-> Print("pic/kyoumu/comp_theo_pipSm.eps");
  c1-> Print("pic/kyoumu/comp_theo_pipSm.png");

  TGraphErrors *gra_pimS0_data=(TGraphErrors*)f->Get("pimS0_CS0");
  TGraph *gra_pimS0_blue=(TGraph*)f->Get("pimS0_miyagawa_blue_conv");
  TGraph *gra_pimS0_red=(TGraph*)f->Get("pimS0_miyagawa_red_conv");
  TGraph *gra_pimS0_green=(TGraph*)f->Get("pimS0_miyagawa_green_conv");
  TGraph *gra_pimS0A=(TGraph*)f->Get("pimS0_modelA_conv");
  TGraph *gra_pimS0B=(TGraph*)f->Get("pimS0_modelB_conv");
  gra_pimS0_blue-> SetLineStyle(9);
  gra_pimS0_red-> SetLineStyle(9);
  gra_pimS0_green-> SetLineStyle(9);
  gra_pimS0_data-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimS0_data-> GetYaxis()-> SetRangeUser(0., 35.);
  gra_pimS0_data-> SetLineColor(3);
  gra_pimS0_data-> SetMarkerColor(3);
  gra_pimS0A-> SetLineColor(3);
  gra_pimS0B-> SetLineColor(3);
  gra_pimS0_blue-> SetLineColor(3);
  gra_pimS0_red-> SetLineColor(3);
  gra_pimS0_green-> SetLineColor(3);

  gra_pimS0_blue-> SetLineStyle(2);
  gra_pimS0_red-> SetLineStyle(4);
  gra_pimS0_green-> SetLineStyle(5);

  gra_pimS0A-> SetLineWidth(2);
  gra_pimS0B-> SetLineWidth(3);

  gra_pimS0_data-> Draw("AP");
  gra_pimS0_blue-> Draw("L");
  gra_pimS0_red-> Draw("L");
  gra_pimS0_green-> Draw("L");
  gra_pimS0A-> Draw("L");
  gra_pimS0B-> Draw("L");

  TLegend *leg=new TLegend(0.2, 0.5, 0.5, 0.95);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_pimS0_data, "Data", "lpe");
  leg-> AddEntry(gra_pimS0_red, "Cieply and Smejkal", "lp");
  leg-> AddEntry(gra_pimS0_blue, "Ohnishi", "lp");
  leg-> AddEntry(gra_pimS0_green, "ORB", "lp");
  leg-> AddEntry(gra_pimS0A, "DCC model.A", "lp");
  leg-> AddEntry(gra_pimS0B, "DCC model,B", "lp");
  leg-> Draw();

  c1-> Print("pic/kyoumu/comp_theo_pimS0.eps");
  c1-> Print("pic/kyoumu/comp_theo_pimS0.png");
}
