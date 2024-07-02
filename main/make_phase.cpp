#include "constant.hh"
#include "W_to_mom.hh"
#include "read_file.hh"
#include "root_util.hh"
#include "Kamano.hh"
#include "reso.hh"

const TString outrootname="~/spectra.root";

const Kamano kamanoSpectra;

int main(){
  TFile *of=new TFile(outrootname, "update");
  if( of-> IsZombie() || !of-> IsOpen() ) of=new TFile(outrootname, "recreate");

  std::vector< std::vector<double> > pimSp_A_points=read_file::read_xy("txt/pimSp_A.txt");
  std::vector< std::vector<double> > pipSm_A_points=read_file::read_xy("txt/pipSm_A.txt");
  std::vector< std::vector<double> > pimS0_A_points=read_file::read_xy("txt/pimS0_A.txt");
  std::vector< std::vector<double> > pi0S0_A_points=read_file::read_xy("txt/pi0S0_A.txt");

  std::vector< std::vector<double> > pimSp_B_points=read_file::read_xy("txt/pimSp_B.txt");
  std::vector< std::vector<double> > pipSm_B_points=read_file::read_xy("txt/pipSm_B.txt");
  std::vector< std::vector<double> > pimS0_B_points=read_file::read_xy("txt/pimS0_B.txt");
  std::vector< std::vector<double> > pi0S0_B_points=read_file::read_xy("txt/pi0S0_B.txt");

  std::vector<double> x, y_A, y_B;
  for( size_t i=0; i<pimSp_A_points[0].size(); i++ ){
    x.push_back(pimSp_A_points[0][i]);
    double phase_A=(pimSp_A_points[1][i]-pipSm_A_points[1][i])/sqrt(pimS0_A_points[1][i]*pi0S0_A_points[1][i]);
    double phase_B=(pimSp_B_points[1][i]-pipSm_B_points[1][i])/sqrt(pimS0_B_points[1][i]*pi0S0_B_points[1][i]);
    if( isnan(phase_A) ) phase_A=0;
    if( isnan(phase_B) ) phase_B=0;

    y_A.push_back(phase_A);
    y_B.push_back(phase_B);

    std::cout<<phase_A<<"   "<<phase_B<<std::endl;
    // std::cout<<pimSp_A_points[0][i]<<"   "
    // 	     <<pipSm_A_points[0][i]<<"   "
    // 	     <<pimS0_A_points[0][i]<<"   "
    // 	     <<pi0S0_A_points[0][i]<<"   "
    // 	     <<pimSp_B_points[0][i]<<"   "
    // 	     <<pipSm_B_points[0][i]<<"   "
    // 	     <<pimS0_B_points[0][i]<<"   "
    // 	     <<pi0S0_B_points[0][i]<<"   "
    // 	     <<std::endl;
  }

  TGraph *gra_A=new TGraph(x.size(), &x[0], &y_A[0]);
  TGraph *gra_B=new TGraph(x.size(), &x[0], &y_B[0]);

  gra_A-> Write("gra_phase_A");
  gra_B-> Write("gra_phase_B");

}
