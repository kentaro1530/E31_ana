#include "common.hh"
#include "TMatrix.hh"
#include "reso.hh"
#include "root_util.hh"
#include <TMinuit.h>
#include <TNtuple.h>
#include "util.hh"

const TString outrootfile="~/test_pole_mass.root";

const int PRINT_LEVEL=-1;

TransMatrix KN_piS_T(piMass, sigmaMass, kMass, NMass);


int main(){
  TFile *of=new TFile(outrootfile, "recreate");
  double par[5] = { 0.04, -0.5, 0.8,  -0.4, -0.40 };
  double err[5] = { 0.05, 0.05, 0.05, 0.05, 0.05 };
  
  KN_piS_T.setA(std::complex<double>(par[1]/Const_GeVFM, par[2]/Const_GeVFM));
  KN_piS_T.setR(std::complex<double>(par[3]/Const_GeVFM, par[4]/Const_GeVFM));
  double pole, pole_min, pole_max, width, width_min, width_max;

  util::TMatrix::getPoleWidth(KN_piS_T, err[1]/Const_GeVFM, err[2]/Const_GeVFM, err[3]/Const_GeVFM, err[4]/Const_GeVFM,
			      pole, pole_min, pole_max, width, width_min, width_max);

  of-> Write();
  of-> Close();
}
