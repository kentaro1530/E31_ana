#include "read_file.hh"
#include "root_util.hh"

std::vector<TGraph*> read_file::makeSpecByNoumi(const std::string &file_name){
  std::vector<std::vector<double>> xy=read_4(file_name);
  std::vector<TGraph*> result;
  std::vector<double> x;
  for( int i=0; i<xy[0].size(); i++ ) x.push_back(0.001*xy[0][i]);
  result.push_back(new TGraph(xy[0].size(), &x[0], &xy[1][0]));
  result.push_back(new TGraph(xy[0].size(), &x[0], &xy[2][0]));
  result.push_back(new TGraph(xy[0].size(), &x[0], &xy[3][0]));

  return result;
}

TGraph* read_file::makeGraph(const std::string &file_name){
  std::vector<std::vector<double> > xy=read_xy(file_name);
  TGraph *gra=new TGraph(xy[0].size(), &xy[0][0], &xy[1][0]);
  return root_util::set_opts(gra);
}

TGraph* read_file::makeGraph2(const std::string &file_name){
  std::vector<std::vector<double> > xy=read_xy2(file_name);
  TGraph *gra=new TGraph(xy[0].size(), &xy[0][0], &xy[1][0]);
  return root_util::set_opts(gra);
}

TGraph* read_file::makeGraph_conv(const std::string &file_name){
  std::vector<std::vector<double> > xy=read_xy(file_name);
  std::vector<double> x, y;
  for( size_t i=0; i<xy[0].size(); i++ ){
    x.push_back(xy[0][i]);
    y.push_back(reso::conv_kn(xy[0][i], xy[0], xy[1]));
    //    std::cout<<xy[0][i]<<"   "<<reso::conv_kn(xy[0][i], xy[0], xy[1])<<std::endl;
  }
  TGraph *gra=new TGraph(xy[0].size(), &x[0], &y[0]);
  return root_util::set_opts(gra);
}

TGraph* read_file::makeGraph_conv2(const std::string &file_name){
  std::vector<std::vector<double> > xy=read_xy2(file_name);
  std::vector<double> x, y;
  for( size_t i=0; i<xy[0].size(); i++ ){
    x.push_back(xy[0][i]);
    y.push_back(reso::conv_kn(xy[0][i], xy[0], xy[1]));
    //    std::cout<<xy[0][i]<<"   "<<reso::conv_kn(xy[0][i], xy[0], xy[1])<<std::endl;
  }
  TGraph *gra=new TGraph(xy[0].size(), &x[0], &y[0]);
  return root_util::set_opts(gra);
}

std::vector<TGraphErrors*> read_file::makeCS3(const std::string &file_name){
  //  std::cout<<file_name<<std::endl;
  std::vector<std::vector<double> > params=read_6(file_name);

  std::vector<double> x, y, xerr, yerr0, yerr1, yerr2;
  for( size_t i=0; i<params[0].size(); i++ ){
    x.push_back(params[0][i]);
    y.push_back(params[1][i]);
    xerr.push_back(params[2][i]);
    yerr2.push_back(params[3][i]);
    yerr1.push_back(params[4][i]);
    yerr0.push_back(params[5][i]);
  }
  TGraphErrors* gra0=new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr0[0]);
  TGraphErrors* gra1=new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr1[0]);
  TGraphErrors* gra2=new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr2[0]);

  std::vector<TGraphErrors*> results;
  results.push_back(root_util::set_opts(gra0));
  results.push_back(root_util::set_opts(gra1));
  results.push_back(root_util::set_opts(gra2));

  return results;
}

std::vector<TGraphErrors*> read_file::makeCS2(const std::string &file_name){
  std::vector<std::vector<double> > params=read_5(file_name);

  std::vector<double> x, y, xerr, yerr0, yerr1;
  for( size_t i=0; i<params[0].size(); i++ ){
    x.push_back(params[0][i]);
    y.push_back(params[1][i]);
    xerr.push_back(params[2][i]);
    yerr1.push_back(params[3][i]);
    yerr0.push_back(params[4][i]);
  }
  TGraphErrors* gra0=new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr0[0]);
  TGraphErrors* gra1=new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr1[0]);

  std::vector<TGraphErrors*> results;
  results.push_back(root_util::set_opts(gra0));
  results.push_back(root_util::set_opts(gra1));

  return results;
}

TGraphErrors* read_file::makeCS(const std::string &file_name){
  std::vector<std::vector<double> > params=read_4(file_name);

  std::vector<double> x, y, xerr, yerr0;
  for( size_t i=0; i<params[0].size(); i++ ){
    x.push_back(params[0][i]);
    y.push_back(params[1][i]);
    xerr.push_back(params[2][i]);
    yerr0.push_back(params[3][i]);
  }
  return new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr0[0]);

}
