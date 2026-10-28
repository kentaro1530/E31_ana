#include "common.hh"
#include "TMatrix.hh"
#include "reso.hh"
#include "root_util.hh"
#include <TMinuit.h>
#include <TNtuple.h>
#include "util.hh"

const TString inrootfile="~/spectra.root";
const TString inrootfile2="~/spectra_fit_scat_amp_I0.root";
const TString outrootfile="spectra_fit_scat_amp_int.root";

const int PRINT_LEVEL=-1;

TransMatrix KN_piS_T_I0(piMass, sigmaMass, kMass, NMass);
TransMatrix KN_piS_T_I1(piMass, sigmaMass, kMass, NMass);
TGraph *responseFunc;
TGraph *gra_data[3];

void fcn(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag);

void fcn(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag){
  chi2 = 0;
  Int_t ndf = 0;
  KN_piS_T_I1.setPhase(par[2]);
  std::vector<double> mass, pimSp_y, pipSm_y, pimS0_y;
  for( int i=0; i<responseFunc->GetN(); i++ ){
    double x, y;
    responseFunc->GetPoint(i, x, y);
    mass.push_back(x);
    std::complex<double> T_I0 = par[0]*KN_piS_T_I0.amp12(x);
    std::complex<double> T_I1 = par[1]*KN_piS_T_I1.amp12(x);

    pimSp_y.push_back(y*(norm(T_I0)+2*real(T_I0*T_I1)+norm(T_I1)));
    pipSm_y.push_back(y*(norm(T_I0)-2*real(T_I0*T_I1)+norm(T_I1)));
    pimS0_y.push_back(y*norm(T_I1));
  }

  for( int j=0; j<3; j++ ){
    for( int i=0; i<gra_data[j]-> GetN(); i++ ){
      double x, y;
      gra_data[j]->GetPoint(i, x, y);
      double err=gra_data[j]->GetErrorY(i);
      
      double calc_y=0;
      if( j==0 )      calc_y=reso::conv_kn(x, mass, pimSp_y);
      else if( j==1 ) calc_y=reso::conv_kn(x, mass, pipSm_y);
      else if( j==2 ) calc_y=reso::conv_kp(x, mass, pimS0_y);

      if( err<1.0e-8 ) continue;
      //      std::cout<<j<<"  "<<i<<"  "<<x<<"  "<<y<<"  "<<calc_y<<"  "<<err<<std::endl;
      chi2 += pow(y-calc_y, 2)/(err*err);
      ndf++;
    }
  }

  //  std::cout<<chi2<<" "<<ndf<<std::endl;
  //  exit(0);
}

