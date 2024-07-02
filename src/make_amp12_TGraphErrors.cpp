#include "util.hh"

const int N=100000;

std::complex<double> calc_amp22(TransMatrix &mat, const double &x, const double &A_re, const double &A_im, const double &R_re, const double &R_im){
  mat.setAR(A_re, A_im, R_re, R_im);
  return mat.amp22(x);
}

std::vector<TGraphAsymmErrors*> util::TMatrix::make_amp12_TGraphErrors(const TransMatrix &tmat, const double &A_re_err, const double &A_im_err, const double &R_re_err, const double &R_im_err, 
								       const double &min, const double &max){
  TransMatrix tmat2=tmat;
  double A_re=tmat.getA().real();
  double A_im=tmat.getA().imag();
  double R_re=tmat.getR().real();
  double R_im=tmat.getR().imag();

  std::vector<double> x, y_re, y_im, y_re_min, y_re_max, y_im_min, y_im_max;
  for( double m=min; m<max; m+=0.001 ){
    std::complex<double> amp22=tmat.amp22(m);
    double amp22_re_min=amp22.real();
    double amp22_re_max=amp22.real();
    double amp22_im_min=amp22.imag();
    double amp22_im_max=amp22.imag();

    TH1F *h1_re=new TH1F(Form("amp_check_re_%d", (int)(1000*m)), "", 1000, -20, 20);
    TH1F *h1_im=new TH1F(Form("amp_check_im_%d", (int)(1000*m)), "", 1000, -20, 20);

    for( int i=0; i<N; i++ ){
      double tmp_A_re=A_re+2.0*A_re_err*(gRandom-> Rndm()-0.5);
      double tmp_A_im=A_im+2.0*A_im_err*(gRandom-> Rndm()-0.5);
      double tmp_R_re=R_re+2.0*R_re_err*(gRandom-> Rndm()-0.5);
      double tmp_R_im=R_im+2.0*R_im_err*(gRandom-> Rndm()-0.5);
      
      std::complex<double> tmp_amp22=calc_amp22(tmat2, m, tmp_A_re, tmp_A_im, tmp_R_re, tmp_R_im);
      
      h1_re-> Fill(tmp_amp22.real());
      h1_im-> Fill(tmp_amp22.imag());
    }
    h1_re-> Fit("gaus", "");
    double re_mean =h1_re->GetFunction("gaus")-> GetParameter(1);
    double re_sigma=h1_re->GetFunction("gaus")-> GetParameter(2);
    h1_im-> Fit("gaus", "");
    double im_mean =h1_im->GetFunction("gaus")-> GetParameter(1);
    double im_sigma=h1_im->GetFunction("gaus")-> GetParameter(2);

    x.push_back(m);
    y_re.push_back(amp22.real());
    y_im.push_back(amp22.imag());

    y_re_max.push_back((re_mean+re_sigma)-amp22.real());
    y_re_min.push_back(amp22.real()-(re_mean-re_sigma));
    y_im_max.push_back((im_mean+im_sigma)-amp22.imag());
    y_im_min.push_back(amp22.imag()-(im_mean-im_sigma));

    // std::cout<<"m="<<m<<std::endl;
    // std::cout<<amp22_re_min<<"  "<<amp22.real()<<"  "<<amp22_re_max<<std::endl;
    // std::cout<<amp22_im_min<<"  "<<amp22.imag()<<"  "<<amp22_im_max<<std::endl;
  }

  std::vector<TGraphAsymmErrors*> result;
  result.push_back(new TGraphAsymmErrors(x.size(), &x[0], &y_re[0], 0, 0, &y_re_min[0], &y_re_max[0]));
  result.push_back(new TGraphAsymmErrors(x.size(), &x[0], &y_im[0], 0, 0, &y_im_min[0], &y_im_max[0]));
  return result;
}
