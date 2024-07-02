#include "constant.hh"
#include "W_to_mom.hh"
#include "reso.hh"
#include "TMatrix.hh"

const std::complex<double> A_noumi(-1.12,  0.84);
const std::complex<double> R_noumi(-0.18, -0.40);

const std::complex<double> A_I1[]={
  std::complex<double>(0.60, 0.50),
  std::complex<double>(0.45, 0.53),
  std::complex<double>(0.52, 0.64)
};
const TString name[]={  "TW1",
  "Ohnishi",
  "ORB"
};

const std::complex<double> complex_zero(0, 0);

void make_scat_amp(const TransMatrix &T, const char *name);

void make_scat_amp(){
  TransMatrix T_piS_KN(piMass, sigmaMass, kMass, NMass);
  T_piS_KN.setA(A_noumi/Const_GeVFM);
  T_piS_KN.setR(R_noumi/Const_GeVFM);
  make_scat_amp(T_piS_KN, "fit_noumi");

  T_piS_KN.setR(complex_zero);
  for( size_t i=0; i<sizeof(A_I1)/sizeof(A_I1[0]); i++ ){
    T_piS_KN.setA(A_I1[i]/Const_GeVFM);
    make_scat_amp(T_piS_KN, name[i].Data());
  }
}

void make_scat_amp(const TransMatrix &T, const char *name){
  std::vector<double> x, amp_KN_KN_re, amp_KN_KN_im, amp_KN_piS_re, amp_KN_piS_im, amp_KN_KN_abs2, amp_KN_piS_abs2;
  for( double mass=1.3; mass<1.6; mass+=0.001 ){
    auto amp_KN_KN=T.amp22(mass);
    auto amp_KN_piS=T.amp12(mass);

    x.push_back(mass);
    amp_KN_KN_re.push_back(amp_KN_KN.real()*Const_GeVFM);
    amp_KN_KN_im.push_back(amp_KN_KN.imag()*Const_GeVFM);
    amp_KN_piS_re.push_back(amp_KN_piS.real()*Const_GeVFM);
    amp_KN_piS_im.push_back(amp_KN_piS.imag()*Const_GeVFM);
    amp_KN_KN_abs2.push_back(std::norm(amp_KN_KN)*Const_GeVFM);
    amp_KN_piS_abs2.push_back(std::norm(amp_KN_piS)*Const_GeVFM);
  } 

  TGraph *gra_KN_KN_re=new TGraph(x.size(), &x[0], &amp_KN_KN_re[0]);  
  TGraph *gra_KN_KN_im=new TGraph(x.size(), &x[0], &amp_KN_KN_im[0]);  
  TGraph *gra_KN_piS_re=new TGraph(x.size(), &x[0], &amp_KN_piS_re[0]);  
  TGraph *gra_KN_piS_im=new TGraph(x.size(), &x[0], &amp_KN_piS_im[0]);  
  TGraph *gra_KN_KN_abs2=new TGraph(x.size(), &x[0], &amp_KN_KN_abs2[0]);  
  TGraph *gra_KN_piS_abs2=new TGraph(x.size(), &x[0], &amp_KN_piS_abs2[0]);  
  gra_KN_KN_re-> Write(Form("%s_KN_KN_re", name));
  gra_KN_KN_im-> Write(Form("%s_KN_KN_im", name));
  gra_KN_piS_re-> Write(Form("%s_KN_piS_re", name));
  gra_KN_piS_im-> Write(Form("%s_KN_piS_im", name));
  gra_KN_KN_abs2-> Write(Form("%s_KN_KN_abs2", name));
  gra_KN_piS_abs2-> Write(Form("%s_KN_piS_abs2", name));
}
