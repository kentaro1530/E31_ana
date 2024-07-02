#include "common.hh"
#include "TMatrix.hh"
#include <TMinuit.h>
#include <TNtuple.h>

#include "fit_scat_amp/setup.hh"

const TString inrootfile="~/spectra.root";
const TString outrootfile="~/spectra_fit_byI1.root";

// TGraphErrors *g_fit[3];

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

  TransMatrix T_piS_KN(piMass, sigmaMass, kMass, NMass);
  T_piS_KN.setA(std::complex<double>(0, 0));
  T_piS_KN.setR(std::complex<double>(0, 0));
}
