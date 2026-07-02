#include "../init.C"

const TString infilename="~/ag_Run78/root/Run78/readAna_chk.root";

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
  h2-> GetXaxis()-> SetTitle("dE [MeVee]");
  h2-> GetYaxis()-> SetTitle("d(K^{-}, n #pi^{+} #pi^{-}) [GeV/c^{2}]");

  return h2;
}

void draw_NCdE_KNpipi_MM(){
  init();
  TFile *f = new TFile(infilename);
  TCanvas *c1 = new TCanvas("c1", "c1");
  TH2F *h2 = setOpts((TH2F*)f-> Get("NCdE_KNpipi_MM"));
  TH2F *h2_true = setOpts((TH2F*)f-> Get("NCdE_KNpipi_MM_true"));
  h2-> RebinX(10);
  h2_true-> RebinX(10);
  h2-> GetXaxis()-> SetRangeUser(0.0, 150.);
  h2-> GetYaxis()-> SetRangeUser(0.85, 1.0);
  TProfile* prof = h2_true-> ProfileX();
  prof-> SetMarkerStyle(2);
  prof-> SetLineWidth(2);
  
  h2-> Draw("colz");
  prof-> Draw("same");

  c1-> Print("pic/Run78/NCdE_KNpipi_MM.eps");
  c1-> Print("pic/Run78/NCdE_KNpipi_MM.png");
}

