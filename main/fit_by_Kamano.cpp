#include "common.hh"
#include "Kamano.hh"
#include <TMinuit.h>
#include <TNtuple.h>

const TString inrootfile="~/spectra.root";
const TString outrootfile="~/spectra_fit.root";
const Kamano kamanoSpectra;
TGraphErrors* g_fit[3];

void fcn_A(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag);
void fcn_B(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag);
void get_chi2_ndf_A(Double_t &chi2, Int_t &ndf, Double_t par[3]);
void get_chi2_ndf_B(Double_t &chi2, Int_t &ndf, Double_t par[3]);
std::vector<TGraph*> make_spectra_A(double par[3]);
std::vector<TGraph*> make_spectra_B(double par[3]);
TMinuit* makeMinuit();
bool fit(TMinuit *minuit, double par[3], double err[3]);
void save(double chi2, double ndf, double par[3], double err[3]){
  TNtuple *tup=new TNtuple("fit_params", "", "chi2:NDF:A_I0:A_I1:epsilon:A_I0_err:A_I1_err:epsilon_err");
  tup-> Fill(chi2, ndf, par[0], par[1], par[2], err[0], err[1], err[2]);
  std::cout<<"===== Print Fit Result ====="<<std::endl;
  std::cout<<"> Chi2 = "<<chi2<<"   NDF = "<<ndf<<"    Chi2/NDF = "<<chi2/ndf<<std::endl;
  std::cout<<"> A I=0   = "<<par[0]<<" +- "<<err[0]<<std::endl;
  std::cout<<"> A I=1   = "<<par[1]<<" +- "<<err[1]<<std::endl;
  std::cout<<"> epsilon = "<<par[2]<<" +- "<<err[2]<<std::endl;
}

int main(){
  TFile *f=new TFile(inrootfile);
  g_fit[0]=(TGraphErrors*)f->Get("pimSp_CS0");
  g_fit[1]=(TGraphErrors*)f->Get("pipSm_CS0");
  g_fit[2]=(TGraphErrors*)f->Get("pimS0_CS0");

  TFile *of=new TFile(outrootfile, "recreate");
  of-> cd();
  g_fit[0]-> Write("gra_pimSp_CS");
  g_fit[1]-> Write("gra_pipSm_CS");
  g_fit[2]-> Write("gra_pimS0_CS");

  std::vector<double> pimSp_y, pipSm_y, pimS0_y, I0_y, I1_y, interfer_y;
  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_A_by_phase");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_A);
  //   minuit-> FixParameter(0);
  //   minuit-> FixParameter(1);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_A(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_A(par);
  // }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_B_by_phase");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_B);
  //   minuit-> FixParameter(0);
  //   minuit-> FixParameter(1);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_B(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_B(par);
  // }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_A");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_A);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_A(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_A(par);
  // }

  {
    TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_B");
    dir-> cd();
    TMinuit* minuit=makeMinuit();
    minuit-> SetFCN(fcn_B);
    double par[3], err[3];
    fit(minuit, par, err);
    double chi2; int ndf;
    get_chi2_ndf_B(chi2, ndf, par);
    ndf -= minuit-> GetNumFreePars(); 
    save(chi2, ndf, par, err);
    std::vector<TGraph*> gras=make_spectra_B(par);
  }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_A_fix_Phi");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_A);
  //   minuit-> FixParameter(2);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_A(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_A(par);
  // }

  {
    TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_B_fix_Phi");
    dir-> cd();
    TMinuit* minuit=makeMinuit();
    minuit-> SetFCN(fcn_B);
    minuit-> FixParameter(2);
    double par[3], err[3];
    fit(minuit, par, err);
    double chi2; int ndf;
    get_chi2_ndf_B(chi2, ndf, par);
    ndf -= minuit-> GetNumFreePars(); 
    save(chi2, ndf, par, err);
    std::vector<TGraph*> gras=make_spectra_B(par);
  }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_A_fix_Phi_I0");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_A);
  //   minuit-> FixParameter(0);
  //   minuit-> FixParameter(2);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_A(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_A(par);
  // }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_B_fix_Phi_I0");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_B);
  //   minuit-> FixParameter(0);
  //   minuit-> FixParameter(2);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_B(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_B(par);
  // }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_B_fix_I0");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_B);
  //   minuit-> FixParameter(0);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_B(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_B(par);
  // }

  // {
  //   TDirectory *dir=(TDirectory*)of-> mkdir("fit_model_A_fix_I0");
  //   dir-> cd();
  //   TMinuit* minuit=makeMinuit();
  //   minuit-> SetFCN(fcn_A);
  //   minuit-> FixParameter(0);
  //   double par[3], err[3];
  //   fit(minuit, par, err);
  //   double chi2; int ndf;
  //   get_chi2_ndf_A(chi2, ndf, par);
  //   ndf -= minuit-> GetNumFreePars(); 
  //   save(chi2, ndf, par, err);
  //   std::vector<TGraph*> gras=make_spectra_A(par);
  // }

  of-> cd();
  of-> Write();
}

