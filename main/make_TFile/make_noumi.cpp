#include "read_file.hh"

void make_noumi(){
  std::vector<TGraph*> specByNoumi=read_file::makeSpecByNoumi("txt/fit_noumi.txt");
  specByNoumi[0]-> Write("specByNoumi_woRes");
  specByNoumi[1]-> Write("specByNoumi_wRes");
  specByNoumi[2]-> Write("responseFunc");

  std::vector<TGraph*> specByNoumi_kmp=read_file::makeSpecByNoumi("txt/fit_noumi_kpm.txt");
  specByNoumi_kmp[0]-> Write("specByNoumi_kmp_woRes");
  specByNoumi_kmp[1]-> Write("specByNoumi_kmp_wRes");
  specByNoumi_kmp[2]-> Write("responseFunc_kmp");

  std::vector<TGraph*> specByNoumi_k0n=read_file::makeSpecByNoumi("txt/fit_noumi_k0n.txt");
  specByNoumi_k0n[0]-> Write("specByNoumi_k0n_woRes");
  specByNoumi_k0n[1]-> Write("specByNoumi_k0n_wRes");
  specByNoumi_k0n[2]-> Write("responseFunc_k0n");
}
