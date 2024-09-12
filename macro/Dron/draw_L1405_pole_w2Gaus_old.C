#include "macro/Dron/L1405_param.h"
#include "macro/init.C"

void draw_L1405_pole_w2Gaus(){
  init();
  std::cout<<"===== Pole parameter ====="<<std::endl;
  std::cout<<pole_Kmp_lower[2]<<"  "<<pole_Kmp_upper[2]<<std::endl;
  std::cout<<pole_KN_lower[2]<<"  "<<pole_KN_upper[2]<<std::endl;
  std::cout<<pole_KzeroN_lower[2]<<"  "<<pole_KzeroN_upper[2]<<std::endl;
  std::cout<<"Best Fit : "<<pole_KN_bestFit<<std::endl;
  std::cout<<"Fit upper : "<<pole_KN_upper[2]-pole_KN_bestFit<<std::endl;
  std::cout<<"Fit lower : "<<pole_KN_lower[2]-pole_KN_bestFit<<std::endl;
  std::cout<<"Syst upper : "<<pole_KzeroN_upper[2]-pole_KN_upper[2]<<std::endl;
  std::cout<<"Syst lower : "<<pole_Kmp_lower[2]-pole_KN_lower[2]<<std::endl;

  std::cout<<"===== Width parameter ====="<<std::endl;
  std::cout<<width_Kmp_lower[2]<<"  "<<width_Kmp_upper[2]<<std::endl;
  std::cout<<width_KN_lower[2]<<"  "<<width_KN_upper[2]<<std::endl;
  std::cout<<width_KzeroN_lower[2]<<"  "<<width_KzeroN_upper[2]<<std::endl;
  std::cout<<"Best Fit : "<<width_KN_bestFit<<std::endl;
  std::cout<<"Fit upper : "<<width_KN_upper[2]-width_KN_bestFit<<std::endl;
  std::cout<<"Fit lower : "<<width_KN_lower[2]-width_KN_bestFit<<std::endl;
  std::cout<<"Syst upper : "<<width_KzeroN_upper[2]-width_KN_upper[2]<<std::endl;
  std::cout<<"Syst lower : "<<width_Kmp_lower[2]-width_KN_lower[2]<<std::endl;
  return;

  TGraph* gra_chi2NDF_Kmp=set(make_chi2NDF_graph(pole_KN_range, pole_Kmp_chi2, pole_Kmp_NDF), kRed);
  TGraph* gra_chi2NDF_KN=set(make_chi2NDF_graph(pole_KN_range, pole_KN_chi2, pole_KN_NDF), 3);
  TGraph* gra_chi2NDF_KzeroN=set(make_chi2NDF_graph(pole_KN_range, pole_KzeroN_chi2, pole_KzeroN_NDF), kBlue);

  TGraph* gra_chi2_Kmp=set(new TGraph(7, pole_KN_range, pole_Kmp_chi2), kRed);
  TGraph* gra_chi2_KN=set(new TGraph(7, pole_KN_range, pole_KN_chi2), 3);
  TGraph* gra_chi2_KzeroN=set(new TGraph(7, pole_KN_range, pole_KzeroN_chi2), kBlue);
  gra_chi2NDF_KN-> GetYaxis()-> SetRangeUser(0.0, 2.5);
  gra_chi2NDF_KN->GetXaxis()-> SetTitle("Range of #sigma");
  gra_chi2NDF_KN->GetYaxis()-> SetTitle("#chi^{2}/NDF");
  gra_chi2NDF_KN-> Draw("AP");
  gra_chi2NDF_KzeroN-> Draw("P");
  gra_chi2NDF_Kmp-> Draw("P");
  c1-> Print("pic/Dron/L1405_pole_chi2NDF.eps");

  TGraph* gra_mean_KN=set(new TGraph(7, pole_KN_range, pole_KN_mean), 3);
  TGraph* gra_upper_KN=set(new TGraph(7, pole_KN_range, pole_KN_upper), 3);
  TGraph* gra_lower_KN=set(new TGraph(7, pole_KN_range, pole_KN_lower), 3);

  TGraph* gra_mean_Kmp=set(new TGraph(7, pole_Kmp_range, pole_Kmp_mean), kRed);
  TGraph* gra_upper_Kmp=set(new TGraph(7, pole_Kmp_range, pole_Kmp_upper), kRed);
  TGraph* gra_lower_Kmp=set(new TGraph(7, pole_Kmp_range, pole_Kmp_lower), kRed);

  TGraph* gra_mean_KzeroN=set(new TGraph(7, pole_KzeroN_range, pole_KzeroN_mean), kBlue);
  TGraph* gra_upper_KzeroN=set(new TGraph(7, pole_KzeroN_range, pole_KzeroN_upper), kBlue);
  TGraph* gra_lower_KzeroN=set(new TGraph(7, pole_KzeroN_range, pole_KzeroN_lower), kBlue);

  gra_mean_KN-> GetYaxis()-> SetRangeUser(1.410, 1.430);
  gra_upper_KN-> SetMarkerStyle(23);
  gra_lower_KN-> SetMarkerStyle(22);

  gra_mean_Kmp-> GetYaxis()-> SetRangeUser(1.410, 1.430);
  gra_upper_Kmp-> SetMarkerStyle(23);
  gra_lower_Kmp-> SetMarkerStyle(22);

  gra_mean_KzeroN-> GetYaxis()-> SetRangeUser(1.410, 1.430);
  gra_upper_KzeroN-> SetMarkerStyle(23);
  gra_lower_KzeroN-> SetMarkerStyle(22);

  gra_mean_KN-> Draw("APL");
  gra_upper_KN-> Draw("PL");
  gra_lower_KN-> Draw("PL");
  c1-> Print("pic/Dron/L1405_pole_range_Kmp.eps");

  gra_mean_Kmp-> Draw("APL");
  gra_upper_Kmp-> Draw("PL");
  gra_lower_Kmp-> Draw("PL");
  c1-> Print("pic/Dron/L1405_pole_range_KN.eps");

  gra_mean_KzeroN-> Draw("APL");
  gra_upper_KzeroN-> Draw("PL");
  gra_lower_KzeroN-> Draw("PL");
  c1-> Print("pic/Dron/L1405_pole_range_KzeroN.eps");
}

TGraph *set(TGraph *gra, int color=kBlack){
  gra->SetTitle("");
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra-> SetLineWidth(2);

  gra->SetMarkerColor(color);
  gra->SetLineColor(color);
  gra->SetMarkerStyle(8);
  gra->SetMarkerSize(1.5);

  return gra;
}


TGraph* make_chi2NDF_graph(double range[], double chi2[], double ndf[]){
  double chi2NDF[7];
  for( int i=0; i<7; i++ ) chi2NDF[i]=chi2[i]/ndf[i];
  return new TGraph(7, range, chi2NDF);
}
