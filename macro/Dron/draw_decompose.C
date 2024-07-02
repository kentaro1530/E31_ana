#include "macro/init.C"

void draw_decompose(){
  init();

  ifstream ifs_ave("/home/had/kinoue/ag_Run78/txt/Run78/pimSp_pipSm_ave_CS_NC170_2sigma.txt");
  ifstream ifs_sub("/home/had/kinoue/ag_Run78/txt/Run78/pimSp_pipSm_sub_CS_NC170_2sigma.txt");
  ifstream ifs_I1("txt/pimS0_CS.txt");
  string str;
  std::vector<double> x_ave, x_sub, x_pimS0, y_ave, y_sub, y_pimS0, xerr_arr, ave_err, ave_err2, ave_err3, sub_err, sub_err2, sub_err3,  pimS0_err, pimS0_err2;
  while( getline(ifs_ave, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==6 ){
      x_ave.push_back(x);
      y_ave.push_back(y);
      ave_err.push_back(err);
      ave_err2.push_back(err2);
      ave_err3.push_back(err3);
      xerr_arr.push_back(xerr);
    }
  }

  while( getline(ifs_sub, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==6 ){
      x_sub.push_back(x);
      y_sub.push_back(y);
      sub_err.push_back(err);
      sub_err2.push_back(err2);
      sub_err3.push_back(err3);
    }
  }

  while( getline(ifs_I1, str) ){
    double x, y, xerr, err, err2, err3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &x, &y, &xerr, &err, &err2, &err3)==5 ){
      x_pimS0.push_back(x);
      y_pimS0.push_back(y);
      pimS0_err.push_back(err);
      pimS0_err2.push_back(err2);
    }
  }

  std::vector<double> y_I0, I0_err, I0_err2, I0_err3;
  for( int i=0; i<y_ave.size(); i++ ){
    y_I0.push_back(y_ave[i]-0.5*y_pimS0[i]);
    I0_err.push_back(sqrt(pow(ave_err[i], 2)+pow(0.5*pimS0_err[i], 2)));
    I0_err2.push_back(sqrt(pow(ave_err2[i], 2)+pow(0.5*pimS0_err2[i], 2)));
    I0_err3.push_back(sqrt(pow(ave_err3[i], 2)+pow(0.5*pimS0_err2[i], 2)));
  }

  TGraphErrors *gra_sub=set(new TGraphErrors(x_sub.size(), &x_sub[0], &y_sub[0], &xerr_arr[0], &sub_err[0]));
  TGraphErrors *gra_sub2=set(new TGraphErrors(x_sub.size(), &x_sub[0], &y_sub[0], &xerr_arr[0], &sub_err2[0]));
  TGraphErrors *gra_sub3=set(new TGraphErrors(x_sub.size(), &x_sub[0], &y_sub[0], &xerr_arr[0], &sub_err3[0]));
  TGraphErrors *gra_ave=set(new TGraphErrors(x_ave.size(), &x_ave[0], &y_ave[0], &xerr_arr[0], &ave_err[0]));
  TGraphErrors *gra_I0_2=set(new TGraphErrors(x_ave.size(), &x_ave[0], &y_I0[0], &xerr_arr[0], &I0_err2[0]));
  TGraphErrors *gra_I0_3=set(new TGraphErrors(x_ave.size(), &x_ave[0], &y_I0[0], &xerr_arr[0], &I0_err3[0]));
  TGraphErrors *gra_I0=set(new TGraphErrors(x_ave.size(), &x_ave[0], &y_I0[0], &xerr_arr[0], &I0_err[0]));
  TGraphErrors *gra_pimS0=set(new TGraphErrors(x_ave.size(), &x_ave[0], &y_pimS0[0], &xerr_arr[0], &pimS0_err[0]));
  gra_sub-> SetLineWidth(1);
  gra_I0-> SetLineWidth(1);

  gra_sub2-> SetFillStyle(0);
  gra_I0_2-> SetFillStyle(0);
  gra_sub-> SetFillStyle(0);
  gra_I0-> SetFillStyle(0);

  gra_sub3-> Draw("AP");
  gra_sub2-> Draw("P2");
  gra_sub-> Draw("P2");
  drawKPthre();
  c1-> Print("pic/Dron/interfer.eps");

  gra_I0_3-> Draw("AP");
  gra_I0_2-> Draw("P2");
  gra_I0-> Draw("P2");
  drawKPthre();
  c1-> Print("pic/Dron/I0.eps");
}

void drawKPthre(){
  const double kpThre=(kpMass+pMass);
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);
  line.DrawLine(kpThre, 0.0, kpThre, 30);
}

TGraphErrors* set(TGraphErrors *gra, int colorID=kBlack){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);
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
  return gra;
}

TGraph* set(TGraph *gra, int colorID=kBlack){
  gra-> SetLineColor(colorID);
  gra-> SetLineWidth(3);
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);
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
  return gra;
}