void fcn_A(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag){
  int npoint=0;
  get_chi2_ndf_A(chi2, npoint, par);
}

void get_chi2_ndf_A(Double_t &chi2, Int_t &ndf, Double_t *par){
  chi2=0;
  ndf=0;
  std::vector<std::vector<double> > I0_xy=kamanoSpectra.pi0S0_A_points();
  std::vector<std::vector<double> > I1_xy=kamanoSpectra.pimS0_A_points();
  std::vector<std::vector<double> > interfer_xy=kamanoSpectra.interfer_A_points();

  std::vector<double> pimSp_y, pipSm_y, pimS0_y;
  for( size_t i=0; i<I0_xy[0].size(); i++ ){
    pimSp_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]+0.5*par[2]*sqrt(par[0]*par[1])*interfer_xy[1][i]);
    pipSm_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]-0.5*par[2]*sqrt(par[0]*par[1])*interfer_xy[1][i]);
    pimS0_y.push_back(par[1]*I1_xy[1][i]);
  }

  for( int i=0; i<g_fit[0]->GetN(); i++ ){  
    double x, y;
    g_fit[0]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[0]->GetErrorY(i);
    double calc_y=reso::conv_kn(x, I0_xy[0], pimSp_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
  for( int i=0; i<g_fit[1]->GetN(); i++ ){  
    double x, y;
    g_fit[1]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[1]->GetErrorY(i);
    double calc_y=reso::conv_kn(x, I0_xy[0], pipSm_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
  for( int i=0; i<g_fit[2]->GetN(); i++ ){  
    double x, y;
    g_fit[2]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[2]->GetErrorY(i);
    double calc_y=reso::conv_kp(x, I0_xy[0], pimS0_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
}

void fcn_B(Int_t &npar, Double_t *gin, Double_t &chi2, Double_t *par, Int_t iflag){
  int npoint=0;
  get_chi2_ndf_B(chi2, npoint, par);
}

void get_chi2_ndf_B(Double_t &chi2, Int_t &ndf, Double_t *par){
  chi2=0;
  ndf=0;
  std::vector<std::vector<double> > I0_xy=kamanoSpectra.pi0S0_B_points();
  std::vector<std::vector<double> > I1_xy=kamanoSpectra.pimS0_B_points();
  std::vector<std::vector<double> > interfer_xy=kamanoSpectra.interfer_B_points();

  std::vector<double> pimSp_y, pipSm_y, pimS0_y;
  for( size_t i=0; i<I0_xy[0].size(); i++ ){
    pimSp_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]+0.5*par[2]*sqrt(par[0]*par[1])*interfer_xy[1][i]);
    pipSm_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]-0.5*par[2]*sqrt(par[0]*par[1])*interfer_xy[1][i]);
    pimS0_y.push_back(par[1]*I1_xy[1][i]);
  }

  for( int i=0; i<g_fit[0]->GetN(); i++ ){  
    double x, y;
    g_fit[0]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[0]->GetErrorY(i);
    double calc_y=reso::conv_kn(x, I0_xy[0], pimSp_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
  for( int i=0; i<g_fit[1]->GetN(); i++ ){  
    double x, y;
    g_fit[1]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[1]->GetErrorY(i);
    double calc_y=reso::conv_kn(x, I0_xy[0], pipSm_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
  for( int i=0; i<g_fit[2]->GetN(); i++ ){  
    double x, y;
    g_fit[2]->GetPoint(i, x, y);
    if( x<1.35 || 1.5<x ) continue;
    double err=g_fit[2]->GetErrorY(i);
    double calc_y=reso::conv_kp(x, I0_xy[0], pimS0_y);
    if( err<1.0e-8 ) continue;

    chi2+=pow(y-calc_y, 2)/(err*err);
    ndf++;
  }
}

std::vector<TGraph*> make_spectra_A(double par[3]){
  std::vector<std::vector<double> > I0_xy=kamanoSpectra.pi0S0_A_points();
  std::vector<std::vector<double> > I1_xy=kamanoSpectra.pimS0_A_points();
  std::vector<std::vector<double> > interfer_xy=kamanoSpectra.interfer_A_points();

  std::vector<double> pimSp_y, pipSm_y, pimS0_y, I0_y, I1_y, interfer_y;
  for( size_t i=0; i<I0_xy[0].size(); i++ ){
    I0_y.push_back(par[0]*I0_xy[1][i]);
    I1_y.push_back(0.5*par[1]*I1_xy[1][i]);
    pimSp_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]+0.5*par[2]*par[1]*par[0]*interfer_xy[1][i]);
    pipSm_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]-0.5*par[2]*par[1]*par[0]*interfer_xy[1][i]);
    pimS0_y.push_back(par[1]*I1_xy[1][i]);
    interfer_y.push_back(0.5*par[2]*sqrt(par[1]*par[0])*interfer_xy[1][i]);
  }  

  std::vector<double> pimSp_y_conv, pipSm_y_conv, pimS0_y_conv, I0_y_conv, I1_y_conv, interfer_y_conv;
  for( size_t i=0; i<pimSp_y.size(); i++ ){
    I0_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], I0_y));
    I1_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], I1_y));
    pimSp_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pimSp_y));
    pipSm_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pipSm_y));
    pimS0_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pimS0_y));
    interfer_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], interfer_y));
  }
  std::vector<TGraph*> gras;
  gras.push_back(new TGraph(I0_y_conv.size(), &I0_xy[0][0], &I0_y_conv[0]));
  gras.push_back(new TGraph(I1_y_conv.size(), &I0_xy[0][0], &I1_y_conv[0]));
  gras.push_back(new TGraph(pimSp_y_conv.size(), &I0_xy[0][0], &pimSp_y_conv[0]));
  gras.push_back(new TGraph(pipSm_y_conv.size(), &I0_xy[0][0], &pipSm_y_conv[0]));
  gras.push_back(new TGraph(pimS0_y_conv.size(), &I0_xy[0][0], &pimS0_y_conv[0]));
  gras.push_back(new TGraph(interfer_y_conv.size(), &I0_xy[0][0], &interfer_y_conv[0]));

  // gras.push_back(new TGraph(I0_y_conv.size(), &I0_xy[0][0], &I0_y[0]));
  // gras.push_back(new TGraph(I1_y_conv.size(), &I0_xy[0][0], &I1_y[0]));
  // gras.push_back(new TGraph(pimSp_y_conv.size(), &I0_xy[0][0], &pimSp_y[0]));
  // gras.push_back(new TGraph(pipSm_y_conv.size(), &I0_xy[0][0], &pipSm_y[0]));
  // gras.push_back(new TGraph(pimS0_y_conv.size(), &I0_xy[0][0], &pimS0_y[0]));
  // gras.push_back(new TGraph(interfer_y_conv.size(), &I0_xy[0][0], &interfer_y[0]));

  gras[0]-> Write("gra_I0");
  gras[1]-> Write("gra_I1");
  gras[2]-> Write("gra_pimSp");
  gras[3]-> Write("gra_pipSm");
  gras[4]-> Write("gra_pimS0");
  gras[5]-> Write("gra_interfer");

  return gras;
}

