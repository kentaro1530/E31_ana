#include "macro/init.C"

double bestFit=1.41833;

void fit_L1405_pole(){
  init();
  double lower1, upper1, lower2, upper2, lower3, upper3;
  fit("Kmp", lower1, upper1);
  c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus.eps");
  std::cout<<lower1<<"  "<<upper1<<std::endl;
  fit("KN", lower2, upper2);
  c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus.eps");
  std::cout<<lower2<<"  "<<upper2<<std::endl;
  fit("KzeroN", lower3, upper3);
  c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus.eps");
  std::cout<<lower3<<"  "<<upper3<<std::endl;

  std::cout<<"fit lower : "<<bestFit-lower2<<std::endl;
  std::cout<<"fit upper : "<<upper2-bestFit<<std::endl;
  std::cout<<"syst. lower : "<<lower2-lower1<<std::endl;
  std::cout<<"syst. upper : "<<upper3-upper2<<std::endl;
}

void fit(TString dirName, double &lower, double &upper, double threshold=0.5){
  TFile *f=new TFile("~/spectra_fit_scat_amp_I0.root");
  TDirectory *dir=(TDirectory*)f->Get(dirName);
  TH1F *h1=set((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> Rebin(2);
  h1-> GetXaxis()-> SetTitle("Pole [GeV]");
  h1-> GetYaxis()-> SetTitle("Counts");
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.45);
  double bin_h, bin_l;
  serachFWHM(h1, bin_l, bin_h, threshold);
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
  box.DrawBox(1.35, 0.0, bin_l, h1->GetMaximum()); 
  box.DrawBox(1.45, 0.0, bin_h, h1->GetMaximum()); 
  std::cout<<"mean : "<<func->GetParameter(1)<<std::endl;
  std::cout<<"sigma_l : "<<func->GetParameter(2)<<std::endl;
  std::cout<<"sigma_h : "<<func->GetParameter(3)<<std::endl;
  lower=func->GetParameter(1)-func->GetParameter(2);
  upper=func->GetParameter(1)+func->GetParameter(3);
}

void serachFWHM(TH1F *h1, double &min, double &max, double threshold){
  double max_content=h1->GetMaximum();
  for( int bin=h1->GetNbinsX(); bin>0; bin-- ){
    if( h1->GetBinContent(bin)>threshold*max_content){
      max=h1->GetBinCenter(bin);
      break;
    }
  }

  for( int bin=1; bin<h1->GetNbinsX(); bin++ ){
    if( h1->GetBinContent(bin)>threshold*max_content){
      min=h1->GetBinCenter(bin);
      break;
    }
  }
  //  std::cout<<min<<"  "<<max<<std::endl;
}
