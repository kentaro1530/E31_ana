#include "constant.hh"
#include "W_to_mom.hh"
#include "read_file.hh"
#include "root_util.hh"
#include "reso.hh"

#include "make_TFile/make_Miyagawa_spec.cpp"
#include "make_TFile/make_Kamano_spec.cpp"
#include "make_TFile/make_CS.cpp"
#include "make_TFile/make_noumi.cpp"
#include "make_TFile/make_scat_amp.cpp"

const TString outrootname="~/spectra.root";

// const Kamano kamanoSpectra;

int main(){
  TFile *of=new TFile(outrootname, "recreate");
  make_Miyagawa_spec();
  make_Kamano_spec();
  make_CS();
  make_noumi();

  make_scat_amp();

  std::cout<<"write file >> "<<of-> GetName()<<std::endl;
  of-> Write();
  of-> Close();
}
