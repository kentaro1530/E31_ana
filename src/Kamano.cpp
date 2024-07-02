#include "Kamano.hh"

Kamano::Kamano(){
  std::cout<<"Kmano calc result read START"<<std::endl;
  pimSp_A_xy=read_file::read_xy("txt/pimSp_A.txt");
  pimSp_B_xy=read_file::read_xy("txt/pimSp_B.txt");
  pipSm_A_xy=read_file::read_xy("txt/pipSm_A.txt");
  pipSm_B_xy=read_file::read_xy("txt/pipSm_B.txt");
  pi0S0_A_xy=read_file::read_xy("txt/pi0S0_A.txt");
  pi0S0_B_xy=read_file::read_xy("txt/pi0S0_B.txt"); 
  pimS0_A_xy=read_file::read_xy("txt/pimS0_A.txt");
  pimS0_B_xy=read_file::read_xy("txt/pimS0_B.txt"); 
  std::vector<double> x, y_A, y_B;
  for( size_t i=0; i<pimSp_A_xy[0].size(); i++ ){
    x.push_back(pimSp_A_xy[0][i]);
    y_A.push_back(pimSp_A_xy[1][i]-pipSm_A_xy[1][i]);
    y_B.push_back(pimSp_B_xy[1][i]-pipSm_B_xy[1][i]);
  }
  interfer_A_xy.push_back(x);
  interfer_A_xy.push_back(y_A);

  interfer_B_xy.push_back(x);
  interfer_B_xy.push_back(y_B);
  std::cout<<"Kmano calc result read FINISH"<<std::endl;
}

double Kamano::I0_A(double m) const { return util::interpolate(pi0S0_A_xy, m); }
double Kamano::I0_B(double m) const { return util::interpolate(pi0S0_B_xy, m); }
double Kamano::I1_A(double m) const { return util::interpolate(pimS0_A_xy, m); }
double Kamano::I1_B(double m) const { return util::interpolate(pimS0_B_xy, m); }

double Kamano::pimSp_A(double m) const { return util::interpolate(pimSp_A_xy, m); }
double Kamano::pimSp_B(double m) const { return util::interpolate(pimSp_B_xy, m); }
double Kamano::pipSm_A(double m) const { return util::interpolate(pipSm_A_xy, m); }
double Kamano::pipSm_B(double m) const { return util::interpolate(pipSm_B_xy, m); }


void Kamano::dump(){
  std::cout<<"Kamano Spectra dumpping"<<std::endl;
  for( size_t i=0; i<pimSp_A_xy[0].size(); i++ ){
    std::cout<<pimSp_A_xy[0][i]<<"  "<<pimSp_A_xy[1][i]<<"  "
	     <<pimSp_B_xy[0][i]<<"  "<<pimSp_B_xy[1][i]<<"  "
	     <<pipSm_A_xy[0][i]<<"  "<<pipSm_A_xy[1][i]<<"  "
	     <<pipSm_B_xy[0][i]<<"  "<<pipSm_B_xy[1][i]<<"  "
	     <<pi0S0_A_xy[0][i]<<"  "<<pi0S0_A_xy[1][i]<<"  "
	     <<pi0S0_B_xy[0][i]<<"  "<<pi0S0_B_xy[1][i]<<"  "
	     <<pimS0_A_xy[0][i]<<"  "<<pimS0_A_xy[1][i]<<"  "
	     <<pimS0_B_xy[0][i]<<"  "<<pimS0_B_xy[1][i]<<std::endl;
  }
}
