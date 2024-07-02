#ifndef SCAT_HH
#define SCAT_HH 1

#include "W_to_mom.hh"
#include "common.hh"

namespace scat{
  std::complex<double> KbarN_piSigma(const std::complex<double> &A, const std::complex<double> &R, double W, double phase=1.0);
  std::complex<double> KbarN_KbarN(const std::complex<double> &A, const std::complex<double> &R, double W, double phase=1.0);
}
#endif
