#include "../../init.C"

void draw_n_mom(){
  init();
  TFile *f = new TFile("~/ag_Run78/root/Run78/KN_ana_bin10.root");
  TDirectory *dir = (TDirectory*)f-> Get("data");

  TCanvas *c1 = new TCanvas("c1", "c1");
  TH1F *h1=setOpts((TH1F*)dir->Get("mmN_mom_K0"));
  h1-> Rebin(5);
  h1-> GetXaxis()-> SetRangeUser(0.0, 0.5);
  h1-> GetYaxis()-> SetTitle("Counts");
  h1-> GetXaxis()-> SetTitle("momentum [GeV/c]");
  h1-> Draw();

  c1-> Print("pic/Dron/K0_ana/mmN_mom.eps");
}

