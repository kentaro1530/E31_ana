#include "macro/init.C"

double searchPole(TGraph* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy;
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}

double searchPole_min(TGraphAsymmErrors* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy-gra->GetErrorYlow(i);
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}

double searchPole_max(TGraphAsymmErrors* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy+gra->GetErrorYhigh(i);
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}

void draw_fit_scat_amp_I0(){
  init();
  TFile *f=new TFile("~/spectra_fit_scat_amp_I0.root");
  
  draw(f, "KN");
  printParam(f, "KN");
  c1-> Print("pic/Dron/fit_I0_KN.eps");
  drawScatAmp(f, "KN");
  c1-> Print("pic/Dron/fit_scat_amp_I0_KN.eps");

  draw(f, "KzeroN");
  printParam(f, "KzeroN");
  c1-> Print("pic/Dron/fit_I0_KzeroN.eps");
  drawScatAmp(f, "KzeroN");
  c1-> Print("pic/Dron/fit_scat_amp_I0_KzeroN.eps");

  draw(f, "Kmp");
  printParam(f, "Kmp");
  c1-> Print("pic/Dron/fit_I0_Kmp.eps");
  drawScatAmp(f, "Kmp");
  c1-> Print("pic/Dron/fit_scat_amp_I0_Kmp.eps");
  return;
}

void printParam(TFile*f, TString dirName){
  TDirectory* dir=(TDirectory*)f->Get(dirName);
  TNtuple *tup=(TNtuple*)dir-> Get("fit_params");
  float chi2, ndf, scale, scale_err, A_I0_re, A_I0_re_err, A_I0_im, A_I0_im_err, R_I0_re, R_I0_re_err, R_I0_im, R_I0_im_err;
  tup-> SetBranchAddress("chi2", &chi2);
  tup-> SetBranchAddress("NDF", &ndf);
  tup-> SetBranchAddress("scale", &scale);
  tup-> SetBranchAddress("scale_err", &scale_err);
  tup-> SetBranchAddress("A_I0_re", &A_I0_re);
  tup-> SetBranchAddress("A_I0_re_err", &A_I0_re_err);
  tup-> SetBranchAddress("A_I0_im", &A_I0_im);
  tup-> SetBranchAddress("A_I0_im_err", &A_I0_im_err);
  tup-> SetBranchAddress("R_I0_re", &R_I0_re);
  tup-> SetBranchAddress("R_I0_re_err", &R_I0_re_err);
  tup-> SetBranchAddress("R_I0_im", &R_I0_im);
  tup-> SetBranchAddress("R_I0_im_err", &R_I0_im_err);
  tup-> GetEntry(0);

  std::cout<<chi2<<"/"<<ndf<<"="<<chi2/ndf<<std::endl;
  std::cout<<scale<<" +- "<<scale_err<<std::endl;
  std::cout<<A_I0_re<<" +- "<<A_I0_re_err<<std::endl;
  std::cout<<A_I0_im<<" +- "<<A_I0_im_err<<std::endl;
  std::cout<<R_I0_re<<" +- "<<R_I0_re_err<<std::endl;
  std::cout<<R_I0_im<<" +- "<<R_I0_im_err<<std::endl;
}

TGraph* setOpts(TGraph* gra){
  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  return gra;
}

void drawScatAmp(TFile *f, TString dirName){
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TGraph* gra_re=setOpts(scale(Const_GeVFM, (TGraph*)dir->Get("gra_I0_KN_KN_re")));
  TGraph* gra_im=scale(Const_GeVFM, (TGraph*)dir->Get("gra_I0_KN_KN_im"));
  TGraphAsymmErrors* gra_re_wErr=scaleAsymm(Const_GeVFM, (TGraphAsymmErrors*)dir->Get("gra_I0_KN_KN_re_wErr"));
  TGraphAsymmErrors* gra_im_wErr=scaleAsymm(Const_GeVFM, (TGraphAsymmErrors*)dir->Get("gra_I0_KN_KN_im_wErr"));
  gra_re_wErr-> SetFillColor(kRed);
  gra_im_wErr-> SetFillColor(kBlue);
  gra_re_wErr-> SetFillStyle(3001);
  gra_im_wErr-> SetFillStyle(3001);
  gra_re-> SetLineWidth(2);
  gra_im-> SetLineWidth(2);
  gra_re-> SetLineColor(kRed);
  gra_im-> SetLineColor(kBlue);
  gra_re-> SetTitle(0);
  gra_re-> GetYaxis()-> SetRangeUser(-1.5, 3.5);
  gra_re-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_re-> Draw("AL");
  gra_im-> Draw("L");
  gra_im_wErr-> Draw("4");
  gra_re_wErr-> Draw("4");

  double pole=searchPole(gra_re);
  double pole_min=searchPole_min(gra_re_wErr);
  double pole_max=searchPole_max(gra_re_wErr);

  std::cout<<"Pole position : "<<pole<<" -"<<pole-pole_min<<" +"<<pole_max-pole<<std::endl;

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(kMass+NMass, -1.5, kMass+NMass, 3.5);
}

void draw(TFile *f, TString dirName){
  TGraphErrors *data=(TGraphErrors*)f->Get("I0_CS");
  data-> GetYaxis()-> SetRangeUser(0, 20);
  data-> Draw("AP");

  TDirectory* dir=(TDirectory*)f->Get(dirName);
  TGraph *responseFunc=(TGraph*)dir->Get("responseFunc");
  TGraph* gra_I0=(TGraph*)dir->Get("fit_I0");
  TGraph* gra_I0_wReso=(TGraph*)dir->Get("fit_I0_wReso");
  responseFunc=scale(0.25, responseFunc);
  responseFunc-> SetLineWidth(2);
  responseFunc-> SetLineColor(kBlue);
  responseFunc-> SetLineStyle(9);
  responseFunc-> Draw("L");

  gra_I0-> SetLineColor(kRed);
  gra_I0-> SetLineWidth(2);
  gra_I0-> SetLineStyle(9);
  gra_I0-> Draw("L");

  gra_I0_wReso-> SetLineColor(kRed);
  gra_I0_wReso-> SetLineWidth(2);
  gra_I0_wReso-> Draw("L");

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(kMass+NMass, 0, kMass+NMass, 20);
}

TGraph* scale(double scale, TGraph* gra){
  std::vector<double>x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(scale*tmpy);
  }
  TGraph* gra= new TGraph(x.size(), &x[0], &y[0]);
  return gra;
}

TGraphAsymmErrors* scaleAsymm(double scale, TGraphAsymmErrors* gra){
  std::vector<double> x, y, xerr_min, xerr_max, yerr_min, yerr_max;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra->GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(scale*tmpy);
    xerr_min.push_back(gra->GetErrorXlow(i));
    xerr_max.push_back(gra->GetErrorXhigh(i));
    yerr_min.push_back(scale*gra->GetErrorYlow(i));
    yerr_max.push_back(scale*gra->GetErrorYhigh(i));
  }
  //  for( int i=0; i<x.size(); i++ ) std::cout<<x[i]<<"  "<<xerr_min[i]<<"  "<<xerr_max[i]<<"  "<<y[i]<<"  "<<yerr_min[i]<<"  "<<yerr_max[i]<<std::endl

  return new TGraphAsymmErrors(x.size(), &x[0], &y[0], &xerr_min[0], &xerr_max[0], &yerr_min[0], &yerr_max[0]);
}
