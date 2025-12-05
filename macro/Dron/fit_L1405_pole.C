// #include "macro/init.C"
#include "../init.C"

const double bestFit=1.41833;

void fit(TString dirName, double threshold=0.5);
void serachFWHM(TH1F *h1, double &min, double &max, double threshold);

double range[]={ exp(-0.5*0.5/2), exp(-0.75*0.75/2), exp(-1./2), exp(-1.5*1.5/2), exp(-2), exp(-2.5*2.5/2), exp(-9/2), 0 };

void fit_L1405_pole(){
  init();
  TCanvas *c1=new TCanvas("c1", "c1");
  const TString dirName="KzeroN";
  
  for( int i=0; i<sizeof(range)/sizeof(range[0]); i++ ){
    fit(dirName, range[i]);    
    c1-> Print(Form("pic/Dron/fit_L1405_pole_%s_%d.eps", dirName.Data(), i));
    // std::string str;
    // std::cin>>str;
  }
}

void fit(TString dirName, double threshold){
  TFile *f=new TFile("~/spectra_fit_scat_amp_I0.root");
  TDirectory *dir=(TDirectory*)f->Get(dirName);
  TH1F *h1=setOpts((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> Rebin(2);
  h1-> GetXaxis()-> SetTitle("Pole [GeV]");
  h1-> GetYaxis()-> SetTitle("Counts");
  h1-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  double bin_h, bin_l;
  if( threshold>0 ) serachFWHM(h1, bin_l, bin_h, threshold);
  else bin_l=1.35, bin_h=1.5;

  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, h1->GetBinCenter(h1->GetMaximumBin()));
  func-> SetParameter(2, 0.3*h1->GetRMS());
  func-> SetParameter(3, 0.3*h1->GetRMS());
  
  h1-> Draw();
  h1-> Fit("double_gaus", "", "", bin_l, bin_h);
  TBox box;
  box.SetFillStyle(3002);
  box.SetFillColor(kGray);
  if( threshold>0 ){
    box.DrawBox(1.35, 0.0, bin_l, h1->GetMaximum()); 
    box.DrawBox(1.50, 0.0, bin_h, h1->GetMaximum());
  }
  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(bestFit, 0, bestFit, 1.05*h1->GetMaximum());

  std::cout<<"{"<<std::endl;
  std::cout<<"\"cutHeight\" : "<<threshold<<", "<<std::endl;
  std::cout<<"\"chi2\" : "<<func->GetChisquare()<<", "<<std::endl;
  std::cout<<"\"NDF\" : "<<func->GetNDF()<<", "<<std::endl;
  std::cout<<"\"fitLower\" : "<<bin_l<<", "<<std::endl;
  std::cout<<"\"fitUpper\" : "<<bin_h<<", "<<std::endl;
  std::cout<<"\"lower\" : "<<func->GetParameter(1)-func->GetParameter(2)<<", "<<std::endl;
  std::cout<<"\"upper\" : "<<func->GetParameter(1)+func->GetParameter(3)<<", "<<std::endl;
  std::cout<<"\"mean\" : "<<func->GetParameter(1)<<std::endl;
  std::cout<<"},"<<std::endl;
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
}
