#include "../init.C"

TString infilename = "~/spectra_fit_scat_amp_I0.root";

void draw_pole_width(){
  TFile *f = new TFile(infilename);
  TCanvas *c1 = new TCanvas("c1", "c1");
  TDirectory* dir = (TDirectory*)f->Get("KN");
  TH1F* h1 = setOpts((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.45);
  h1-> GetXaxis()-> SetTitle("M [GeV]");
  h1-> Draw();
  c1-> Print("pic/Dron/fit_scat_amp_I0_pole_KN.eps");
  
  h1 = setOpts((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> Draw();
  h1-> GetXaxis()-> SetTitle("#Gamma [GeV]");
  c1-> Print("pic/Dron/fit_scat_amp_I0_width_KN.eps");

  dir = (TDirectory*)f->Get("Kmp");
  h1 = setOpts((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.45);
  h1-> GetXaxis()-> SetTitle("M [GeV]");
  h1-> Draw();
  c1-> Print("pic/Dron/fit_scat_amp_I0_pole_Kmp.eps");
  
  h1 = setOpts((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> Draw();
  h1-> GetXaxis()-> SetTitle("#Gamma [GeV]");
  c1-> Print("pic/Dron/fit_scat_amp_I0_width_Kmp.eps");

  dir = (TDirectory*)f->Get("KzeroN");
  h1 = setOpts((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.45);
  h1-> GetXaxis()-> SetTitle("M [GeV]");
  h1-> Draw();
  c1-> Print("pic/Dron/fit_scat_amp_I0_pole_KzeroN.eps");
  
  h1 = setOpts((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> Draw();
  h1-> GetXaxis()-> SetTitle("#Gamma [GeV]");
  c1-> Print("pic/Dron/fit_scat_amp_I0_width_KzeroN.eps");
}

