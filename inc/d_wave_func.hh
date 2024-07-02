#ifndef D_WAVE_FUNC_HH
#define D_WAVE_FUNC_HH 1

#include "constant.hh"

namespace d_wave_func{
  const double gammaMass=0.2315380*Const_GeVFM; // GeV
  const double m0=0.9*Const_GeVFM; // GeV
  const double C[]={ 0.88472985, -0.26408759, -0.44114404e-1, -0.14397512e2, 0.85591256e2, -0.31876761e3, 0.70336701e3, -0.90049586e3, 0.66145441e3, -0.25958894e3, 42.2607181439998 };

  double value(const double p);

  const double KNUCL_PARAM[6] = { 1162.54, 0.0376533, 124.49, 0.0790454, 4.2879, 0.156929};
  double value_knucl(const double p);
}
#endif
