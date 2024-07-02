#include "Kamano.hh"

const Kamano kamanoSpectra;

void make_Kamano_spec(){
  TGraph *gra_pimSpA=read_file::makeGraph("txt/pimSp_A.txt");
  TGraph *gra_pipSmA=read_file::makeGraph("txt/pipSm_A.txt");
  TGraph *gra_pi0S0A=read_file::makeGraph("txt/pi0S0_A.txt");
  TGraph *gra_pimS0A=read_file::makeGraph("txt/pimS0_A.txt");
  TGraph *gra_aveA  =read_file::makeGraph("txt/ave_A.txt");

  gra_pimSpA-> Write("pimSp_modelA");
  gra_pipSmA-> Write("pipSm_modelA");
  gra_pi0S0A-> Write("pi0S0_modelA");
  gra_pimS0A-> Write("pimS0_modelA");
  gra_aveA->   Write("ave_modelA");

  TGraph *gra_pimSpB=read_file::makeGraph("txt/pimSp_B.txt");
  TGraph *gra_pipSmB=read_file::makeGraph("txt/pipSm_B.txt");
  TGraph *gra_pi0S0B=read_file::makeGraph("txt/pi0S0_B.txt");
  TGraph *gra_pimS0B=read_file::makeGraph("txt/pimS0_B.txt");
  TGraph *gra_aveB  =read_file::makeGraph("txt/ave_B.txt");
  gra_pimSpB-> Write("pimSp_modelB");
  gra_pipSmB-> Write("pipSm_modelB");
  gra_pi0S0B-> Write("pi0S0_modelB");
  gra_pimS0B-> Write("pimS0_modelB");
  gra_aveB->   Write("ave_modelB");

  TGraph *gra_pimSpA_conv=read_file::makeGraph_conv("txt/pimSp_A.txt");
  TGraph *gra_pipSmA_conv=read_file::makeGraph_conv("txt/pipSm_A.txt");
  TGraph *gra_pi0S0A_conv=read_file::makeGraph_conv("txt/pi0S0_A.txt");
  TGraph *gra_pimS0A_conv=read_file::makeGraph_conv("txt/pimS0_A.txt");
  TGraph *gra_aveA_conv  =read_file::makeGraph_conv("txt/ave_A.txt");
  gra_pimSpA_conv-> Write("pimSp_modelA_conv");
  gra_pipSmA_conv-> Write("pipSm_modelA_conv");
  gra_pi0S0A_conv-> Write("pi0S0_modelA_conv");
  gra_pimS0A_conv-> Write("pimS0_modelA_conv");
  gra_aveA_conv->   Write("ave_modelA_conv");

  TGraph *gra_pimSpB_conv=read_file::makeGraph_conv("txt/pimSp_B.txt");
  TGraph *gra_pipSmB_conv=read_file::makeGraph_conv("txt/pipSm_B.txt");
  TGraph *gra_pi0S0B_conv=read_file::makeGraph_conv("txt/pi0S0_B.txt");
  TGraph *gra_pimS0B_conv=read_file::makeGraph_conv("txt/pimS0_B.txt");
  TGraph *gra_aveB_conv  =read_file::makeGraph_conv("txt/ave_B.txt");
  gra_pimSpB_conv-> Write("pimSp_modelB_conv");
  gra_pipSmB_conv-> Write("pipSm_modelB_conv");
  gra_pi0S0B_conv-> Write("pi0S0_modelB_conv");
  gra_pimS0B_conv-> Write("pimS0_modelB_conv");
  gra_aveB_conv->   Write("ave_modelB_conv");

  std::vector<double> x, y_A, y_B, y_A_conv, y_B_conv, pimS0_heaf, pimS0_heaf_conv;
  for( int i=0; i<gra_pimS0A->GetN(); i++ ){
    double tmpx, tmpy_A, tmpy_A_conv, tmpy_B, tmpy_B_conv;
    gra_pimS0A-> GetPoint(i, tmpx, tmpy_A);
    gra_pimS0B-> GetPoint(i, tmpx, tmpy_B);
    gra_pimS0A_conv-> GetPoint(i, tmpx, tmpy_A_conv);
    gra_pimS0B_conv-> GetPoint(i, tmpx, tmpy_B_conv);
  }

  for( double m=1.35; m<1.55; m+=0.001 ){
    x.push_back(m);
    y_A.push_back(kamanoSpectra.interfer_A(m));
    y_B.push_back(kamanoSpectra.interfer_B(m));
    y_A_conv.push_back(reso::conv_kn(m, kamanoSpectra.interfer_A_points()[0], kamanoSpectra.interfer_A_points()[1]));
    y_B_conv.push_back(reso::conv_kn(m, kamanoSpectra.interfer_B_points()[0], kamanoSpectra.interfer_B_points()[1]));
  }

  TGraph *gra_interfer_A=new TGraph(x.size(), &x[0], &y_A[0]);
  TGraph *gra_interfer_B=new TGraph(x.size(), &x[0], &y_B[0]);
  gra_interfer_A-> Write("interfer_A");
  gra_interfer_B-> Write("interfer_B");

  TGraph *gra_interfer_A_conv=new TGraph(x.size(), &x[0], &y_A_conv[0]);
  TGraph *gra_interfer_B_conv=new TGraph(x.size(), &x[0], &y_B_conv[0]);
  gra_interfer_A_conv-> Write("interfer_A_conv");
  gra_interfer_B_conv-> Write("interfer_B_conv");


}