std::vector<TGraph*> make_spectra_B(double par[3]){
  std::vector<std::vector<double> > I0_xy=kamanoSpectra.pi0S0_B_points();
  std::vector<std::vector<double> > I1_xy=kamanoSpectra.pimS0_B_points();
  std::vector<std::vector<double> > interfer_xy=kamanoSpectra.interfer_B_points();

  std::vector<double> pimSp_y, pipSm_y, pimS0_y, I0_y, I1_y, interfer_y;
  for( size_t i=0; i<I0_xy[0].size(); i++ ){
    I0_y.push_back(par[0]*I0_xy[1][i]);
    I1_y.push_back(0.5*par[1]*I1_xy[1][i]);
    pimSp_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]+0.5*par[2]*par[1]*par[0]*interfer_xy[1][i]);
    pipSm_y.push_back(par[0]*I0_xy[1][i]+0.5*par[1]*I1_xy[1][i]-0.5*par[2]*par[1]*par[0]*interfer_xy[1][i]);
    pimS0_y.push_back(par[1]*I1_xy[1][i]);
    interfer_y.push_back(0.5*par[2]*sqrt(par[1]*par[0])*interfer_xy[1][i]);
  }  

  std::vector<double> pimSp_y_conv, pipSm_y_conv, pimS0_y_conv, I0_y_conv, I1_y_conv, interfer_y_conv;
  for( size_t i=0; i<pimSp_y.size(); i++ ){
    I0_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], I0_y));
    I1_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], I1_y));
    pimSp_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pimSp_y));
    pipSm_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pipSm_y));
    pimS0_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], pimS0_y));
    interfer_y_conv.push_back(reso::conv_kn(I0_xy[0][i], I0_xy[0], interfer_y));
  }
  std::vector<TGraph*> gras;
  gras.push_back(new TGraph(I0_y_conv.size(), &I0_xy[0][0], &I0_y_conv[0]));
  gras.push_back(new TGraph(I1_y_conv.size(), &I0_xy[0][0], &I1_y_conv[0]));
  gras.push_back(new TGraph(pimSp_y_conv.size(), &I0_xy[0][0], &pimSp_y_conv[0]));
  gras.push_back(new TGraph(pipSm_y_conv.size(), &I0_xy[0][0], &pipSm_y_conv[0]));
  gras.push_back(new TGraph(pimS0_y_conv.size(), &I0_xy[0][0], &pimS0_y_conv[0]));
  gras.push_back(new TGraph(interfer_y_conv.size(), &I0_xy[0][0], &interfer_y_conv[0]));

  gras[0]-> Write("gra_I0");
  gras[1]-> Write("gra_I1");
  gras[2]-> Write("gra_pimSp");
  gras[3]-> Write("gra_pipSm");
  gras[4]-> Write("gra_pimS0");
  gras[5]-> Write("gra_interfer");

  return gras;
}

