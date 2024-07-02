#include "util.hh"

void util::write_tgraph(const std::vector<double> &x, const std::vector<double> &y, const TString &name){
  TGraph *gra=new TGraph(x.size(), &x[0], &y[0]);
  gra-> Write(name);
}

void util::write_tgraph2D(std::vector<double> &x, std::vector<double> &y, std::vector<double> &z, const TString &name){
  TGraph2D *gra=new TGraph2D(name, "", x.size(), &x[0], &y[0], &z[0]);
  gra-> Write();
}
