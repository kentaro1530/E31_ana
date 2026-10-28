#include "util.hh"

const int N=100000;

bool util::TMatrix::getPoleWidth(const TransMatrix&tmat, const double &A_re_err, const double &A_im_err, const double &R_re_err, const double &R_im_err,
				 double &pole, double &pole_min, double &pole_max, double &width, double &width_min, double &width_max){
  pole_min  =  1.5;
  pole_max  =  0;
  width_min =  1.0;
  width_max = -1.0;

  TransMatrix tmat2=tmat;
  double A_re=tmat.getA().real();
  double A_im=tmat.getA().imag();
  double R_re=tmat.getR().real();
  double R_im=tmat.getR().imag();
  std::complex<double> A(A_re, A_im);
  std::complex<double> R(R_re, R_im);

  std::complex<double> ans1=(std::complex<double>(0, 1)*A+sqrt(-A*A-2.0*A*R))/(A*R);
  std::complex<double> ans2=(std::complex<double>(0, 1)*A-sqrt(-A*A-2.0*A*R))/(A*R);
  std::complex<double> pole1=sqrt(ans1*ans1+tmat.getMass10()*tmat.getMass10())+sqrt(ans1*ans1+tmat.getMass11()*tmat.getMass11());
  std::complex<double> pole2=sqrt(ans2*ans2+tmat.getMass10()*tmat.getMass10())+sqrt(ans2*ans2+tmat.getMass11()*tmat.getMass11());

  pole=pole1.real();
  width=pole1.imag();

  TH1F *h1_p=new TH1F("Pole_dist_flat", "Pole_dist",  1500, 1.350, 1.5);
  TH1F *h1_w=new TH1F("Width_dist_flat","Width_dist", 2000, -0.1, 0.1);

  TH1F *h1_p2=new TH1F("Pole_dist_gauss", "Pole_dist",  1500, 1.350, 1.5);
  TH1F *h1_w2=new TH1F("Width_dist_gauss","Width_dist", 2000, -0.1, 0.1);

  TH2F *h2_A=new TH2F("A_dist_check", "A check", 1000, -10.0, 10.0, 1000, -10.0, 10.0);
  TH2F *h2_R=new TH2F("R_dist_check", "R check", 1000, -10.0, 10.0, 1000, -10.0, 10.0);

  TH1F *h1_T=new TH1F("TbarT_dist", "TbarT_dist", 1000, 0.0, 10.0);
  
  for( int i=0; i<N; i++ ){
    double tmp_A_re=A_re+2.0*A_re_err*(gRandom-> Rndm()-0.5);
    double tmp_A_im=A_im+2.0*A_im_err*(gRandom-> Rndm()-0.5);
    double tmp_R_re=R_re+2.0*R_re_err*(gRandom-> Rndm()-0.5);
    double tmp_R_im=R_im+2.0*R_im_err*(gRandom-> Rndm()-0.5);
    A=std::complex<double>(tmp_A_re, tmp_A_im);
    R=std::complex<double>(tmp_R_re, tmp_R_im);
    ans1=(std::complex<double>(0, 1)*A+sqrt(-A*A-2.0*A*R))/(A*R);
    ans2=(std::complex<double>(0, 1)*A-sqrt(-A*A-2.0*A*R))/(A*R);

    pole1=sqrt(ans1*ans1+tmat.getMass10()*tmat.getMass10())+sqrt(ans1*ans1+tmat.getMass11()*tmat.getMass11());
    pole2=sqrt(ans2*ans2+tmat.getMass10()*tmat.getMass10())+sqrt(ans2*ans2+tmat.getMass11()*tmat.getMass11());
    h1_p-> Fill(pole1.real());
    h1_w-> Fill(pole1.imag());

    if( pole_min>pole1.real() ) pole_min=pole1.real();
    if( pole_max<pole1.real() ) pole_max=pole1.real();

    if( width_min>pole1.imag() ) width_min=pole1.imag();
    if( width_max<pole1.imag() ) width_max=pole1.imag();

    h2_A-> Fill(tmp_A_re, tmp_A_im);
    h2_R-> Fill(tmp_R_re, tmp_R_im);

    tmp_A_re=gRandom-> Gaus(A_re, A_re_err);
    tmp_A_im=gRandom-> Gaus(A_im, A_im_err);
    tmp_R_re=gRandom-> Gaus(R_re, R_re_err);
    tmp_R_im=gRandom-> Gaus(R_im, R_im_err);
    A=std::complex<double>(tmp_A_re, tmp_A_im);
    R=std::complex<double>(tmp_R_re, tmp_R_im);
    tmat2.setA(A);
    tmat2.setR(R);    
    ans1=(std::complex<double>(0, 1)*A+sqrt(-A*A-2.0*A*R))/(A*R);
    ans2=(std::complex<double>(0, 1)*A-sqrt(-A*A-2.0*A*R))/(A*R);
    pole1=sqrt(ans1*ans1+tmat.getMass10()*tmat.getMass10())+sqrt(ans1*ans1+tmat.getMass11()*tmat.getMass11());
    pole2=sqrt(ans2*ans2+tmat.getMass10()*tmat.getMass10())+sqrt(ans2*ans2+tmat.getMass11()*tmat.getMass11());
    h1_p2-> Fill(pole1.real());
    h1_w2-> Fill(pole1.imag());
    h1_T-> Fill(pow(fabs(tmat.amp22(pole1.real()))/fabs(tmat2.amp12(pole1.real())), 2));
  }

  std::cout<<"Pole  : "<<pole<<"  "<<pole_max<<"   "<<pole_min<<std::endl;
  std::cout<<"Width : "<<width<<"  "<<width_max<<"   "<<width_min<<std::endl;
  std::cout<<"T1/T2 : "<<pow(fabs(tmat.amp22(pole))/fabs(tmat.amp12(pole)), 2)<<std::endl;
  
  return true;
}








