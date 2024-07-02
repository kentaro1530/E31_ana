#include "scat.hh"
#include "d_wave_func.hh"
#include "Gopal.hh"

int main(){
  std::cout<<"===== Test START ====="<<std::endl;
  TFile *of=new TFile("test.root", "recreate");
  std::complex<double> A(-1.12/Const_GeVFM, 0.84/Const_GeVFM), R(-0.18/Const_GeVFM, -0.40/Const_GeVFM);
  {
    std::vector<double> x, y_re, y_im;
    for( double mass=1.35; mass<1.5; mass+=0.001){    
      std::complex<double> T=scat::KbarN_KbarN(A, R, mass);
      std::cout<<mass<<"   "<<T.real()<<"  "<<T.imag()<<std::endl;
      x.push_back(mass);
      y_re.push_back(T.real());
      y_im.push_back(T.imag());
    }
    TGraph *gra_re=new TGraph(x.size(), &x[0], &y_re[0]);
    TGraph *gra_im=new TGraph(x.size(), &x[0], &y_im[0]);
    gra_re-> Write("gra_T_KbarN_KbarN_re");
    gra_im-> Write("gra_T_KbarN_KbarN_im");
  }

  {
    std::vector<double> x, y;
    for( double p=0; p<0.5; p+=0.001){
      x.push_back(p);
      y.push_back(d_wave_func::value(p));
    }
    TGraph *gra=new TGraph(x.size(), &x[0], &y[0]);
    gra-> Write("gra_d_wave_func");
  }
  std::cout<<"===== Test FINISH ====="<<std::endl;



}
