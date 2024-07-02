#include "macro/init.C"
#include <iostream>

void draw_all_phase(){
  init();

  const double kpThre=(kpMass+pMass);
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

  TGraphErrors *gra_sub=new TGraphErrors(x_sub.size(), &x_sub[0], &y_sub[0], &xerr_arr[0], &sub_err[0]);
  TGraphErrors *gra_ave=new TGraphErrors(x_ave.size(), &x_ave[0], &y_ave[0], &xerr_arr[0], &ave_err[0]);
  TGraphErrors *gra_I0=new TGraphErrors(x_ave.size(), &x_ave[0], &y_I0[0], &xerr_arr[0], &I0_err[0]);
  TGraphErrors *gra_pimS0=new TGraphErrors(x_ave.size(), &x_ave[0], &y_pimS0[0], &xerr_arr[0], &pimS0_err[0]);
  TFile *f=new TFile("~/spectra.root");
  TFile *f2=new TFile("~/spectra_fit.root");
  TFile *f3=new TFile("~/spectra_fit2.root");
  TDirectory *dir=(TDirectory*)f2-> Get("fit_model_B");
  TGraphErrors *gra_pimSp=(TGraphErrors*)f-> Get("pimSp_CS0");
  TGraphErrors *gra_pipSm=(TGraphErrors*)f-> Get("pipSm_CS0");
  set(gra_sub);
  set(gra_I0);
  set(gra_pimS0, 3);
  set(gra_pimSp, kRed);
  set(gra_pipSm, kBlue);

  f-> ls();
  double scaleI0=0.692;
  double scaleI1=1.697;
  double B=0.670;
  double scale_interfer=sqrt(scaleI0*scaleI1)*B;

  double scaleI0_2=0.704;
  double scaleI1_2=1.461;
  double B_2=0.751;
  double scale_interfer_2=sqrt(scaleI0_2*scaleI1_2)*B_2;
  TGraph *gra_I0_calc=(TGraph*)f->Get("pi0S0_modelB_conv");
  TGraph *gra_interfer_calc=(TGraph*)f->Get("interfer_B_conv");
  TGraph *gra_I1_calc=(TGraph*)f->Get("pimS0_modelB_conv");
  TGraph *gra_pimSp_calc_1=(TGraph*)dir->Get("gra_pimSp");
  TGraph *gra_pipSm_calc_1=(TGraph*)dir->Get("gra_pipSm");
  TDirectory *dir=(TDirectory*)f3-> Get("fit_model_B_2");
  TGraph *gra_pimSp_calc_2=(TGraph*)dir->Get("gra_pimSp");
  TGraph *gra_pipSm_calc_2=(TGraph*)dir->Get("gra_pipSm");
  gra_I0_calc_1 = scale(gra_I0_calc, scaleI0);
  gra_I1_calc_1 = scale(gra_I1_calc, scaleI1);
  gra_interfer_calc_1 = scale(gra_interfer_calc, scale_interfer);
  gra_I0_calc_2 = scale(gra_I0_calc, scaleI0_2);
  gra_I1_calc_2 = scale(gra_I1_calc, scaleI1_2);
  gra_interfer_calc_2 = scale(gra_interfer_calc, scale_interfer_2);

  set(gra_I0_calc_1, 46);
  set(gra_interfer_calc_1, 46);
  set(gra_I1_calc_1, 46);
  set(gra_pimSp_calc_1, 46);
  set(gra_pipSm_calc_1, 46);

  set(gra_I0_calc_2, 38);
  set(gra_interfer_calc_2, 38);
  set(gra_I1_calc_2, 38);
  set(gra_pimSp_calc_2, 38);
  set(gra_pipSm_calc_2, 38);
  //  set(gra_pimSp_calc_2, kRed);
  //  set(gra_pipSm_calc_2, kBlue);
  gra_sub->GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_sub-> Draw("AP");
  gra_interfer_calc_1-> Draw("PL");
  gra_interfer_calc_2-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/interfer_fit_2.eps");

  gra_pimS0->GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimS0-> Draw("AP");
  gra_I1_calc_1-> Draw("PL");
  gra_I1_calc_2-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/I1_fit.eps");

  gra_I0->GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_I0-> Draw("AP");
  gra_I0_calc_1-> Draw("PL");
  gra_I0_calc_2-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/I0_fit_2.eps");

  gra_pimSp->GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimSp-> Draw("AP");
  gra_pimSp_calc_1-> Draw("PL");
  gra_pimSp_calc_2-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/DCC_pimSp_B_fit_2.eps");

  gra_pipSm->GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pipSm-> Draw("AP");
  gra_pipSm_calc_1-> Draw("PL");
  gra_pipSm_calc_2-> Draw("PL");
  line.DrawLine(kpThre, 0.0, kpThre, 30);
  c1-> Print("~/ag_Run78/pic/Dron/DCC_pipSm_B_fit_2.eps");
}

void set(TGraphErrors *gra, int colorID=kBlack){
  //  gra=GevToMev(gra);
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
  //  gra=GevToMev(gra);
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

TGraph* scale(TGraph *gra, double val){
  std::vector<double> x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra->GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(val*tmpy);

    std::cout<<tmpx<<"   "<<tmpy<<"   "<<std::endl;
  }
  return new TGraph(x.size(), &x[0], &y[0]);
}
