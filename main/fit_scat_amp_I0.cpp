#include "common.hh" 
#include "TMatrix.hh"
#include "reso.hh"
#include "root_util.hh"
#include <TMinuit.h>
#include <TNtuple.h>
#include "util.hh"

const TString inrootfile="~/spectra.root";
const TString outrootfile="~/spectra_fit_scat_amp_I0.root";

const int PRINT_LEVEL=-1;

TransMatrix KN_piS_T(piMass, sigmaMass, kMass, NMass);
TGraph *responseFunc;
TGraph *gra_data;
double init_par[5]  = { 0.04, -1.00, 0.80, -0.2, -0.40 }; 

void fit();
void fcn(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag);
void get_chi2_ndf(Double_t &chi2, Int_t &ndf, const Double_t *par);
void save();
void mkdir(TFile *of, TString name);

int main(){
  TFile *f=new TFile(inrootfile);
  TGraphErrors *data=(TGraphErrors*)f->Get("");
  responseFunc=(TGraph*)f->Get("responseFunc");
  gra_data=root_util::set_opts((TGraphErrors*)f->Get("I0_CS"));
  for( int i=0; i<gra_data->GetN(); i++ ){
    double x, y;
    gra_data-> GetPoint(i, x, y);
    double erry = gra_data->GetErrorY(i);
    std::cout<<i<<"  "<<x<<"  "<<y<<"  "<<erry<<std::endl;
  }
  return 0;
  
  TFile *of=new TFile(outrootfile, "recreate");
  gra_data-> Write("I0_CS");
  KN_piS_T.setA(std::complex<double>(0.60, 0.50));
  KN_piS_T.setR(std::complex<double>(0, 0));

  mkdir(of, "KN");
  fit();

  responseFunc=(TGraph*)f-> Get("responseFunc_kmp");
  KN_piS_T.setMasses(piMass, sigmaMass, kmMass, pMass);
  mkdir(of, "Kmp");
  fit();

  responseFunc=(TGraph*)f-> Get("responseFunc_k0n");
  KN_piS_T.setMasses(piMass, sigmaMass, k0Mass, nMass);
  mkdir(of, "KzeroN");
  fit();

  of-> Write();
  of-> Close();
}

void mkdir(TFile *of, TString name){
  std::cout<<"TFile("<<of->GetName()<<")  mkdir("<<name<<")"<<std::endl;
  TDirectory *dir=(TDirectory*)of-> mkdir(name);
  dir-> cd();
}

void save(double chi2, int ndf, double par[5], double err[5]){
  std::vector<double> mass0, fit_pimS0;
  for( double i=0; i<responseFunc->GetN(); i++ ){
    double x, y;
    responseFunc->GetPoint(i, x, y);
    mass0.push_back(x);
    fit_pimS0.push_back(par[0]*y*norm(KN_piS_T.amp12(x)));
  }

  std::vector<double> mass, T_I1_KN_KN_re, T_I1_KN_KN_im, T_I1_KN_piS_re, T_I1_KN_piS_im, T_I1_KN_KN_abs2, T_I1_KN_piS_abs2, fit_pimS0_wReso;
  for( double m=1.3; m<1.6; m+=0.001 ){
    fit_pimS0_wReso.push_back(reso::conv_kp(m, mass0, fit_pimS0));
    mass.push_back(m);
    T_I1_KN_KN_re.push_back(KN_piS_T.amp22(m).real());
    T_I1_KN_KN_im.push_back(KN_piS_T.amp22(m).imag());
    T_I1_KN_KN_abs2.push_back(norm(KN_piS_T.amp22(m)));
    T_I1_KN_piS_re.push_back(KN_piS_T.amp12(m).real());
    T_I1_KN_piS_im.push_back(KN_piS_T.amp12(m).imag());
    T_I1_KN_piS_abs2.push_back(norm(KN_piS_T.amp12(m)));
  }
  TGraph *gra_fit        = new TGraph(mass0.size(), &mass0[0], &fit_pimS0[0]);
  TGraph *gra_fit_wReso  = new TGraph(mass.size(), &mass[0], &fit_pimS0_wReso[0]);
  gra_fit-> Write("fit_I0");
  gra_fit_wReso-> Write("fit_I0_wReso");

  TGraph *gra_KN_KN_re   = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_re[0]);
  TGraph *gra_KN_KN_im   = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_im[0]);
  TGraph *gra_KN_KN_abs2 = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_abs2[0]);
  TGraph *gra_KN_piS_re   = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_re[0]);
  TGraph *gra_KN_piS_im   = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_im[0]);
  TGraph *gra_KN_piS_abs2 = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_abs2[0]);
  gra_KN_KN_re-> Write("gra_I0_KN_KN_re");
  gra_KN_KN_im-> Write("gra_I0_KN_KN_im");
  gra_KN_KN_abs2-> Write("gra_I0_KN_KN_abs2");
  gra_KN_piS_re-> Write("gra_I0_KN_piS_re");
  gra_KN_piS_im-> Write("gra_I0_KN_piS_im");
  gra_KN_piS_abs2-> Write("gra_I0_KN_piS_abs2");

  responseFunc-> Write("responseFunc");

  std::vector<TGraphAsymmErrors*> gras=util::TMatrix::make_amp12_TGraphErrors(KN_piS_T, err[1]/Const_GeVFM, err[2]/Const_GeVFM, err[3]/Const_GeVFM, err[4]/Const_GeVFM);
  double pole, pole_min, pole_max, width, width_min, width_max;
  util::TMatrix::getPoleWidth(KN_piS_T, err[1]/Const_GeVFM, err[2]/Const_GeVFM, err[3]/Const_GeVFM, err[4]/Const_GeVFM, pole, pole_min, pole_max, width, width_min, width_max);
  gras[0]-> Write("gra_I0_KN_KN_re_wErr");
  gras[1]-> Write("gra_I0_KN_KN_im_wErr");

  TNtuple *tup=new TNtuple("fit_params", "", "chi2:NDF:scale:scale_err:A_I0_re:A_I0_re_err:A_I0_im:A_I0_im_err:R_I0_re:R_I0_re_err:R_I0_im:R_I0_im_err:Pole:Width");
  tup-> Fill(chi2, ndf, par[0], err[0], par[1], err[1], par[2], err[2], par[3], err[3], par[4], err[4], pole, width);
}

