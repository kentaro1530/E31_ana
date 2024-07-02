#ifndef UTIL_HH
#define UTIL_HH

#include "common.hh"
#include "TMatrix.hh"
#include "TInclude.hh"

namespace util{
  double interpolate(const std::vector<std::vector<double> > &points, double x);

  void write_tgraph(const std::vector<double> &x, const std::vector<double> &y, const TString &name);
  void write_tgraph2D(std::vector<double> &x, std::vector<double> &y, std::vector<double> &z, const TString &name);

  namespace TMatrix{
    std::vector<TGraphAsymmErrors*> make_amp12_TGraphErrors(const TransMatrix &tmat, const double &A_re_err, const double &A_im_err, const double &R_re_err, const double &R_im_err, 
							    const double &min=1.35, const double &max=1.60);

    bool getPoleWidth(const TransMatrix &tmat, const double &A_re_err, const double &A_im_err, const double &R_re_err, const double &R_im_err,
		      double &pole, double &pole_min, double &pole_max, double &width, double &width_min, double &width_max);
  }
}

#endif
