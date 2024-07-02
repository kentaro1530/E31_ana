#include "read_file.hh"

void make_CS(){
  std::vector<TGraphErrors*> pimSp_CS=read_file::makeCS3("txt/CS_pimSp_after.txt");
  pimSp_CS[0]-> Write("pimSp_CS0");
  pimSp_CS[1]-> Write("pimSp_CS1");
  pimSp_CS[2]-> Write("pimSp_CS2");

  std::vector<TGraphErrors*> pipSm_CS=read_file::makeCS3("txt/CS_pipSm_after.txt");
  pipSm_CS[0]-> Write("pipSm_CS0");
  pipSm_CS[1]-> Write("pipSm_CS1");
  pipSm_CS[2]-> Write("pipSm_CS2");

  std::vector<TGraphErrors*> sub_CS=read_file::makeCS3("txt/CS_sub.txt");
  std::cout<<sub_CS[0]-> GetN()<<std::endl;
  sub_CS[0]-> Write("sub_CS0");
  sub_CS[1]-> Write("sub_CS1");
  sub_CS[2]-> Write("sub_CS2");

  std::vector<TGraphErrors*> ave_CS=read_file::makeCS3("txt/CS_ave.txt");
  std::cout<<ave_CS[0]-> GetN()<<std::endl;
  ave_CS[0]-> Write("ave_CS0");
  ave_CS[1]-> Write("ave_CS1");
  ave_CS[2]-> Write("ave_CS2");

  std::vector<TGraphErrors*> pimS0_CS=read_file::makeCS2("txt/CS_pimS0.txt");
  pimS0_CS[0]-> Write("pimS0_CS0");
  pimS0_CS[1]-> Write("pimS0_CS1");
  std::vector<double> x,x_err,  I0_CS, I0_CS_err;
  for( int i=0; i<pimS0_CS[0]->GetN(); i++ ){
    double tmpx, tmpx2, tmp_ave, tmp_pimS0;
    pimS0_CS[0]-> GetPoint(i, tmpx, tmp_pimS0);
    ave_CS[0]-> GetPoint(i, tmpx2, tmp_ave);
    double pimS0_err=pimS0_CS[0]-> GetErrorY(i);
    double ave_err=ave_CS[0]-> GetErrorY(i);
    std::cout<<tmpx<<"  "<<tmpx2<<"  "<<tmp_ave<<"  "<<tmp_pimS0<<std::endl;
    x.push_back(tmpx);
    x_err.push_back(0.005);
    I0_CS.push_back(tmp_ave-0.5*tmp_pimS0);
    I0_CS_err.push_back(sqrt(pow(pimS0_err, 2)+pow(ave_err, 2)));
  }
  TGraphErrors *gra_I0=new TGraphErrors(x.size(), &x[0], &I0_CS[0], &x_err[0], &I0_CS_err[0]);
  gra_I0-> Write("I0_CS");

  std::vector<TGraphErrors*> pimL_CS=read_file::makeCS2("txt/CS_pimL.txt");
  pimL_CS[0]-> Write("pimL_CS0");
  pimL_CS[1]-> Write("pimL_CS1");

  TGraphErrors* pi0S0_CS=read_file::makeCS("txt/CS_pi0S0_ana65.txt");
  pi0S0_CS-> Write("pi0S0_CS");

  TGraphErrors* pimSp_CS_back=read_file::makeCS("txt/CS_pimSp_ana65.txt");
  pimSp_CS_back-> Write("pimSp_CS_backward");
}
