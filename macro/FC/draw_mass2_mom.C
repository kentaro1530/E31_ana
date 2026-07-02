#include "../init.C"

const TString infilename="~/ag_Run78/root/Run68/readAna.root";

TH2F* setOpts(TH2F* h2){
  h2-> SetStats(0);
  h2-> SetMarkerStyle(8);
  h2-> SetLineWidth(2);
  h2-> SetTitle("");
  h2-> GetXaxis()->SetLabelSize(0.05);
  h2-> GetXaxis()->SetTitleSize(0.06);
  h2-> GetXaxis()->CenterTitle();
  h2-> GetYaxis()->SetLabelSize(0.05);
  h2-> GetYaxis()->SetTitleSize(0.06);
  h2-> GetYaxis()->CenterTitle();
  h2-> GetXaxis()-> SetTitle("mass^{2} [(GeV/c^{2})^{2}]");
  h2-> GetYaxis()-> SetTitle("momentum [GeV/c]");

  return h2;
}

void draw_mass2_mom(){
  init();
  TFile *f = new TFile(infilename);
  TCanvas *c1 = new TCanvas("c1", "c1");
  TH2F *h2 = setOpts((TH2F*)f-> Get("FC_mass2_mom_RK"));
  h2-> GetXaxis()-> SetRangeUser(-0.1, 1.5);
  h2-> GetYaxis()-> SetRangeUser(0.5, 1.5);
  h2-> Draw();

  c1-> Print("pic/Run68/FC/FC_mass2_mom.eps");
  c1-> Print("pic/Run68/FC/FC_mass2_mom.png");
}
