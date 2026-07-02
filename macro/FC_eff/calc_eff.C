#include "../init.C"

const TString infilename="~/ag_Run78/root/Run78/readAna.root";

void calc_eff(){
  init();
  TFile *f = new TFile(infilename);

  TCanvas *c1 = new TCanvas("c1", "c1");
  TH1F *h1 = setOpts((TH1F*)f->Get("KLpim_MM_trigCDH3"));
  h1-> GetXaxis()-> SetTitle("d(K^{-}, #Lambda #pi^{-})\"X\" [GeV/c^{2}]");
  h1-> GetYaxis()-> SetTitle("Counts");
  h1-> GetXaxis()-> SetRangeUser(0.8, 1.5);
  h1-> Draw();
  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(kRed);
  line.DrawLine(0.89, 0, 0.89, 1.05*h1->GetMaximum());
  line.DrawLine(0.99, 0, 0.99, 1.05*h1->GetMaximum());

  c1-> Print("KLpim_MM.eps");
  c1-> Print("KLpim_MM.ong");
}
