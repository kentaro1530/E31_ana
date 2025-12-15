#include "config.hh"

template <class F>
double diff(F f, double x, double h = 1e-8){ return (f(x+h)-f(x-h))/(2.0*h); }

double search_q0(const double m, double eps = 1e-8){
  auto f = [m](double q2) { return sqrt(pow(onshell_mass, 2) + q2) + sqrt(pow(Kbar_mass, 2) + q2) - m; };
  double x0 = 0.1;
  double x2 = x0 - f(x0)/diff(f, x0);
  //  std::cout<<x0<<"  "<<x2<<"  "<<std::fabs(x0-x2)<<std::endl;
  
  while( std::fabs(x0-x2)>eps ){
    x0 = x2;
    x2 = x0 - f(x0)/diff(f, x0);
    //    std::cout<<x0<<"  "<<x2<<std::endl;
  }

  //  std::cout<<"q2 = "<<x2<<"  f(q2) = "<<f(x2)<<std::endl;
  return x2;
}

  
