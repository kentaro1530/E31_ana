#ifndef FUNC_HH
#define FUNC_HH 1

#include "constant.hh"

namespace func{
  inline double gauss(const double x, const double mean, const double sigma){ return (1.0/(sqrt(2.0*PI)*sigma))*exp(-0.5*pow((x-mean)/sigma, 2)); }
}

#endif 
