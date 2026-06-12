#include "../init.C"
#include <iostream>
#include <sstream>

TString tagName[]={ "T0 1hit", "TOF Kaon", "BLC 1track", "BLC2 1track", "D5 mom", "D5 & BHD", "BPC", "BLC2BPC", "Fiducial" };

double getKbeamNum(int run=-1){
  ifstream ifs("txt/KbeamNum_run78.txt");
  std::string str;
  while( getline(ifs, str) ){
    int run2; double num;
    stringstream ss(str);
    ss>>run2; ss>>num;

    if( run2==run ) return num;
  }

  std::cout<<"error"<<std::endl;
}

void Kf_reduction(){
  init();

  std::vector<int> prodRun;
  ifstream ifs("txt/Run78_run_prod.txt");
  std::string str;

  while( getline(ifs, str) ){
    stringstream ss(str);
    int run;
    ss>>run;
    prodRun.push_back(run);
  }

  std::vector<double> x, xx, w;
  std::vector<double> suv_rate[10], rel_rate[10], suv_err[10], rel_err[10];
  std::vector<double> k_beam_num;
  double reject_sum=0;  
  for( int i=0; i<prodRun.size(); i++ ){
    TFile *f=new TFile(Form("~/ag_Run78/root/Run78/readBeam/run%d.root", prodRun[i]));
    TH1F *h1 = (TH1F*)f-> Get("Kf_Reduction");
    
    std::vector<double> evnum;
    for( int bin=1; bin<=h1->GetNbinsX(); bin++ ) evnum.push_back(h1->GetBinContent(bin));
    if( evnum[0]==0 ){
      std::cout<<prodRun[i]<<"  continue"<<std::endl;
      reject_sum+=getKbeamNum(prodRun[i]);
      continue;
    }
    
  }
}
