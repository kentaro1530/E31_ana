#include "../init.C"
const TString infilename = "../ag_Run78/root/Run78/readBeam.root";

TH2F* setOpts(TH2F* h2);
  
void draw_beam_profFF(){
  init();
  TFile *f = new TFile(infilename);
  TCanvas *c1 = new TCanvas();
  TEllipse circle(-0.4, -0.5, 3);
  circle.SetLineWidth(2);
  circle.SetLineColor(2);
  circle.SetFillStyle(0);
  
  TH2F *h2 = setOpts((TH2F*)f-> Get("BeamProf_Kf"));
  h2-> GetXaxis()-> SetTitle("X [cm]");
  h2-> GetYaxis()-> SetTitle("Y [cm]");
  h2-> GetXaxis()-> SetRangeUser(-7, 7);
  h2-> GetYaxis()-> SetRangeUser(-7, 7);
  h2-> Draw("colz");
  circle.Draw();
  c1-> Print("profFF_Kf.eps");
  
  h2 = setOpts((TH2F*)f-> Get("BeamProf_KCDH2"));
  h2-> GetXaxis()-> SetTitle("X [cm]");
  h2-> GetYaxis()-> SetTitle("Y [cm]");
  h2-> GetXaxis()-> SetRangeUser(-7, 7);
  h2-> GetYaxis()-> SetRangeUser(-7, 7);
  h2-> Draw("colz");
  circle.Draw();
  c1-> Print("profFF_KCDH2.eps");  
}

TH2F* setOpts(TH2F* h2){
  std::cout<<h2<<std::endl;
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
  return h2;
}
