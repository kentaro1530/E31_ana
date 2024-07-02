#include "read_file.hh"

std::vector< std::vector<double> > read_file::read_xy(const std::string &file_name){
  std::ifstream ifs(file_name.c_str());

  std::string str;
  std::vector<double> x, y;
  while( getline(ifs, str) ){
    double tmpx, tmpy;
    if( str.empty() || str[0]=='#' ) continue;

    if( sscanf(str.c_str(), "%lf %lf", &tmpx, &tmpy)==2 ){
      //      std::cout<<tmpx<<"  "<<tmpy<<std::endl;
      x.push_back(0.001*tmpx);
      y.push_back(tmpy);
    }
    else std::cout<<"!!!!! read_file::read_xy invalid format !!!!! "<<str<<std::endl;
  }
  std::vector<std::vector<double> > xy;
  xy.push_back(x);
  xy.push_back(y);
  return xy;
}

std::vector< std::vector<double> > read_file::read_xy2(const std::string &file_name){
  std::ifstream ifs(file_name.c_str());

  std::string str;
  std::vector<double> x, y;
  while( getline(ifs, str) ){
    if( str.empty() || str[0]=='#' ) continue;

    double tmpx, tmpy;
    if( sscanf(str.c_str(), "%lf %lf", &tmpx, &tmpy)==2 ){
      //      std::cout<<tmpx<<"  "<<tmpy<<std::endl;
      x.push_back(tmpx);
      y.push_back(tmpy);
    }
    else std::cout<<"!!!!! read_file::read_xy invalid format !!!!! "<<str<<std::endl;
  }
  std::vector<std::vector<double> > xy;
  xy.push_back(x);
  xy.push_back(y);
  return xy;
}

std::vector< std::vector<double> > read_file::read_4(const std::string &file_name){
  std::ifstream ifs(file_name.c_str());

  std::string str;
  std::vector<double> x1, x2, x3, x4;
  while( getline(ifs, str) ){
    if( str.empty() || str[0]=='#' ) continue;

    double tmp1, tmp2, tmp3, tmp4;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf", &tmp1, &tmp2, &tmp3, &tmp4)==4 ){
      x1.push_back(tmp1);  x2.push_back(tmp2);  x3.push_back(tmp3);  x4.push_back(tmp4); 
    }
    else std::cout<<"!!!!! read_file::read5 invalid format !!!!! "<<str<<std::endl;
  }
  std::vector<std::vector<double> > result;
  result.push_back(x1);  result.push_back(x2);  result.push_back(x3);  result.push_back(x4); 
  return result;
}

std::vector< std::vector<double> > read_file::read_5(const std::string &file_name){
  std::ifstream ifs(file_name.c_str());

  std::string str;
  std::vector<double> x1, x2, x3, x4, x5;
  while( getline(ifs, str) ){
    if( str.empty() || str[0]=='#' ) continue;

    double tmp1, tmp2, tmp3, tmp4, tmp5;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf", &tmp1, &tmp2, &tmp3, &tmp4, &tmp5)==5 ){
      x1.push_back(tmp1);  x2.push_back(tmp2);  x3.push_back(tmp3);  x4.push_back(tmp4);  x5.push_back(tmp5);
    }
    else std::cout<<"!!!!! read_file::read5 invalid format !!!!! "<<str<<std::endl;
  }
  std::vector<std::vector<double> > result;
  result.push_back(x1);  result.push_back(x2);  result.push_back(x3);  result.push_back(x4);  result.push_back(x5);
  return result;
}

std::vector< std::vector<double> > read_file::read_6(const std::string &file_name){
  std::ifstream ifs(file_name.c_str());

  std::string str;
  std::vector<double> x1, x2, x3, x4, x5, x6;
  while( getline(ifs, str) ){
    if( str.empty() || str[0]=='#' ) continue;

    double tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6)==6 ){
      x1.push_back(tmp1);  x2.push_back(tmp2);  x3.push_back(tmp3);  x4.push_back(tmp4);  x5.push_back(tmp5); x6.push_back(tmp6);
    }
    else std::cout<<"!!!!! read_file::read_6 invalid format !!!!! "<<str<<std::endl;
  }
  std::vector<std::vector<double> > result;
  result.push_back(x1);  result.push_back(x2);  result.push_back(x3);  result.push_back(x4);  result.push_back(x5); result.push_back(x6);
  return result;
}
