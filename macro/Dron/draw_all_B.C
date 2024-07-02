#include "macro/init.C"
#include <iostream>

void draw_all_B(){
  init();

  const double kpThre=1000*(kpMass+pMass);
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);  
  ifstream ifs_ave("/home/had/kinoue/ag_Run78/txt/Run78/pimSp_pipSm_ave_CS_NC170_2sigma.txt");
  ifstream ifs_sub("/home/had/kinoue/ag_Run78/txt/Run78/pimSp_pipSm_sub_CS_NC170_2sigma.txt");
  ifstream ifs_I0("txt/pimS0_CS.txt");
  string str;
  std::vector<double> x_ave, x_sub, x_pimS0, y_ave, y_sub, y_pimS0, xerr_arr, ave_err, sub_err, pimS0_err;
  while( getline(ifs_ave, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==6 ){
      x_ave.push_back(x);
      y_ave.push_back(y);
      ave_err.push_back(err3);
      xerr_arr.push_back(xerr);
    }
  }

  while( getline(ifs_sub, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==6 ){
      x_sub.push_back(x);
      y_sub.push_back(y);
      sub_err.push_back(err3);
    }
  }

  while( getline(ifs_I0, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==5 ){
      x_pimS0.push_back(x);
      y_pimS0.push_back(y);
      pimS0_err.push_back(err2);
    }
  }
  
  std::vector<double> y_I0, I0_err;
  for( int i=0; i<y_ave.size(); i++ ){
    y_I0.push_back(y_ave[i]-0.5*y_pimS0[i]);
    I0_err.push_back(sqrt(pow(ave_err[i], 2)+pow(0.5*pimS0_err[i], 2)));
  }

  TGraphErrors *gra_sub=GevToMev(new TGraphErrors(x_sub.size(), &x_sub[0], &y_sub[0], &xerr_arr[0], &sub_err[0]));
  TGraphErrors *gra_ave=GevToMev(new TGraphErrors(x_ave.size(), &x_ave[0], &y_ave[0], &xerr_arr[0], &ave_err[0]));
  TGraphErrors *gra_I0=GevToMev(new TGraphErrors(x_ave.size(), &x_ave[0], &y_I0[0], &xerr_arr[0], &I0_err[0]));
  TGraphErrors *gra_pimS0=GevToMev(new TGraphErrors(x_ave.size(), &x_ave[0], &y_pimS0[0], &xerr_arr[0], &pimS0_err[0]));
  TFile *f=new TFile("~/spectra.root");
  TGraphErrors *gra_pimSp=(TGraphErrors*)f-> Get("pimSp_CS0");
  TGraphErrors *gra_pipSm=(TGraphErrors*)f-> Get("pipSm_CS0");
  gra_pimSp=GevToMev(gra_pimSp);
  gra_pipSm=GevToMev(gra_pipSm);
  set(gra_sub);
  set(gra_I0);
  set(gra_pimS0, 3);
  set(gra_pimSp, kRed);
  set(gra_pipSm, kBlue);
  
  TGraph *gra_I0_calc=(TGraph*)f->Get("pi0S0_modelB_conv");
  TGraph *gra_interfer_calc=(TGraph*)f->Get("interfer_B_conv");
  TGraph *gra_I1_calc=(TGraph*)f->Get("pimS0_modelB_conv");
  TGraph *gra_pimSp_calc=(TGraph*)f->Get("pimSp_modelB_conv");
  TGraph *gra_pipSm_calc=(TGraph*)f->Get("pipSm_modelB_conv");
  gra_I0_calc=GevToMev(gra_I0_calc);
  gra_interfer_calc=GevToMev(gra_interfer_calc);
  gra_I1_calc=GevToMev(gra_I1_calc);
  gra_pimSp_calc=GevToMev(gra_pimSp_calc);
  gra_pipSm_calc=GevToMev(gra_pipSm_calc);

  set(gra_I0_calc);
  set(gra_interfer_calc);
  set(gra_I1_calc, 3);
  set(gra_pimSp_calc, kRed);
  set(gra_pipSm_calc, kBlue);
  gra_interfer_calc-> Draw("APL");

  gra_sub-> Draw("AP");
  gra_interfer_calc-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/interfer_B.eps");

  gra_pimS0-> Draw("AP");
  gra_I1_calc-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/I1_B.eps");

  gra_I0-> Draw("AP");
  gra_I0_calc-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/I0_B.eps");

  gra_pimSp-> Draw("AP");
  gra_pimSp_calc-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/DCC_pimSp_B.eps");

  gra_pipSm-> Draw("AP");
  gra_pipSm_calc-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/DCC_pipSm_B.eps");
}

void set(TGraphErrors *gra, int colorID=kBlack){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1350, 1500);
  gra-> GetYaxis()-> SetRangeUser(0, 30);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();

  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
}

void set(TGraph *gra, int colorID=kBlack){
  gra-> SetLineColor(colorID);
  gra-> SetLineWidth(3);
  gra-> GetXaxis()-> SetRangeUser(1350, 1500);
  gra-> GetYaxis()-> SetRangeUser(0, 30);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();

  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");
}