void fit(){
  TMinuit* minuit=new TMinuit(5);
  minuit-> SetPrintLevel(PRINT_LEVEL);
  TString name[5] = { "scale", "A_re", "A_im", "R_re", "R_im" };
  double par[5];
  //  double par[5]  = { 0.2, KN_piS_T.getA().real(), KN_piS_T.getA().imag(), 0, 0 };
  double err[5];
  for( int i=0; i<5; i++ ){
    par[i]=init_par[i];
    err[i]=0.01*fabs(init_par[i]);
  }
  int flag=0;
  for( int i=0; i<5; i++ ){
    std::cout<<"Set Prameter "<<i<<" "<<name[i]<<"\t"<<par[i]<<"\t"<<err[i]<<std::endl;
    minuit->mnparm(i, name[i], par[i], err[i], -9999, 9999, flag);
  }
  Double_t arglist[20]; arglist[0]=3000; arglist[1]=1;
  Int_t ierflag;

  minuit-> SetFCN(fcn);
  minuit-> Command("Set Strategy 0");
  minuit-> mnexcm("SIMPLEX", arglist, 1, ierflag);
  minuit-> mnexcm("MIGRAD", arglist, 1, ierflag);
  minuit-> mnexcm("HESSE", arglist, 1, ierflag);

  double chi2;
  int ndf;

  for( int i=0; i<minuit->GetNumPars(); i++ ){
    TString name; double bnd1, bnd2; int flag;
    minuit-> mnpout(i, name, par[i], err[i], bnd1, bnd2, flag);
    std::cout<<i<<"  "<<name<<"   \t"<<par[i]<<" +- "<<err[i]<<"   "<<bnd1<<"-"<<bnd2<<"  flag="<<flag<<std::endl;
  }
  get_chi2_ndf(chi2, ndf, par);
  ndf-=5;
  std::cout<<"chi2/NDF = "<<chi2<<"  "<<ndf<<" = "<<chi2/ndf<<std::endl;
  save(chi2, ndf, par, err);

  //  for( int i=0; i<5; i++ ) init_par[i]=par[i];
  delete minuit;
}

void fcn(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag){
  chi2=9999;
  Int_t ndf=0;
  KN_piS_T.setA(std::complex<double>(par[1], par[2])/Const_GeVFM);
  KN_piS_T.setR(std::complex<double>(par[3], par[4])/Const_GeVFM);
  get_chi2_ndf(chi2, ndf, par);
}

void get_chi2_ndf(Double_t &chi2, Int_t &ndf, const Double_t *par){
  std::vector<double> mass, pimS0_y;
  for( int i=0; i<responseFunc->GetN(); i++ ){
    double x, y;
    responseFunc->GetPoint(i, x, y);
    mass.push_back(x);
    pimS0_y.push_back(par[0]*norm(KN_piS_T.amp12(x))*y);
  }

  chi2=0; ndf=0;
  for( int i=0; i<gra_data->GetN(); i++ ){
    double x, y;
    gra_data-> GetPoint(i, x, y);
    double err=gra_data->GetErrorY(i);
    double calc_y=reso::conv_kp(x, mass, pimS0_y);

    if( x<1.35 || 1.5<x ) continue;
    if( err<1.0e-8 ) continue;
    
    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }

  // std::cout<<"chi2 = "<<chi2<<"   NDF = "<<ndf<<"   chi2/NDF = "<<chi2/ndf<<std::endl;
  // std::cout<<"Exit Call"<<std::endl;
  // exit(0);
}