int main(){
  TFile *f = new TFile(inrootfile);
  gra_data[0] = (TGraphErrors*)f-> Get("pimSp_CS0");
  gra_data[1] = (TGraphErrors*)f-> Get("pipSm_CS0");
  gra_data[2] = (TGraphErrors*)f-> Get("pimS0_CS0");
  responseFunc=(TGraph*)f->Get("responseFunc");
  
  TFile *f2 = new TFile(inrootfile2);

  TDirectory *dir = (TDirectory*)f2-> Get("KN");
  TNtuple *tup = (TNtuple*)dir-> Get("fit_params");

  Float_t scale, A_re, A_im, R_re, R_im;
  Float_t scale_err, A_re_err, A_im_err, R_re_err, R_im_err;
  tup-> SetBranchAddress("scale", &scale);
  tup-> SetBranchAddress("scale_err", &scale_err);
  tup-> SetBranchAddress("A_I0_re", &A_re);
  tup-> SetBranchAddress("A_I0_re_err", &A_re_err);
  tup-> SetBranchAddress("A_I0_im", &A_im);
  tup-> SetBranchAddress("A_I0_im_err", &A_im_err);
  tup-> SetBranchAddress("R_I0_re", &R_re);
  tup-> SetBranchAddress("R_I0_re_err", &R_re_err);
  tup-> SetBranchAddress("R_I0_im", &R_im);
  tup-> SetBranchAddress("R_I0_im_err", &R_im_err);    
  tup-> GetEntry(0);

  std::cout<<scale<<" +- "<<scale_err<<std::endl;
  std::cout<<A_re<<" +- "<<A_re_err<<std::endl;
  std::cout<<A_im<<" +- "<<A_im_err<<std::endl;
  std::cout<<R_re<<" +- "<<R_re_err<<std::endl;
  std::cout<<R_im<<" +- "<<R_im_err<<std::endl;  
  
  KN_piS_T_I0.setA(std::complex<double>(A_re, A_im)/Const_GeVFM);
  KN_piS_T_I0.setR(std::complex<double>(R_re, R_im)/Const_GeVFM);

  std::cout<<KN_piS_T_I0.getA().real()<<std::endl;
  KN_piS_T_I1.setA(std::complex<double>(0.6, 0.8)/Const_GeVFM);
  KN_piS_T_I1.setR(std::complex<double>(0, 0));
  
  TMinuit* minuit=new TMinuit(3);
  minuit-> SetPrintLevel(PRINT_LEVEL);
  int flag;
  minuit-> mnparm(0, "A_I0",  0.5, 0.1, 0, 5, flag);
  minuit-> mnparm(1, "A_I1",  0.5, 0.1, 0, 5, flag);
  minuit-> mnparm(2, "phase", 0.5, 0.1, -1.7, 1.7, flag);
  Double_t arglist[20]; arglist[0]=3000; arglist[1]=1;
  Int_t ierflag;
  minuit-> SetFCN(fcn);
  minuit-> Command("Set Strategy 0");
  minuit-> mnexcm("SIMPLEX", arglist, 1, ierflag);
  minuit-> mnexcm("MIGRAD", arglist, 1, ierflag);
  minuit-> mnexcm("HESSE", arglist, 1, ierflag);

  TFile *of = new TFile(outrootfile, "recreate");
  gra_data[0]-> Write("pimSp_CS");
  gra_data[1]-> Write("pipSm_CS");
  gra_data[2]-> Write("pimS0_CS");

  double par[3], err[3];
  for( int i=0; i<minuit->GetNumPars(); i++ ){
    TString name; double bnd1, bnd2; int flag;
    minuit-> mnpout(i, name, par[i], err[i], bnd1, bnd2, flag);
    std::cout<<i<<"  "<<name<<"   \t"<<par[i]<<" +- "<<err[i]<<"   "<<bnd1<<"-"<<bnd2<<"  flag="<<flag<<std::endl;
  }
  KN_piS_T_I1.setPhase(par[2]);
  std::cout<<KN_piS_T_I0.getPhase()<<std::endl;
  
  std::vector<double> x, pimSp_y, pipSm_y, pimS0_y, I0_re, I0_im, I1_re, I1_im, I0I1_norm, interfer;
  for( int i=0; i<responseFunc->GetN(); i++ ){
    double m, y;
    responseFunc->GetPoint(i, m, y);
    x.push_back(m);
    std::complex<double> T_I0 = par[0]*KN_piS_T_I0.amp12(m);
    std::complex<double> T_I1 = par[1]*KN_piS_T_I1.amp12(m);
    pimSp_y.push_back(y*(norm(T_I0)+2*real(T_I0*T_I1)+norm(T_I1)));
    pipSm_y.push_back(y*(norm(T_I0)-2*real(T_I0*T_I1)+norm(T_I1)));
    pimS0_y.push_back(y*norm(T_I1));
    I0_re.push_back(T_I0.real());
    I0_im.push_back(T_I0.imag());
    I1_re.push_back(T_I1.real());
    I1_im.push_back(T_I1.imag());
    I0I1_norm.push_back(y*(norm(T_I0)+norm(T_I1)));
    interfer.push_back(y*2*real(T_I0*T_I1));
  }
  std::vector<double> pimSp_y_conv, pipSm_y_conv, pimS0_y_conv;
  for( int i=0; i<x.size(); i++ ){
    pimSp_y_conv.push_back(reso::conv_kn(x[i], x, pimSp_y));
    pipSm_y_conv.push_back(reso::conv_kn(x[i], x, pipSm_y));
    pimS0_y_conv.push_back(reso::conv_kp(x[i], x, pimS0_y));
  }
  
  TGraph *gra_pimSp = new TGraph(x.size(), &x[0], &pimSp_y[0]);
  TGraph *gra_pipSm = new TGraph(x.size(), &x[0], &pipSm_y[0]);
  TGraph *gra_pimS0 = new TGraph(x.size(), &x[0], &pimS0_y[0]);
  TGraph *gra_pimSp_conv = new TGraph(x.size(), &x[0], &pimSp_y_conv[0]);
  TGraph *gra_pipSm_conv = new TGraph(x.size(), &x[0], &pipSm_y_conv[0]);
  TGraph *gra_pimS0_conv = new TGraph(x.size(), &x[0], &pimS0_y_conv[0]);  
  TGraph *gra_I0_re = new TGraph(I0_re.size(), &x[0], &I0_re[0]);
  TGraph *gra_I0_im = new TGraph(I0_re.size(), &x[0], &I0_im[0]);
  TGraph *gra_I1_re = new TGraph(I0_re.size(), &x[0], &I1_re[0]);
  TGraph *gra_I1_im = new TGraph(I0_re.size(), &x[0], &I1_im[0]);
  TGraph *gra_norm = new TGraph(I0I1_norm.size(), &x[0], &I0I1_norm[0]);
  TGraph *gra_interfer = new TGraph(interfer.size(), &x[0], &interfer[0]);
  
  gra_pimSp-> Write("pimSp_calc");
  gra_pipSm-> Write("pipSm_calc");
  gra_pimS0-> Write("pimS0_calc");
  gra_pimSp_conv-> Write("pimSp_calc_conv");
  gra_pipSm_conv-> Write("pipSm_calc_conv");
  gra_pimS0_conv-> Write("pimS0_calc_conv");
  gra_I0_re-> Write("T_I0_re");
  gra_I0_im-> Write("T_I0_im");
  gra_I1_re-> Write("T_I1_re");
  gra_I1_im-> Write("T_I1_im");
  gra_norm-> Write("I0I1_norm");
  gra_interfer-> Write("interfer");
  
  of-> Write();
  of-> Close();
  
}
