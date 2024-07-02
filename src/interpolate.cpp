#include "util.hh"

double util::interpolate(const std::vector<std::vector<double> > &points, double x){
  if( x<points[0][0] || points[0][points[0].size()-1]<x ) return 0;
  for( size_t i=0; i<points[0].size()-1; i++ ){
    if( points[0][i]<=x && x<=points[0][i+1] ){
      //      std::cout<<points[0][i]<<"   "<<points[1][i]<<"    "<<points[0][i+1]<<"   "<<points[1][i+1]<<"    "<<std::endl;
      return points[1][i]+(x-points[0][i])*(points[1][i+1]-points[1][i])/(points[0][i+1]-points[0][i]);
    }
  }

  return -1;
}
