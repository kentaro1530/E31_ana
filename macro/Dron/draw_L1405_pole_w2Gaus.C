#include "L1405_param.h"
#include "../init.C"

const int SIZE=sizeof(pole_Kmp_cut_hight)/sizeof(pole_Kmp_cut_hight[0]);

TGraph* make_chi2NDF_graph(const double range[], const double chi2[], const double ndf[]);
TGraph* setOpts(TGraph* gra, int kColor=kBlack);

void printParam();

void draw_L1405_pole_w2Gaus(){
  init();
  printParam();
  
  TCanvas *c1=new TCanvas("c1", "c1");
  
  TGraph *gra_chi2NDF_Kmp=setOpts(make_chi2NDF_graph(pole_Kmp_cut_hight, pole_Kmp_chi2, pole_Kmp_NDF), 6);
  TGraph *gra_chi2NDF_KN=setOpts(make_chi2NDF_graph(pole_KN_cut_hight, pole_KN_chi2, pole_KN_NDF), kRed);
  TGraph *gra_chi2NDF_KzeroN=setOpts(make_chi2NDF_graph(pole_KzeroN_cut_hight, pole_KzeroN_chi2, pole_KzeroN_NDF), kBlue);
  gra_chi2NDF_KzeroN-> GetXaxis()-> SetTitle("#chi^{2}/NDF");
  gra_chi2NDF_KzeroN-> GetYaxis()-> SetTitle("Cut Height");
  gra_chi2NDF_KzeroN-> Draw("APL");
  gra_chi2NDF_Kmp-> Draw("PL");
  gra_chi2NDF_KN-> Draw("PL");
  TLegend *leg=new TLegend(0.5, 0.6, 0.8, 0.9);
  leg-> SetFillStyle(0);
  leg-> SetBorderSize(0);
  leg-> AddEntry(gra_chi2NDF_Kmp, "K^{-}p threshold", "lp");
  leg-> AddEntry(gra_chi2NDF_KN,  "#bar{K}N threshold", "lp");
  leg-> AddEntry(gra_chi2NDF_KzeroN, "K^{0}n threshold", "lp");
  leg-> Draw();
  c1-> Print("pic/Dron/L1405_pole_chi2NDF.eps");
  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  
  TGraph *gra_lower_Kmp=setOpts(new TGraph(SIZE, pole_Kmp_lower, pole_Kmp_cut_hight), 6);
  TGraph *gra_upper_Kmp=setOpts(new TGraph(SIZE, pole_Kmp_upper, pole_Kmp_cut_hight), 6); 
  gra_lower_Kmp-> GetXaxis()-> SetLimits(1.410, 1.43);
  gra_lower_Kmp-> GetXaxis()-> SetTitle("Range of Pole [MeV]");
  gra_lower_Kmp-> GetYaxis()-> SetTitle("Cut Height");  
  gra_lower_Kmp-> Draw("APL");
  gra_upper_Kmp-> Draw("PL");
  line.DrawLine(pole_KN_bestFit, 0, pole_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_pole_range_Kmp.eps");
  
  TGraph *gra_lower_KN=setOpts(new TGraph(SIZE, pole_KN_lower, pole_KN_cut_hight), kRed);
  TGraph *gra_upper_KN=setOpts(new TGraph(SIZE, pole_KN_upper, pole_KN_cut_hight), kRed); 
  gra_lower_KN-> GetXaxis()-> SetLimits(1.410, 1.43);
  gra_lower_KN-> GetXaxis()-> SetTitle("Range of Pole [MeV]");
  gra_lower_KN-> GetYaxis()-> SetTitle("Cut Height");  
  gra_lower_KN-> Draw("APL");
  gra_upper_KN-> Draw("PL");
  line.DrawLine(pole_KN_bestFit, 0, pole_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_pole_range_KN.eps");
  
  TGraph *gra_lower_KzeroN=setOpts(new TGraph(SIZE, pole_KzeroN_lower, pole_KzeroN_cut_hight), kBlue);
  TGraph *gra_upper_KzeroN=setOpts(new TGraph(SIZE, pole_KzeroN_upper, pole_KzeroN_cut_hight), kBlue); 
  gra_lower_KzeroN-> GetXaxis()-> SetLimits(1.410, 1.43);
  gra_lower_KzeroN-> GetXaxis()-> SetTitle("Range of Pole [MeV]");
  gra_lower_KzeroN-> GetYaxis()-> SetTitle("Cut Height");  
  gra_lower_KzeroN-> Draw("APL");
  gra_upper_KzeroN-> Draw("PL");
  line.DrawLine(pole_KN_bestFit, 0, pole_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_pole_range_KzeroN.eps");
}

void printParam(){
  std::cout<<"===== Pole parameter ====="<<std::endl;
  std::cout<<pole_Kmp_lower[1]<<"  "<<pole_Kmp_upper[1]<<std::endl;
  std::cout<<pole_KN_lower[1]<<"  "<<pole_KN_upper[1]<<std::endl;
  std::cout<<pole_KzeroN_lower[1]<<"  "<<pole_KzeroN_upper[1]<<std::endl;
  std::cout<<"Best Fit : "<<pole_KN_bestFit<<std::endl;
  std::cout<<"Fit upper : "<<pole_KN_upper[1]-pole_KN_bestFit<<std::endl;
  std::cout<<"Fit lower : "<<pole_KN_lower[1]-pole_KN_bestFit<<std::endl;
  std::cout<<"Syst upper : "<<pole_KzeroN_upper[1]-pole_KN_upper[1]<<std::endl;
  std::cout<<"Syst lower : "<<pole_Kmp_lower[1]-pole_KN_lower[1]<<std::endl;

  std::cout<<"===== Width parameter ====="<<std::endl;
  std::cout<<width_Kmp_lower[1]<<"  "<<width_Kmp_upper[1]<<std::endl;
  std::cout<<width_KN_lower[1]<<"  "<<width_KN_upper[1]<<std::endl;
  std::cout<<width_KzeroN_lower[1]<<"  "<<width_KzeroN_upper[1]<<std::endl;
  std::cout<<"Best Fit : "<<width_KN_bestFit<<std::endl;
  std::cout<<"Fit upper : "<<width_KN_upper[1]-width_KN_bestFit<<std::endl;
  std::cout<<"Fit lower : "<<width_KN_lower[1]-width_KN_bestFit<<std::endl;
  std::cout<<"Syst upper : "<<width_KzeroN_upper[1]-width_KN_upper[1]<<std::endl;
  std::cout<<"Syst lower : "<<width_Kmp_lower[1]-width_KN_lower[1]<<std::endl;
}

TGraph* setOpts(TGraph* gra, int kColor){
  gra-> SetMarkerColor(kColor);
  gra-> SetLineColor(kColor);
  gra-> SetLineWidth(3);
  gra-> SetMarkerStyle(8);

  gra->SetTitle("");
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->SetLineWidth(2);
  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  return gra;
}

TGraph* make_chi2NDF_graph(const double range[], const double chi2[], const double ndf[]){
  double chi2NDF[SIZE];
  for( int i=0; i<7; i++ ) chi2NDF[i]=chi2[i]/ndf[i];
  return new TGraph(SIZE, chi2NDF, range);
}
