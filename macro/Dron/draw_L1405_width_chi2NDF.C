#include "L1405_param.h"
#include "../init.C"

const int SIZE=sizeof(width_Kmp_cut_hight)/sizeof(width_Kmp_cut_hight[0]);

TGraph* make_chi2NDF_graph(const double range[], const double chi2[], const double ndf[]);
TGraph* setOpts(TGraph* gra, int kColor=kBlack);

void draw_L1405_width_chi2NDF(){
  init();
  TCanvas *c1=new TCanvas("c1", "c1");

  double sigma_list[]={ 0.5, 0.75, 1.0, 1.5, 2.0, 2.5, 3.0, 100.0 };
  TGraph *gra_chi2NDF_Kmp=setOpts(make_chi2NDF_graph(sigma_list, width_Kmp_chi2, width_Kmp_NDF), 6);
  TGraph *gra_chi2NDF_KN=setOpts(make_chi2NDF_graph(sigma_list, width_KN_chi2, width_KN_NDF), kRed);
  TGraph *gra_chi2NDF_KzeroN=setOpts(make_chi2NDF_graph(sigma_list, width_KzeroN_chi2, width_KzeroN_NDF), kBlue);
  gra_chi2NDF_KzeroN-> GetYaxis()-> SetTitle("#chi^{2}/NDF");
  gra_chi2NDF_KzeroN-> GetXaxis()-> SetTitle("Fit Range of #sigma");
  gra_chi2NDF_KzeroN-> GetXaxis()-> SetRangeUser(0, 3.0);
  gra_chi2NDF_KzeroN-> Draw("APL");
  gra_chi2NDF_Kmp-> Draw("PL");
  gra_chi2NDF_KN-> Draw("PL");
  TLegend *leg=new TLegend(0.2, 0.5, 0.5, 0.75);
  leg->	SetFillStyle(0);
  leg-> SetBorderSize(0);
  leg-> AddEntry(gra_chi2NDF_Kmp, "K^{-}p threshold", "lp");
  leg-> AddEntry(gra_chi2NDF_KN,  "#bar{K}N threshold", "lp");
  leg-> AddEntry(gra_chi2NDF_KzeroN, "K^{0}n threshold", "lp");
  leg-> Draw();
  c1-> Print("pic/Dron/L1405_width_chi2NDF.eps");
  return;
  
  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  
  TGraph *gra_lower_Kmp=setOpts(new TGraph(SIZE, width_Kmp_lower, width_Kmp_cut_hight), 6);
  TGraph *gra_upper_Kmp=setOpts(new TGraph(SIZE, width_Kmp_upper, width_Kmp_cut_hight), 6); 
  gra_lower_Kmp-> GetXaxis()-> SetLimits(-0.035, -0.01);
  gra_lower_Kmp-> GetXaxis()-> SetTitle("Range of Width [MeV]");
  gra_lower_Kmp-> GetYaxis()-> SetTitle("Cut Height");
  gra_lower_Kmp-> Draw("APL");
  gra_upper_Kmp-> Draw("PL");
  line.DrawLine(width_KN_bestFit, 0, width_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_width_range_Kmp.eps");
  
  TGraph *gra_lower_KN=setOpts(new TGraph(SIZE, width_KN_lower, width_KN_cut_hight), kRed);
  TGraph *gra_upper_KN=setOpts(new TGraph(SIZE, width_KN_upper, width_KN_cut_hight), kRed); 
  gra_lower_KN-> GetXaxis()-> SetLimits(-0.035, -0.01);
  gra_lower_KN-> GetXaxis()-> SetTitle("Range of Width [MeV]");
  gra_lower_KN-> GetYaxis()-> SetTitle("Cut Height");
  gra_lower_KN-> Draw("APL");
  gra_upper_KN-> Draw("PL");
  line.DrawLine(width_KN_bestFit, 0, width_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_width_range_KN.eps");
  
  TGraph *gra_lower_KzeroN=setOpts(new TGraph(SIZE, width_KzeroN_lower, width_KzeroN_cut_hight), kBlue);
  TGraph *gra_upper_KzeroN=setOpts(new TGraph(SIZE, width_KzeroN_upper, width_KzeroN_cut_hight), kBlue); 
  gra_lower_KzeroN-> GetXaxis()-> SetLimits(-0.035, -0.01);
  gra_lower_KzeroN-> GetXaxis()-> SetTitle("Range of Width [MeV]");
  gra_lower_KzeroN-> GetYaxis()-> SetTitle("Cut Height");
  gra_lower_KzeroN-> Draw("APL");
  gra_upper_KzeroN-> Draw("PL");
  line.DrawLine(width_KN_bestFit, 0, width_KN_bestFit, 0.67);
  c1-> Print("pic/Dron/L1405_width_range_KzeroN.eps");
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
  return new TGraph(SIZE, range, chi2NDF);
}
