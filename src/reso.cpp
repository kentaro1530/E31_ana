#include "reso.hh"

double reso::conv_kn(const double &x, const std::vector<double> &func_x, const std::vector<double> &func_y){
  double val=0;
  for( size_t i=1; i<func_x.size(); i++ ){
    const double x1=func_x[i-1];
    const double x2=func_x[i];
    const double dx=x2-x1;
    const double y1=func_y[i-1]*func::gauss(func_x[i-1], x, kn(x));
    const double y2=func_y[i]*func::gauss(func_x[i], x, kn(x));
    //    std::cout<<i<<"   "<<x1<<"   "<<x2<<"   "<<y1<<"   "<<y2<<std::endl;
    val+=0.5*dx*(y1+y2);
  }

  return val;
}

double reso::conv_kp(const double &x, const std::vector<double> &func_x, const std::vector<double> &func_y){
  double val=0;
  for( size_t i=1; i<func_x.size(); i++ ){
    const double x1=func_x[i-1];
    const double x2=func_x[i];
    const double dx=x2-x1;
    const double y1=func_y[i-1]*func::gauss(func_x[i-1], x, kp(x));
    const double y2=func_y[i]*func::gauss(func_x[i], x, kp(x));
    //    std::cout<<i<<"   "<<x1<<"   "<<x2<<"   "<<y1<<"   "<<y2<<std::endl;
    val+=0.5*dx*(y1+y2);
  }

  return val;
}
