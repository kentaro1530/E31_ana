#ifndef READFILE_HH
#define READFILE_HH 1

#include "common.hh"
#include "reso.hh"
#include "TInclude.hh"

namespace read_file{
  std::vector< std::vector<double> > read_xy2(const std::string &file_name);
  std::vector< std::vector<double> > read_xy(const std::string &file_name);
  std::vector< std::vector<double> > read_4(const std::string &file_name);
  std::vector< std::vector<double> > read_5(const std::string &file_name);
  std::vector< std::vector<double> > read_6(const std::string &file_name);
  TGraph* makeGraph2(const std::string &file_name);
  TGraph* makeGraph_conv2(const std::string &file_name);
  //  TGraph* makeGraph_conv(const std::string &file_name);
  TGraph* makeGraph(const std::string &file_name);
  TGraph* makeGraph_conv(const std::string &file_name);

  std::vector<TGraphErrors*> makeCS3(const std::string &file_name);
  std::vector<TGraphErrors*> makeCS2(const std::string &file_name);
  std::vector<TGraph*> makeSpecByNoumi(const std::string &file_name);
  TGraphErrors* makeCS(const std::string &file_name);
}
#endif
