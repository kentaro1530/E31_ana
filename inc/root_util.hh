#ifndef ROOT_UTIL_HH
#define ROOT_UTIL_HH 1

#include "common.hh"
#include "TInclude.hh"

namespace root_util{
  TGraph* set_opts(TGraph *gra);
  TGraphErrors* set_opts(TGraphErrors *gra);

  TGraph* add(TGraph *gra1, TGraph *gra2);
  TGraph* sub(TGraph *gra1, TGraph *gra2);
  TGraph* scale(double scale, TGraph *gra1);
}

#endif
