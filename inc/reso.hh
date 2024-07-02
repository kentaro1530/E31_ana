#ifndef RESO_HH
#define RESO_HH 1

#include "common.hh"
#include "func.hh"

namespace reso{
  const double kn_param[4]={ 0.0968203, -0.0798362, 0.00572992, 0.00531044 };
  const double kp_param[4]={ 0.0965427, -0.091453, 0.0176405, 0.0023315 };

  inline double kn(const double &m){ return kn_param[0]+kn_param[1]*m+kn_param[2]*m*m+kn_param[3]*m*m*m; }
  inline double kp(const double &m){ return kp_param[0]+kp_param[1]*m+kp_param[2]*m*m+kp_param[3]*m*m*m; }

  double conv_kn(const double &x, const std::vector<double> &func_x, const std::vector<double> &func_y);
  double conv_kp(const double &x, const std::vector<double> &func_x, const std::vector<double> &func_y);
}

#endif
