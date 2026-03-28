#include "../init.C"
const TString dirName="pic/Dron/";

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

void draw_FC_reso_KP_MM(){
  init();
  
  TFile *f0=new TFile("../ag_Run78/root/sim/kd_pS1385_pimS0/readAna.root");
  TFile *f1=new TFile("../ag_Run78/root/sim/kd_pS1385_pimL/readAna.root");

  TCanvas *c1 = new TCanvas("c1", "c1");
  
  std::vector<double> x, s0, s1, e0, e1, ave, err;  
  TH2F *h2=(TH2F*)f0-> Get("KP_MM_diff_MC");
  h2-> RebinX(10);
  h2-> RebinY(10);
  for( int bin=35; bin<80; bin++ ){
    x.push_back(h2->GetXaxis()->GetBinCenter(bin));
    TH1F *h1=(TH1F*)h2->ProjectionY(Form("KP_MM_diff_%d", bin), bin, bin);
    h1-> Fit("gaus");
    h1-> Draw();
    //    c1-> Update();
    s0.push_back(h1->GetFunction("gaus")->GetParameter(2));
    e0.push_back(h1->GetFunction("gaus")->GetParError(2));
  }

  h2=(TH2F*)f1-> Get("KP_MM_diff_MC");
  h2-> RebinX(10);
  h2-> RebinY(10);
 
  for( int bin=35; bin<80; bin++ ){
    TH1F *h1=(TH1F*)h2->ProjectionY(Form("KP_MM_diff_%d", bin), bin, bin);
    h1-> Fit("gaus");
    h1-> Draw();
    //    c1-> Update();
    if( bin != 35 ) s1.push_back(h1->GetFunction("gaus")->GetParameter(2));
    else s1.push_back(0);
    e1.push_back(h1->GetFunction("gaus")->GetParError(2));
  }

  for( int i=0; i<x.size(); i++ ){
    ave.push_back(0.5*(s0[i]+s1[i]));
    err.push_back(0.5*(e0[i]+e1[i]));
  }

  TGraphErrors *gra0=setOpts(new TGraphErrors(x.size(), &x[0], &s0[0], 0, &e0[0]), 5);
  TGraphErrors *gra1=setOpts(new TGraphErrors(x.size(), &x[0], &s1[0], 0, &e1[0]), 6);
  TGraphErrors *gra_ave=setOpts(new TGraphErrors(x.size(), &x[0], &ave[0], 0, &err[0]));

  gra0-> GetXaxis()-> SetRangeUser(1.35, 1.7);
  gra0-> GetYaxis()-> SetRangeUser(0., 0.015);
  gra0-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
  gra0-> GetYaxis()-> SetTitle("#sigma of gaussian [ns]");
  gra0-> Draw("AP");
  gra_ave-> Draw("PE");
  gra1-> Draw("PE");
  gra0-> Draw("PE");

  TLegend *leg= new TLegend(0.2, 0.2, 0.5, 0.45);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra0, "#pi^{-} #Sigma^{0}", "EP");
  leg-> AddEntry(gra1, "#pi^{-} #Lambda", "EP");
  leg-> AddEntry(gra_ave, "Average", "LEP");
  leg-> Draw();
  gra_ave-> Fit("pol3");

  c1-> Print(Form("%s/FC_reso_KP_MM.eps", dirName.Data()));
  c1-> Print(Form("%s/FC_reso_KP_MM.png", dirName.Data()));
}

TGraphErrors* setOpts(TGraphErrors* gra, int color){
  gra-> SetMarkerStyle(8);
  gra-> SetLineWidth(2);
  gra-> SetMarkerColor(color);
  gra-> SetLineColor(color);
  gra-> SetLineWidth(2);
  gra->SetTitle("");
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  return gra;
}
