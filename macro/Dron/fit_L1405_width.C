#include "macro/init.C"

void fit_L1405_width(){
  init();
  double lower, upper;
  fit("Kmp", lower, upper);
  c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus.eps");
  std::cout<<lower<<"  "<<upper<<std::endl;
  fit("KN", lower, upper);
  c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus.eps");
  std::cout<<lower<<"  "<<upper<<std::endl;
  fit("KzeroN", lower, upper);
  c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus.eps");
  std::cout<<lower<<"  "<<upper<<std::endl;
}

void fit(TString dirName, double &lower, double &upper){
  TFile *f=new TFile("~/spectra_fit_scat_amp_I0.root");
  TDirectory *dir=(TDirectory*)f->Get(dirName);
  TH1F *h1=set((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> Rebin(2);
  h1-> GetXaxis()-> SetTitle("Width [GeV]");
  h1-> GetYaxis()-> SetTitle("Counts");
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  double bin_h, bin_l;
  serachFWHM(h1, bin_l, bin_h);
  double mean=h1->GetBinCenter(h1->GetMaximumBin());
  double sigma_l=(mean-bin_l)/(2*sqrt(2*log(2)));
  double sigma_h=(bin_h-mean)/(2*sqrt(2*log(2)));
  //  std::cout<<sigma_l<<"  "<<sigma_h<<std::endl;

  h1-> Draw();
  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, mean);
  func-> SetParameter(2, sigma_h);
  func-> SetParameter(3, sigma_l);

  h1-> Fit("double_gaus", "q", "", bin_l, bin_h);
  TBox box;
  box.SetFillStyle(3002);
  box.SetFillColor(kGray);
  box.DrawBox(-0.1, 0.0, bin_l, h1->GetMaximum()); 
  box.DrawBox(0.0, 0.0, bin_h, h1->GetMaximum()); 
  lower=func->GetParameter(1)-func->GetParameter(3);
  upper=func->GetParameter(1)+func->GetParameter(2);

  // h1-> Fit("double_gaus", "q", "", mean-1.5*sigma_l, mean+1.5*sigma_h);
  // c1-> Update();
  // h1-> Fit("double_gaus", "q", "", mean-2.0*sigma_l, mean+2.0*sigma_h);
  // c1-> Update();
  // h1-> Fit("double_gaus", "q", "", mean-2.5*sigma_l, mean+2.5*sigma_h);
  // c1-> Update();
  // h1-> Fit("double_gaus", "q", "", mean-3.0*sigma_l, mean+3.0*sigma_h);
  // c1-> Update();
  // h1-> Fit("double_gaus", "q", "", mean-3.5*sigma_l, mean+3.5*sigma_h);
  // c1-> Update();
  // h1-> Fit("double_gaus", "q", "", mean-4.0*sigma_l, mean+4.0*sigma_h);
  // c1-> Update();

  // TLine line;
  // line.DrawLine(bin_l, 0, bin_l, h1->GetMaximum());
  // line.DrawLine(bin_h, 0, bin_h, h1->GetMaximum());
  // line.DrawLine(mean-sigma_l, 0, mean-sigma_l, h1->GetMaximum());
  // line.DrawLine(sigma_h+mean, 0, sigma_h+mean, h1->GetMaximum());
  // line.DrawLine(mean, 0, mean, h1->GetMaximum());
}

void serachFWHM(TH1F *h1, double &min, double &max){
  double max_content=h1->GetMaximum();
  for( int bin=h1->GetNbinsX(); bin>0; bin-- ){
    if( h1->GetBinContent(bin)>0.5*max_content){
      max=h1->GetBinCenter(bin);
      break;
    }
  }

  for( int bin=1; bin<h1->GetNbinsX(); bin++ ){
    if( h1->GetBinContent(bin)>0.5*max_content){
      min=h1->GetBinCenter(bin);
      break;
    }
  }
  //  std::cout<<min<<"  "<<max<<std::endl;
}