TMinuit* makeMinuit(){
  TMinuit* minuit=new TMinuit(3);
  minuit-> SetPrintLevel(-1);
  TString par_name[3]={ "Scale I=0", "Scale I=1", "epsilon" };
  double step[3]={ 0.01, 0.01, 0.01 };
  double init_par[3]={1.0, 1.0, 1.0};
  double min[3]={ 0, 0, 0 };
  double max[3]={ 2.0, 2.0,  2.0 };
  int flag=0;
  for( int i=0; i<3; i++ ) minuit-> mnparm(i, par_name[i], init_par[i], step[i], min[i], max[i], flag);
  return minuit;
}

bool fit(TMinuit *minuit, double par[3], double err[3]){
  double arglist[20]; arglist[0]=3000, arglist[1]=1;
  int ierflag=0;
  minuit->Command("SET STRategy 0");
  minuit->mnexcm("SIMPLEX", arglist, 1, ierflag);
  minuit->mnexcm("MIGRAD", arglist, 1, ierflag);
  minuit->mnexcm("HESSE", arglist, 1, ierflag);
  for( int i=0; i<minuit->GetNumPars(); i++ ){
    TString name; double bnd1, bnd2; int flag;
    minuit-> mnpout(i, name, par[i], err[i], bnd1, bnd2, flag);
  }
  return true;
}

