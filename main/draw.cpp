#include "constant.hh"
#include "W_to_mom.hh"
#include "read_file.hh"

#include <TApplication.h>

const TString inrootfile="~/spectra.root";

int main(int argc, char** argv){
  TApplication theApp("theApp", &argc, argv);
  theApp.Run();
  std::cout<<"aaa"<<std::endl;
  TFile *f=new TFile(inrootfile);

  f-> ls();
  f-> Close();
}
