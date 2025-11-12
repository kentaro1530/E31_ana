#include "../init.C"

const TString infilename="../ag_Run78/root/Run78/KN_ana_bin10_NC170_2sigma.root";

void drawKN_MM(){
  TFile *f = new TFile(infilename);
  setMargin();
  TCanvas *c1 = new TCanvas();
  
  TLine line; line.SetLineWidth(2); line.SetLineColor(3);
  const double kpThre=kpMass+pMass;

  TH1F* h1=setOpts((TH1F*)((TDirectoryFile*)f-> Get("data"))-> Get("KN_MM_woAll"));
  h1-> Rebin(10);
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  h1-> GetXaxis()->SetTitle("d(K^{-}, n)\"#pi#Sigma\" [GeV]");
  h1-> GetYaxis()->SetTitle("Counts/10 MeV");
  h1-> Draw("e");
  line.DrawLine(kpThre, 0, kpThre, 1.1*h1->GetMaximum());

  c1-> Print("pic/Dron/discussion/KN_MM_woAll.eps"); 
}

