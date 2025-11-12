#include "L1405_param.h"

void print_L1405_param(){
  for( int i=0; i<6; i++ ){
    double pole_fit_low   = pole_KN_lower[i]-pole_KN_bestFit;
    double pole_fit_high  = pole_KN_upper[i]-pole_KN_bestFit;
    double pole_syst_low  = pole_Kmp_lower[i]-pole_KN_lower[i];
    double pole_syst_high = pole_KzeroN_upper[i]-pole_KN_upper[i];
    
    std::cout<<i<<"  "<<pole_KN_bestFit<<"  "<<pole_fit_low<<" "<<pole_fit_high<<"  "<<pole_syst_low<<"  "<<pole_syst_high<<std::endl;
  }

  for( int i=0; i<6; i++ ){
    double width_fit_low   = width_KN_lower[i]-width_KN_bestFit;
    double width_fit_high  = width_KN_upper[i]-width_KN_bestFit;
    double width_syst_low  = width_Kmp_lower[i]-width_KN_lower[i];
    double width_syst_high = width_KzeroN_upper[i]-width_KN_upper[i];
    
    std::cout<<i<<"  "<<width_KN_bestFit<<"  "<<width_fit_low<<" "<<width_fit_high<<"  "<<width_syst_low<<"  "<<width_syst_high<<std::endl;
  }
    
  //  std::cout<<"aaa"<<std::endl;
}
