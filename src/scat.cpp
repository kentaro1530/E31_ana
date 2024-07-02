#include "scat.hh"

std::complex<double> scat::KbarN_piSigma(const std::complex<double> &A, const std::complex<double> &R, double W, double phase){
  std::complex<double> k1=W_to_mom(W, sigmaMass, piMass);
  std::complex<double> k2=W_to_mom(W, NMass, kMass);
  std::cout<<W<<"   "<<k1<<"   "<<k2<<std::endl;

  std::complex<double> T=(exp(std::complex<double>(0, 1)*phase)/sqrt(k1))*sqrt(A.imag()-0.5*pow(abs(A), 2)*R*k2*k2)/(1.0-std::complex<double>(0, 1)*A*k2+0.5*A*R*k2*k2);
  return T;
}

std::complex<double> scat::KbarN_KbarN(const std::complex<double> &A, const std::complex<double> &R, double W, double phase){
  std::complex<double> k1=W_to_mom(W, sigmaMass, piMass);
  std::complex<double> k2=W_to_mom(W, NMass, kMass);

  std::complex<double> T=A/(1.0-std::complex<double>(0, 1)*A*k2+0.5*A*R*k2*k2);
  return T;
}
