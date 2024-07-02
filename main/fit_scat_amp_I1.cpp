#include "common.hh" 
#include "TMatrix.hh"
#include "reso.hh"
#include <TMinuit.h>
#include <TNtuple.h>

const TString inrootfile="~/spectra.root";
const TString outrootfile="~/spectra_fit_scat_amp_I1.root";

const int PRINT_LEVEL=-1;

TransMatrix KN_piS_T(piMass, sigmaMass, kMass, NMass);
TGraph *responseFunc;
TGraph *gra_data;

void fit();
void fcn(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag);
void get_chi2_ndf(Double_t &chi2, Int_t &ndf, const Double_t *par);
void save();

void save(double chi2, int ndf, double par[5]){
  TNtuple *tup=new TNtuple("fit_params", "", "chi2:NDF:scale:A_I1_re:A_I1_im:R_I1_re:R_I1_im");
  tup-> Fill(chi2, ndf, par[0], par[1], par[2], par[3], par[4]);

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
  gra_fit-> Write("fit_pimS0");
  gra_fit_wReso-> Write("fit_pimS0_wReso");

  TGraph *gra_KN_KN_re   = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_re[0]);
  TGraph *gra_KN_KN_im   = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_im[0]);
  TGraph *gra_KN_KN_abs2 = new TGraph(mass.size(), &mass[0], &T_I1_KN_KN_abs2[0]);
  TGraph *gra_KN_piS_re   = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_re[0]);
  TGraph *gra_KN_piS_im   = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_im[0]);
  TGraph *gra_KN_piS_abs2 = new TGraph(mass.size(), &mass[0], &T_I1_KN_piS_abs2[0]);
  gra_KN_KN_re-> Write("gra_I1_KN_KN_re");
  gra_KN_KN_im-> Write("gra_I1_KN_KN_im");
  gra_KN_KN_abs2-> Write("gra_I1_KN_KN_abs2");
  gra_KN_piS_re-> Write("gra_I1_KN_piS_re");
  gra_KN_piS_im-> Write("gra_I1_KN_piS_im");
  gra_KN_piS_abs2-> Write("gra_I1_KN_piS_abs2");

  //  TGraph *gra_A_re=new TGraph(mass.size(); &mass[0],
}

void fit(){
  TMinuit* minuit=new TMinuit(5);
  minuit-> SetPrintLevel(PRINT_LEVEL);
  TString name[5] = { "scale", "A_re", "A_im", "R_re", "R_im" };
  double par[5]   = { 0.56, KN_piS_T.getA().real(), KN_piS_T.getA().imag(), 0, 0 };
  double err[5]  = { 0.01, 0.01*KN_piS_T.getA().real(), 0.01*KN_piS_T.getA().imag(), 0.01*KN_piS_T.getA().real(), 0.01*KN_piS_T.getA().imag() };
  int flag=0;
  for( int i=0; i<5; i++ ) minuit->mnparm(i, name[i], par[i], err[i], -9999, 9999, flag);
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
  save(chi2, ndf, par);
  std::cout<<"chi2/NDF = "<<chi2<<"/"<<ndf<<" = "<<chi2/ndf<<std::endl;
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

int main(){
  TFile *f=new TFile(inrootfile);
  TGraphErrors *data=(TGraphErrors*)f->Get("pimS0_CS0");
  responseFunc=(TGraph*)f->Get("responseFunc");
  gra_data=(TGraphErrors*)f->Get("pimS0_CS0");

  TFile *of=new TFile(outrootfile, "recreate");
  gra_data-> Write("pimS0_CS0");
  responseFunc-> Write("responseFunc");
  KN_piS_T.setA(std::complex<double>(0.60, 0.50));
  KN_piS_T.setR(std::complex<double>(0, 0));
  fit();

  of-> Write();
  of-> Close();
}
