#include "W_to_mom.hh"

std::complex<double> W_to_mom(const double &W, double m1, double m2){
  if( W>m1+m2 ) return std::complex<double>(sqrt((W*W-(m1+m2)*(m1+m2))*(W*W-(m1-m2)*(m1-m2)))/(2*W), 0);
  else       return std::complex<double>(0, sqrt(((m1+m2)*(m1+m2)-W*W)*(W*W-(m1-m2)*(m1-m2)))/(2*W));
}
