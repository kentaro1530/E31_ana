#include "../init.C"

TString infilename = "~/ag_Run78/root/Run78/readCalibCDC.root";

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
  h2-> GetXaxis()-> SetTitle("Drift time [ns]");
  h2-> GetYaxis()-> SetTitle("Residual [mm]");

  return h2;
}

void draw_res_dt(){
  init();
  
  TCanvas *c1 = new TCanvas("c1", "c1");
  TFile *f = new TFile(infilename);
  TH2F *h2 = setOpts((TH2F*)f-> Get("CDC_dt_res"));
  h2-> GetYaxis()-> SetRangeUser(-0.1, 0.1);
  h2-> Draw("colz");

  c1-> Print("pic/Run78/CDS/CDS_res_dt.eps");
  c1-> Print("pic/Run78/CDS/CDS_res_dt.png");
}
