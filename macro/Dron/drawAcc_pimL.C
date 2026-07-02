#include "../init.C"

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

void drawAcc_pimL(){
  init();
  TFile *f = new TFile("~/ag_Run78/root/sim/kd_pS1385_pimL/readAna.root");

  TCanvas *c1 = new TCanvas("c1", "c1");
  TH1F *h_trig=new TH1F("h_trig", "Trigger mass", 25, 1.35, 1.6);
  TH1F *h_eff=new TH1F("h_eff", "Effective mass", 25, 1.35, 1.6);

  Float_t mm; TNtuple *tup=(TNtuple*)f->Get("tup_trig_mass_fp"); tup->SetBranchAddress("m", &mm);
  for( int ev=0; ev<tup->GetEntries(); ev++ ){ tup->GetEntry(ev); h_trig->Fill(mm); }

  TNtuple *tup_eff=(TNtuple*)f->Get("tup_eff_mass_fp_pipi_mm1"); tup_eff->SetBranchAddress("m", &mm);
  for( int ev=0; ev<tup_eff->GetEntries(); ev++ ){ tup_eff->GetEntry(ev); h_eff->Fill(mm); }

  std::vector<double> x, xerr, y, yerr;
  for( int bin=1; bin<=h_trig->GetNbinsX(); bin++ ){
    x.push_back(h_trig->GetBinCenter(bin));
    xerr.push_back(0.5*h_trig->GetBinWidth(bin));
    double deno = h_trig-> GetBinContent(bin);
    double num  = h_eff-> GetBinContent(bin);
    double p = num/deno;
    double err = sqrt(p*(1-p)/deno);
    y.push_back(p);
    yerr.push_back(err);
  }

  TGraphErrors *gra = setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr[0]), 6);
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra-> GetYaxis()-> SetRangeUser(0.0, 0.1);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
  gra-> GetYaxis()-> SetTitle("Ana. efficiency");
  gra-> Draw("AP");

  c1-> Print("pic/Dron/KP_ana/pimL_acc.png");
  c1-> Print("pic/Dron/KP_ana/pimL_acc.eps");  
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
