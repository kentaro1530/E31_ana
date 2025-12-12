#include "L1405_param.h"

void print_L1405_pole_param(){
  
  std::cout<<pole_KN_bestFit<<" + "<<pole_KN_upper[2] - pole_KN_bestFit<<" - "<<pole_KN_bestFit - pole_KN_lower[2]
	   << " + "<<pole_KzeroN_upper[2] - pole_KN_upper[2]<<" - "<<pole_KN_lower[2] - pole_Kmp_lower[2]<<std::endl;

  std::cout<<width_KN_bestFit<<" + "<<width_KN_upper[2] - width_KN_bestFit<<" - "<<width_KN_bestFit - width_KN_lower[2]
	   << " + "<<width_KzeroN_upper[2] - width_KN_upper[2]<<" - "<<width_KN_lower[2] - width_Kmp_lower[2]<<std::endl;
    
    
}
