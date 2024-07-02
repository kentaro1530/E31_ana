#include "d_wave_func.hh"

double d_wave_func::value(const double p){
  double val=0;
  for( size_t i=0; i<sizeof(C)/sizeof(C[0]); i++ ){
    const double m=(gammaMass+m0*i);
    val+=C[i]/(p*p+m*m);
  }
  return val;
}

double d_wave_func::value_knucl(const double p){
  return KNUCL_PARAM[0]*exp(-pow(p/KNUCL_PARAM[1], 2))+ KNUCL_PARAM[2]*exp(-pow(p/KNUCL_PARAM[3], 2))+ KNUCL_PARAM[4]*exp(-pow(p/KNUCL_PARAM[5], 2));
}
