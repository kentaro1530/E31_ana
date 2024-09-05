#include "Gopal.hh"

std::complex<double> Gopal::scat_amp_I0(const double &W){
  using namespace KbarN_KbarN_I0;

  int index_m=-1;
  double delta=-1;
  
  for( int i=0; i<sizeof(masses)/sizeof(masses[0]); i++ ){
    if( W<masses[i] ){
      index_m=i-1;
      delta=(W-masses[index_m])/0.01;
      break;
    }
  }
  if( index_m==-1 ){
    std::cout<<"!!!!! Gopal::scat_amp_I0 Error !!!!!"<<std::endl;
    std::cout<<"      W="<<W<<"  index_m="<<index_m<<std::endl;
    exit(0);
  }

  std::complex<double> amp(0, 0);
  amp += std::complex<double>(S01_re[index_m]+(S01_re[index_m+1]-S01_re[index_m])*delta, S01_im[index_m]+(S01_im[index_m+1]-S01_im[index_m])*delta);
  amp += std::complex<double>(P01_re[index_m]+(P01_re[index_m+1]-P01_re[index_m])*delta, P01_im[index_m]+(P01_im[index_m+1]-P01_im[index_m])*delta);
  amp += std::complex<double>(P03_re[index_m]+(P03_re[index_m+1]-P03_re[index_m])*delta, P03_im[index_m]+(P03_im[index_m+1]-P03_im[index_m])*delta);
  amp += std::complex<double>(D03_re[index_m]+(D03_re[index_m+1]-D03_re[index_m])*delta, D03_im[index_m]+(D03_im[index_m+1]-D03_im[index_m])*delta);
  amp += std::complex<double>(D05_re[index_m]+(D05_re[index_m+1]-D05_re[index_m])*delta, D05_im[index_m]+(D05_im[index_m+1]-D05_im[index_m])*delta);
  amp += std::complex<double>(P05_re[index_m]+(P05_re[index_m+1]-P05_re[index_m])*delta, P05_im[index_m]+(P05_im[index_m+1]-P05_im[index_m])*delta);
  amp += std::complex<double>(P07_re[index_m]+(P07_re[index_m+1]-P07_re[index_m])*delta, P07_im[index_m]+(P07_im[index_m+1]-P07_im[index_m])*delta);
  amp += std::complex<double>(G07_re[index_m]+(G07_re[index_m+1]-G07_re[index_m])*delta, G07_im[index_m]+(G07_im[index_m+1]-G07_im[index_m])*delta);
  amp += std::complex<double>(G09_re[index_m]+(G09_re[index_m+1]-G09_re[index_m])*delta, G09_im[index_m]+(G09_im[index_m+1]-G09_im[index_m])*delta);
  amp += std::complex<double>(H09_re[index_m]+(H09_re[index_m+1]-H09_re[index_m])*delta, H09_im[index_m]+(H09_im[index_m+1]-H09_im[index_m])*delta);
  //  std::cout<<W<<"  "<<index_m<<"  "<<delta_m<<std::endl;

  return amp;
}

std::complex<double> Gopal::scat_amp_I1(const double &W){
  using namespace KbarN_KbarN_I1;

  int index_m=-1;
  double delta=-1;
  
  for( int i=0; i<sizeof(masses)/sizeof(masses[0]); i++ ){
    if( W<masses[i] ){
      index_m=i-1;
      delta=(W-masses[index_m])/0.01;
      break;
    }
  }
  if( index_m==-1 ){
    std::cout<<"!!!!! Gopal::scat_amp_I1 Error !!!!!"<<std::endl;
    std::cout<<"      W="<<W<<"  index_m="<<index_m<<std::endl;
    exit(0);
  }

  std::complex<double> amp(0, 0);
  amp += std::complex<double>(S11_re[index_m]+(S11_re[index_m+1]-S11_re[index_m])*delta, S11_im[index_m]+(S11_im[index_m+1]-S11_im[index_m])*delta);
  amp += std::complex<double>(P11_re[index_m]+(P11_re[index_m+1]-P11_re[index_m])*delta, P11_im[index_m]+(P11_im[index_m+1]-P11_im[index_m])*delta);
  amp += std::complex<double>(P13_re[index_m]+(P13_re[index_m+1]-P13_re[index_m])*delta, P13_im[index_m]+(P13_im[index_m+1]-P13_im[index_m])*delta);
  amp += std::complex<double>(D13_re[index_m]+(D13_re[index_m+1]-D13_re[index_m])*delta, D13_im[index_m]+(D13_im[index_m+1]-D13_im[index_m])*delta);
  amp += std::complex<double>(D15_re[index_m]+(D15_re[index_m+1]-D15_re[index_m])*delta, D15_im[index_m]+(D15_im[index_m+1]-D15_im[index_m])*delta);
  amp += std::complex<double>(P15_re[index_m]+(P15_re[index_m+1]-P15_re[index_m])*delta, P15_im[index_m]+(P15_im[index_m+1]-P15_im[index_m])*delta);
  amp += std::complex<double>(P17_re[index_m]+(P17_re[index_m+1]-P17_re[index_m])*delta, P17_im[index_m]+(P17_im[index_m+1]-P17_im[index_m])*delta);
  amp += std::complex<double>(G17_re[index_m]+(G17_re[index_m+1]-G17_re[index_m])*delta, G17_im[index_m]+(G17_im[index_m+1]-G17_im[index_m])*delta);
  amp += std::complex<double>(G19_re[index_m]+(G19_re[index_m+1]-G19_re[index_m])*delta, G19_im[index_m]+(G19_im[index_m+1]-G19_im[index_m])*delta);
  amp += std::complex<double>(H19_re[index_m]+(H19_re[index_m+1]-H19_re[index_m])*delta, H19_im[index_m]+(H19_im[index_m+1]-H19_im[index_m])*delta);
  //  std::cout<<W<<"  "<<index_m<<"  "<<delta_m<<std::endl;

  return amp;
}
