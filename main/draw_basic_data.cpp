#include "constant.hh"
#include "W_to_mom.hh"
#include "reso.hh"
#include "TMatrix.hh"
#include "d_wave_func.hh"

const TString outrootname="scat_test.root";

int main(){
  TransMatrix T_piS_KN(piMass, sigmaMass, kMass, NMass);
  // TransMatrix T_piS_KN(piMass, sigmaMass, kMass, NMass, std::complex<double>(1.4177, 0.84), std::complex<double>(-0.18, -0.4), 0);

  TFile *of=new TFile(outrootname, "recreate");

  std::vector<double> x, amp_KN_KN_re, amp_KN_KN_im, amp_KN_KN_abs, amp_KN_piS_re, amp_KN_piS_im, amp_KN_piS_abs;
  //  std::cout<<T_piS_KN.amp12(1.4)<<std::endl;
  for( double mass=1.35; mass<1.5; mass+=0.001 ){
    x.push_back(mass);
    auto amp_KN_KN=T_piS_KN.amp22(mass);
    auto amp_KN_piS=T_piS_KN.amp12(mass);
    amp_KN_KN_re.push_back(amp_KN_KN.real()*0.19733);
    amp_KN_KN_im.push_back(amp_KN_KN.imag()*0.19733);
    amp_KN_piS_re.push_back(amp_KN_piS.real()*0.19733);
    amp_KN_piS_im.push_back(amp_KN_piS.imag()*0.19733);
    std::cout<<mass<<"  "<<T_piS_KN.amp12(mass)<<std::endl;
  }

  double sum=0;
  for( size_t i=0; i<sizeof(d_wave_func::C)/sizeof(d_wave_func::C[0]); i++ ){
    std::cout<<"C_"<<i<<"  "<<d_wave_func::C[i]<<std::endl;
    sum+=d_wave_func::C[i];
  }
  std::cout<<"Sum(C) = "<<sum<<std::endl;

  std::vector<double> mom, wave_func, wave_func_pp, wave_func_knucl, wave_func_knucl_pp;
  for( double p=0; p<1.0; p+=0.001 ){
    mom.push_back(p);
    //    std::cout<<p<<"  "<<d_wave_func::value(p)<<std::endl;
    wave_func.push_back(d_wave_func::value(p));
    wave_func_pp.push_back(p*p*d_wave_func::value(p));
    wave_func_knucl.push_back(d_wave_func::value_knucl(p));
    wave_func_knucl_pp.push_back(p*p*d_wave_func::value_knucl(p));
  }

  TGraph *gra_KN_re=new TGraph(x.size(), &x[0], &amp_KN_KN_re[0]);
  gra_KN_re-> Write("KN_KN_re");
  TGraph *gra_KN_im=new TGraph(x.size(), &x[0], &amp_KN_KN_im[0]);
  gra_KN_im-> Write("KN_KN_im");
  TGraph *gra_piS_re=new TGraph(x.size(), &x[0], &amp_KN_piS_re[0]);
  gra_piS_re-> Write("KN_piS_re");
  TGraph *gra_piS_im=new TGraph(x.size(), &x[0], &amp_KN_piS_im[0]);
  gra_piS_im-> Write("KN_piS_im");

  TGraph *gra_d_wave_func=new TGraph(mom.size(), &mom[0], &wave_func[0]);
  gra_d_wave_func-> Write("d_wave_func");
  TGraph *gra_d_wave_func_pp=new TGraph(mom.size(), &mom[0], &wave_func_pp[0]);
  gra_d_wave_func-> Write("d_wave_func_pp");

  TGraph *gra_d_wave_func_knucl=new TGraph(mom.size(), &mom[0], &wave_func_knucl[0]);
  gra_d_wave_func_knucl-> Write("d_wave_func_knucl");
  TGraph *gra_d_wave_func_knucl_pp=new TGraph(mom.size(), &mom[0], &wave_func_knucl_pp[0]);
  gra_d_wave_func_knucl_pp-> Write("d_wave_func_knucl_pp");

  of-> Write();
}
