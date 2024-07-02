#include "constant.hh"
#include "W_to_mom.hh"
#include "read_file.hh"

int main(){
  std::cout<<"Hello World"<<std::endl;
  std::cout<<"K mass : "<<kMass<<std::endl;
  std::cout<<"N mass : "<<NMass<<std::endl;
  std::cout<<"pi mass : "<<piMass<<std::endl;
  std::cout<<"S  mass : "<<sigmaMass<<std::endl;

  std::cout<<"WWWW : "<<W_to_mom(kMass+NMass, piMass, sigmaMass)<<std::endl;
  //  TGraph *gra_pimA=read_file::makeGraph("txt/pimSp_A.txt");

}
